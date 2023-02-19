/*
*  utilitaire generation
*   fichiers utilitaires pour generer, noms, prenoms et n° de tel.
*/

#define _POSIX_TIMERS

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

#include "type_def.h"

using namespace std;

string genererNomPrenom(string list, int nb)
{
    string inputString[nb];
    fstream input;

    //initialisation de la graine de srand au temps courant à la nanoseconde
    struct timespec spec;
    clock_gettime(CLOCK_REALTIME, &spec);
    srand(spec.tv_nsec);

    input.open(list.c_str(), ios::in);
    for(int i=0; i<nb; i++){
        input>>inputString[i];
    }
    input.close();
    return inputString[rand()%nb];
}

string genererTel()
{
    //initialisation de la graine de srand au temps courant a la nanoseconde
    struct timespec spec;
    clock_gettime(CLOCK_REALTIME, &spec);
    srand(spec.tv_nsec);

    string num = "0"+to_string(rand()%7+1);
    for(int i =0;i<8;i++){
        num = num+to_string(rand()%10);
    }
    return num;
}

/**
 * Permet de generer une nouvelle personne
 * retourne la personne
*/
st_personne *generer_personne()
{
    st_personne *n_personne = new (st_personne);

    n_personne->nom = genererNomPrenom("Noms_TP4.txt", 1000);
    n_personne->prenom = genererNomPrenom("Prenoms_TP4.txt", 11612);
    n_personne->numero = genererTel();

    return n_personne;
}

/**
 * Permet de creer un nouvel element dans une liste
 * retourne la valeur du nouvel element dans la liste
*/
st_element_liste *creer_element_liste()
{
    st_element_liste *n_element = new st_element_liste;

    n_element->prev = nullptr;
    n_element->next = nullptr;
    n_element->personne = generer_personne();

    return n_element;
}

/**
 * Permet d'afficher les coordonnees d'une personne
*/
void affichage_personne(st_personne *pers)
{
    cout << "Nom : " << pers->nom << endl;
    cout << "Prenom : " << pers->prenom << endl;
    cout << "Tel : " << pers->numero << endl;
}

/**
 * Permet de tester si les champs de coordonnees de deux personnes sont égaux et non vides
 * Retourne true si les personnes sont les mêmes personnes
*/
bool egalitee_personne(st_personne *pers1, st_personne *pers2)
{
    if ((pers1 == nullptr) || (pers2 == nullptr))
        return false;

    if ((pers1->nom == pers2->nom) && (pers1->prenom == pers1->prenom) && (pers1->numero == pers2->numero))
        return true;

    return false;
}

/**
 * Permet de comparer deux personnes et de les departager par leurs coordonnees
 * Retourne un booleen, vrai si la premiere personne est avant l'autre
*/
bool comparer_personnes(st_personne *pers1, st_personne *pers2)
{
    if ((pers1 == nullptr) || (pers2 == nullptr))
        return false;

    if (egalitee_personne(pers1, pers2))
        return false;

    if (pers1->nom != pers2->nom)
    {
        int max_length = (pers1->nom.length() > pers2->nom.length()) ? pers1->nom.length() : pers2->nom.length();

        for (int i = 0; i < max_length; i++)
        {
            //cout << "nom1: "<< pers1->nom[i] << "nom2: " << pers2->nom[i] << endl;
            if (pers1->nom[i] < pers2->nom[i])
                return true;
            if (pers1->nom[i] > pers2->nom[i])
                return false;
        }
    }

    if (pers1->prenom != pers2->prenom)
    {
        int max_length = (pers1->prenom.length() > pers2->prenom.length()) ? pers1->prenom.length() : pers2->prenom.length();

        for (int i = 0; i < max_length; i++)
        {
            //cout << "prenom: "<< pers1->prenom[i] << "prenom2: " << pers2->prenom[i] << endl;
            if (pers1->prenom[i] < pers2->prenom[i])
                return true;
            if (pers1->prenom[i] > pers2->prenom[i])
                return false;
        }
    }

    if (pers1->numero != pers2->numero)
    {
        int max_length = (pers1->numero.length() > pers2->numero.length()) ? pers1->numero.length() : pers2->numero.length();

        for (int i = 0; i < max_length; i++)
        {
            //cout << "numero1: "<< pers1->numero[i] << "numero2: " << pers2->numero[i] << endl;
            if (pers1->numero[i] < pers2->numero[i])
                return true;
            if (pers1->numero[i] > pers2->numero[i])
                return false;
        }
    }

    return false;
}
