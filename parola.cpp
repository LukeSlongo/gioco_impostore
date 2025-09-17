#include "parola.hpp"

Parola::Parola(QWidget *parent){
    QVBoxLayout* layout = new QVBoxLayout(this);
    QHBoxLayout* parolaimpostori = new QHBoxLayout();
    QHBoxLayout* spuntafatto = new QHBoxLayout();

    fatto = new QPushButton("Avanti");
    parolascelta = new QLineEdit();
    parolascelta->setPlaceholderText("Parola...");
    numero_impostori = new QLineEdit();
    numero_impostori->setPlaceholderText("Impostori");

    spunta = new QCheckBox("Parola generata automaticamente");

    parolaimpostori->addWidget(parolascelta, 8);
    parolaimpostori->addWidget(numero_impostori, 2);
    spuntafatto->addWidget(spunta);
    spuntafatto->addWidget(fatto);

    layout->addLayout(parolaimpostori);
    layout->addLayout(spuntafatto);

    //numero_impostori->setMaximumWidth(50);

    connect(fatto, &QPushButton::clicked, this, [this]() { emit passa_a_assegna(this); });
}