/*Aula 11
    Dicas:
        -Pessoal, pra quem ta fazendo a aula 11, o B e o C 
        não envolvem nada difícil, e o D e E envolvem grafos
*/

//Problema A
#include<bits/stdc++.h>
using namespace std;

int main(){
    string palavra;
    bool sussu=false;
    //getline(cin, entrada);
    //istringstream ss(entrada);
    while(cin>>palavra){
        //ss>>palavra;
        //cout<<palavra<<endl;
        if(palavra == "Sussu" || palavra == "Sussu!"|| palavra == "Sussu.") sussu = true;
        /*if (palavra.back() == '.' || palavra.back() == '!'){
            cout<<"O cara é bom!"<<endl;
            return 0;
        }*/
    }
    if (palavra.back() == '?'){
            cout<<"7"<<endl;
            return 0;
        }
    if(sussu){
        cout<<"AI SUSSU!"<<endl;
        return 0;
    }
    cout<<"O cara é bom!"<<endl;
    return 0;
}
