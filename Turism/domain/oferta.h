#include <stdbool.h>
#pragma once

struct oferta{
    char* tip;
    char* destinatie;
    char* data_plecare;
    float pret;
};

typedef struct oferta oferta;

oferta Creeaza_oferta(char *tip, char* destinatie, char* data_plecare, float pret);

void Distruge_oferta(oferta* of);

oferta Copiazaoferta(oferta* of);

void Modifica_oferta(oferta *of, oferta B);

bool oferte_egale(oferta A, oferta B);

void Test_Creaza();

void Teste_Domain();