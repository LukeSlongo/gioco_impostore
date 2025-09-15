#include <QApplication>
#include <QStyleFactory>
#include "mainwindow.hpp"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QApplication::setStyle(QStyleFactory::create("Fusion"));

    //GestoreJSON::filename = QFileDialog::getOpenFileName(nullptr,"Seleziona file JSON", "", "File JSON (*.json)");

    MainWindow window;
    //window.resize(1280, 720);
    window.show();

    return app.exec();
}