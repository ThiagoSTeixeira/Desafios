//Aula 7
/*Problema A
        -recebe x (2 <= x <= 10^9)
        -encontrar 2 inteiros a e b tq maxDivCom(a,b) + minMultCom(a,b) = x
        -caso haja mais de uma resposta, devolver qualquer uma
        -t tests cases
    Dicas:
        -resolver na mao os casos de 2 a 10.
        -tentar fazer em 1 linha talvez?
        -ver a aula gravada
*/
#include<bits/stdc++.h>
using namespace std;

//A resposta x-1 e 1 sempre funciona!!!!!!!!!
int main(){
    int t;
    cin>>t;
    vector<int> x(t);
    for (int i=0; i<t; i++) cin>>x[i];
    for (int i=0; i<t; i++) printf("%d %d\n", x[i]-1, 1);
    return(0);
}
/*Problema B
    -array a de tamanho n (1 <= n <= 10^5 && 1 <= a <= 10^9)
    -a soma dos n's nao excede 10^5
    -qual sera a longest increasing subsequence de um array de n copias de a
    -t test cases
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n;
    cin>>t;
    int resp[t];
    for (int i=0; i<t; i++){
        cin>>n;
        vector<int> seq(n);
        for(int j=0; j<n; j++) scanf("%d", &seq[j]);
        sort(seq.begin(), seq.end());
        seq.erase(unique(seq.begin(), seq.end()), seq.end());
        resp[i] = seq.size();
    }
    for(int i=0; i<t; i++) cout<<resp[i]<<endl;
    return 0;
}

/*Problema C
    -N niveis (1 <= N <= 100)
    -Hi HealthPacks
    -Ei Inimigos
    -Ai municao
    -1 <= Hi,Ei,AI <= 10^4
    -Todo nivel eh diferente
    -Printar o nvl mais facil e o mais dificil (1 soh se N=1)
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, Hi, Ei, Ai;
    int MaxV=-100000, MinV=100000, MaxL = 0, MinL=0;
    cin>>N;
    if(N==1){
        cout<<"Easiest and Hardest is level 1";
        return 0;
    }

}

/*Enunciado de merda, codigo resolve o problem errado
//prioridade Hi=3, Ei=2, Ai=1

int main(){
    int N, Hi, Ei, Ai;
    int MaxV=-100000, MinV=100000, MaxL = 0, MinL=0;
    cin>>N;
    if(N==1){
        cout<<"Easiest and Hardest is level 1";
        return 0;
    }
    for(int i=0; i<N; i++){
        scanf("%d %d %d", &Hi, &Ei, &Ai);
        if(3*Hi - 2*Ei + Ai > MaxV){
            MaxV = 3*Hi - 2*Ei + Ai;
            MaxL = i;
        }
        if(3*Hi - 2*Ei + Ai < MinV){
            MinV = 3*Hi - 2*Ei + Ai;
            MinL = i;
        }
    }
    printf("Easiest is level %d \nHardest is level %d", MaxL+1, MinL+1);
    return 0;
}
*/
