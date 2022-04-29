#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int info;
    lista *prox;
} Lista;

/* função de criação: retorna uma lista vazia */
Lista* criaLista ()
{
    return NULL;
}

/* inserção no início: retorna a lista atualizada */
Lista *insereLista (Lista *l, int i)
{
    Lista *novo = (Lista*) malloc(sizeof(Lista));
    novo->info = i;
    novo->prox = l;
    return novo;
}

/* função vazia: retorna 1 se vazia ou 0 se não vazia */
int ListaVazia (Lista *l)
{
    return (l == NULL);
}

/* função busca: busca um elemento na lista */
Lista *busca (Lista *l, int v)
{
    Lista *p;
    for (p=l; p!=NULL; p = p->prox)
    {
        if (p->info == v)
            return p;
    }
    return NULL; /* não achou o elemento */
}

/* função retira: retira elemento da lista */
Lista *Remove (Lista *l, int v)
{
    Lista *ant = NULL; /* ponteiro para elemento anterior */
    Lista *p = l; /* ponteiro para percorrer a lista */
    /* procura elemento na lista, guardando anterior */
    while (p != NULL && p->info != v)
    {
        ant = p;
        p = p->prox;
    }
    /* verifica se achou elemento */
    if (p == NULL)
    {
        printf("\nElemento nao encontrado\n");
        return l; /* não achou: retorna lista original */
    }
    /* retira elemento */
    if (ant == NULL)
    {
        /* retira elemento do inicio */
        l = p->prox;
        printf("\nElemento removido \n");
    }
    else
    {
        /* retira elemento do meio da lista */
        ant->prox = p->prox;
        printf("\nElemento removido \n");
    }
    free(p);
    return l;
}


// função imprime: imprime valores dos elementos
void imprimeLista (Lista *l)
{
    Lista *p;
    for (p=l; p!=NULL; p=p->prox)
    {
        printf("\n\nInfo = %d\n", p->info);
    }
}

int main()
{

    Lista *minhaLista = criaLista();
    Lista *resposta;
    int opcao, valor;

    do
    {
        printf("\n1 - Inserir no inicio\n2 - Imprimir\n3 - A lista esta vazia?\n4- Buscar um elemento\n5 - Retire um elemento\n0 - Sair\n");
        scanf("%d", &opcao);

        switch(opcao)
        {
        case 1:
            printf("Digite um valor a ser inserido: ");
            scanf("%d", &valor);
            minhaLista = insereLista(minhaLista, valor);
            break;
        case 2:
            imprimeLista(minhaLista);
            break;
        case 3:
            if(ListaVazia(minhaLista))
                printf("A lista esta vazia\n");
            else
                printf("A lista nao esta vazia\n");
            ListaVazia(minhaLista);
        case 4:
            printf("\nInforme o valor para busca: ");
            scanf("%d", &valor);
            resposta = busca(minhaLista, valor);
            if(resposta!=NULL)
                printf("\nO valor foi encontrado na lista: %d", resposta->info);
            else
                printf("\nO valor %d nao foi encontrado na lista", valor);
       case 5:
            printf("\nInforme um valor para remover: ");
            scanf("%d",&valor);
            minhaLista = Remove(minhaLista, valor);
        case 0:
            printf("Finalizando...\n");
            break;
        default:
            printf("Opcao invalida!");
        }
    }
    while(opcao != 0);

    return 0;

}
