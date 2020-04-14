/*Aula 12
    Teoria dos numeros e combinatoria
*/

/*Problema A
    -T casos
    -a, b jogadores em cada time (0<=a,b<=10^9)
    -devolver ok ou a divisao mais correta(x<=y)
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    long long int total;
    cin>>T;
    vector<int> a(T);
    vector<int> b(T);
    for(int i=0; i<T; i++) cin>>a[i]>>b[i];
    for(int i=0; i<T; i++){
        if(a[i]==b[i] || a[i]==b[i]-1 || a[i]==b[i]+1) cout<<"Ok\n";
        else{
            total = a[i]+b[i];
            if(total%2 != 0) cout<<total/2<<" "<<(total/2)+1<<endl;
            else cout<<total/2<<" "<< total/2<<endl;
        }
    }
    return 0;
}



