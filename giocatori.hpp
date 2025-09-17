#ifndef giocatorihpp
#define giocatorihpp

#include <QWidget>
#include <QVector>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QScrollArea>

class Giocatori : public QWidget {
    Q_OBJECT


public:
    QVector<QString> giocatori;
    QVector<QLineEdit*> le_giocatori;
    QPushButton* aggiungi;
    QPushButton* togli;
    QPushButton* fatto;
    QVBoxLayout* tt;
    QVBoxLayout* layoutgiocatori;
    QHBoxLayout* layoutpulsanti;
    QScrollArea* scroll;
    QWidget* container_scroll;

    Giocatori(QWidget *parent = nullptr);

signals:
    void passa_a_parola();
};

#endif