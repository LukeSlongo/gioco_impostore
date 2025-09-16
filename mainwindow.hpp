#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include <QMainWindow>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStackedWidget>
#include <QVector>
#include "giocatori.hpp"
#include "parola.hpp"
#include "passa.hpp"
#include "cosa.hpp"
#include <QRandomGenerator>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QStringList>

class MainWindow : public QMainWindow {
    Q_OBJECT
private:
    Giocatori* players;
    Parola* word;
    QStackedWidget* stack;
    Passa* pass;
    Cosa* thing;
    int posizione;
public:
    MainWindow(QWidget *parent = nullptr);
    QString parolaCasuale();
};

#endif