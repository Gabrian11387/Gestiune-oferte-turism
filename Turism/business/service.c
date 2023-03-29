#include "../repository/repo_oferte.h"
#include "service.h"
#include "../validator/validator_oferte.h"
#include <string.h>
#include <assert.h>

int Adauga_oferta_business(Lista_oferte* List, TElem el)
{
    if(valid(el) == -1)
        return -1;
    Adauga(List, el);
    return 0; //totul e ok
}

Lista_oferte Creeaza_Lista_Vida_business()
{
    return Creeaza_Lista_Vida();
}

int Verifica_nr_oferta(Lista_oferte* List, int nr_oferta_de_modificat)
{
    if(nr_oferta_de_modificat > List->lg)
        return -1;
    return 0;
}

int Modifica_oferta_business(Lista_oferte* L, int ord, TElem A)
{
    if(valid(A) == -1)
        return -1;
    ord--;
    Distruge_oferta(L->oferte+ord);
    Sterge_oferta(L, ord);
    Adauga(L, A);
    return 0; // totul e ok
}

void Sterge_oferta_business(Lista_oferte* List, int nr_ofertei)
{
    Sterge_oferta(List, nr_ofertei);
}

Lista_oferte Sorteaza_lista_cresc_dupa_pret(Lista_oferte List)
{
    for(int i = 0; i < List.lg - 1; i ++)
        for(int j = i + 1; j < List.lg; j ++)
            if((List.oferte + i)->pret > (List.oferte + j)->pret) {
                TElem tmp;
                tmp = *(List.oferte + i);
                *(List.oferte + i) = *(List.oferte + j);
                *(List.oferte + j) = tmp;
            }
    return List;
}

Lista_oferte Filtreaza(Lista_oferte List, char* dest)
{
    for(int i = 0; i < List.lg; i ++)
        if(strcmp((List.oferte+i)->destinatie, dest) != 0)
        {
            Sterge_oferta_business(&List, i);
            i--;
        }
    return List;
}

int size_business(Lista_oferte L)
{
    return size(&L);
}

bool compare(const oferta* A, const oferta* B)
{
    return (A->pret < B->pret);
}

Lista_oferte Sortare_generica(Lista_oferte List, bool compara(const oferta*, const oferta*))
{
    for(int i = 0; i < List.lg - 1; i ++)
        for(int j = i + 1; j < List.lg; j ++)
            if(compara(List.oferte + i, (List.oferte + j)) == false) {
                TElem tmp;
                tmp = *(List.oferte + i);
                *(List.oferte + i) = *(List.oferte + j);
                *(List.oferte + j) = tmp;
            }
    return List;
}

void Teste_Creeaza_Lista_vida()
{
    Lista_oferte L = Creeaza_Lista_Vida_business();
    assert(size_business(L) == 0);
    Distruge_Lista(&L);
}

void Teste_Adauga()
{
    Lista_oferte L = Creeaza_Lista_Vida_business();
    assert(size_business(L) == 0);
    TElem A = Creeaza_oferta("mare","Everest","22.07.2023",600);
    Adauga_oferta_business(&L, A);
    assert(size_business(L) == 1);
    TElem oferta_invalida = Creeaza_oferta("acasa","Everest","22.07.2023",600);
    assert(Adauga_oferta_business(&L, oferta_invalida) == -1);
    Distruge_oferta(&oferta_invalida);
    Distruge_Lista(&L);
}

void Teste_Sterge()
{
    Lista_oferte L = Creeaza_Lista_Vida_business();
    TElem A = Creeaza_oferta("mare","Everest","22.07.2023",600);
    Adauga_oferta_business(&L, A);
    Sterge_oferta_business(&L, 0);
    assert(size_business(L) == 0);
    Distruge_Lista(&L);
}

void Teste_Modifica()
{
    Lista_oferte L = Creeaza_Lista_Vida_business();
    TElem A = Creeaza_oferta("mare","Everest","22.07.2023",600);
    TElem B = Creeaza_oferta("munte", "Ineu","20.03.2023",400);
    Adauga_oferta_business(&L, A);
    //o sa modific oferta A cu valorile stocate de oferta B
    Modifica_oferta_business(&L, 1, B);
    assert(strcmp(L.oferte->tip, B.tip) == 0);
    assert(strcmp(L.oferte->destinatie, B.destinatie) == 0);
    assert(strcmp(L.oferte->data_plecare, B.data_plecare) == 0);
    assert(L.oferte->pret == B.pret);
    TElem oferta_invalida = Creeaza_oferta("acasa","Everest","22.07.2023",600);
    assert(Modifica_oferta_business(&L, 1, oferta_invalida) == -1);
    Distruge_oferta(&oferta_invalida);
    Distruge_Lista(&L);
}

void Teste_Verifica_nr_oferta()
{
    Lista_oferte L = Creeaza_Lista_Vida_business();
    TElem A = Creeaza_oferta("mare","Everest","22.07.2023",600);
    Adauga_oferta_business(&L, A);
    assert(Verifica_nr_oferta(&L, 1) == 0);
    assert(Verifica_nr_oferta(&L, 10) == -1);
    Distruge_Lista(&L);
}

void Teste_Filtreaza()
{
    Lista_oferte L = Creeaza_Lista_Vida_business();
    TElem A = Creeaza_oferta("mare","Everest","22.07.2023",600);
    Adauga_oferta_business(&L, A);
    TElem B = Creeaza_oferta("munte", "Ineu","20.03.2023",400);
    Adauga_oferta_business(&L, B);
    Lista_oferte Lf = Filtreaza(CopieLista(&L), "Ineu");
    assert(oferte_egale(*Lf.oferte, B) == true);
    Distruge_Lista(&L);
    Distruge_Lista(&Lf);
}

void Teste_Sortare()
{
    Lista_oferte L = Creeaza_Lista_Vida_business();
    TElem A = Creeaza_oferta("mare","Everest","22.07.2023",600);
    Adauga_oferta_business(&L, A);
    TElem B = Creeaza_oferta("munte", "Ineu","20.03.2023",400);
    Adauga_oferta_business(&L, B);
    TElem C = Creeaza_oferta("mare", "Heniu", "20.07.2015", 100);
    Adauga_oferta_business(&L, C);
    Lista_oferte Ls = Sorteaza_lista_cresc_dupa_pret(CopieLista(&L));
    assert(oferte_egale(*Ls.oferte, C) == true);
    assert(oferte_egale(*(Ls.oferte + 1), B) == true);
    assert(oferte_egale(*(Ls.oferte + 2), A) == true);
    Distruge_Lista(&L);
    Distruge_Lista(&Ls);
}

void TestComapara()
{
    TElem A = Creeaza_oferta("mare","Everest","22.07.2023",600);
    TElem B = Creeaza_oferta("munte", "Ineu","20.03.2023",400);
    TElem C = Creeaza_oferta("mare", "Heniu", "20.07.2015", 100);
    assert(compare(&A, &B) == false);
    assert(compare(&B, &C) == false);
    Distruge_oferta(&A);
    Distruge_oferta(&B);
    Distruge_oferta(&C);
}

void TesteSortareGenerica()
{
    Lista_oferte L = Creeaza_Lista_Vida_business();
    TElem A = Creeaza_oferta("mare","Everest","22.07.2023",600);
    Adauga_oferta_business(&L, A);
    TElem B = Creeaza_oferta("munte", "Ineu","20.03.2023",400);
    Adauga_oferta_business(&L, B);
    TElem C = Creeaza_oferta("mare", "Heniu", "20.07.2015", 100);
    Adauga_oferta_business(&L, C);
    Lista_oferte Ls = Sortare_generica(CopieLista(&L), compare);
    assert(oferte_egale(*Ls.oferte, C) == true);
    assert(oferte_egale(*(Ls.oferte + 1), B) == true);
    assert(oferte_egale(*(Ls.oferte + 2), A) == true);
    Distruge_Lista(&L);
    Distruge_Lista(&Ls);
}

void Teste_Service()
{
    Teste_Creeaza_Lista_vida();
    Teste_Adauga();
    Teste_Sterge();
    Teste_Modifica();
    Teste_Verifica_nr_oferta();
    Teste_Filtreaza();
    Teste_Sortare();
    TestComapara();
    TesteSortareGenerica();
}

