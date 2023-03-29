#pragma once
#include "../domain/oferta.h"
#include "../repository/repo_oferte.h"

Lista_oferte Creeaza_Lista_Vida_business();
// perconditii:
// postconditii:

int Adauga_oferta_business(Lista_oferte* List, TElem el);

void Afiseaza(Lista_oferte);

int Verifica_nr_oferta(Lista_oferte* List, int nr_oferta_de_modificat);

int Modifica_oferta_business(Lista_oferte* L, int ord, TElem A);

void Sterge_oferta_business(Lista_oferte*  List, int nr_ofertei);

Lista_oferte Sorteaza_lista_cresc_dupa_pret(Lista_oferte List);

Lista_oferte Filtreaza(Lista_oferte List, char* destinatie);

bool compare(const oferta* A, const oferta* B);

Lista_oferte Sortare_generica(Lista_oferte List, bool compara(const oferta*, const oferta*));

void Teste_Creeaza_Lista_vida();

void Teste_Adauga();

void Teste_Sterge();

void Teste_Modifica();

void Teste_Verifica_nr_oferta();

void Teste_Filtreaza();

void Teste_Service();