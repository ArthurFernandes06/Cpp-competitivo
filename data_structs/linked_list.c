#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *prox;
    struct Node *ant;

}Node;

typedef struct LinkedList{
    struct Node *prim;
    struct Node *ult;
    int tamanho;

}LinkedList;

void criar_lista(LinkedList *ll)
{
    ll->prim =  NULL;
    ll->tamanho = 0;
}
void inserir_ll( LinkedList *ll,int pos,int valor)
{
    Node *node = (Node*) malloc(sizeof(Node));
    if (node == NULL) {
        fprintf(stdout, "Erro: malloc retornou NULL\n");
        exit(EXIT_FAILURE);
    }

    node->data = valor;
    if(ll->prim == NULL)
    {
        node->ant = NULL;
        node->prox = NULL;
        ll->prim = node;
        ll->ult = node;
        ll->tamanho++;
    }else
    {
        if(pos <= 0)
        {
            node->prox = ll->prim;
            node->ant = NULL;
            ll->prim->ant = node;
            ll->prim = node;
            ll->tamanho++;
        }else if(pos >=ll->tamanho)
        {
            node->ant = ll->ult;
            ll->ult->prox = node;
            node->prox = NULL;
            ll->tamanho++;
            ll->ult = node;

        }else
        {
            int i = 1;
            Node *n1 = ll->prim;
            while(i <= pos && n1 != NULL)
            {
                if(i == pos)
                {
                    Node *n2 = n1->prox;
                    n1->prox = node;
                    n2->ant = node;
                    node->ant = n1;
                    node->prox = n2;
                    ll->tamanho++;
                }
                n1 = n1->prox;
                i++;
            }
        }


    }
}

void printa_ll(LinkedList *ll)
{
    Node *no = ll->prim;
    while(no != NULL)
    {
        printf("%d ", no->data);
        no = no->prox;
    }
    printf("\n");
}



int main()
{
    LinkedList ll;
    criar_lista(&ll);

    int j =0;
    for(int i =0; i<=10; i = i +2)
    {
        inserir_ll(&ll,ll.tamanho,i);

    }
    printa_ll(&ll);

}
