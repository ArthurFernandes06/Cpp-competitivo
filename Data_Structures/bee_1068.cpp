
#include <bits/stdc++.h>

using namespace std;
int main() {
    
    stack<char> parenteses;
    string entrada;
    bool saida;
    
    while(getline(cin,entrada))
    {
        while(!parenteses.empty())
        {
            parenteses.pop();
        }
        saida = true;
        for(int i = 0; i < entrada.size(); ++i)
        {
            if(entrada[i] == '(')
            {
                parenteses.push('(');
            }
            else if(entrada[i] == ')' && !parenteses.empty())
            {
                parenteses.pop();
            }
            else if(entrada[i] == ')')
            {
                saida = false;
                break;
            }
            
        }
        if(!parenteses.empty()) saida = false;

        if(saida) cout << "correct" << endl;
        else cout << "incorrect" << endl;
        
    }

    return 0;
}
