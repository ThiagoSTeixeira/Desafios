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
    while(cin>>palavra){
        if(palavra == "Sussu" || palavra == "Sussu!"|| palavra == "Sussu.") sussu = true;
    }
    if(palavra.back() == '?'){
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
/*Problema B
    -Mesa 10m x 10m
    -Q querys (Q<= 5000)
    -Query A = coloca prato cm centro em (x, y) e raio r
    -Query B = remove o prato cm centro (x, y) e raio r
    -0 <= x,y <=1000 && 1<=r<=1000
    -Equacao da circunferencia-> (x-x0)^2 + (y-y0)^2 = r^2
*/
#include<bits/stdc++.h>
using namespace std;

bool encaixa(int x, int y, int r, int x0, int y0, int r0){
    return(r0 == 0 || !(sqrt(pow(abs(x-x0), 2) + pow(abs(y-y0), 2)) < r+r0));
}
int main(){
    int Q, tempX, tempY, tempR;
    char type;
    cin>>Q;
    vector<int> x(Q, 0);
    vector<int> y(Q, 0);
    vector<int> r(Q, 0);
    vector<bool> ans(Q, false);
    for(int i=0; i<Q; i++){
        cin>>type>>tempX>>tempY>>tempR;
        if(type == 'R'){
            for(int j=0; j<Q; j++){
                if(x[j]==tempX && y[j]==tempY && r[j]==tempR){
                    x[j]=y[j]=r[j]=0;
                    ans[i] = true;
                }
            }
        }
        if(type == 'A'){
            ans[i] = true;
            for(int j=0; j<Q; j++){
                if(!encaixa(tempX, tempY, tempR, x[j], y[j], r[j])){
                    ans[i] = false;
                    break;
                }
            }
            if(ans[i]){
                x[i] = tempX;
                y[i] = tempY;
                r[i] = tempR;
            }
        }
    }
    for(int i=0; i<Q; i++){
        if(ans[i]) cout<<"Ok"<<endl;
        else cout<<"No"<<endl;
    }
}

