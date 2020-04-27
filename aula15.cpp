//Aula 15

/*Problema A
    -n Dragoes (1 <= 1000)
    -Duelos determinados pela strength
    -Kirito tem s de strength (1 <= 10^4)
    -Strength do drag i = x[i]
    -Bonus de forca = y[i]
    -(1 <= x[i],y[i] <= 10^4)
*/
#include<bits/stdc++.h>
using namespace std;
//sort por struct
struct drag{
    int x;
    int y;
};
bool ordenaForca(drag d1, drag d2){
    return d1.x<d2.x;
}
int main(){
    int s, n;
    cin>>s>>n;
    vector<drag> drags(n);
    for(int i=0; i<n; i++) cin >> drags[i].x >> drags[i].y;

    sort(drags.begin(), drags.end(), ordenaForca);
    for(int i=0; i<n; i++){
        if(s<=drags[i].x){
            cout<<"NO";
            return 0;
        }
        else s+=drags[i].y;
    }
    cout<<"YES";
    return 0;
}