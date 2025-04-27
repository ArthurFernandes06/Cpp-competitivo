#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int>carneiros(n);
    vector<bool>visitada(n, false);
    

    //armazenando o input de cada estrela
    for(int i = 0; i < n; ++i){
        cin >> carneiros[i];//atribuindo o numero de carneiros de cada estrela
        
        
    }

    int i = 0;
    while(i >= 0 && i <n){
        visitada[i] = true;//marca que passou pela estrela

        //se o número de carneiros for par
        if(carneiros[i]%2 == 0){
            
            //se tiver algum cairneiro na estrela 
            if(carneiros[i] > 0)carneiros[i] -= 1;

            //se existir estrela pra voltar, volte, se nao, interrompa o laco
            if(i > 0) i -= 1;
            else break;
        }

        //se o numero for impar
        else{

            //se tiver algum cairneiro na estrela 
            if(carneiros[i] > 0)carneiros[i] -= 1;

            //se existir estrela pra voltar, volte, se nao, interrompa o laco
            if(i < n - 1) i += 1;  
            else break;
                
        }
    }

    long long sobra = 0;
    int estrelas = 0;
    //somando os carneiros que sobraram e vendo se ele passou por alguma estrela
    for (int j = 0; j < n; ++j) {
        if (visitada[j]) estrelas++;
        sobra += carneiros[j];
    }

    cout << estrelas << " " << sobra;

}