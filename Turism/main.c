#include <stdio.h>
#include "business//service.h"
#include "domain/oferta.h"
#include "repository/repo_oferte.h"
#include "validator/validator_oferte.h"

void Afiseaza(Lista_oferte L)
{
    if(L.lg == 0)
        printf("Nu exista nicio oferta in aplicatie!\n");
    for(int i = 0; i < L.lg; i ++)
    {
        printf("Oferta ");
        printf("%d: ", i+1);
        printf("%s, ",(L.oferte+i)->tip);
        printf("%s, ",(L.oferte+i)->destinatie);
        printf("%s, ",(L.oferte+i)->data_plecare);
        printf("%.2f\n",(L.oferte+i)->pret);
    }
}

void run_meniu()
{
    Lista_oferte List = Creeaza_Lista_Vida_business();
    int ruleaza = 1;
    while(ruleaza)
    {
        printf("1.Adauga oferta noua\n2.Actualizeaza oferta\n3.Sterge oferta\n4.Oferte ordonate crescator dupa pret\n5.Oferte filtrate dupa destinatie\n6.Afiseaza lista\n7.Opreste aplicatia\n");
        int choice;
        printf("Alege optiunea:");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Introdu oferta\n");
                char tip[20], dest[30], data_plecare[30];
                float pret;
                printf("tip:");
                scanf("%s", tip);
                printf("destinatie:");
                scanf("%s", dest);
                printf("data plecare:");
                scanf("%s", data_plecare);
                printf("pret:");
                scanf("%f", &pret);
                int ok = Adauga_oferta_business(&List, Creeaza_oferta(tip, dest, data_plecare, pret));
                if(ok == -1)
                    printf("Oferta invalida!\n");
                else
                    printf("Oferta adaugata cu succes!\n");
                break;
            case 2:
                printf("Introdu numarul de ordine al ofertei:\n");
                int nr_oferta_de_modificat;
                scanf("%d", &nr_oferta_de_modificat);
                int ok1 = Verifica_nr_oferta(&List, nr_oferta_de_modificat);
                if(ok1 == -1)
                    printf("Numar de ordine al ofertei invalid!\n");
                else
                {
                    char tip1[20], dest1[30], data_plecare1[30];
                    float pret1;
                    printf("tip nou:");
                    scanf("%s", tip1);
                    printf("destinatie noua:");
                    scanf("%s", dest1);
                    printf("data plecare noua:");
                    scanf("%s", data_plecare1);
                    printf("pret nou:");
                    scanf("%f", &pret1);
                    int ok11 = Modifica_oferta_business(&List, nr_oferta_de_modificat , Creeaza_oferta(tip1, dest1, data_plecare1, pret1));
                    if(ok11 == -1)
                        printf("Oferta invalida!\n");
                    else
                        printf("Oferta modificata cu succes!\n");
                }
                break;
            case 3:
                printf("Introdu numarul de ordine al ofertei:\n");
                int nr_ofertei;
                scanf("%d", &nr_ofertei);
                int ok2 = Verifica_nr_oferta(&List, nr_ofertei);
                if(ok2 == -1)
                    printf("Numar de ordine al ofertei invalid!\n");
                else
                {
                    Sterge_oferta_business(&List, nr_ofertei - 1);
                    printf("Oferta a fost stearsa cu succes!\n");
                }
                break;
            case 4:
                printf("Lista sortata crescator dupa pret\n");
                Lista_oferte L_sortata = Sortare_generica(CopieLista(&List), compare);
                Afiseaza(L_sortata);
                Distruge_Lista(&L_sortata);
                break;
            case 5:
                printf("Lista filtrata dupa destinatie\n");
                char destinatie[30];
                scanf("%s", destinatie);
                Lista_oferte Lista_filtrata = Filtreaza(CopieLista(&List), destinatie);
                Afiseaza(Lista_filtrata);
                Distruge_Lista(&Lista_filtrata);
                break;
            case 6:
                Afiseaza(List);
                break;
            case 7:
                Distruge_Lista(&List);
                ruleaza = 0;
                break;
            default:
                printf("Comanda invalida!\n");
                printf("\n");
        }
    }
}

int main()
{
    TesteRepo();
    Teste_Domain();
    Teste_Service();
    Teste_Validator();
    run_meniu();
    return 0;
}

