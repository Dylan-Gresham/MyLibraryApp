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
    this->ui->authorInput->setText(QString::fromStdString(editBook.getAuthor()));
    this->originalData[1] = editBook.getAuthor();
    this->ui->numPagesInput->setValue(editBook.getNumPages());
    this->originalData[2] = editBook.getNumPages();
    this->ui->statusBox->setCurrentIndex(editBook.getReadingStatus());
    this->originalData[3] = editBook.getReadingStatus();
    this->ui->ratingInput->setValue(editBook.getRating());
    this->originalData[4] = editBook.getRating();
}

EditDialog::~EditDialog()
{
    delete ui;
}

void EditDialog::done(int r) {
    if(QDialog::Accepted == r) { // Ok was pressed
        this->editedData[0] = this->ui->titleInput->text().toStdString();
        this->editedData[1] = this->ui->authorInput->text().toStdString();
        this->editedData[2] = this->ui->numPagesInput->text().toStdString();
        this->editedData[3] = this->ui->statusBox->currentIndex();
        this->editedData[4] = this->ui->ratingInput->text().toStdString();

        // Update the Book's data in the Library
        if(this->originalData[0].compare(this->editedData[0]) != 0) {
            this->book.setTitle(this->editedData[0]);
        }

        if(this->originalData[1].compare(this->editedData[1]) != 0) {
            this->book.setAuthor(this->editedData[1]);
        }

        if(this->originalData[2].compare(this->editedData[2]) != 0) {
            this->book.setNumPages(stoi(this->editedData[2]));
        }

        if(this->originalData[3].compare(this->editedData[3]) != 0) {
            this->book.setStatus(stoi(this->editedData[3]));
        }

        if(this->originalData[4].compare(this->editedData[4]) != 0) {
            this->book.setRating(stoi(this->editedData[4]));
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

