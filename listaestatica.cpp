#include<stdio.h>
#include "listaestatica.h"

int main()
{
    int valor, retorno, opcao;

    do
    {
        printf("\n1 - Inicializa lista\n2 - Inserir elemento na lista\n3 - Remover elemento da lista\n4 - A lista esta cheia?\n5 - A lista esta vazia?\n0 -  Finalizar\n");
        scanf("%d",&opcao);

        switch(opcao)
        {
        case 1:
            inicializaLista();
            break;
        case 2:
            printf("\nQual valor a inserir na lista ? ");
            scanf("%d", &valor);
            retorno = adiciona(valor);
            if(retorno >= 0)
                printf("\nValor inserido: %d", aLista.dados[aLista.ultimo]);
            else
            {
                if(retorno == errolistacheia)
                    printf("\nA lista esta cheia");
                else if(retorno ==errolistacheia)
                    printf("\nA lista esta vazia");
                else if(retorno ==erroposicao);
                printf("\nErro de posicao");
            }
            break;
        case 3:
            retorno = retira();
            if(retorno >= 0)
                printf("\nValor removido. Ultimo agora eh: %d", aLista.dados[aLista.ultimo]);
            else
            {
                if(retorno == errolistacheia)
                    printf("\nA lista esta cheia");
                else if(retorno == errolistacheia)
                    printf("\nA lista esta vazia");
                else if(retorno == erroposicao);
                printf("\nErro de posicao");
            }
            break;
        case 4:

            if(listaCheia() == -1)
                printf("A lista esta cheia");
            else
                printf("A lista nao esta cheia");
            break;
        case 5:
            if(listaVazia() ==- 1)
                printf("\nA lista esta vazia");
            else
                printf("\nA lista nao esta vazia");
            break;
        case 0:
            printf("Finalizando....\n");
            break;
        default:
            printf("\nOpcao invalida!");

        }
    }
    while(opcao != 0);



    return 0;

}
