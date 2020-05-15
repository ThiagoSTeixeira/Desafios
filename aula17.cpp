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
    return 0;
}
/*Problema B
    -n habitantes (1<=n<= 10^5)
    -T test cases (1<=T<=1000)
    -a[i] dinheiro de cada habitante (1<=a[i]<=10^9)
    -x dinheiros = rico (1<=x<=10^9)
    -governo cata o dinheiro de alguns habitantes,
    soma e divide igual entre eles
    -encontrar o maximo possivel de pessoas ricas
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, rico;
    cin>>n>>rico;
    vector<int> dinheiros(n);

    return 0;
}
