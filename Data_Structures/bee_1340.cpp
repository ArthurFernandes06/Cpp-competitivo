// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
void vf_data(vector<int> entrada, vector<int> remover)
{
    bool pilha = true;
    bool fila = true;
    bool fila_prioridade = true;

   
    for( int i = 0; i < remover.size(); ++i)
    {
        //verifica se não é pilha
        if(entrada[entrada.size() - i - 1] != remover[i]) pilha = false;

        //verifica se não é fila
        if(entrada[entrada[i] != remover[i]]) fila = false;

       
    }
    sort(entrada.begin(),entrada.end());

    //verifica se é uma fila de prioridade
    for(int i = 0; i < remover.size(); ++i)
    {
        if(entrada[entrada.size() - 1 - i] != remover[i]) fila_prioridade = false;

    }

    if(fila_prioridade && fila && )
    {
        c
    }

}


int main() {
	int n, operacao, x;

    while(cin >> n)
    {
        vector<int> entrada;
        vector<int> remover;
        for(int i = 0; i < n; ++i)
        {
            cin >> operacao;
            cin >> x;
            if(operacao == 1)
            {
                entrada.push_back(x);
            }
            else if( operacao == 2)
            {
                remover.push_back(x);
            }
        }
    }
}
