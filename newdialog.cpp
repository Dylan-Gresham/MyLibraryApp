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

void NewDialog::done(int r)
{
    if(QDialog::Accepted == r) // OK was pressed
    {
        // Validate Input
        if(this->ui->titleInputBox->text().size() > 0 && this->ui->authorInputBox->text().size() > 0
            && this->ui->numPagesInputBox->value() > 0 &&
            this->ui->titleInputBox->text().toStdString().compare("Invalid title!") != 0 &&
            this->ui->authorInputBox->text().toStdString().compare("Invalid author!") != 0)
        { // If all inputs are good
            QDialog::done(r);
            return;
        } else { // One or more inputs are invalid
            if(!(this->ui->titleInputBox->text().size() > 0)) // If title input was invalid
            {
                this->ui->titleInputBox->setText("Invalid title!"); // Set title text
            }

            if(!(this->ui->authorInputBox->text().size() > 0)) // If author input was invalid
            {
                this->ui->authorInputBox->setText("Invaild author!");
            }

            if(!(this->ui->numPagesInputBox->value() > 0)) // If numPages input was invalid
            {
                this->ui->numPagesInputBox->setValue(0); // Set numPages
            }

            return;
        }
    } else { // Cancel, close or exc was pressed
        QDialog::done(r);
        return;
    }
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

    // Add new inputs to Library as a Book

    // Free memory using delete
    delete [] returnInts;
    delete [] returnStrings;

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
