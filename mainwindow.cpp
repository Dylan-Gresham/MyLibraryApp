//
// mainwindow.cpp
// Created by Dylan Gresham on 8/29/2023
//

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newdialog.h"
#include "globalvars.h"

#include <QTableWidgetItem>
#include <QString>

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

        bookAddition = 0;
    }
}

