//
// newdialog.h
// Created by Dylan Gresham on 8/29/2023
//

#ifndef LIBRARYAPP_NEWDIALOG_H
#define LIBRARYAPP_NEWDIALOG_H

#include "Book.h"

#include <QDialog>

namespace Ui {
class NewDialog;
}

class NewDialog : public QDialog
{
    Q_OBJECT

public:
    std::string* getStrings();
    int* getInts();
    Book returnBook = Book("", "", "", 0, -1, 4);

    explicit NewDialog(QWidget *parent = nullptr);
    ~NewDialog();

private slots:
    void on_buttonBox_rejected();

    void on_buttonBox_accepted();

    void done(int r);

private:
    Ui::NewDialog *ui;
};

#endif // LIBRARYAPP_NEWDIALOG_H
