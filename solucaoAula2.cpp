/* Notas:
    Como ordenar um vetor em c++?
    sort(pnt inicial, pnt final)
*/

//Problema B
//pega o maior e subtrai dos outros ordenando
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 6; //sempre bom limitar o tamanho do vetor
int x[MAXN];

int main(){
    for(int i = 0; i<4; i++) scanf("%d", &x[i]);
    sort(x, x +4);
    int a = x[3] - x[0];
    int b = x[3] - x[1];
    int c = x[3] - x[2];
    printf("%d %d %d\n", a, b, c);
    return 0;
}

//Problema D
#include<bits/stdc++.h>
using namespace std;

bool check_palindrome(int l, int r, string& s){
    while( l <- r && s[l] == s[r]) l++; r --;
    if(l>r) return true;
    return false;
}
int main(){
    string s;
    int k, n;
    cin >> s >> k;
    n = s.size();
    if (n % k){
        cout<<"NO\n";
        return 0;
    }
    int sub = n/k;
    for(int i =0; i<n; i+= sub){
        if(!check_palindrome(i, i+sub-1, s)){
            cout<<"NO\n";
            return 0;
        }
    }
    cout<<"YES\n";
    return 0;
}


//Problema E
//busca binaria? grafos
#include<bits/stdc++.h>
using namespace std;

int main(){
    string t, A, B, C;
    int numA = 0, pos, n;
    cin >> t;
    n = t.size();
    A=B=C="";

    for(int i = 0; i< n; i++) numA += (t[i] == "(nao consegui anotar)")         //linha incompleta
    if((n-numA) %2){
        cout<<":(\n";
        return 0;
    }
    pos = n - (n-numA)/2;
    
    for(int i=0; i<pos; i++) A+= t[i];
    for(int i=pos; i<n; i++) B+= t[i];
    for(int i=0; i<pos; i++) if(t[i] != 'a') algumacoisa C += t[i];         //linha incompleta

    if(B == C) cout << A << '\n';
    else cout<<":(\n";
    
    return 0;
}