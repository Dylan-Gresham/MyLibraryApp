//
// mainwindow.cpp
// Created by Dylan Gresham on 8/29/2023
//

#include "ui_mainwindow.h"
#include "searchdialog.h"
#include "mainwindow.h"
#include "globalvars.h"
#include "editdialog.h"
#include "newdialog.h"

#include <QTableWidgetItem>
#include <QMessageBox>
#include <QModelIndex>
#include <QString>

#include <iostream>

int bookAddition;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    bookAddition = 0;
    ui->setupUi(this);

    connect(this->ui->bookTable->horizontalHeader(), SIGNAL(sortIndicatorChanged(int,Qt::SortOrder)),
            this, SLOT(sortIndicatorChanged(int,Qt::SortOrder)));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_newButton_clicked()
{
    // Opens a new dialog menu with the MainWindow being the parent
    bookAddition = 0;
    NewDialog * dialog = new NewDialog(this);
    dialog->setModal(true); // Enables modality
    dialog->exec();

    if(bookAddition == 1) {
        // Get values from most recent book and store in proper Q variables
        QString titleQStr = QString::fromStdString(dialog->returnBook.getTitle());
        QString authorQStr = QString::fromStdString(dialog->returnBook.getAuthor());
        QString numPagesQStr = QString::number(dialog->returnBook.getNumPages());

        QString ratingQStr;
        // Determine which value to place for rating
        if(dialog->returnBook.getRating() == -1) {
            ratingQStr = QString::fromStdString("Awaiting Rating");
        } else if(dialog->returnBook.getRating() >= 0) {
            ratingQStr = QString::number(dialog->returnBook.getRating());
        } else {
            ratingQStr = QString::fromStdString("Unknown");
        }

        // Determine which value to place for status
        QString statusQStr = QString::fromStdString(dialog->returnBook.statusToStr());

         // Append a new row to the table
        this->ui->bookTable->insertRow(this->ui->bookTable->rowCount());

        // Add values to the row
        this->ui->bookTable->setItem(this->ui->bookTable->rowCount() - 1, 0, new QTableWidgetItem(titleQStr));
        this->ui->bookTable->setItem(this->ui->bookTable->rowCount() - 1, 1, new QTableWidgetItem(authorQStr));
        this->ui->bookTable->setItem(this->ui->bookTable->rowCount() - 1, 2, new QTableWidgetItem(numPagesQStr));
        this->ui->bookTable->setItem(this->ui->bookTable->rowCount() - 1, 3, new QTableWidgetItem(statusQStr));
        this->ui->bookTable->setItem(this->ui->bookTable->rowCount() - 1, 4, new QTableWidgetItem(ratingQStr));

        // Create, Center, & Add editButton
        QWidget *ebWidget = new QWidget();
        QPushButton *editButton = new QPushButton();
        editButton->setText("Edit");
        QHBoxLayout *editHboxLayout = new QHBoxLayout(ebWidget);
        editHboxLayout->addWidget(editButton);
        editHboxLayout->setAlignment(Qt::AlignCenter);
        editHboxLayout->setContentsMargins(0, 0, 0, 0);
        ebWidget->setLayout(editHboxLayout);
        connect(editButton, &QPushButton::clicked, this, &MainWindow::editButtonClicked);
        this->ui->bookTable->setCellWidget(this->ui->bookTable->rowCount() - 1, 5, ebWidget);

        // Create, Center, & Add Remove Button
        QWidget *rbWidget = new QWidget();
        QPushButton *removeButton = new QPushButton();
        removeButton->setText("Remove");
        QHBoxLayout *removeHBoxLayout = new QHBoxLayout(rbWidget);
        removeHBoxLayout->addWidget(removeButton);
        removeHBoxLayout->setAlignment(Qt::AlignCenter);
        removeHBoxLayout->setContentsMargins(0, 0, 0, 0);
        rbWidget->setLayout(removeHBoxLayout);
        connect(removeButton, &QPushButton::clicked, this, &MainWindow::removeButtonClicked);
        this->ui->bookTable->setCellWidget(this->ui->bookTable->rowCount() - 1, 6, rbWidget);

        bookAddition = 0;
    }
}

void MainWindow::editButtonClicked() {
    // Get bookTable row
    QWidget *parentWidget = qobject_cast<QWidget *>(sender()->parent()); // Gets parent widget
    int row;
    if(parentWidget) {
        row = this->ui->bookTable->indexAt(parentWidget->pos()).row(); // Gets the row index if the parentWidget isn't a nullptr
    } else {
        return;
    }

    // Get the book title of the row
    std::string ogTitle = this->ui->bookTable->item(row, 0)->text().toStdString();

    // Find Library entry from Library->booksVector that matches
    Book toEditBook = lib.findBook(ogTitle);

    // Open Edit Dialog
    EditDialog* editDialog = new EditDialog(this, toEditBook);
    editDialog->setModal(true);
    editDialog->exec();

    this->ui->bookTable->item(row, 0)->setText(QString::fromStdString(editDialog->book.getTitle()));
    this->ui->bookTable->item(row, 1)->setText(QString::fromStdString(editDialog->book.getAuthor()));
    this->ui->bookTable->item(row, 2)->setText(QString::number(editDialog->book.getNumPages()));
    this->ui->bookTable->item(row, 3)->setText(QString::fromStdString(editDialog->book.statusToStr()));
    if(editDialog->book.getRating() == -1) {
        this->ui->bookTable->item(row, 4)->setText(QString::fromStdString("Awaiting Rating"));
    } else {
        this->ui->bookTable->item(row, 4)->setText(QString::number(editDialog->book.getRating()));
    }

    /* Check Library->authorsMap for the original author, if the author name changed,
     * decrement and increment new author
     *
     * I think doing Library->authorsMap[oldAuthor]-- and then Library->authorsMap[newAuthor]++
     * would accomplish this
     */
    lib.getAuthors()[editDialog->originalData[1]]--;
    lib.getAuthors()[editDialog->editedData[1]]++;

    return;
}

void MainWindow::removeButtonClicked() {
    QWidget *parentWidget = qobject_cast<QWidget *>(sender()->parent()); // Get the parent widget of the removeButton
    if(parentWidget) {
        int row = this->ui->bookTable->indexAt(parentWidget->pos()).row(); // Get the row index
        std::string remTitle = this->ui->bookTable->item(row, 0)->text().toStdString(); // Get the title of the Book at that row
        this->ui->bookTable->removeRow(row);
        this->ui->bookTable->setCurrentCell(row - 1, 0);
        int delBookPass = lib.deleteBook(remTitle);
        if(delBookPass < 0) {
            QMessageBox::information(this, tr("LibraryApp"),
                                     QString::fromStdString(remTitle +
                                                            " was not found in your Library database."),
                                     QMessageBox::Ok);
        }
    }
}

void MainWindow::on_searchButton_clicked()
{
    // Opens a new dialog menu with the MainWindow being the parent
    SearchDialog * dialog = new SearchDialog(this);
    dialog->setModal(true);
    dialog->exec();

    // Determine if we should search or not
    if(dialog->doSearch()) {
        // Get the book to search for
        std::string searchTitle = dialog->getQuery();

        bool found = false;
        QTableWidgetItem * item;
        for(int row = 0; row < this->ui->bookTable->rowCount(); row++)
        {
            if(this->ui->bookTable->item(row, 0)->text().toStdString().compare(searchTitle) == 0) {
                found = true;
                item = this->ui->bookTable->item(row, 0);
                break;
            }
        }

        if(found) {
            QModelIndex idx = this->ui->bookTable->indexFromItem(item);
            this->ui->bookTable->scrollTo(idx);
        } else {
            QMessageBox::information(this, tr("LibraryApp"),
                                     QString::fromStdString(searchTitle +
                                                            " was not found in your Library."),
                                     QMessageBox::Ok);
        }
    }
}

void MainWindow::sortIndicatorChanged(int column, Qt::SortOrder sortOrder) {
    int newSortFunction = -1;
    if(column == 0) { // Title column
        newSortFunction = 1; // Alphabetical by title
    } else if(column == 1) { // Author column
        newSortFunction = 0; // Alphabetical by author
    } else if(column == 2) { // Total # of Pages column
        newSortFunction = 4; // Descending by totalNumPages
    } else if(column == 3) { // Status column
        newSortFunction = 8; // Descending by status
    } else if(column == 4) { // Rating column
        newSortFunction = 5; // Descending by rating
    } else {
        newSortFunction = 0;
    }

    if(sortOrder == 0) {
        if(newSortFunction <= 1 || (newSortFunction <= 5 && newSortFunction > 3)) {
            newSortFunction += 2;
        } else {
            newSortFunction++;
        }
    }

    lib.setSortingFunction(newSortFunction);
    lib.sortLibrary();

    return;
}
