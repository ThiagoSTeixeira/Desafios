/*NOTAS:
Para encontrar o teto: int(ceil(x/n)) ou (x+n-1)/n !!!!
*/
#include<bits/stdc++.h>
using namespace std;

/*Programa D
Bastava contar a quantidade de zeros antes do primeiro 1 e depois do ultimo 1, e depois subtrair da quantidade total de zeros
*/

//Programa E

int main(){
    int n, pos, l, r;
    cin >> n >> pos >> l >> r;
    int op1 = abs(r - pos);
    int op2 = abs(l- pos);
    
    if (l != 1 && r !=n){
        cout<<min(op1, op2) + r -l + 2 << endl;
        //incompleto
    }
}