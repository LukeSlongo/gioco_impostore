#ifndef parola
#define parola

#include <QWidget>
#include <QVector>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
//#include "giocatori.hpp"

class Parola : public QWidget {
    Q_OBJECT

    
public:
    Parola(QWidget *parent = nullptr);

    QLineEdit* parolascelta;
    QLineEdit* numero_impostori;
    QPushButton* fatto;
signals:
    void passa_a_assegna(Parola*);
};

#endif