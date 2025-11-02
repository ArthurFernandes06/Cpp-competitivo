#include <stdio.h>
#include <stdlib.h>

void swap(int a,int b, int A[])
{
    //Funcao para trocar posicoes
    int aux,pos;
    aux = A[a - 1];
    A[a-1] = A[b - 1];
    A[b - 1] = aux;
 
}

int main()
{
    FILE *fin = fopen("shell.in", "r");
    FILE *fout = fopen("shell.out", "w");

    int n;//Numero de iteracoes
    int a,b;//Valores que serao trocados
    int targ;//Posicao chutada
    int cont[3] = {0,0,0}; //Contador para cada possivel posicao de inicio da pedra
    int A[3] = {1,2,3};
    
    fscanf(fin,"%d", &n);

    for(int i = 0; i < n; ++i)
    {
        fscanf(fin,"%d%d%d", &a,&b,&targ);
        swap(a,b,A);
        cont[A[targ - 1] - 1]++;
        /*
            Aqui o valor do contador é incrementado,
            cada valor do vetor A, indica a posicao de inicio, que no comeco é 1 2 3.
            o cont[0] indica o contador para caso a pedra esteja em 1, o cont[1] para  2
            e o cont[2] para o tres.

            Se a pedra estiver na posicao targ -1(valor chutado) , isso implica que a pedra comecou na posicao que
            o vetor A guarda, que no caso é A[targ - 1], então nos adicionamos 1 ao contador para a possibilidade
            de comecar em A[targ - 1], ficando cont[A[targ - 1] - 1]++
        */

    }

    if(cont[0] > cont[1] && cont [0] > cont[2])
    {
        fprintf(fout,"%d", cont[0]);
    }else if(cont[1] > cont[2])
    {
        fprintf(fout,"%d", cont[1]);
    }else
    {
        fprintf(fout,"%d", cont[2]);;
    }

}