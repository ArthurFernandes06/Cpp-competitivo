#include <stdio.h>
#include <stdlib.h>

int main()
{
    
    FILE *fin = fopen("blist.in", "r");
    FILE *fout = fopen("blist.out", "w");
    
    int n, baldes_max = 0, baldes = 0;
    int intervalo;
    fscanf(fin,"%d", &n); 
    int vacas[n][3];

    for(int i = 0; i <n; ++i)
    {
        
        fscanf(fin, "%d%d%d", &vacas[i][0], &vacas[i][1], &vacas[i][2]);
    }

    for (int tempo = 1; tempo <= 1000; ++tempo)
    {
        baldes = 0;
        for(int i = 0; i < n; ++i)
        {
            if(tempo >= vacas[i][0] && tempo < vacas[i][1]) baldes += vacas[i][2];
        }
        if(baldes > baldes_max) baldes_max = baldes;
    }
    fprintf(fout,"%d", baldes_max);
}