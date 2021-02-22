#include <stdlib.h>
#include <stdio.h>
#include "Hashmap.h"

ControList * PointerListinit()
{
    MaList * maList =(MaList *) malloc(sizeof(MaList *));
    ControList *controList = (ControList *) malloc(sizeof(ControList));

    if (maList == NULL || controList == NULL)
    {
        exit(EXIT_FAILURE);
    }

    maList->cle = 0;
    maList->val = 0;
    maList->suivant = NULL;
    
    controList->premier = maList;

    return controList;
}

void Hashmap_addE(ControList *controList, int val, char cle)
{
    MaList *nouveau = malloc(sizeof(MaList));
    
    if ( controList == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    nouveau->val = val;
    nouveau->cle = cle;
    
    nouveau->suivant = controList->premier;
    controList->premier = nouveau;

}

/*
return -1 if element doesnt exist
*/
int Hashmap_getElement(ControList *controList, char cle)
{
    int var = 0, element = -1;
    if (controList == NULL)
    {
        exit(EXIT_FAILURE);
    }
    MaList *actuel = controList->premier;

    while (actuel != NULL)
    {
        if (actuel->cle == cle)
        {
            var = 1;
            element = actuel->val;
        }
        actuel = actuel->suivant;
    }
    if (var == 0)
    {
       printf("element doesnt exist !! element return = -1 \n");
    }

    return element;
}

void Hashmap_clearLastE(ControList *controList)
{
   
    if (controList == NULL)
    {
        exit(EXIT_FAILURE);
    }

    if (controList->premier != NULL)
    {
        MaList *aSupprimer = controList->premier;
        controList->premier = controList->premier->suivant;
        free(aSupprimer); 
    }  
    
}

void Hashmap_deleteE(ControList *controList, char cle)
{
    int var = 0;

    MaList * aSupprimer;

    if (controList == NULL)
    {
        exit(EXIT_FAILURE);
    }

    MaList *actuel = controList->premier;

    while (actuel != NULL)
    {
        if (actuel->cle == cle)
        {
            var = 1;
            aSupprimer = actuel;
        }
        actuel = actuel->suivant;
    }
    if (var == 1)
    {
       free(aSupprimer);
    }

}