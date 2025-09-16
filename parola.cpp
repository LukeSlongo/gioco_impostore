#include "parola.hpp"

Parola::Parola(QWidget *parent){
    QHBoxLayout* layout = new QHBoxLayout(this);

    fatto = new QPushButton("Avanti");
    parolascelta = new QLineEdit();
    parolascelta->setPlaceholderText("Parola...");
    numero_impostori = new QLineEdit();
    numero_impostori->setPlaceholderText("Impostori");

    spunta = new QCheckBox("Parola generata automaticamente");

    layout->addWidget(parolascelta);
    layout->addWidget(numero_impostori);
    layout->addWidget(spunta);
    layout->addWidget(fatto);

    numero_impostori->setMaximumWidth(50);

    connect(fatto, &QPushButton::clicked, this, [this]() { emit passa_a_assegna(this); });
}