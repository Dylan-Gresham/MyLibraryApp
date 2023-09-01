//
// mainwindow.cpp
// Created by Dylan Gresham on 8/29/2023
//

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newdialog.h"
#include "globalvars.h"
#include "searchdialog.h"

#include <QString>
#include <QModelIndex>
#include <QTableWidgetItem>
#include <QMessageBox>

#include <iostream>

int bookAddition;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    bookAddition = 0;
    ui->setupUi(this);
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
        QString titleQStr = QString::fromStdString(lib.getBooks().back().getTitle());
        QString authorQStr = QString::fromStdString(lib.getBooks().back().getAuthor());
        QString numPagesQStr = QString::number(lib.getBooks().back().getNumPages());

        QString ratingQStr;
        // Determine which value to place for rating
        if(lib.getBooks().back().getRating() == -1) {
            ratingQStr = QString::fromStdString("Awaiting Rating");
        } else if(lib.getBooks().back().getRating() >= 0) {
            ratingQStr = QString::number(lib.getBooks().back().getRating());
        } else {
            ratingQStr = QString::fromStdString("Unknown");
        }

        QString statusQStr;
        // Determine which value to place for status
        if(lib.getBooks().back().getReadingStatus() == 0) {
            statusQStr = QString::fromStdString("Plan to Read");
        } else if(lib.getBooks().back().getReadingStatus() == 1) {
            statusQStr = QString::fromStdString("Reading");
        } else if(lib.getBooks().back().getReadingStatus() == 2) {
            statusQStr = QString::fromStdString("Completed");
        } else if(lib.getBooks().back().getReadingStatus() == 3) {
            statusQStr = QString::fromStdString("Aside");
        } else if(lib.getBooks().back().getReadingStatus() == 4) {
            statusQStr = QString::fromStdString("Dropped");
        } else {
            statusQStr = QString::fromStdString("Unknown");
        }

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

        cout << this->ui->bookTable->cellWidget(this->ui->bookTable->rowCount(), 5) << endl;
        cout << this->ui->bookTable->cellWidget(this->ui->bookTable->rowCount(), 6) << endl;
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

    // Get book information from that row
    std::string ogTitle = this->ui->bookTable->item(row, 0)->text().toStdString();
    std::string ogAuthor = this->ui->bookTable->item(row, 1)->text().toStdString();
    int ogNumPages = this->ui->bookTable->item(row, 2)->text().toInt();

    int ogStatus;
    std::string ogStatusValue = this->ui->bookTable->item(row, 3)->text().toStdString();
    if(ogStatusValue.compare("Plan to Read") == 0) {
        ogStatus = 0;
    } else if(ogStatusValue.compare("Reading") == 0) {
        ogStatus = 1;
    } else if(ogStatusValue.compare("Complete") == 0) {
        ogStatus = 2;
    } else if(ogStatusValue.compare("Aside") == 0) {
        ogStatus = 3;
    } else if(ogStatusValue.compare("Dropped") == 0) {
        ogStatus = 4;
    } else {
        ogStatus = -1;
    }

    if(ogStatus == -1) {
        return;
    }

    int ogRating;
    std::string ogRatingValue = this->ui->bookTable->item(row, 4)->text().toStdString();
    if(ogRatingValue.compare("Awaiting Rating") == 0 || ogRatingValue.compare("Unknown") == 0) {
        ogRating = -1; // Not yet rated value
    } else {
        ogRating = stoi(ogRatingValue); // String to Int function
    }

    // Find Library entry from Library->booksVector that matches
    Book toEditBook = lib.findBook(ogTitle);

    // Open Edit Dialog


    // When Edit Dialog is accepted (i.e. not canceled or window closed), replace Library entry's info
    // Update bookTable row with new info
    /* Check Library->authorsMap for the original author, if the author name changed,
     * decrement and increment new author (I think doing Library->authorsMap[oldAuthor]--
     * and then Library->authorsMap[newAuthor]++ would accomplish this
     */
    // Return
}

void MainWindow::removeButtonClicked() {
    QWidget *parentWidget = qobject_cast<QWidget *>(sender()->parent()); // Get the parent widget of the removeButton
    if(parentWidget) {
        int row = this->ui->bookTable->indexAt(parentWidget->pos()).row(); // Get the row index
        std::string remTitle = this->ui->bookTable->item(row, 0)->text().toStdString(); // Get the title of the Book at that row
        this->ui->bookTable->removeRow(row);
        this->ui->bookTable->setCurrentCell(row - 1, 0);
        int delBookPass = lib.deleteBook(remTitle);
        if(delBookPass == -1) {
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

