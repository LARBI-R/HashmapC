/* java Hashmap equivalent code
* $Id: Hashmap.h, 2021/02/22 16:37:30  $
* Written by LARBI Rochedi <rochedi.larbi@gmail.com>
*
*/

#ifndef _HASHMAP_H
#define _HASHMAP_H

typedef struct MaList MaList;
typedef struct ControList ControList;

struct MaList {
    int val;
    char cle;
    MaList * suivant;
};

struct ControList
{
    MaList * premier;
};

ControList * PointerListinit(void);
void Hashmap_addE(ControList *controList, int val, char cle);
int Hashmap_getElement(ControList *controList, char cle);
void Hashmap_clearLastE(ControList *controList);
void Hashmap_deleteE(ControList *controList, char cle);


#endif