//Aula 4
/*
Dicas:
    -Usar grafos
    -Ate agora o curso nao precisava de pre conhecimento de ED,
     agora exercicios irao demandar mais
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

/*Problema B
    -n problemas (1 <= n <= 2*10^5)
    -dificuldade do i-th = a[i] (todas distintas e dadas em ordem 1 <= a[i] <= 10^9)
    -nao pode haver um problema i com dificuldade > 2*a[i]-1
    -encontrar a maior quantidade de problemas possiveis
*/
#include<bits/stdc++.h>
using namespace std;

//Utilizar 2 ponteiros
int main(){
    int n, maxp=0, j=0;
    cin>>n;
    int dif[n];
    for(int i=0; i<n; i++) scanf("%d", &dif[i]);   
    for(int i=0; i<n; i++){
        j=i;
        while(j+1<n && dif[j+1] <= 2*dif[j]) j++;
        if(j-i+1 > maxp) maxp= j-i+1;
        i = j;
    }
    cout<<maxp;
}

