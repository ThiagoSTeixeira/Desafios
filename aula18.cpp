//Aula 18

/*Problema A
    -n ranks
    -d[i] anos pra subir de i pra i+1
*/
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