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

/*Problema B
    -a1, a2
    -k1, k2
    -n

    2 3
    5 1
    8
    -printar max e min
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int a1, a2, k1, k2, n;
    int maxi, min;
    cin>>a1>>a2>>k1>>k2>>n;
    int maxB4Out = a1*(k1-1) + a2*(k2-1); //maximo de cartoes antes de haver expulsao
    min = max(0, n-maxB4Out);
    if(k1<=k2){
        int cart = k1*a1;
        if(n<cart) maxi = n/k1;
        else{
            n-=a1*k1;
            maxi = a1 + n/k2;
        }
    }
    if(k1>k2){
        int cart = k2*a2;
        if(n<cart) maxi = n/k2;
        else{
            n-=a2*k2;
            maxi = a2 + n/k1;
        }
    }
    cout<<min<<" "<<maxi;    
}
/*Problema D
*/

