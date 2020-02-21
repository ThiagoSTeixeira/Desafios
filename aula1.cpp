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
}
/**/
//Programa E Aula 1
#include<bits/stdc++.h>
#include<string>

using namespace std;
int main(){