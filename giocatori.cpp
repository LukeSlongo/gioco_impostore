#include "giocatori.hpp"

Giocatori::Giocatori(QWidget *parent){
    tt = new QVBoxLayout(this);
    layoutgiocatori = new QVBoxLayout();
    layoutpulsanti = new QHBoxLayout();
    scroll = new QScrollArea();
    container_scroll = new QWidget();

    container_scroll->setLayout(layoutgiocatori);
    scroll->setWidget(container_scroll);
    scroll->setWidgetResizable(true);
    tt->addWidget(scroll);
    
    aggiungi = new QPushButton("+", this);
    togli = new QPushButton("-", this);
    fatto = new QPushButton("Avanti", this);

    QLineEdit* nomepersona = new QLineEdit();
    nomepersona->setPlaceholderText("Nome");

    layoutgiocatori->addWidget(nomepersona);
    layoutpulsanti->addWidget(togli, 1);
    layoutpulsanti->addWidget(aggiungi,1);
    layoutpulsanti->addWidget(fatto,2);

    le_giocatori.append(nomepersona);

    //tt->addLayout(layoutgiocatori);
    tt->addLayout(layoutpulsanti);
    scroll->setFrameShape(QFrame::NoFrame);


    connect(aggiungi, &QPushButton::clicked, this, [this]() { 
        QLineEdit* np = new QLineEdit();
        np->setPlaceholderText("Nome");
        layoutgiocatori->addWidget(np);
        le_giocatori.append(np);
        tt->invalidate();
        tt->activate();
    });

    connect(togli, &QPushButton::clicked, this, [this]() { 
        if(le_giocatori.size()>1){
            QLineEdit* todelete = le_giocatori[le_giocatori.size()-1];
            layoutgiocatori->removeWidget(todelete);
            delete todelete;
            le_giocatori.pop_back();
        }
    });

    connect(fatto, &QPushButton::clicked, this, [this]() { 
        for(QLineEdit* edit : le_giocatori){
            giocatori.append(edit->text());
        }
        emit passa_a_parola(); });
}