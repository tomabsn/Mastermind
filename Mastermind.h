#ifndef MASTERMIND_H
#define MASTERMIND_H
#include "Combinaison.h"
#include "Pinouche.h"


class Mastermind {
public:
	int const static MAX_ESSAIS_SUCCES = 8;
	int tentative;
	int nombredeplace;
	bool gagne;
	Case TabRes[Combinaison::NB_PINOUCHES];
	Mastermind();
	~Mastermind();
	string essayer(Combinaison &c);
	bool est_reussi(Combinaison &c);
	bool partie_perdue();
};


inline ostream& operator<< (ostream& os, Mastermind &m) {
	string resultP = "Félicitation !vous avez réussi en ";
	string resultN = "Aie vous avez perdu... ";
	string fin = " coup(s) !";
	fin.insert(0, to_string(m.tentative));
	if (m.gagne) {
		fin.insert(0, resultP);
	}
	else {
		fin.insert(0, resultN);
	}
	
	os << fin;

	return os;
}

#endif // !MASTERMIND_H

