#include "business/business_residuos.h"

bool atualizar_residuo(const residuo_t *r)
{
    if (!r)
    {
        return false;
    }

    // Registra o resíduo
    return atualizar_residuo_csv(r);
}

