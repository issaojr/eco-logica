#include "business/business_industria.h"

int obter_todas_industrias(
	industria_t *industrias_out,
	size_t max_industrias,
	size_t *total_industrias_out)
{
	
	if (listar_industrias_csv(
		industrias_out,
		max_industrias,
		total_industrias_out))
	{
		return 0; 
	}
	else
	{
		return 1; 
	}
}

bool cadastrar_industria(const industria_t *industria)
{
	industria_t existente;
	
	if (validar_industria_csv(industria->cnpj, &existente))
	{
		return false;
	}
	
	return inserir_industria_csv(industria);
}

int adicionar_industria(industria_t *industria)
{
	if (!industria)
		return 1; 

	
	bool existe = buscar_industria_csv(industria->cnpj, industria);

	if (existe)
	{
		return 2; 
	}

	
	if (inserir_industria_csv(industria))
	{
		return 0; 
	}
	else
	{
		return 1; 
	}
}

int editar_industria(industria_t *industria)
{
	if (!industria)
		return 1; 

	
	if (atualizar_industria_csv(industria))
	{
		return 0; 
	}
	else
	{
		return 1; 
	}
}

int excluir_industria(const char *cnpj)
{
	
	if (excluir_industria_csv(cnpj))
	{
		return 0; 
	}
	else
	{
		return 1; 
	}
}

bool buscar_industria_por_cnpj(const char *cnpj, industria_t *industria_out)
{
	if (!cnpj || !industria_out) return false;

	if (!buscar_industria_csv(cnpj, industria_out)) return false;

	return true;
}

bool gerar_relatorio_lista_industrias(relatorio_t *rel)
{
    if (!rel)
        return false;

    industria_t industrias[TAM_MAX_INDUSTRIAS];
    size_t total = 0;

    if (!listar_industrias_csv(industrias, TAM_MAX_INDUSTRIAS, &total) || total == 0)
        return false;

    rel->colunas = 13;
    rel->linhas = total;

    const char *cabecalhos[] = {
        "CNPJ", "Razão Social", "Nome Fantasia", "Telefone", "Logradouro",
        "Número", "Bairro", "Cidade", "Estado", "CEP",
        "Data Abertura", "Nome Responsável", "Email Responsável"
    };

    rel->cabecalhos = malloc(rel->colunas * sizeof(char *));
    if (!rel->cabecalhos)
        return false;

    for (size_t i = 0; i < rel->colunas; i++)
        rel->cabecalhos[i] = _util_strdup(cabecalhos[i]);

    rel->dados = malloc(total * sizeof(char **));
    if (!rel->dados)
    {
        for (size_t i = 0; i < rel->colunas; i++)
            free(rel->cabecalhos[i]);
        free(rel->cabecalhos);
        return false;
    }

    for (size_t i = 0; i < total; i++)
    {
        rel->dados[i] = malloc(rel->colunas * sizeof(char *));
        rel->dados[i][0]  = _util_strdup(industrias[i].cnpj);
        rel->dados[i][1]  = _util_strdup(industrias[i].razao_social);
        rel->dados[i][2]  = _util_strdup(industrias[i].nome_fantasia);
        rel->dados[i][3]  = _util_strdup(industrias[i].telefone);
        rel->dados[i][4]  = _util_strdup(industrias[i].logradouro);
        rel->dados[i][5]  = _util_strdup(industrias[i].numero);
        rel->dados[i][6]  = _util_strdup(industrias[i].bairro);
        rel->dados[i][7]  = _util_strdup(industrias[i].cidade);
        rel->dados[i][8]  = _util_strdup(industrias[i].estado);
        rel->dados[i][9]  = _util_strdup(industrias[i].cep);
        rel->dados[i][10] = _util_strdup(industrias[i].data_abertura);
        rel->dados[i][11] = _util_strdup(industrias[i].nome_responsavel);
        rel->dados[i][12] = _util_strdup(industrias[i].email_responsavel);

        for (size_t j = 0; j < rel->colunas; j++)
        {
            if (!rel->dados[i][j])
            {
                for (size_t k = 0; k <= i; k++)
                {
                    for (size_t l = 0; l < (k == i ? j : rel->colunas); l++)
                        free(rel->dados[k][l]);
                    free(rel->dados[k]);
                }
                for (size_t j = 0; j < rel->colunas; j++)
                    free(rel->cabecalhos[j]);
                free(rel->cabecalhos);
                free(rel->dados);
                return false;
            }
        }
    }

    return true;
}
