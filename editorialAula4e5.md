## Editorial Aula 4 e 5

## Aula 4

# Problema A 
 Para encontrarmos a string S de tamanho minimo que contenha exatamente K vezes a string T, basta encontrarmos o breakpoint em que o inicio da string T eh contida em seu final (Isto eh, o primeiro indice i > 0 tal que s[i...n] = s[j...(n - i)]). Isso chama-se funcao prefixo, e podemos calcula-la de forma linear como KMP faz (https://en.wikipedia.org/wiki/Knuth-Morris-Pratt_algorithm) ou de forma quadratica, com dois for loops encadeados. Apos encontrar esse breakpoint, basta concaternamos a string T a ela mesma, pulando os i primeiros caracteres.

# Problema B
Podemos encontrar a resposta de forma gulosa, encontrando os conjuntos em que a[i] <= a[i - 1]*2. Basta iterarmos no vetor, verificando se a condicao a[i] <= a[i - 1]*2 vale, em caso positivo adicionamos 1 a nossa candidata a resposta atual, e em caso negativo vemos se a candidata a reposta atual eh maior que a resposta que ja temos.

# Problema C
  Podemos calcular de forma gulosa quantos "skips" seriam necessarios para matar cada monstro. Para isso podemos ler a vida de todos os monstros e calcular a vida modulo a + b, para saber o quando de vida o monstro teria depois do ultimo ataque de b. Se for 0, precisamos somar a + b. Entao vemos se a vida restante do monstro for menor que a, precisamos de 0 skips, senao precisamos de (h[i] - 1) / a (Chegamos a esse resultado subtraindo o teto da divisao de h[i] por a de 1). Entao matamos primeiro os monstros que conseguimos matar com a menor quantidade de skips, adicionando eles a resposta. 

# Problema D
  Para esse problema precisamos primeiro notar que a interseccao maximal entre os segmentos [(L_1, R_1), ..., (L_n, R_n)] eh o segmento (max L, min R) (Se o segmento nao for degenerado). Podemos encontrar o segundo maior L e o segundo menor R e tentar remover os respectivos segmentos. Alternativamente, podemos calcular o maximo prefixo de L e maximo sufixo de L (mesmo para minimo prefixo de R e minimo sufixo de R) e calcular a resposta removendo cada um dos elementos.
​       
# Problema E
  Esse problema envolvia Teoria dos numeros e aritmetica modular. Primeiro precisamos perceber que a concatecacao dos numeros X e Y eh X * 10^(dig(Y)) + Y se dig(Y) for a quantidade de digitos em Y. Entao podemos perceber que dois numeros X e Y concatenados sao divisiveis por k se e somente se [X * 10^(dig(Y)) + Y] % k == 0. Isso pode ser reescrito da forma X * 10^(dig(Y)) = -Y modulo K. Entao podemos calcular [a[i] * 10^j] % k para todo j entre 0 e 10, e contamos quantos sao iguais a cada valor entre [0, k) para cada j. E entao podemos iterar por todos os a[i], calcular a quantidade de digitos de a[i] e o valor de -a[i] mod k (Podemos fazer (-(a[i] % k) + k) % k) e ir somando a resposta a quantidade de elementos que sao iguais a -a[i] mod k precalculados anteriormente (Podemos ter guardado numa tabela e checar cnt[dig(a[i])][-a[i] mod k]). Precisamos nos atentar para nao contar o par (i, i), entao precisamos checar se a[i] * 10^(dig(a[i])) == -a[i] mod k.
  Outra forma de contar eh criando 10 vetores, para guardar os a[i] * 10^j e fazer busca binaria neles no outro passo para contar quantos elementos sao iguais.

## Aula 5

# Problema A 
  Todos fizeram. Caso tenha duvidas entrar em contato.

# Problema B
  Podemos ordenar as strings pelo seu tamanho, e entao verificamos se para todo i > 0, S[i - 1] eh substring de S[i] (Isso eh, se existe um j tal que S[i - 1][0...n] == S[i][j...j+n]).

# Problema C
  Podemos guardar para cada elemento em cada sequencia uma tripla (soma, sequencia_i, elemento_j). Podemos guardar essa tripla no formato de um mapa de (soma -> (sequencia_i, elemento_j)). Entao calculamos as somas de uma sequencia, e entao iteramos por todos os elementos da sequencia preenchendo esse mapa. Se a posicao do mapa ja esta preenchida, encotramos um par. Se terminamos esse processo sem encontrar um par eh por que nao tem resposta.

# Problema D
  Para esse problema precisamos primeiro perceber que a resposta esta entre 1 e 3. Podemos perceber isso tentando encontrar uma resposta para 3 elementos. Vamos supor que temos 3 elementos a, b e c (a < b < c). se dist(a, b) = 2^i e dist(b, c) = 2^j temos que dist(a, c) = 2^i + 2^j = 2^k (Entao i == j). Se supormos 4 elementos (a < b < c < d) essa condicao deveria valer para a tripla (b, c, d) tambem, entaoteriamos dist(c, d) = 2*k e dist(a, d) = 3 * 2^i (O que claramente nao eh uma potencia de 2).

  Entao podemos iterar por todos os elementos e todas as potencias de 2, de 0 a 30. Podemos assumir que o elemento que estamos iterando por eh o elemento do "meio" e entao checamos se x[i] - 2^j e x[i] + 2^j estao no vetor x. Em caso positivo temos uma resposta de tamanho 3. Se somente x[i] - 2*j ou x[i] + 2^j estiverem no vetor temos uma resposta de tamanho 2. Em caso de nenhum deles estarem no vetor nossa resposta tem tamanho 1 (que eh qualquer elemento do vetor). 

# Problema E
  Para esse problema podemos usar DFS ou BFS para achar todas as "componentes" do nosso labirinto. Podemos pensar nesse labirinto como um grafo, onde cada no aponta para exatamente 1 elemento. Entao iteramos por cada no iniciando uma DFS ou BFS se o no nao foi marcado ainda e marcamos os outros nos visitados com o numero da iteracao que estamos. Para cada DFS ou BFS que nao chega em no marcado na iteracao atual, somamos 1 a resposta. Pode-se fazer tambem com union-find.

- Obs: Foi notado que alguns alunos estao se utilizando de solucoes e editoriais extra classe para resolver os problemas durante a primeira semana. A partir da aula de hoje (Aula 7) isso sera estritamente proibido. Se, a partir da aula 7 o aluno escolher ler um editorial ou buscar a solucao do problema online durante a primeira semana, ele pode admitir que viu o editorial ou solucao e o problema passa a valer metade da nota (Como se fosse da segunda semana). Nao eh recomendado fazer isso, mas o aluno tem a escolha. Se o Aluno ver editorial ou solucao e nao admitir e for descoberto, ele zera a prova e pode sofrer consequencias depois.