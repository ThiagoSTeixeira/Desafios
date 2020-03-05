/*Dicas:
    site cppreference.com 
    Inicializem containeres da STL antes  de adicionar coisas. Por exemplo

    string a;
    a[0] = 'b'; // ou a[i] = 'b'

    Estaria errado pois não existe "a[0]". O mesmo vale para

    vector<int> v;
    v[0] = '1';

    string eh um vector<char>, então você pode dar "push_back" para adicioanr um elemento ou inicializar com um tamanho. Por exemplo:

    string a = "";
    a.push_back('b'); // estaria correto
    ou
    string a = "";
    a += 'b';
    ou ate
    vector<int> v(n); // onde n eh o tamanho q vc quer;
    v[0] = 1; // ou v[i] tambem funciona

    É recomendável utilizar as estruturas da STL (set, map, vector, multiset, ou até mesmo list se quiser usar lista ligada).
 
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

//Problema C
    //Sequencia de Inteiros de tamanho n (2x10^5)
    //inteiro k
    //print x 10^9(long long) tq k elementos sejam <= x
#include<bits/stdc++.h>
using namespace std;

int main(){
    unsigned long int n;
    int k;
    cin>>n>>k;
    unsigned long int v[n];
    for(int i=0; i<n; i++) cin>>v[i];
    sort(v, v+n);
    if(k==0){
        if(v[0]>1) cout<<1;
        else cout<<-1;
        return 0;
    }
    if(v[k-1] == v[k]) cout<< -1;
    else cout<<v[k-1];
    return 0;
} 

//Problema D
//encontrar o caminho e dps fazer ida e volta?
//considerar casos em que o numero eh impar para nao acabar fora do quadrado
//tem que ter exatamente k movimentos por isso no exemplo eh 1
*/
//Problema E

//NAO FUNCIONA!!
#include<bits/stdc++.h>
#include <functional>
using namespace std;

int main(){
    int n;
    long long int numeros[n];
    long long int resposta[n];
    cin>>n;
    for(int i = 0; i<n; i++) cin>>numeros[i];
    sort(numeros, numeros+n);
    for(int j=0; j<n; j++){
        if(j==0) resposta[0] = numeros[n-1];
        else{
            for(int k = 0; k<n; k++){
                if(numeros[k]==resposta[j-1]/3){
                    resposta[j] = numeros[k];
                    break;
                }
                else if(numeros[k] == resposta[j-1]*2){
                    resposta[j] = numeros[k];
                    break;
                }
            }   
        }
    }
    //cout<<"oi"<<endl;
    cout<< resposta[0];
    for(int z=0; z<n; z++) printf("%Ld ", resposta[z]); 
    return 0;
}
