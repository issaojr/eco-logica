#include "business/business_residuos.h"

bool atualizar_residuo(const residuo_t *r)
{
    if (!r)
    {
        return false;
    }

    
    return atualizar_residuo_csv(r);
}

