/*Aula 17
    -Cuidado com o input do C, usar gets ou getline
*/

/*Problema A
    -t casos (1<=t<=10^4)
    -int a, b
    -1 movimento -> a+=1
    -quantos movimentos ate a divisivel por b
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, a, b;
    cin>>t;
    vector<int> ans(t);
    for(int i=0; i<t; i++){
        cin>>a>>b;
        int cont = 0;
        if(a<=b) ans[i] = b-a;
        else if(a%b == 0) ans[i] = 0;
        else ans[i] = b-a%b;
    }
    for(int i=0; i<t; i++) cout<<ans[i]<<endl;
}

