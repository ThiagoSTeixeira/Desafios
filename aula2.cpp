//Aula 2
/**/
//Problema A
#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int n, result, acount = 0;
    cin>>s;
    n = s.size();
    for(int i = 0; i<n; i++){
        if (s[i] == 'a' || s[i] == 'A') acount++;
    }
    if(n/2 >= acount) result = acount*2 - 1;
    else result = n;

    cout<<result;
    return 0;
}

//Problema B
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 6; //sempre bom limitar o tamanho do vetor
int x[MAXN];

int main(){
    for(int i = 0; i<4; i++) scanf("%d", &x[i]);
    sort(x, x +4);          //nao necessariamente precisa ordernar, pode soh encontrar o maior
    int a = x[3] - x[0];
    int b = x[3] - x[1];
    int c = x[3] - x[2];
    printf("%d %d %d\n", a, b, c);
    return 0;
}

//Problema C
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, x, y, a, b;
    cin>>t;
    int resp[t] = {-1};
    for(int i = 0; i<t; i++){
        cin>> x >>y >> a >> b;
        for(int j=0; j<y; j++){
            if (x==y){ 
                //cout<<j<<endl;
                resp[i]=j;
                cout<<j<<"<"<<endl;
                break;
            }
            if(x>=y){
                //cout<< -1 << endl;
                resp[i]= -1;
                cout<<-1<<"<"<<endl;
                break;
            }
            x+=a;
            y-=b;
        }
    }
    for(int i=0; i<t;i++) cout<<resp[i]<<endl;
    return 0;
}

