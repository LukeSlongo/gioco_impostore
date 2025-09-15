#include "parola.hpp"

Parola::Parola(QWidget *parent){
    QHBoxLayout* layout = new QHBoxLayout(this);

    fatto = new QPushButton("Avanti");
    parolascelta = new QLineEdit();
    numero_impostori = new QLineEdit();;

    layout->addWidget(parolascelta);
    layout->addWidget(numero_impostori);
    layout->addWidget(fatto);

    numero_impostori->setMaximumWidth(30);

    connect(fatto, &QPushButton::clicked, this, [this]() { emit passa_a_assegna(this); });
}