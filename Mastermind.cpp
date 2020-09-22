#include "Mastermind.h"
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>    


Mastermind::Mastermind() {
	int couleur;
	Case joint;
	gagne = false;
	tentative = 0;
	Place p = aucun;
	srand(time(NULL));
	for (int i = 0; i < Combinaison::NB_PINOUCHES; i++) {

		couleur = rand() % 6;
		switch (couleur) {
		case 0:
			joint.color = "Bleu";
			break;
		case 1:
			joint.color = "Blanc";
			break;
		case 2:
			joint.color = "Noir";
			break;
		case 3:
			joint.color = "Vert";
			break;
		case 4:
			joint.color = "Rouge";
			break;
		case 5:
			joint.color = "Jaune";
			break;
		}
		joint.position = i;
		joint.validation = p;

		TabRes[i] = joint;
	}
}

string Mastermind::essayer(Combinaison &c) {
	int BienPlace = 0;
	int MalPlace = 0;
	int i;
	/*for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (c.entre[j].color == this->TabRes[i].color && this->TabRes[i].validation != Place::bp && c.entre[j].validation != Place::bp) {
				if (i == j) {
					c.entre[j].validation = Place::bp;
					this->TabRes[j].validation = Place::bp;
					BienPlace++;
				}
				else if (i != j) {
					c.entre[j].validation = Place::mp;
					this->TabRes[j].validation = Place::mp;
					MalPlace++;
				}
			}
		}
		
	}*/

	//on rgarde d'abord ceux qui sont bien placé 
	for (i = 0; i < Combinaison::NB_PINOUCHES; i++) {
		if (c.entre[i].color == this->TabRes[i].color) {
			c.entre[i].validation = bp;
			this->TabRes[i].validation = bp;
			BienPlace++;
		}
	}

	int j;
	for (i = 0; i < Combinaison::NB_PINOUCHES; i++) {
		for (j = 0; j < Combinaison::NB_PINOUCHES; j++) {
			if (c.entre[j].validation == aucun && this->TabRes[i].validation==aucun && c.entre[j].color==this->TabRes[i].color) {
				MalPlace++;
				c.entre[j].validation = mp;
				this->TabRes[i].validation = mp;
			}
		}
	}

	for (i = 0; i < Combinaison::NB_PINOUCHES; i++) {
		c.entre[i].validation = aucun;
		this->TabRes[i].validation = aucun;
	}


	string nbrBP = " pinouche(s) bien placée(s) et \n";
	string nbrMP = " pinouche(s) mal placée(s) mais bonne couleur";
	
	nbrBP.insert(0,to_string(BienPlace));
	nbrMP.insert(0,to_string(MalPlace));
	nbrMP.insert(0, nbrBP);
	tentative++;
	nombredeplace = BienPlace;


	return nbrMP;
}

bool Mastermind::est_reussi(Combinaison &c) {
	
	gagne = nombredeplace == Combinaison::NB_PINOUCHES;
	nombredeplace = 0;
	return gagne;
}

bool Mastermind::partie_perdue() {
	gagne = MAX_ESSAIS_SUCCES == tentative;
	return gagne;
}

Mastermind::~Mastermind() {

}