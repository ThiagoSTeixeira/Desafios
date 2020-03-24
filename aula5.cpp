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

/*Problema A
    -n estudantes
    -rating do iesimo estudante = a[i]
    -formar um time de k estudantes com ratings distintos
    -se for impossivel print "NO", caso contrario "YES" e dps os indices
    -se tiver multiplas solucoes printar qualquer uma
    - 1 <= k <= n <= 100
    - 1 <= a[i] <= 100
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> indices;
    
    for(int i=0; i<n; i++) cin>>a[i];

    sort(a.begin(), a.end());
    indices.push_back(); //incompleta
    
    for(int i=1; i<n; i++){
        if(a[i] != a[i-1])
    }
    if(a.size() >= k){
        cout<<"YES"<<endl;
        for(int i=0; i<k; i++) cout<<a[i]<<" ";
    }
    return(0);
}


