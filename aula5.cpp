/* Aula 5
Dicas:
    Pessoal, um problema da Aula 5 exige conhecimentos de grafo (spoiler: é o E). 
    Não deu tempo de ensinar como andar num grafo e como vai ter jubileu do IME e
    contest durante a proxima aula vou deixar alguns links aqui (Ambas buscas funcionam):

    - Busca em profundidade: https://pt.wikipedia.org/wiki/Busca_em_profundidade

    - Busca em Largura: https://pt.wikipedia.org/wiki/Busca_em_largura

    - Aula de DFS/Grafos do BixeCamp do IME: https://www.youtube.com/watch?v=qTRO41yezFs&t=3179s


    Peço desculpas por não passar esse conteúdo em aula, teve umas dúvidas no começo
    (O que é maravilhoso, semrpe perguntem) e tive que falar com a Cris. Qq coisa estamos aí.
*/

////////SOLUCAO AULA 5 -- VINDA DO EDITORIAL ///////////////

//PROBLEMA A
#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n, k;
	cin >> n >> k;
	set<int> el;
	vector<int> ans;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		if (!el.count(x)) {
			ans.push_back(i);
			el.insert(x);
		}
	}
	
	if (int(ans.size()) < k) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
		for (int i = 0; i < k; ++i)
			cout << ans[i] + 1 << " ";
		cout << endl;
	}
	
	return 0;
}

//PROBLEMA B
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n;
	cin >> n;
	vector<string> s(n);
	for (int i = 0; i < n; ++i)
		cin >> s[i];
		
	sort(s.begin(), s.end(), [&] (const string &s, const string &t) {
		return s.size() < t.size();
	});
	
	for (int i = 0; i < n - 1; ++i) {
		if (s[i + 1].find(s[i]) == string::npos) {
			cout << "NO\n";
			return 0;
		}
	}
	
	cout << "YES\n";
	for (auto it : s)
		cout << it << endl;
	
	return 0;
}

//PROBLEMA C
#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int k;
	cin >> k;
	vector<pair<int, pair<int, int>>> a;
	for (int i = 0; i < k; ++i) {
		int n;
		cin >> n;
		vector<int> x(n);
		for (int j = 0; j < n; ++j)
			cin >> x[j];
		int sum = accumulate(x.begin(), x.end(), 0);
		for (int j = 0; j < n; ++j)
			a.push_back(make_pair(sum - x[j], make_pair(i, j)));
	}
	
	stable_sort(a.begin(), a.end());
	for (int i = 0; i < int(a.size()) - 1; ++i) {
		if (a[i].first == a[i + 1].first && (a[i].second.first != a[i + 1].second.first)) {
			cout << "YES" << endl;
			cout << a[i + 1].second.first + 1 << " " << a[i + 1].second.second + 1 << endl;
			cout << a[i].second.first + 1 << " " << a[i].second.second + 1 << endl;
			return 0;
		}
	}
	
	cout << "NO\n";
	
	return 0;
}

//PROBLEMA D

#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n;
	cin >> n;
	vector<int> x(n);
	for (int i = 0; i < n; ++i) {
		cin >> x[i];
	}
	
	sort(x.begin(), x.end());
	vector<int> res = { x[0] };
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 31; ++j) {
			int lx = x[i] - (1 << j);
			int rx = x[i] + (1 << j);
			bool isl = binary_search(x.begin(), x.end(), lx);
			bool isr = binary_search(x.begin(), x.end(), rx);
			if (isl && isr && int(res.size()) < 3) {
				res = { lx, x[i], rx };
			}
			if (isl && int(res.size()) < 2) {
				res = { lx, x[i] };
			}
			if (isr && int(res.size()) < 2) {
				res = { x[i], rx };
			}
		}
	}
	
	cout << int(res.size()) << endl;
	for (auto it : res)
		cout << it << " ";
	cout << endl;
	
	return 0;
}

//PROBLEMA E
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define mod 1000000009
char opposite[200];
bool valid(int x , int y , int n , int m){
    if(x >=0 && y>=0 && y< m && x<n)
        return true;
    return false;
}
int main(){
    int n , m;
    scanf("%d%d",&n , &m);
    char arr[n+9][m+9];
    for(int i = 0 ; i < n ; i++)
        scanf("%s",arr[i]);
    int count = 0 , check[n+9][m+9];
    memset(check , 0 , sizeof check);
    int prev = 0 , color=0;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            queue<pii >q;
            q.push(mp(i , j));
            vector<pii > path;
            path.pb(mp(i , j));
            if(!check[i][j]){
                color = prev + 1;
                check[i][j] = color;
                while(!q.empty()){
                    pii pos = q.front();
                    q.pop();
                    int x = pos.first , y = pos.second;
                    if(arr[x][y] == 'S')
                        x++;
                    else if(arr[x][y] == 'E')
                        y++;
                    else if(arr[x][y] == 'N')
                        x--;
                    else if(arr[x][y] == 'W')
                        y--;
                    if(valid(x , y , n , m) && check[x][y] == 0){
                        path.pb(mp(x , y));
                        q.push(mp(x , y));
                        check[x][y] = color;
                    } else if(valid(x , y , n , m) && check[x][y]!=0){
                        int save = check[x][y];
                        if(check[x][y] < color){
                            for(int p = 0 ; p < path.size() ; p++)
                                check[path[p].first][path[p].second] = check[x][y];
                        }
                        color =save;
                        break;
                    }
                }
                if(color>prev)
                    prev++;
            }
        }
    }
    cout<<prev<<endl;
    return 0;
}