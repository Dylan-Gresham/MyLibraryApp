//
// editdialog.cpp
// Created by Dylan Gresham on 09/01/2023
//

#include "editdialog.h"
#include "ui_editdialog.h"

EditDialog::EditDialog(QWidget *parent, Book editBook) :
    QDialog(parent),
    ui(new Ui::EditDialog)
{
    ui->setupUi(this);
    this->book = editBook;
    this->ui->titleInput->setText(QString::fromStdString(editBook.getTitle()));
    this->originalData[0] = editBook.getTitle();
    this->ui->authorFirstInput->setText(QString::fromStdString(editBook.getAuthorFirstName()));
    this->originalData[1] = editBook.getAuthorFirstName();
    this->ui->authorLastInput->setText(QString::fromStdString(editBook.getAuthorLastName()));
    this->originalData[2] = editBook.getAuthorLastName();
    this->ui->numPagesInput->setValue(editBook.getNumPages());
    this->originalData[3] = editBook.getNumPages();
    this->ui->statusBox->setCurrentIndex(editBook.getReadingStatus());
    this->originalData[4] = editBook.getReadingStatus();
    this->ui->ratingInput->setValue(editBook.getRating());
    this->originalData[5] = editBook.getRating();
}

EditDialog::~EditDialog()
{
    delete ui;
}

void EditDialog::done(int r) {
    if(QDialog::Accepted == r) { // Ok was pressed
        this->editedData[0] = this->ui->titleInput->text().toStdString();
        this->editedData[1] = this->ui->authorFirstInput->text().toStdString();
        this->editedData[2] = this->ui->authorLastInput->text().toStdString();
        this->editedData[3] = this->ui->numPagesInput->text().toStdString();
        this->editedData[4] = this->ui->statusBox->currentIndex();
        this->editedData[5] = this->ui->ratingInput->text().toStdString();

        // Update the Book's data in the Library
        if(this->originalData[0].compare(this->editedData[0]) != 0) {
            this->book.setTitle(this->editedData[0]);
        }

        if(this->originalData[1].compare(this->editedData[1]) != 0) {
            this->book.setAuthorFirstName(this->editedData[1]);
        }

        if(this->originalData[2].compare(this->editedData[2]) != 0) {
            this->book.setAuthorLastName(this->editedData[2]);
        }

        if(this->originalData[3].compare(this->editedData[3]) != 0) {
            this->book.setNumPages(stoi(this->editedData[3]));
        }

        if(this->originalData[4].compare(this->editedData[4]) != 0) {
            this->book.setStatus(stoi(this->editedData[4]));
        }

        if(this->originalData[5].compare(this->editedData[5]) != 0) {
            this->book.setRating(stoi(this->editedData[5]));
        }

        QDialog::done(r);
        return;
    } else { // Cancel, close, or exc was pressed
        QDialog::done(r);
        return;
    }
}

void EditDialog::on_buttonBox_accepted()
{
    accept();
}


void EditDialog::on_buttonBox_rejected()
{
    reject();
}

