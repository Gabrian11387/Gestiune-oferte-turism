#include "repo_oferte.h"
#include <malloc.h>
#include <assert.h>

Lista_oferte Creeaza_Lista_Vida()
{
    Lista_oferte Lista;
    Lista.cap = 2;
    Lista.oferte = (oferta*)malloc(Lista.cap * sizeof(oferta));
    Lista.lg = 0;
    return Lista;
}

void Distruge_Lista(Lista_oferte* L)
{
    for(int i = 0 ; i < L->lg; i ++)
        Distruge_oferta(&L->oferte[i]);
    free(L->oferte);
    L->oferte = NULL;
    L->lg = 0;
}

int size(Lista_oferte* L)
{
    return L->lg;
}

void AsiguraCapacitate(Lista_oferte* L)
{
    if(L->lg < L->cap)
        return; // e destul loc
    int nouaCap = L->cap + 5;
    oferta* noferte = malloc(nouaCap* sizeof(oferta));
    for(int i = 0; i < L->lg; i ++)
        noferte[i] = L->oferte[i];
    free(L->oferte);
    L->oferte = noferte;
    L->cap = nouaCap;
}

void Adauga(Lista_oferte* L, TElem el)
{
    AsiguraCapacitate(L);
    L->oferte[L->lg] = el;
    L->lg++;
}

void Sterge_oferta(Lista_oferte* List, int nr_ofertei)
{
    oferta A = List->oferte[nr_ofertei];
    Distruge_oferta(&A);
    for(int i = nr_ofertei; i < size(List) - 1; i ++)
        *(List->oferte + i) = *(List->oferte + i + 1);
    List->lg--;
}

Lista_oferte CopieLista(Lista_oferte* L)
{
    Lista_oferte Lcopie = Creeaza_Lista_Vida();
    for(int i = 0; i < L->lg; i ++)
        Adauga(&Lcopie, Copiazaoferta(&L->oferte[i]));
    return Lcopie;
}

void TesteAdauga()
{
    Lista_oferte L = Creeaza_Lista_Vida();
    TElem A = Creeaza_oferta("munte", "Everest", "02.10.2022", 500);
    assert(size(&L) == 0);
    Adauga(&L, A);
    assert(size(&L) == 1);
    Distruge_Lista(&L);
}

void TesteSterge()
{
    Lista_oferte L = Creeaza_Lista_Vida();
    TElem A = Creeaza_oferta("munte", "Everest", "02.10.2022", 500);
    TElem B = Creeaza_oferta("mare", "Ineu", "02.10.2022", 300);
    Adauga(&L, A);
    Adauga(&L, B);
    assert(size(&L) == 2);
    Sterge_oferta(&L, 0);
    assert(size(&L) == 1);
    Distruge_Lista(&L);
    assert(L.oferte == NULL);
    assert(L.lg == 0);
}

void TesteCopieLista()
{
    Lista_oferte L = Creeaza_Lista_Vida();
    TElem A = Creeaza_oferta("munte", "Everest", "02.10.2022", 500);
    Adauga(&L, A);
    Lista_oferte Lc = CopieLista(&L);
    assert(size(&Lc) == 1);
    Distruge_Lista(&L);
    Distruge_Lista(&Lc);
}

void TestAsiguraCapacitate()
{
    Lista_oferte L = Creeaza_Lista_Vida();
    TElem A = Creeaza_oferta("munte", "Everest", "02.10.2022", 500);
    Adauga(&L, A);
    TElem B = Creeaza_oferta("mare", "Ineu", "02.10.2022", 200);
    TElem C = Creeaza_oferta("munte", "Heniu", "02.10.2022", 100);
    Adauga(&L, B);
    assert(L.cap == 2);
    Adauga(&L, C);
    assert(L.cap == 7);
    Distruge_Lista(&L);
}

void TesteRepo()
{
    TesteAdauga();
    TesteSterge();
    TesteCopieLista();
    TestAsiguraCapacitate();
}
