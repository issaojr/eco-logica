#include "business/business_funcionario.h"

/**
 * @brief Obtém a lista completa de todos os funcionários cadastrados.
 *
 * @param funcionarios_out Ponteiro para o array onde os funcionários serão armazenados.
 * @param max_funcionarios O tamanho máximo do array funcionarios_out.
 * @param total_funcionarios_out Ponteiro para armazenar o número total de funcionários lidos.
 * @return int 1 se a leitura foi bem-sucedida (mesmo que vazia), 0 em caso de erro.
 */
bool obter_todos_funcionarios(
	funcionario_t *funcionarios_out,
	size_t max_funcionarios,
	size_t *total_funcionarios_out)
{
	/* Delega a chamada para a camada de persistência */
	if (listar_funcionarios_csv(
		funcionarios_out,
		max_funcionarios,
		total_funcionarios_out))
	{
		return true; 
	}
	else
	{
		return false; 
	}
}

int adicionar_funcionario(funcionario_t *funcionario)
{
	if (!funcionario)
		return 1; 

	bool existe = buscar_funcionario_csv(funcionario->matricula, funcionario);

	if (existe)
	{
		return 2; 
	}

	if (inserir_funcionario_csv(funcionario))
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int editar_funcionario(funcionario_t *funcionario)
{
	if (!funcionario)
		return 1; 

	if (atualizar_funcionario_csv(funcionario))
	{
		return 0; 
	}
	else
	{
		return 1; 
	}
}

int excluir_funcionario(char *matricula)
{
	if (excluir_funcionario_csv(matricula))
	{
		return 0; 
	}
	else
	{
		return 1; 
	}
}

bool buscar_funcionario_por_matricula(char *matricula, funcionario_t *funcionario_out)
{
	if (!funcionario_out)
		return false; 

	return buscar_funcionario_csv(matricula, funcionario_out);
}

bool gerar_relatorio_lista_funcionarios(relatorio_t *rel)
{
    if (!rel)
        return false;

    funcionario_t funcionarios[TAM_MAX_FUNCIONARIOS];
    size_t total = 0;

    if (!listar_funcionarios_csv(funcionarios, TAM_MAX_FUNCIONARIOS, &total) || total == 0)
        return false;

    rel->colunas = 3;
    rel->linhas = total;

    const char *cabecalhos[] = {
        "Matrícula", "Nome", "Hash Senha"
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
        rel->dados[i][0] = _util_strdup(funcionarios[i].matricula);
        rel->dados[i][1] = _util_strdup(funcionarios[i].nome);
        rel->dados[i][2] = _util_strdup(funcionarios[i].hash_senha);

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