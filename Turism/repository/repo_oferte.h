#pragma once
#include "../domain/oferta.h"

typedef oferta TElem;

typedef struct{
    TElem* oferte;
    int lg;
    int cap;
}Lista_oferte;

Lista_oferte Creeaza_Lista_Vida();

void Distruge_Lista(Lista_oferte* L);

int size(Lista_oferte* L);

void Adauga(Lista_oferte* L, TElem el);

void Sterge_oferta(Lista_oferte* List, int nr_ofertei);

Lista_oferte CopieLista(Lista_oferte* L);

void TesteAdauga();

void TesteRepo();

void TesteSterge();



