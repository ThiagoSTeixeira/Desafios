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
    return 0;
}

/*Problema C
    -n monstros em fileira de 1 a n (1<= n <= 2*10^5)
    -monstro[i] tem h[i] de hp (1<= h[i] <= 10^9)
    -ataque = a, ataque do oponente
    -compete com o oponente para matar os monstros
    -dar o last hit = 1 ponto, caso contrario 0 pontos
    -k = qntidade de vezes que o ataque do oponente pode ser pulado
    -(1<= a,b,k <= 10^9)
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, a, b, k;
    cin>>n>>a>>b>>k;
    int monstro[n];
    int total = 0;
    for(int i=0; i<n; i++){ 
        cin>>monstro[i]; 
        monstro[i] %= a+b;
        if(monstro[i] == 0) monstro[i] = a+b;
        monstro[i]= ((monstro[i] + a-1) / a) - 1;   //vetor de custos
    }
    sort(monstro, monstro+n);   //Mata os menos custosos primeiro
    for(int i=0; i<n; i++){
        if(k-monstro[i] < 0) break;
        total++;
        k -= monstro[i];
    }
    cout<< total;
    return 0;
}

/*Problema D
    -n segmentos de numeros [l, r] (podem ser iguais, dentro de outros, etc.)
    -encontrar qual segmento tirar para ter a maior intersecao possivel
    -2 <= n <= 3*10^5
    -0 <= l <= r <= 10^9
    -Printar o tamanho da maior intercessao possivel
*/
#include<bits/stdc++.h>
using namespace std;

//resposta retirada do editorial do codeforces! (n entendi fdc)
const int INF = int(1e9);   //infinito

int main(){
    int n;
    cin>>n;
    int l[n+1], r[n+1];
    int prl[n+1], prr[n+1], suf[n+1], pos[n+1];
    
    for(int i=0; i<n; i++) scanf("%d %d", &l[i], &r[i]);
    prl[0] = suf[n]= 0;
    prr[0] = pos[n] = INF;
    
    for(int i=0; i<n; i++){
        prl[i+1] = max(prl[i], l[i]);
        prr[i+1] = min(prr[i], r[i]);
    }

    for (int i = n-1; i>=0; i--){
        suf[i] = max(suf[i+1], l[i]);
        pos[i] = min(pos[i+1], r[i]);
    }
    int resp = 0;
    for(int i=0; i<n; i++) resp = max(resp, min(prr[i], pos[i+1])- max(prl[i], suf[i+1]));
    cout<<resp;
    return 0;
}

