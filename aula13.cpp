/*Aula 13
*/

/*Problema A
    -Lucky digits(LD) = 4 7
    -Lucky number(LN) = numero composto de apenas LD
    -Nearly lucky number(NLN) = numero de LDs eh LN
    -Decidir se n eh NLN (1<=n<=10^18)
*/
#include<bits/stdc++.h>
using namespace std;
int countLD(long long n){
    string ns = to_string(n);
    int count=0;
    for(int i=0; i<ns.size(); i++) {
        if (ns[i] == '7' || ns[i] == '4') count ++;
    }
    return count;
}
int main(){
    long long n;
    cin>>n;
    int LDs = countLD(n);
    string ns = to_string(LDs);
    for(int i=0; i<ns.size(); i++){
        if(ns[i] != '7' && ns[i]!='4'){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}
