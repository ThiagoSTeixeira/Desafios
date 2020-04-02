//Aula 10
/*Problema A
    -n membros recebem com baldes de 1 a n
    -balde 1 tem 1 pipoca, 2 tem 2 e assim por diante
    -todas as pipocas foram juntadas em 1 balde(1 vai p2, 2 p 3 ...)
    -1 pipoca cai em cada passo
    -n-1 passos(2<=n<=3*10^9)
*/
#include<bits/stdc++.h>
using namespace std;
//equacao de gauss para achar soma de numeros consecutivos - pipocas perdidas
int main(){
    long long int n, resultado;
    cin>>n;
    resultado = ((n+1)*n/2) - (n-1);
    cout<<resultado;
    return 0;
}