#include "mainwindow.hpp"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    //QWidget* centralWidget = new QWidget(this);
    //setCentralWidget(centralWidget);
    //setStyleSheet("background-color: #323232;");

    QWidget* centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    setWindowTitle("Gioco");
    QVBoxLayout* lp = new QVBoxLayout(centralWidget);

    stack = new QStackedWidget(this);
    players = new Giocatori();
    word = new Parola();
    pass = new Passa("a");
    thing = new Cosa("a","b");
    stack->addWidget(players);
    stack->addWidget(word);
    stack->addWidget(pass);
    stack->addWidget(thing);

    lp->addWidget(stack);

    posizione = 0;

    stack->setCurrentWidget(players);


    connect(players, &Giocatori::passa_a_parola, this, [this](){
        stack->setCurrentWidget(word);
    });

    connect(word, &Parola::passa_a_assegna, this, [this](){
        QVector<QString>& p = this->players->giocatori;
        QString impostori = this->word->numero_impostori->text();
        int imp = impostori.toInt();
        for(int i=0; i<p.size();i++){
            QString tmp = p[i];
            int t = QRandomGenerator::global()->bounded(0, p.size());
            p[i] = p[t];
            p[t] = tmp;
        }//fare il pulsante -
        int tm = imp;
        for(int i=0;i<tm;i++){
            if(p[i].contains("#")){
                tm++;
            }else{
                p[i]=p[i] + "[]";
            }
        }

        for(int i=0; i<p.size();i++){
            QString tmp = p[i];
            int t = QRandomGenerator::global()->bounded(0, p.size());
            p[i] = p[t];
            p[t] = tmp;
        }

        pass->setPropertiesDC(p[posizione]);
        //posizione++;
        stack->setCurrentWidget(pass);

        if(word->spunta->isChecked()){
            word->parolascelta->setText(parolaCasuale());
        }
    });

    connect(pass, &Passa::passa_a_nuovo, this, [this](){
        thing->setPropertiesDC(players->giocatori[posizione], word->parolascelta->text());
        posizione++;
        stack->setCurrentWidget(thing);
        if(posizione == this->players->giocatori.size()){
            this->thing->pfine->show();
            this->thing->ok->hide();
        }
    });

    connect(thing, &Cosa::passa_a_passa, this, [this](){
        pass->setPropertiesDC(players->giocatori[posizione]);
        stack->setCurrentWidget(pass);
    });

    connect(thing, &Cosa::fine, this, [this](){
        
        this->players->giocatori.clear();
        posizione = 0;
        stack->setCurrentWidget(players);
        this->thing->pfine->hide();
        this->thing->ok->show();
    });
}

QString MainWindow::parolaCasuale()
{
    // Apri il file (se usi risorse usa ":/lista_categorie.json")
    QFile file("lista_categorie.json");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Impossibile aprire il file JSON";
        return {};
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonParseError err;
    QJsonDocument doc = QJsonDocument::fromJson(data, &err);
    if (err.error != QJsonParseError::NoError) {
        qWarning() << "Errore parsing JSON:" << err.errorString();
        return {};
    }

    QJsonObject root = doc.object();

    // Metti tutti gli elementi di tutte le categorie in una sola lista
    QStringList tutteLeParole;
    for (auto it = root.begin(); it != root.end(); ++it) {
        QJsonArray arr = it.value().toArray();
        for (const QJsonValue &v : arr) {
            tutteLeParole.append(v.toString());
        }
    }

    if (tutteLeParole.isEmpty()) {
        qWarning() << "Nessuna parola trovata";
        return {};
    }

    // Scegli indice casuale
    int index = QRandomGenerator::global()->bounded(tutteLeParole.size());
    return tutteLeParole.at(index);
}