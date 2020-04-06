//Aula9
/*Dicas
Quando estamos num grid, podemos fazer dois vetores:

dx[] = {1, 0, -1, 0}
dy[] = {0, 1, 0, -1}

e ao em vez de fazermos 4 ifs pra fazer bfs/dfs podemos simplesmente fazer um for loop para encontrar os adjacentes

for (int i = 0; i < 4; i++) {
    int nextX = x + dx[i];
    int nextY = y + dy[i]
}

Percebam que podemos estender isso para mais dimensões também...
*/
/*Problema A
    -Pasto de R x C celulas(1 <= R, C<=500)
    -Cada celula pode estar vazia(.), ter uma ovelha(S), lobo(W) ou cachorro(D)
    -Ovelhas e cachorros não se mexem
    -Colocar os cachorros de modo que os lobos nao peguem as ovelhas
    -Se for impossivel printar "No" se for, "Yes" e o tabuleiro
    -N eh necessario minimizar o numero de cachorros
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int R, C;
    bool possivel = true;
    cin>>R>>C;
    char campo[R][C];
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++) cin>>campo[i][j];
    }
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(!possivel) break;

            if(campo[i][j] == 'S'){ 
                //lobos
                if(i>0 && campo[i-1][j]=='W') possivel = false;
                if(j>0 && campo[i][j-1]=='W') possivel = false;
                if(i<R-1 && campo[i+1][j]=='W') possivel = false;
                if(j<C-1 && campo[i][j+1]=='W') possivel = false;
                //vazios
                if(i>0 && campo[i-1][j]=='.') campo[i-1][j] = 'D';
                if(j>0 && campo[i][j-1]=='.') campo[i][j-1] = 'D';
                if(i<R-1 && campo[i+1][j]=='.') campo[i+1][j] = 'D';
                if(j<C-1 && campo[i][j+1]=='.') campo[i][j+1] = 'D'; 
            }
        }
    }
    if(!possivel){
        cout<<"No";
        return 0;
    }
    cout<<"Yes"<<endl;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++) cout<<campo[i][j];
        cout<<endl;
    }
    return 0;
}
