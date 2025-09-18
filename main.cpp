#include <bits\stdc++.h>

using namespace std;
//Quantos pares existem tal que i e j tal que i < j && b[i] > b[j]

int mergesort(vector<int> &H, int inicio, int fim)
{
    if(inicio == fim)
    {
        return 0;
    }else
    {
        int meio = (inicio + fim)/2;
        int c1 = mergesort(H,inicio,meio);
        int c2 = mergesort(H, meio, fim);
        int c3 = 0;

        int tam = fim - inicio + 1;
        int A[tam];

        int i = inicio; //comeco esquerdo de H.
        int j = meio + 1;//aponta para o comeco direito de H.

        int k = 0;

        while(i <= meio || j <= fim)
        {
            if(i > meio) {A[k] = H[j]; k++; j++;}
            else if(j > fim) {A[k] = H[i];k++; i++;}
            else if(H[i] > H[j]){
                A[k] = H[i];k++; i++;
                c3 += fim - j +1;

            }else{
                A[k] = H[j]; k++; j++;
            }
        }
        i = inicio;
        k = 0;
        while(i <= fim)
        {
            H[i] = A[k];
            i++;
            k++;
        }
        return c1 + c2 + c3;
    }

}

int main()
{

    int n;
    scanf("%d", &n);
    vector<int> b;
    for(int i = 0; i < n; ++i)
    {
        scanf("%d",&b[i]);
    }
    cout << mergesort(b, 0, n);

    return 0;
}
