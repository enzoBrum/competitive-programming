#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;
using pli = pair<ll, int>;


  /**
  
  Essa questão tem 10^4 queries.

  Cada query nos da o conjunto P de peças disponívels (no máximo 21) e faz a seguinte pergunta: 
    quantos subjconjuntos de P representam jogos que pdem ser vencidos?

  Uma solução inocente seria calcular isso diretamente para cada query individual. Isto é, para cada query, percorrer todos os subjconjuntos
  de P e contar explicitamente quais são vencíveis.

  Só tem um pequeno problema? Essa operação seria O(N * 2^N) e seria executada 10^4 no máximo. Devido à grande quantidade de queries, fazer algo assim
  sem levar TLE seria impossível.

  Logo, precisamos de uma estratégia mais eficiente.

  Por exemplo, imagine se pudessemos pré-computar para cada P, a quantidade de subconjuntos dele que resultam em jogos válidos antes de começar a responder as queries.
  Se isso fosse possível, responder cada query seria meramente O(1), visto que bastaria olhar o valor pré computado de P.

  Maasss...como pré-computer isso em tempo hábil???? Afinal, ainda não precisariamos visitar, para cada P, todos os seus subconjuntos individualmente resultando em uma solução
  consideravelmente lenta??

  Algo assim por exemplo:
    for (int mask = 0; mask < (1 << N); ++mask)
      for (int submask = 0; submask < (1 << N); ++submask)
        if ((mask&submask) == submask && is_valid_game(submask))
          dp[mask]++;

  Sim, isso em si ainda seria bastante lento. Literalmente O(4^N), o que nunca iria passarm.
  Mesmo se otimizassemos isso para somente percorrer os subconjuntos de cada mascara, ainda assim teriamos O(3^N), que também não passaria.

  É ai, contudo, que entra a grande sacada dessa questão. Existe uma coisa chamada SOS dp que consegue fazer essa soma de subconjuntos em O(N * 2^N).
  Ao usarmos ela, conseguimos pré-computar tudo em (O * 2^N) e responder as 10^4 queries em O(1), o que com absoluta certeza nos daria AC.

  Abaixo está o código para a solução.
  */

int INF = 1e9;
const int N = 21;
ll INFL = 1e17;

// Peças do jogo de dominó.
pii pieces[N];

// Jogos válidos são aqueles que podem ser vencidos.
// Cada bit dessa máscara corresponde à uma peça do array pieces.
// Se o bit for 1, a peça está sendo usada. Se for 0, não está.
int valid_games[1 << N];

// https://codeforces.com/blog/entry/45223
// dp[mask][i] = quantidade de submáscaras de `mask` que somente diferem nos `i` primeiros bits E representam jogos válidos.
//
// dp[mask][i] = 
//      - SE o iésimo bit de mask for 0, não podemos fazer nada com ele. Afinal, se o setássemos para 1, não seria mais uma submáscara de mask.
//        Logo, neste caso dp[mask][i] = dp[mask][i-1].
//      - SENÃO, podemos setar esse bit para 0 ou para 1. Logo temos que:
//          dp[mask][i] = dp[mask][i-1] (onde o bit continua como 1) + dp[mask ^ (1 << i)][i-1] (onde o bit da máscara agora é zero).
//
// Perceba que isso nos permite calcular a soma de todos os subconjuntos de todos os possíveis subconjuntos P em O(N * 2^N), 
// visto que esse é o número de estados.
int sos_dp[1 << N][N+1];

bool active_vertices[7];
bool matrix[7][7];
int deg[7];
bool visited[7];

/**

  Para saber se um conjunto de peças pode ser resolvido, podemos formar um grafo onde os vértices são os números de 1 até 6 que são utilizados
  por alguma peça e as arestas são as peças de dominó em si.

  e.g: 
      1
     / \
 (1,2) (1,3)
   /       \
  2---(2,3)---3


  Nesse sentido, um jogo de dominó só pode ser vencido quando todas as peças forem utilizadas.
  Em outras palavras, um jogo só pode ser vencido quando **todas as arestas** forem utilizadas.

  Isso quer dizer que para sabermos se o jogo é vencível, basta sabermos se é possível percorrer esse grafo
  começando de um vértico U e indo até um vértice V utilizando todas as arestas de tal grafo uma única vez.

  Acontece que essa é a definição de caminho euleriano e felizmente é bem trivial de checar se um grafo possui essa propriedade.

  Basta checar se o grafo é conectado e o grau de dois vértices é ímpar e o dos demais é par. 
  Só isso já é suficiente para sabermos se o grafo tem caminho euleriano e por conseguência se o jogo pode ser vencido.

  Há ainda grafos onde podemos começar de um vértice U, percorrer todas as arestas e terminar neste mesmo vértice U.
  Tais grafos possuem ciclos eulerianos e também correspondem à jogos que podem ser vencidos.

  Para checar existência de ciclo euleriano, basta ver se todas as arestas possuem grau par e se o grafo está conectado.


  @param mask: submascara representando as peças que serão utilizadas. Bits 1 representam peças utilizadas e bits 0 peças ignoradas.
  @return Se um jogo de dominó com as peças definidas por mask pode ser concluído vencido.
*/
bool is_valid(int mask) {
  if (mask == 0)
    return false;

  // NOTE: observe o uso de arrays aqui. Esse negócio roda 2^21 vezes, se alocarmos memória nova à cada execução vai ficar lento demais e tomamos TLE.
  memset(active_vertices, 0, sizeof active_vertices);
  memset(matrix, 0, sizeof matrix);
  memset(deg, 0, sizeof deg);
  memset(visited, 0, sizeof visited);

  for (int i = 0; i < N; ++i)
    if ((mask&(1 << i)) != 0) {
      auto&[u, v] = pieces[i];
      active_vertices[u] = active_vertices[v] = 1;
      matrix[u][v] = matrix[v][u] = 1;
      deg[u]++, deg[v]++;
    }

  for (int i = 1; i <= 6; ++i) {
    if (!active_vertices[i])
      continue;
    queue<int> q;
    q.push(i);

    visited[i] = true;
    while (q.size()) {
      int u = q.front();
      q.pop();

      for (int v = 1; v <= 6; ++v)
        if (!visited[v] && matrix[u][v])
          q.push(v), visited[v] = true;
    }

    break;
  }

  int odd_degrees = 0;
  for (int i = 1; i <= 6; ++i) {
    if (!visited[i] && active_vertices[i])
      return false;
    if (deg[i] % 2 == 1)
      odd_degrees++;
  }

  return odd_degrees == 0 || odd_degrees == 2;
}


signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  // 21 tipos de peças.
  // Cada peça é única, de modo que só precisamos contar
  // todo par (x, y) dado que 1<=x<=6 e 1<=y<=6 uma única vez.
  //
  // Além disso, os pares não são ordenados, de modo que (x, y) = (y, x).
  int idx = 0;
  map<pii, int> piece_to_idx;
  for (int i = 1; i <= 6; ++i)
    for (int j = i; j <=6; ++j) {
      piece_to_idx[{i, j}] = piece_to_idx[{j, i}] = idx;
      pieces[idx++] = {i, j};
    }

  
  // Agora pré-calculamos cada subconjunto de peças que resulta em um jogo válido.
  // A função can_is_valid tem complexidade linear em relação ao número de peças, enquanto o loop abaixo percorre
  // todos os subconjuntos possíveis de peças.
  //
  // Logo, tudo isso é O(N * 2^N) = 21 * 2^21 ~= 10^7.64. I.e: computável em menos de 1 segundo.
  for (int mask = 0; mask < (1 << N); ++mask)
    if (is_valid(mask))
      valid_games[mask] = 1;
  

  // Tendo todos os jogos válidos, executamos o SOS dp em O(N * 2^N) para obter, para cada conjunto P, a soma de todos os seus subconjuntos.
  // Como conjuntos que representam jogos válidos possuem valor 1 e os demais possuem valor 0, isso nos dá a resposta para a query de P.  
  for (int mask = 0; mask < (1 << N); ++mask) {
    
    if (mask & 1)
      sos_dp[mask][0] = valid_games[mask] + valid_games[mask ^ 1];
    else
      sos_dp[mask][0] = valid_games[mask];

    for (int i = 1; i < N; ++i)
      if (mask&(1 << i)) {
        // Perceba que o estado sos_dp[mask][i-1] foi visitado na iteração anterior, enquanto o estado
        // sos_dp[mask ^ (1 << i)] já foi completamente concluída anteriormente no loop exterior.
        //
        // Isso é verdade pois (mask ^ (1 << i)) < mask, de modo que ele já foi visitado anteriormente.
        sos_dp[mask][i] = sos_dp[mask][i-1] + sos_dp[mask ^ (1 << i)][i-1];
      } else {
        sos_dp[mask][i] = sos_dp[mask][i-1];
      }
  }


  // Tendo pré-calculado tudo, agora é só responder as queries.
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    int mask = 0;
    while (n--) {
      int u, v;
      cin >> u >> v;

      mask = mask | (1 << piece_to_idx[{u, v}]);
    }

    cout << sos_dp[mask][N-1] << '\n';
  }
}
