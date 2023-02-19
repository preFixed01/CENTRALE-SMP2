/*
 * ASSE Romain FERRE Cedric
 * TP4
 *
 * Listes chainees
 *
 */
#include <iostream>
#include "utilitaire_generation.h"
#include "repertoire.h"
#include "time.h"

using namespace std;

int main()
{
    cout << "Test de la génération et affichage d'une personne..." << endl;
    st_personne *p_affi = generer_personne();
    affichage_personne(p_affi);
    delete (p_affi);

    cout << "Test de l'égalité entre deux personnes..." << endl;
    st_personne *p1 = generer_personne();
    st_personne *p2 = generer_personne();
    cout << " Egalitee entre P1 et P2 : " << egalitee_personne(p1, p2) << endl;
    cout << " Egalitee entre P1 et P1 : " << egalitee_personne(p1, p1) << endl;

    cout << "Test de la comparaison entre deux personnes..." << endl;
    st_personne *p3 = generer_personne();
    st_personne *p4 = generer_personne();
    p3->nom = p1->nom;
    p4->nom = p1->nom;
    p4->prenom = p1->prenom;
    cout << " Comparaison entre deux personnes différentes (P1 et P2), P1: " << p1->nom << " et P2: " << p2->nom << " résultat: " << comparer_personnes(p1, p2) << endl;
    cout << " Comparaison entre deux personnes aux noms identique (p1.nom: " << p1->nom << " et p3.nom: " << p3->nom
         << " prénom différent (p1.prenom: " << p1->prenom << " et p3.prenom: " << p3->prenom << " résultat: "
         << comparer_personnes(p1, p3) << endl;

    cout << " Comparaison entre deux personnes aux noms identique (p1.nom: " << p1->nom << " et p4.nom: " << p4->nom
         << " prénom identiques (p1.prenom: " << p1->prenom << " et p4.prenom: " << p4->prenom << " et numéros différents (p1.numero: "
         << p1->numero << " et p4.numero: " << p4->numero << " résultat: " << comparer_personnes(p1, p4) << endl;

     delete (p1);
     delete (p2);
     delete (p3);
     delete (p4);

    cout << "Test de la construction et de l'affichage d'une liste chainée..." << endl;
    st_element_liste *head = nullptr;

    for (volatile int i = 0; i < 10; i++)
        head = add_person_to_linked_list(head);

    display_persons_from_linked_list(head);

    cout << "Test de la recherche de personne dans une liste chainée..." << endl;
    st_personne *pers = generer_personne();

    cout << "Recherde de la personne en tête de liste, index attendu 0, résultat:" <<  find_person_from_linked_list(head, head->personne) << endl;
    cout << "Recherde de la personne dans le 5eme element de la liste, index attendu 4, résultat:" <<  find_person_from_linked_list(head, head->next->next->next->next->personne) << endl;
    cout << "Recherde d'une personne inexistante dans la liste, index attendu -1, résultat:" <<  find_person_from_linked_list(head, pers) << endl;
    delete (pers);

    cout << "Test de la suppression de personne dans une liste chainée..." << endl;
    st_personne *pers_to_remove = generer_personne();

    cout << "Suppression de 3 personne: " << head->next->next->next->personne->nom << " " << head->personne->nom << " et " << pers_to_remove->nom << endl;
    head = remove_person_from_linked_list(head, head->next->next->next->personne);
    head = remove_person_from_linked_list(head, head->personne);
    head = remove_person_from_linked_list(head, pers_to_remove);
    display_persons_from_linked_list(head);
    delete (pers_to_remove);

    cout << "Test de la création et de l'affichage d'un tableau de personnes" << endl;
    int nb_elems = 5;
    st_personne **array_persons = new st_personne *[nb_elems];
    fill_tab_of_persons(array_persons, nb_elems);
    print_tab_of_persons(array_persons, nb_elems);

    cout << "Test de la recherche de personnes dans un tableau" << endl;
    st_personne *pers_to_find = generer_personne();
    cout << "Test de la recherche d'une personne (résultat attendu 3), résultat: "
         << find_persons_from_tab(array_persons, nb_elems, array_persons[3]) << endl;
    cout << "Test de la recherche d'une personne (résultat attendu -1), résultat: "
         << find_persons_from_tab(array_persons, nb_elems, pers_to_find) << endl;

     nb_elems = remove_persons_from_tab(&array_persons, nb_elems, array_persons[2]);
     print_tab_of_persons(array_persons, nb_elems);

     clock_t t_create_linked, t_create_tab, t_print_linked, t_print_tab, t_find_on_ll, t_find_on_tab, t_sup_ll, t_sup_tab;
     st_element_liste *h = nullptr;

     //Création de 1000 repertoire dans une LL
     t_create_linked = clock();
     for (volatile int i = 0; i < 1000; i++)
          h = add_person_to_linked_list(h);
     t_create_linked = clock() - t_create_linked;

     //Création de 1000 repertoire dans un tableau
     nb_elems = 1000;
     t_create_tab = clock();
     st_personne **my_array = new st_personne *[nb_elems];
     fill_tab_of_persons(my_array, nb_elems);
     t_create_tab = clock() - t_create_tab;

     //Affichage de 1000 repertoire dans une LL
     t_print_linked = clock();
     display_persons_from_linked_list(h);
     t_print_linked = clock() - t_print_linked;

     //Affichage de 1000 repertoire dans un tableau
     t_print_tab = clock();
     print_tab_of_persons(my_array, nb_elems);
     t_print_tab = clock() - t_print_tab;

     //recherche de 100 personne dans une LL
     t_find_on_ll = clock();
     for (volatile int i = 0; i < 100; i++)
          find_person_from_linked_list(h, generer_personne());
     t_find_on_ll = clock() - t_find_on_ll;

     //Recherche de 100 personnes dans un tableau
     t_find_on_tab = clock();
     for (volatile int i = 0; i < 100; i++)
          find_persons_from_tab(my_array, nb_elems, generer_personne());
     t_find_on_tab = clock() - t_find_on_tab;

     //Suppression de 100 personnes dans une table
     t_sup_tab = clock();
     for (volatile int i = 0; i < 100; i++)
          nb_elems = remove_persons_from_tab(&my_array, nb_elems, my_array[1]);
     t_sup_tab = clock() - t_sup_tab;

     //Suppression de 100 personnes dans une LL
     t_sup_ll = clock();
     for (volatile int i = 0; i < 100; i++)
          h = remove_person_from_linked_list(h, h->personne);
     t_sup_ll = clock() - t_sup_ll;

     cout << "Création de 1000 repertoire dans LL: " << ((float)t_create_linked / CLOCKS_PER_SEC) << " s"<< endl;
     cout << "Création de 1000 repertoire dans tab: " << ((float)t_create_tab / CLOCKS_PER_SEC) << " s"<< endl;
     cout << "Affichage de 1000 repertoire dans LL: " << ((float)t_print_linked / CLOCKS_PER_SEC) << " s"<< endl;
     cout << "Affichage de 1000 repertoire dans tab: " << ((float)t_print_tab / CLOCKS_PER_SEC) << " s"<< endl;
     cout << "Recherche de 100 personnes dans LL: " << ((float)t_find_on_ll / CLOCKS_PER_SEC) << " s"<< endl;
     cout << "Recherche de 100 personnes dans tab: " << ((float)t_find_on_tab / CLOCKS_PER_SEC) << " s"<< endl;
     cout << "Suppression 100 personnes dans tab: " << ((float)t_sup_tab / CLOCKS_PER_SEC) << " s"<< endl;
     cout << "Suppression 100 personnes dans LL: " << ((float)t_sup_ll / CLOCKS_PER_SEC) << " s"<< endl;

    return 0;
}