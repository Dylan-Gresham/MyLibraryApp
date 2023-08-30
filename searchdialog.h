#ifndef SEARCHDIALOG_H
#define SEARCHDIALOG_H

#include <QDialog>
#include <string>

namespace Ui {
class SearchDialog;
}

class SearchDialog : public QDialog
{
    Q_OBJECT

public:
    std::string getQuery();
    bool doSearch();
    bool search;

    explicit SearchDialog(QWidget *parent = nullptr);
    ~SearchDialog();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void done(int r);

private:
    Ui::SearchDialog *ui;
};

#endif // SEARCHDIALOG_H
