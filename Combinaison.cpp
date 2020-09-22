#include "Combinaison.h"

Combinaison::Combinaison() {
	for (int i = 0; i < Combinaison::NB_PINOUCHES; i++) {
		entre[i].color = "";
		entre[i].position = i;
		entre[i].validation = aucun;
	}
}

Combinaison::~Combinaison() {

}