//
// newdialog.cpp
// Created by Dylan Gresham on 8/29/2023
//

#include "newdialog.h"
#include "ui_newdialog.h"

NewDialog::NewDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewDialog)
{
    ui->setupUi(this);
}

NewDialog::~NewDialog()
{
    delete ui;
}

void NewDialog::on_buttonBox_rejected()
{
    reject();
}


void NewDialog::on_buttonBox_accepted()
{
    // Get inputs
    std::string* returnStrings = getStrings();
    int* returnInts = getInts();

    // Assign inputs to individual variables
    std::string newTitle = returnStrings[0];
    std::string newAuthor = returnStrings[1];
    int newNumPages = returnInts[0];
    int newRating = returnInts[1];
    int newStatus = returnInts[2];

    if(newTitle == "" || newAuthor == "") {
        return;
    }

    accept();
}

std::string* NewDialog::getStrings() {
    // Get valuse from inputs
    std::string newTitle = this->ui->titleInputBox->text().toStdString();
    std::string newAuthor = this->ui->authorInputBox->text().toStdString();

    // Create array
    std::string* strArr = new std::string[2];
    strArr[0] = newTitle;
    strArr[1] = newAuthor;

    // Return array
    return strArr;
}

int* NewDialog::getInts() {
    // Get values from inputs
    int newNumPages = this->ui->numPagesInputBox->value();
    int newRating = this->ui->ratingInputBox->value();
    int newCompletionStatus = this->ui->completionInputBox->currentIndex();

    // Create array
    int* intArr = new int[3];
    intArr[0] = newNumPages;
    intArr[1] = newRating;
    intArr[2] = newCompletionStatus;

    // Return array
    return intArr;
}
