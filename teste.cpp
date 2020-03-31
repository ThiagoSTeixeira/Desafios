//Arquivo de teste para funcoes, casos, problemas etc.
#include<bits/stdc++.h>
using namespace std;

struct pessoas{
    int indice;
    int altura;
    string nome;
};

bool ordenaAlt(pessoas i1, pessoas i2){
    return(i1.altura>i2.altura);
}
int main(){
    int N;
    cin>>N;
    struct pessoas lista[N];
    for(int i=0; i<N;i++){
        lista[i].indice = 1;
        lista[i].altura = -i;
    }
    sort(lista, lista+N, ordenaAlt);
    for(int i=0; i<N; i++) printf("%d", lista[i].altura);
    return 0;
}
