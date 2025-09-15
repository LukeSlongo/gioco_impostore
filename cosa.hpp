#ifndef cosa
#define cosa

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
//#include "giocatori.hpp"

class Cosa : public QWidget {
    Q_OBJECT

    
public:
    Cosa(QString name, QString parola, QWidget *parent = nullptr);
    QLabel* text;
    QPushButton* ok;
    QPushButton* pfine;
    void setPropertiesDC(QString n, QString p);
signals:
    void passa_a_passa();
    void fine();
    
};

#endif