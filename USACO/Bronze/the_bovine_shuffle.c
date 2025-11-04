#include <stdio.h>
#include <stdlib.h>
void embaralha(int ord[], int id[], int aux_id[], int n)
{
    for(int i = 0; i <n; ++i)
    {
        aux_id[ord[i]] = id[i];
    }
}

int main()
{
    FILE *fin = fopen("shuffle.in", "r");
    FILE *fout = fopen("shuffle.out", "w");
    int n,leitura; fscanf(fin, "%d", &n);
    int ord[n]; int id[n], aux_id[n]; for(int i = 0; i <n; ++i)
    {
        fscanf(fin, "%d", &leitura);
        ord[leitura - 1] = i;
    } for(int i = 0; i<n; ++i)
    {
        fscanf(fin,"%d", &id[i]);
    }
    embaralha(ord,id,aux_id,n);
    embaralha(ord,aux_id,id,n);
    embaralha(ord,id,aux_id,n);
    for(int i =0; i <n; ++i)
    {
        fprintf(fout,"%d\n",aux_id[i]);
    }
}
