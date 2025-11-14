#include <stdio.h>
#include <stdlib.h>




int main()
{
    /*
     * Na Primeira Linha dessa matriz é guardado a capacidade,
     * na segunda linha o volume armazenado.
    */
    FILE *fin = fopen("mixmilk.in", "r");
    FILE *fout = fopen("mixmilk.out", "w");

    int baldes[3][2];
    int espaco;
    for(int i = 0; i < 3; ++i)
    {
        fscanf(fin,"%d",&baldes[i][0]);
        fscanf(fin,"%d",&baldes[i][1]);
    }


    for(int j = 0; j < 100; ++j)
    {
        espaco = baldes[(j+1)%3][0] - baldes[(j+1)%3][1];
        if(espaco >= baldes[j%3][1])
        {
            baldes[(j+1)%3][1] += baldes[j%3][1];
            baldes[j%3][1] = 0;
        }else
        {
            baldes[(j+1)%3][1] += espaco;
            baldes[j%3][1] -= espaco;
        }
    }



    for(int i = 0; i < 3; ++i)
    {
        fprintf(fout,"%d\n", baldes[i][1]);
    }


}