//Aula 18

/*Problema A
    -n ranks
    -d[i] anos pra subir de i pra i+1

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, a, b, anos = 0;
    cin>>n; 
    vector<int> rnks(n);
    for(int i=0; i<n-1; i++) cin>>rnks[i];
    cin>>a>>b;
    for(int i=a-1; i<b-1; i++) anos+=rnks[i];
    cout<<anos;
    return 0;
}

/*Problema B
    -xadrez 8x8
    -torre e cavalo que nao conseguem se matar
    -descobrir o numero de jeitos de colocar um novo cavalo
*/
#include<bits/stdc++.h>
using namespace std;

bool killshotT(int i, int j, int a, int b){
    return(i == a || j == b);
}
bool killshotC(int i, int j, int a, int b){
    if(i==a && j==b) return true;
    if(a==i-2 || a==i+2){
        if(b==j-1 || b==j+1) return true;
    }
    if(a==i-1 || a==i+1){
        if(b==j-2 || b== j+2) return true;
    }
    return false;
}
int main(){
    string eT, eC;
    int ci, cj, ti, tj, cont = 0;
    cin>>eT>>eC;
    ti=eT[0] - 'a';
    tj=eT[1] - '1';
    ci=eC[0] - 'a';
    cj=eC[1] - '1';
    //cout<<ti<<endl<<tj<<endl<<ci<<endl<<cj<<endl;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(!killshotT(ti, tj, i, j) && !killshotC(ci, cj, i, j) && !killshotC(i, j, ti, tj)) cont++;
        }
    }
    cout<<cont;
    return 0;
}