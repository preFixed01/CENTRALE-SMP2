#pragma once
#include <string>
#include "type_def.h"

using namespace std;

std::string genererNomPrenom(std::string list, int nb);
std::string genererTel();

extern void affichage_personne(st_personne *pers);
extern st_personne *generer_personne();
extern st_element_liste *creer_element_liste();
extern bool egalitee_personne(st_personne *pers1, st_personne *pers2);
extern bool comparer_personnes(st_personne *pers1, st_personne *pers2);
extern st_element_liste *remove_person_from_linked_list(st_element_liste *head, st_personne *person_to_remove);