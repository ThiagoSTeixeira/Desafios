/*Aula 11
    Dicas:
        -Pessoal, pra quem ta fazendo a aula 11, o B e o C 
        não envolvem nada difícil, e o D e E envolvem grafos

*/
//Problema A
#include<bits/stdc++.h>
using namespace std;

int main(){
    string palavra;
    bool sussu=false;
    while(cin>>palavra){
        if(palavra == "Sussu" || palavra == "Sussu!"|| palavra == "Sussu.") sussu = true;
    }
    if(palavra.back() == '?'){
        cout<<"7"<<endl;
        return 0;
    }
    if(sussu){
        cout<<"AI SUSSU!"<<endl;
        return 0;
    }
    cout<<"O cara é bom!"<<endl;
    return 0;
}
/*Problema B
    -Mesa 10m x 10m
    -Q querys (Q<= 5000)
    -Query A = coloca prato cm centro em (x, y) e raio r
    -Query B = remove o prato cm centro (x, y) e raio r
    -0 <= x,y <=1000 && 1<=r<=1000
    -Equacao da circunferencia-> (x-x0)^2 + (y-y0)^2 = r^2
*/
#include<bits/stdc++.h>
using namespace std;

bool encaixa(int x, int y, int r, int x0, int y0, int r0){
    return(r0 == 0 || !(sqrt(pow(abs(x-x0), 2) + pow(abs(y-y0), 2)) < r+r0));
}
int main(){
    int Q, tempX, tempY, tempR;
    char type;
    cin>>Q;
    vector<int> x(Q, 0);
    vector<int> y(Q, 0);
    vector<int> r(Q, 0);
    vector<bool> ans(Q, false);
    for(int i=0; i<Q; i++){
        cin>>type>>tempX>>tempY>>tempR;
        if(type == 'R'){
            for(int j=0; j<Q; j++){
                if(x[j]==tempX && y[j]==tempY && r[j]==tempR){
                    x[j]=y[j]=r[j]=0;
                    ans[i] = true;
                }
            }
        }
        if(type == 'A'){
            ans[i] = true;
            for(int j=0; j<Q; j++){
                if(!encaixa(tempX, tempY, tempR, x[j], y[j], r[j])){
                    ans[i] = false;
                    break;
                }
            }
            if(ans[i]){
                x[i] = tempX;
                y[i] = tempY;
                r[i] = tempR;
            }
        }
    }
    for(int i=0; i<Q; i++){
        if(ans[i]) cout<<"Ok"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
/*Problema C
    -numero minimo de flips para ordenar
    -igual ao numero de numeros invertidos!
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    while(scanf("%d", &N) != EOF){
        int resp = 0;
        vector<int> arr(N);
        for(int i=0; i<N; i++) cin>>arr[i];
        for(int i=0; i<N; i++){
            for(int j=i; j<N; j++){
                if(arr[j]<arr[i]) resp++;
            }
        }
        if(N>1) cout<<"Minimum exchange operations : "<<resp<<endl;
        else cout<<"Minimum exchange operations : "<<0<<endl;
    }
    return 0;
}

/*Problema D
    -encontrar o caminho com o minimo de curvas
    -usar DFS em um grafo?
*/

//SOLUCAO DA AULA
#include <bits/stdc++.h>
using namespace std;
 
#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair
 
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
 
const int MAX = 1123;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;
 
int n, m;
char g[MAX][MAX];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int d[MAX][MAX][4];
bool check (int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < m);
}
 
int main () {
    pii resp = pii(-1, -1);
    pii st = pii(-1, -1);
    memset(d, INF, sizeof(d));
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
	for (int j = 0; j < m; j++) {
	    scanf (" %c", &g[i][j]);
	    if (g[i][j] == 'S') st = pii(i, j);
	    if (g[i][j] == 'T') resp = pii(i, j);
	}
    }
    for (int i = 0; i < 4; i++) 
	d[st.first][st.second][i] = 0;
    
    queue< pair<int, pii> > Q;
 
    Q.push(mp((0), st));
    Q.push(mp((1), st));
    Q.push(mp((2), st));
    Q.push(mp((3), st));
 
    while (!Q.empty()) {
	pii u = Q.front().second;
	int dir = Q.front().first;
	int dist = d[u.first][u.second][dir];
	
	for (int k = 0; k < 4; k++) {
	    int ni = u.first + dx[k];
	    int nj = u.second + dy[k];
	    int nd = (k == dir) ? 0 : 1;
	    if (check(ni, nj) && g[ni][nj] != '*') {
		if (dist + nd < d[ni][nj][k]) {
		    d[ni][nj][k] = dist + nd;
		    Q.push(mp((k), pii(ni,nj)));
		}		
	    }	    
	}
	Q.pop();
    } 
    int p = INF;
    for (int k = 0; k < 4; k++) p = min(p, d[resp.first][resp.second][k]);
    
    printf ("%s\n", (p <= 2) ? "YES" : "NO");
    return 0;
}
 