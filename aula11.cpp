/*Aula 11
    Dicas:
        -Pessoal, pra quem ta fazendo a aula 11, o B e o C 
        não envolvem nada difícil, e o D e E envolvem grafos
*/

//Problema A
#include<bits/stdc++.h>
using namespace std;

int main(){
    string entrada, palavra;
    getline(cin, entrada);
    istringstream ss(entrada);
    while(ss){
        ss>>palavra;
        //cout<<palavra<<endl;
        if (palavra.back() == '?'){
            cout<<"7";
            return 0;
        }
        if(palavra == "Sussu" || palavra == "Sussu!"|| palavra == "Sussu."){
            cout<<"AI SUSSU!";
            return 0;
        }
        if (palavra.back() == '.' || palavra.back() == '!'){
            cout<<"O cara é bom!";
            return 0;
        }
    }
    cout<<"O cara é bom!";
    return 0;
}
