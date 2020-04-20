#include<bits/stdc++.h>
using namespace std;

const int MAX = 112;

vector<int> adj[MAX];
int mrk[MAX], color[MAX];

// O(V + E)
bool dfs(int u) {
   if (!color[u]) color[u] = 1;
   mrk[u] = 1;

   for (int v : adj[u]) {
      if (!mrk[v]) {
         color[v] = (color[u] == 1) ? 2 : 1;
         bool biparted = dfs(v);
         if (!biparted) return biparted;      
      } else if (color[v] == color[u]) {
         // Deu ruim!
         return false;
      }
   }

   return true;
}


// O(V + E);
bool bfs(int x) {
   queue<int> Q;
   Q.push(x);
   mrk[x] = 1;
   color[x] = 1;
   
   while (!Q.empty()) {
      int u = Q.front();
      Q.pop();
      
      for (int v : adj[u]) {
         if (!mrk[v]) {
            color[v] = (color[u] == 1) ? 2 : 1;
            mrk[v] = 1;
            Q.push(v);
         } else if (color[u] == color[v]) {
            return false;
         }         
      }      
   }

   return true;
}


int main() {
   int n, m;

   int inst = 1;
   
   while (scanf("%d%d", &n, &m) != EOF) {
      memset(mrk, 0, sizeof(mrk));
      memset(color, 0, sizeof(color));
      
      for (int i = 0; i < m; i++) {
         int u, v;
         scanf("%d %d", &u, &v);

         adj[u].push_back(v);
         adj[v].push_back(u);
      }

      //bool ok = dfs(1);
      bool ok = bfs(1);
      printf("Instancia %d\n", inst++);
      if (ok)
         puts("sim");
      else
         puts("nao");
      printf("\n");
      for (int i = 0; i <= n; i++)
         adj[i].clear();
   }
   return 0;
}
