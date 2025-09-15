#include "cosa.hpp"

Cosa::Cosa(QString name, QString parola, QWidget *parent){
    QHBoxLayout* layout = new QHBoxLayout(this);
    
    if(name.contains("[]")){
        text = new QLabel("Sei un impostore");
    }else{
        text = new QLabel("La parola è " + parola);
    }
    
    ok = new QPushButton("Ok");
    pfine = new QPushButton("Fine");

    layout->addWidget(text);
    layout->addWidget(ok);
    layout->addWidget(pfine);

    pfine->hide();

    connect(ok, &QPushButton::clicked, this, [this]() { emit passa_a_passa(); });
    connect(pfine, &QPushButton::clicked, this, [this]() { emit fine(); });
}

void Cosa::setPropertiesDC(QString n, QString p){
    if(n.contains("[]")){
        text->setText("Sei un impostore");
        //text = new QLabel("Sei un impostore");
    }else{
        text->setText("La parola è " + p);
        //text = new QLabel("La parola è " + p);
    }
}