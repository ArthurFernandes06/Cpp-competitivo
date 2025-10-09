#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<pair<int,int>>v;

    //Preenchendo um vector com um pair de i e i + 1.
    for(int i = 0; i < 5; ++i)
    {
        pair<int,int> p = {i, i+1};
        v.push_back(p);
    }

    /*percorrenco o vetor por meio de um iterador
      vector<pair<int,int>>:: iterator it = v.begin() -> o começo do conteiner
      it != v.end()-> para quando chega ao fim
      ++it -> passa ao proximo iterador 
    */
    for(vector<pair<int,int>>:: iterator it = v.begin();it != v.end(); ++it )
    {
        //O uso do "*" é referente ao ponteiro, estamos apontado para o iterador e tratando como pair.
        cout << (*it).first << " " << (*it).second << endl;
    }
}