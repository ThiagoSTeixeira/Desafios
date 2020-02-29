/*Dicas:
    site cppreference.com 

 */
//Problema A
#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    int k;
    cin>> n;
    cin >> k;
    for(int i = 0; i<k; i++){
        if(n%10 != 0) n -=1;
        else n = n/10;
    }
    cout<< n;
    return 0;
}

//Problema B
//Usar Hash?? Dicionario