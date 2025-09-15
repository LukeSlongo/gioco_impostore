#include "giocatori.hpp"

Giocatori::Giocatori(QWidget *parent){
    tt = new QHBoxLayout(this);
    aggiungi = new QPushButton("+", this);
    layoutgiocatori = new QVBoxLayout();
    fatto = new QPushButton("Avanti", this);

    QLineEdit* nomepersona = new QLineEdit();
    layoutgiocatori->addWidget(nomepersona);

    le_giocatori.append(nomepersona);

    tt->addLayout(layoutgiocatori);
    tt->addWidget(aggiungi);
    tt->addWidget(fatto);

    connect(aggiungi, &QPushButton::clicked, this, [this]() { 
        QLineEdit* np = new QLineEdit();

        layoutgiocatori->addWidget(np);
        le_giocatori.append(np);
    });

    connect(fatto, &QPushButton::clicked, this, [this]() { 
        for(QLineEdit* edit : le_giocatori){
            giocatori.append(edit->text());
        }
        emit passa_a_parola(); });
}