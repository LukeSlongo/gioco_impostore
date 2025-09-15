#ifndef passa
#define passa

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
//#include "giocatori.hpp"

class Passa : public QWidget {
    Q_OBJECT

    
public:
    Passa(QString name, QWidget *parent = nullptr);
    QLabel* text;
    QString nome;
    QPushButton* scopri;
    void setPropertiesDC(QString);
signals:
    void passa_a_nuovo();
};

#endif