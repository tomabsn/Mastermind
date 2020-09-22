#include <iostream>
#include <locale>
#include "Mastermind.h"
using namespace std;

namespace decoration {
    ostream& mot_de_bienvenue(ostream& os) {
        return os << "Bienvenue a cette chic seance de Mastermind\n"
            << "But: trouver la position et la couleur de "
            << Combinaison::NB_PINOUCHES //accès à un attribut statique !
            << " pinouches en "
            << Mastermind::MAX_ESSAIS_SUCCES
            << " essais maximum"
            << endl;
    }
    ostream& lister_options(ostream& os) {
        return os << "Les couleurs possibles sont:\n\t" << Pinouche::couleurs_possibles(); //accès à une méthode statique !
    }
    ostream& invite(ostream& os) {
        return os << "Entrez une combinaison ("
            << Combinaison::NB_PINOUCHES
            << " couleurs separees par des blancs):"
            << "\n\t";
    }
    ostream& erreur_entree(ostream& os) {
        return os << "Combinaison erronnee.";
    }
    Combinaison lire_combinaison(istream& is, ostream& os) {
        os << lister_options << '\n' << invite;
        Combinaison c;
        while (!(is >> c)) //surcharge d'opérateur
            os << erreur_entree << invite;
        return c;
    }
}

int main() {
    using namespace decoration;
    locale::global(locale{ "" });
    mot_de_bienvenue(cout);
    Mastermind mm;
    Combinaison c = lire_combinaison(cin, cout);
    cout << mm.essayer(c) << endl << endl;
    while (!mm.est_reussi(c) && !mm.partie_perdue()) {
        c = lire_combinaison(cin, cout);
        cout << mm.essayer(c) << endl << endl;
    }
    cout << mm << endl;
    cout << "Merci d'avoir joué ! " << endl;
} 