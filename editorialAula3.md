## Editorial Aula 3

# Problema C

Primeiro precisamos ordenar o vetor dado, então temos alguns casos. Se k = 0 então a única reposta possível é (v[0] - 1) (Se v[0] - 1 for maior ou igual que 1). Se k = n, então a resposta pode ser INF (ou v[k] + 1). Senão a resposta pode ser v[k] - 1 e precisamos verificar se v[k - 1] - 1 é menor ou igual ao nosso valor e se v[k] - 1 é maior ou igual que 1.

# Problema D

Esse problema tem vários casinhos, vamos tentar bolar uma estratégia. Primeiro vamos tentar chegar na posição dada o mais rápido possível, para isso vemos qual é maior (n ou m, podemos tirar o máximo por exemplo), então vamos até min(n, m) pulando em diagonais e o que sobra (se sobrar) é uma linha reta. Vemos se a distancia (n + m - min(n, m)) é maior que K, nesse caso não conseguimos chegar a tempo. Caso contrário, basta basta somar [D - (D%2)] (Isto é, D caso D é par e D - 1, caso D é impar) na resposta, pois podemos seguir a linha reta andando no máximo de diagonais. O que sobra podemos ficar indo e voltando na diagonal (caminho + resto). Caso o resto seja par, basta somar o resto na resposta. Caso o resto não seja par e a distancia em linha reta seja par, temos que transformar um dos passos "diagonais" em passos "retos" então nossa resposta é max(caminho - 1, 0) + max(resto - 1, 0). caso contrário, signfica que nosso resto e nossa diagonal sao impares, entao podemos transformar um passo reto em um passo diagonal logo nossa resposta seria caminho + resto novamente.

# Problema E

Esse problema tem diversas soluções, sendo simular com diversos inícios uma dela. Seja deg3(x) a quantidade de fatores 3 em um numero x (isto eh, o maior y tal que 3^y | x). A solução mais simples é perceber que se existe uma ordem que seja a resposta ela deve respeitar o fato que deg3(a_i) >= deg3(a_[i+1]) e em caso de igualdade eles devem ser colocados em ordem crescente (para podermos "Multiplicar por 2"), podemos tambem usar o fator 2 como criterio de desempate.