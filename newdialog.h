//
// newdialog.h
// Created by Dylan Gresham on 8/29/2023
//

#ifndef LIBRARYAPP_NEWDIALOG_H
#define LIBRARYAPP_NEWDIALOG_H

#include <QDialog>
#include <string>

namespace Ui {
class NewDialog;
}

class NewDialog : public QDialog
{
    Q_OBJECT

public:
    std::string* getStrings();
    int* getInts();

    explicit NewDialog(QWidget *parent = nullptr);
    ~NewDialog();

private slots:
    void on_buttonBox_rejected();

    void on_buttonBox_accepted();

private:
    Ui::NewDialog *ui;
};

#endif // LIBRARYAPP_NEWDIALOG_H
