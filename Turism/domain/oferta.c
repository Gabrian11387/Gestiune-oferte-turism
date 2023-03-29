#include "oferta.h"
#include <assert.h>
#include <string.h>
#include <stdbool.h>
#include <malloc.h>
#include <math.h>

oferta Creeaza_oferta(char* tip, char* destinatie, char* data_plecare, float pret)
{
    oferta A;
    A.tip = (char*) malloc(strlen(tip) + 1);
    for(int i = 0; i < strlen(tip)+1; i ++)
        A.tip[i] = tip[i];
    A.destinatie = (char*) malloc(strlen(destinatie) + 1);
    for(int i = 0; i < strlen(destinatie)+1; i ++)
        A.destinatie[i] = destinatie[i];
    A.data_plecare = (char*) malloc(strlen(data_plecare) + 1);
    for(int i = 0; i < strlen(data_plecare)+1; i ++)
        A.data_plecare[i] = data_plecare[i];
    A.pret = pret;
    return A;
}

void Distruge_oferta(oferta* of)
{
    free(of->tip);
    free(of->destinatie);
    free(of->data_plecare);
    of->tip = NULL;
    of->destinatie = NULL;
    of->data_plecare = NULL;
    of->pret = -1;
}

oferta Copiazaoferta(oferta* of)
{
    return Creeaza_oferta(of->tip, of->destinatie, of->data_plecare, of->pret);
}

void Modifica_oferta(oferta *of, oferta B)
{
    strcpy(of->tip, B.tip);
    strcpy(of->destinatie, B.destinatie);
    strcpy(of->data_plecare, B.data_plecare);
    of->pret = B.pret;
}

bool oferte_egale(oferta A, oferta B)
{
    if(strcmp(A.tip, B.tip) != 0)
        return false;
    if(strcmp(A.destinatie, B.destinatie) != 0)
        return false;
    if(strcmp(A.data_plecare, B.data_plecare) != 0)
        return false;
    double eps = 0.1;
    if(fabs((double)A.pret - (double)B.pret) > (double)eps)
        return false;
    return true;
}

void Test_Creaza()
{
    oferta A = Creeaza_oferta("munte", "Everest","09.10.2023", 400);
    assert(strcmp(A.tip, "munte") == 0);
    assert(strcmp(A.destinatie, "Everest") == 0);
    assert(strcmp(A.data_plecare, "09.10.2023") == 0);
    assert(A.pret == 400);
    Distruge_oferta(&A);
}

void Test_Modifica()
{
    oferta A = Creeaza_oferta("munte", "Everest","09.10.2023", 400);
    oferta B = Creeaza_oferta("mare", "Ineu", "01.09.2003", 500);
    Modifica_oferta(&A, B);
    assert(strcmp(A.tip, B.tip) == 0);
    assert(strcmp(A.destinatie, B.destinatie) == 0);
    assert(strcmp(A.data_plecare, B.data_plecare) == 0);
    assert(A.pret == B.pret);
    Distruge_oferta(&A);
    Distruge_oferta(&B);
}

void TestoferteEgale()
{
    oferta A = Creeaza_oferta("munte", "Everest","09.10.2023", 400);
    oferta B = Creeaza_oferta("mare", "Ineu", "01.09.2003", 500);
    assert(oferte_egale(A, B) == false);
    oferta C = Creeaza_oferta("munte", "Eve","09.10.2023", 400);
    assert(oferte_egale(A, C) == false);
    oferta D = Creeaza_oferta("munte", "Everest","09.10", 400);
    assert(oferte_egale(A, D) == false);
    oferta E = Creeaza_oferta("munte", "Everest","09.10.2023", 100);
    assert(oferte_egale(E, A) == false);
    oferta F = Creeaza_oferta("munte", "Everest","09.10.2023", 400);
    assert(oferte_egale(A, F) == true);
    Distruge_oferta(&A);
    Distruge_oferta(&B);
    Distruge_oferta(&C);
    Distruge_oferta(&D);
    Distruge_oferta(&E);
    Distruge_oferta(&F);
}

void Teste_Domain()
{
    Test_Creaza();
    Test_Modifica();
    TestoferteEgale();
}