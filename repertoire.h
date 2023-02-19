#pragma once

#include "type_def.h"

using namespace std;

extern st_element_liste *add_person_to_linked_list(st_element_liste *head);
extern int display_persons_from_linked_list(st_element_liste *head);
extern int find_person_from_linked_list(st_element_liste *head, st_personne *person_to_find);
extern void fill_tab_of_persons(st_personne **tab, int nb_elem);
extern void print_tab_of_persons(st_personne **tab, int nb_elem);
extern int find_persons_from_tab(st_personne **tab, int nb_elem, st_personne *pers_to_find);
extern int remove_persons_from_tab(st_personne ***tab, int nb_elem, st_personne *pers_to_remove);