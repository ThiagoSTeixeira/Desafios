//Programa teste AULA 1 18/02
#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", a+b);
    return 0;
}

//Programa exemplo final da aula  (halfstring?? printar um sim um nao ate metade da palavra)

//string em c++ eh um vetor de char!

#include<bits/stdc++.h>
using namespace std;
int MAXN = 105;
string w[MAXN];

int main(){
    int n;
    cin >>n;
    
    for (int i=0; i<n; i++){
        cin>>w[i];
    }
    for (int i=0; i<n; i++){
        int word_size = w[i].size();
        for(int j=0; i<word_size/2; j+=2){
            cout<<w[i][j];
        }
        cout<<"\n";
    }
return 0;
}
