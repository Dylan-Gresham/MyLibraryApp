//
// main.cpp
// Created by Dylan Gresham on 8/29/2023
//

#include "mainwindow.h"
#include "Library.h"
#include "globalvars.h"

#include <QApplication>

Library lib;

int main(int argc, char *argv[])
{
    lib = Library(); // Create a new global library everytime program starts
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
