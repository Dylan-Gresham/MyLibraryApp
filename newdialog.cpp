//
// newdialog.cpp
// Created by Dylan Gresham on 8/29/2023
//

#include "newdialog.h"
#include "ui_newdialog.h"
#include "globalvars.h"

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
        if(this->ui->titleInputBox->text().size() > 0
            && this->ui->authorFirstInputBox->text().size() > 0
            && this->ui->authorLastInputBox->text().size() > 0
            && this->ui->numPagesInputBox->value() > 0
            && this->ui->titleInputBox->text().toStdString().compare("Invalid title!") != 0
            && this->ui->authorFirstInputBox->text().toStdString().compare("Invalid first name!") != 0
            && this->ui->authorLastInputBox->text().toStdString().compare("Invalud last name!") != 0)
        { // If all inputs are good
            QDialog::done(r);
            return;
        } else { // One or more inputs are invalid
            if(!(this->ui->titleInputBox->text().size() > 0)) // If title input was invalid
            {
                this->ui->titleInputBox->setText("Invalid title!"); // Set title text
            }
            
            if(!(this->ui->authorFirstInputBox->text().size() > 0)) // If first name input was invalid
            {
                this->ui->authorFirstInputBox->setText("Invaild first name!");
            }

            if(!(this->ui->authorLastInputBox->text().size() > 0)) { // If last name input was invalid
                this->ui->authorLastInputBox->setText("Invalid last name!");
            }

            if(!(this->ui->numPagesInputBox->value() > 0)) // If numPages input was invalid
            {
                this->ui->numPagesInputBox->setValue(0); // Set numPages
            }

            return;
        }
    } else { // Cancel, close or exc was pressed
        bookAddition = -1;
        QDialog::done(r);
        return;
    }
}

void NewDialog::on_buttonBox_rejected()
{
    bookAddition = -1;
    reject();
}


void NewDialog::on_buttonBox_accepted()
{
    // Get inputs
    std::string* returnStrings = getStrings();
    int* returnInts = getInts();

    // Assign inputs to individual variables
    std::string newTitle = returnStrings[0];
    std::string newAuthorFirstName = returnStrings[1];
    std::string newAuthorLastName = returnStrings[2];
    int newNumPages = returnInts[0];
    int newRating = returnInts[1];
    int newStatus = returnInts[2];

    // Add new inputs to Library as a Book
    Book returnBook = Book(newTitle, newAuthorFirstName, newAuthorLastName, newNumPages, newRating, newStatus);
    this->returnBook = returnBook;
    lib.addBook(this->returnBook);
    bookAddition = 1;

    // Free memory using delete
    delete [] returnInts;
    delete [] returnStrings;

    accept();
}

std::string* NewDialog::getStrings() {
    // Get valuse from inputs
    std::string newTitle = this->ui->titleInputBox->text().toStdString();
    std::string newAuthorFirstName = this->ui->authorFirstInputBox->text().toStdString();
    std::string newAuthorLastName = this->ui->authorLastInputBox->text().toStdString();

    // Create array
    std::string* strArr = new std::string[3];
    strArr[0] = newTitle;
    strArr[1] = newAuthorFirstName;
    strArr[2] = newAuthorLastName;

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
