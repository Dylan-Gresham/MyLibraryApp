//
// mainwindow.h
// Created by Dylan Gresham on 8/29/2023
//

#ifndef LIBRARYAPP_MAINWINDOW_H
#define LIBRARYAPP_MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_newButton_clicked();

    void on_searchButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // LIBRARYAPP_MAINWINDOW_H
