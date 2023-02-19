/*
*  repertoire
*   permet de gérer les elements d'une liste de personnes
*/

#include <iostream>

#include "repertoire.h"
#include "utilitaire_generation.h"
#include "type_def.h"
#include "string.h"

/**
 * Permet de créer une personne et d'ajouter cette derniere dans la liste chainées
 * Retourne la tête de liste
*/
st_element_liste *add_person_to_linked_list(st_element_liste *head)
{
    st_element_liste *current = nullptr;
    st_element_liste *new_elem = creer_element_liste(); //Crée l'element et sa personne

    //Si la liste est completement vide [0]
    if (head == nullptr)
        return new_elem;

    //Dans le cas ou on se place avant le premier element [1]
    if (comparer_personnes(new_elem->personne, head->personne))
    {
        new_elem->next = head;
        head->prev = new_elem;
        return new_elem;
    }

    current = head;
    while (current->next != nullptr)
    {
        //Si la personne doit être avant
        if (comparer_personnes(new_elem->personne, current->personne))
        {
            //Configuration des pointeurs du bloc - 1
            current->prev->next = new_elem;
            new_elem->prev = current->prev;

            //Configuration des pointeurs du bloc courrant
            new_elem->next = current;
            current->prev = new_elem;

            return head;
        }
        else
            current = current->next;
    }
    //On est sur le dernier element
    if (comparer_personnes(new_elem->personne, current->personne))
    {
        //Il se place avant
        current->prev->next = new_elem;
        new_elem->prev = current->prev;
        current->prev = new_elem;
        new_elem->next = current;
    }
    else
    {
        //Il se place apres
        current->next = new_elem;
        new_elem->prev = current;
    }

    return head;
}

/**
 * Permet d'afficher toutes les personnes d'une liste chainées
 * retourne -1 si la liste est vide
*/
int display_persons_from_linked_list(st_element_liste *head)
{
    st_element_liste *current = nullptr;

    //Si la liste est vide
    if (head == nullptr)
        return -1;

    current = head;
    while (current->next != nullptr)
    {
        affichage_personne(current->personne);
        current = current->next;
    }
    //On print le dernier element
    affichage_personne(current->personne);

    return 0;
}

/**
 * Permet dde rechercher une personne dans la liste chainée
 * retourne l'indice de la personne recherchée, -1 si elle n'existe pas
*/
int find_person_from_linked_list(st_element_liste *head, st_personne *person_to_find)
{
    st_element_liste *current = head;
    int indice = 0;

    while (current != nullptr)
    {
        if (egalitee_personne(person_to_find, current->personne))
            return indice;
        indice++;
        current = current->next;
    }

    return -1;
}

/**
 * Permet dde rechercher une personne dans la liste chainée
 * retourne l'indice de la personne recherchée, -1 si elle n'existe pas
*/
st_element_liste *remove_person_from_linked_list(st_element_liste *head, st_personne *person_to_remove)
{
    st_element_liste *current = head;

    //Si la liste est completement vide
    if (head == nullptr)
        return nullptr;

    //si le premier element est l'element à supprimer
    if (egalitee_personne(head->personne, person_to_remove))
    {
        current = head->next;
        current->prev = nullptr;
        delete head->personne;
        delete head;

        return current;
    }

    current = head->next;
    while (current->next != nullptr)
    {
        if (egalitee_personne(current->personne, person_to_remove))
        {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current->personne;
            delete current;

            return head;
        }
        else
            current = current->next;
    }

    //On est sur le dernier element
    if (egalitee_personne(current->personne, person_to_remove))
    {
        current->prev->next = nullptr;
        delete current->personne;
        delete current;
    }

    return head;
}

/**
 * Permet de remplir un tableau de personne
*/
void fill_tab_of_persons(st_personne **tab, int nb_elem)
{
    for (int i = 0; i < nb_elem; i++)
        tab[i] = generer_personne();
}

/**
 * Permet d'afficher un tablea ude personne
*/
void print_tab_of_persons(st_personne **tab, int nb_elem)
{
    for (int i = 0; i < nb_elem; i++)
        affichage_personne(tab[i]);
}

/**
 * Permet de chercher une personne dans un tableau de personne
 * Retourne l'index si la personne existe, sinon -1
*/
int find_persons_from_tab(st_personne **tab, int nb_elem, st_personne *pers_to_find)
{
    for (int i = 0; i < nb_elem; i++)
    {
        if (egalitee_personne(tab[i], pers_to_find))
            return i;
    }

    return -1;
}

/**
 * Permet de supprimer un reperoire d'un tableau
 * Retourne la nouvelle taille du tableau
*/
int remove_persons_from_tab(st_personne ***tab, int nb_elem, st_personne *pers_to_remove)
{
    int index = 0;
    st_personne **new_array;

    if (find_persons_from_tab(*tab, nb_elem, pers_to_remove) < 0)
        return nb_elem;

    new_array = new st_personne *[nb_elem - 1];

    for (int i = 0; i < nb_elem; i++)
    {
        if (!egalitee_personne((*tab)[i], pers_to_remove))
        {
            new_array[index] = (*tab)[i];
            index++;
        }
        else
            delete (*tab)[i];
    }
    delete *tab;
    *tab = new_array;

    return nb_elem - 1;
}