#ifndef giocatorihpp
#define giocatorihpp

#include <QWidget>
#include <QVector>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>

class Giocatori : public QWidget {
    Q_OBJECT


public:
    QVector<QString> giocatori;
    QVector<QLineEdit*> le_giocatori;
    QPushButton* aggiungi;
    QPushButton* fatto;
    QHBoxLayout* tt;
    QVBoxLayout* layoutgiocatori;
    
    Giocatori(QWidget *parent = nullptr);

signals:
    void passa_a_parola();
};

#endif