//
// mainwindow.cpp
// Created by Dylan Gresham on 8/29/2023
//

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_newButton_clicked()
{
    // Opens a new dialog menu with the MainWindow being the parent
    NewDialog * dialog = new NewDialog(this);
    dialog->setModal(true); // Enables modality
    dialog->exec();
}

