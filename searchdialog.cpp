#include "searchdialog.h"
#include "ui_searchdialog.h"

SearchDialog::SearchDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchDialog)
{
    ui->setupUi(this);
}

SearchDialog::~SearchDialog()
{
    delete ui;
}

void SearchDialog::done(int r)
{
    if(QDialog::Accepted) { // OK was pressed
        // Validate input
        if(this->ui->queryBox->text().size() > 0) {
            QDialog::done(r);
            return;
        } else { // Invalid input
            return;
        }
    } else { // Cancel, close, or exc was pressed
        QDialog::done(r);
        return;
    }
}

std::string SearchDialog::getQuery() {
    return this->ui->queryBox->text().toStdString();
}

void SearchDialog::on_buttonBox_accepted()
{
    accept();
}


void SearchDialog::on_buttonBox_rejected()
{
    reject();
}

