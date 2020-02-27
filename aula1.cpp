//Programa A AULA 1 18/02

#include<bits/stdc++.h>
using namespace std;

int main(){
    int w;
    scanf("%d", &w);
    if( w%2 == 0) printf("YES");
    else printf("NO");
    return 0;
}

//Programa C Aula 1 

#include<bits/stdc++.h>
using namespace std;
long long n,sum;
int main()
{
    cin>>n;
    sum=n+1;
    if(sum==1)
    {
        cout<<"0"<<endl;
        return 0;
    }
    else{
    if(sum%2==0)cout<<sum/2;
    else cout<<sum;
    return 0;
}
}

//Programa D Aula 1

#include<bits/stdc++.h>
#include<string>

using namespace std;
int main(){
    int n;
    string s;
    bool counting = false;
    int count=0, Tcount = 0;
    cin>>n;
    string v[n];
    for(int i=0; i<n; i++){
        cin>> s;
        v[i]= s;
    }     
    for(int i=0; i<n; i++){
        s = v[i];
        int len = (s.size());
        for(int j=0; j<len; j++){
            if (s[j] == '1' && !counting) counting = true;
            if (counting && s[j]== '0') count++;
            if (counting && s[j]=='1'){
                Tcount += count;
                count = 0;
            } 
        }
        cout<<Tcount<<endl;
        Tcount =0;
        count =0;
        counting = false;   
    }
    return 0;
}

//Programa E Aula 1 
/*Tabs de l ate r (inclusivo)
  cursor em pos-th
    Acoes:
    Esquerda ou Direita
    MaxEsq ou MaxDir
    DelEsq ou DelDir

    printar segundos
  */
#include<bits/stdc++.h>
#include<string>

using namespace std;
int main(){
    int v[4];
    for(int i=0; i<4; i++) cin>>v[i];
    int a=1, b=v[0];       //a= menor, b= maior
    int segundos = 0;
    int pos = v[1], l=v[2], r=v[3];
    while(a != l && b != r){
        if(pos-l< r-pos && l != a){       //escolhe esquerda primeiro
            if(1+l < pos-l) segundos += l+2;    //maxEsq
            else segundos += pos - l+1;       //1 por 1
            cout<< segundos << endl;
            cout<<"em cima";
            a = l;
            pos = l;
        }
        else{                   //escolhe direita primeiro
            if(b-r+1 < r - pos && b != r) segundos += b-r+2;
            else segundos += r-pos +1;
            cout<<segundos<< endl;
            cout<<"embaixo";
            b=r;
            pos =r;
        }
    }
    //cout<<segundos;
    return 0;
}