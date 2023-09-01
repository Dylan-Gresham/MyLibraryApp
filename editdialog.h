//
// editdialog.h
// Created by Dylan Gresham on 09/01/2023
//

#ifndef LIBRRARYAPP_EDITDIALOG_H
#define LIBRRARYAPP_EDITDIALOG_H

#include "Book.h"

#include <QDialog>
#include <string>

namespace Ui {
class EditDialog;
}

class EditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditDialog(QWidget *parent = nullptr, Book editingBook = Book("", "", 0, -1, 0));
    ~EditDialog();
    Book book = Book("", "", 0, -1, 0);
    std::string* originalData;
    std::string* editedData;

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void done(int r);

private:
    Ui::EditDialog *ui;
};

#endif // LIBRRARYAPP_EDITDIALOG_H
