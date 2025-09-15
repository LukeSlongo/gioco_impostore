#include "passa.hpp"

Passa::Passa(QString name, QWidget *parent){
    QVBoxLayout* layout = new QVBoxLayout(this);
    if(name.contains("#")){
        QString a = name;
        a.chop(1);
        nome = a;
    }else if(name.contains("[]")){
        QString a = name;
        a.chop(2);
        nome = a;
    }else{
        nome = name;
    }

    text = new QLabel("Passa il telefono a " + nome);
    scopri = new QPushButton("Scopri");

    layout->addWidget(text);
    layout->addWidget(scopri);

    connect(scopri, &QPushButton::clicked, this, [this]() { emit passa_a_nuovo(); });
}

void Passa::setPropertiesDC(QString n){
    if(n.contains("#")){
        QString a = n;
        a.chop(1);
        nome = a;
    }else if(n.contains("[]")){
        QString a = n;
        a.chop(2);
        nome = a;
    }else{
        nome = n;
    }

    QString t = "Passa il telefono a " + nome;
    text->setText(t);
    //text = new QLabel("Passa il telefono a " + nome);
}