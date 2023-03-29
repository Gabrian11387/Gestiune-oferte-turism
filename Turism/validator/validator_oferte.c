#include <string.h>
#include "../domain/oferta.h"
#include "../validator/validator_oferte.h"
#include <assert.h>

int valid(TElem A)
{
    if(strlen(A.tip) == 0)
        return -1;
    if(strcmp(A.tip,"munte") != 0 && strcmp(A.tip,"mare") != 0 && strcmp(A.tip, "city break") != 0)
            return -1;
    if(strlen(A.destinatie) == 0)
        return -1;
    if(strlen(A.data_plecare) == 0)
        return -1;
    if(A.pret < 0)
        return -1;
    return 0;//totul e ok
}

void Teste_Validator()
{
    TElem A = Creeaza_oferta("", "", "", -200);
    assert(valid(A) == -1);
    TElem B = Creeaza_oferta("oras", "", "", -200);
    assert(valid(B) == -1);
    TElem C = Creeaza_oferta("munte", "", "", -200);
    assert(valid(C) == -1);
    TElem D = Creeaza_oferta("munte", "Everest", "", -200);
    assert(valid(D) == -1);
    TElem E = Creeaza_oferta("munte", "Everest", "2023", -200);
    assert(valid(E) == -1);
    Distruge_oferta(&A);
    Distruge_oferta(&B);
    Distruge_oferta(&C);
    Distruge_oferta(&D);
    Distruge_oferta(&E);
}
