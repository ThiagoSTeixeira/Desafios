//Aula 4
/*
Dicas:
    -Usar grafos!
    -Ate agora o curso nao precisava de pre conhecimento de ED,
     agora exercicios irao demandar mais!
*/
/*Programa A
    -string t de n letras 
    -inteiro k
    -printar 
*/
#include<bits/stdc++.h>
using namespace std;

int encontraIndice(string t, int n){
    int indice = 0;
    for(int i=1; i<n; i++){
        if(t[i] == t[0]){
            indice = 0;
            for(int j=i; j<=n; j++){
                if (j == n) return indice;
                if (t[j] == t[indice]) ++indice;
                else break;
            }
        }
    }
    return 0;
}
int main(){
    int n, k, indice;
    cin >> n >> k;
    string t, subst;
    cin>> t;
    indice = encontraIndice(t, n);
    subst = t.substr(indice, n);
    cout<<t;
    for(int i=0; i<k-1; i++) cout<< subst;  
    return 0;  
}