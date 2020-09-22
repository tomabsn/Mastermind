#ifndef COMBINAISON_H
#define COMBINAISON_H
#include "Pinouche.h"

class Combinaison {
public :
	long int const static NB_PINOUCHES = 4;
    Case entre[NB_PINOUCHES];
    Combinaison();
    ~Combinaison();
};


inline bool operator>>(istream& is, Combinaison &c) {
    

    int Postab = 0;
    Case joint;
    Place p = aucun;
    string phrase;
    int i;
    string reponse;
    getline(cin, phrase);
    phrase.append(" ");
    do {

        i = phrase.find(" ", 0);
        reponse.replace(0, reponse.size(), &(phrase.at(i)));
        reponse.erase(0, 1);
        phrase.erase(i);

        //cout << phrase << endl;

        c.entre[Postab].color = phrase;
        c.entre[Postab].position = Postab;
        c.entre[Postab].validation = p;


        phrase = reponse;
        Postab++;
    } while (reponse.size() > 1);

    return Combinaison::NB_PINOUCHES == Postab;
}

#endif