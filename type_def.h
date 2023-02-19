/*
 * ASSE Romain FERRE Cedric
 * TP4
 *
 * Listes chainees
 *
 */
#pragma once

#include <iostream>
#include <string>

using namespace std;

typedef struct st_element_liste st_element_liste;
typedef struct st_personne st_personne;

struct st_personne
{
    string prenom ;
    string nom;
    string numero;
};

struct st_element_liste
{
    st_personne *personne;
    st_element_liste *prev;
    st_element_liste *next;

};


