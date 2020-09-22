#ifndef PINOUCHE_H
#define PINOUCHE_H
#include <iostream>
#include <string>
using namespace std;

enum couleur {
	BLEU,BLANC,NOIR,VERT,ROUGE,JAUNE
};

enum Place {
	bp,mp, aucun
};

struct Case{
	string color = "";
	long int position = 0;
	Place validation = aucun;
};

class Pinouche {
public:
	string static couleurs_possibles();
};

#endif