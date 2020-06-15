#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
#include "ext/rope"

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx,avx2,fma")

void trace(int x)                         { cerr << x; }
void trace(long x)                        { cerr << x; }
void trace(long long x)                   { cerr << x; }
void trace(unsigned x)                    { cerr << x; }
void trace(unsigned long x)               { cerr << x; }
void trace(unsigned long long x)          { cerr << x; }
void trace(float x)                       { cerr << x; }
void trace(double x)                      { cerr << x; }
void trace(long double x)                 { cerr << x; }
void trace(char x)                        { cerr << '\'' << x << '\''; }
void trace(const char *x)                 { cerr << '\"' << x << '\"'; }
void trace(const string &x)               { cerr << '\"' << x << '\"'; }
void trace(bool x)                        { cerr << (x ? "true" : "false"); }

template <typename A, typename B>                         void trace(const pair <A, B> &x)         { cerr << '{'; trace(x.first); cerr << ','; trace(x.second); cerr << '}'; }
template <typename A, typename B, typename C>             void trace(const tuple <A, B, C> &x)     { cerr << '{'; trace(get <0> (x)); cerr << ','; trace(get <1> (x)); cerr << ','; trace(get <2> (x)); cerr << '}'; }
template <typename A, typename B, typename C, typename D> void trace(const tuple <A, B, C, D> &x)  { cerr << '{'; trace(get <0> (x)); cerr << ','; trace(get <1> (x)); cerr << ','; trace(get <2> (x)); cerr << ','; trace(get <3> (x)); cerr << '}'; }
template <typename T>                                     void trace(const T &x)                   { int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), trace(i); cerr << "}"; }
template <size_t N>                                       void trace(bitset <N> v)                 { cerr << '{'; for (size_t i = 0; i < N; i++) cerr << static_cast <char> ('0' + v[i]); cerr << '}'; }
void _print()                                                                                      { cerr << "]\n"; }
template <typename T, typename... V>                      void _print(T t, V... v)                 { trace(t); if (sizeof...(v)) cerr << ", "; _print(v...); }

#ifndef ONLINE_JUDGE
      #define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
      #define debug(x...)
#endif

template <typename T> using order_set                  = tree <T, null_type, less <T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T1, typename T2> using order_map    = tree <T1, T2, less <T1>, rb_tree_tag, tree_order_statistics_node_update>;

template <class T> bool MIN(T &a, T b)                 { return a > b ? (a = b, true) : false; }
template <class T> bool MAX(T &a, T b)                 { return a < b ? (a = b, true) : false; }

template <class T> T binaryExpo(T a, T p)              { if (p == 0) { return 1LL; } if (p == 1) { return a; } if (p & 1) { return a * binaryExpo(a, p - 1); } T ret = binaryExpo(a, p / 2); return ret * ret; }
template <class T> T bigMod(T a, T p, T m)             { if (p == 0) { return 1LL % m; } if (p == 1) { return a % m; } if (p & 1) { return (a % m * bigMod(a, p - 1, m)) % m; } T ret = bigMod(a, p / 2, m) % m; return (ret * ret) % m; }
template <class T> T modInv(T a, T m)                  { return bigMod(a, m - 2, m); }

template <typename T> string num_str(T num)            { stringstream ss; ss << num; return ss.str(); }
long long str_num(string s)                            { long long num; istringstream iss(s); iss >> num; return num; }

inline long long ON(long long mask, int pos)           { return mask |= (1LL << pos); }
inline long long OFF(long long mask, int pos)          { return mask &= ~(1LL << pos); }
inline long long TOGGLE(long long mask, int pos)       { return mask ^= (1LL << pos); }
inline bool CHECK(long long mask, int pos)             { return (bool)(mask >> pos & 1); }

#define ll              long long int
#define ull             unsigned long long int
#define endl            '\n'
#define pii             pair <int, int>
#define pll             pair <ll, ll>
#define mk              make_pair
#define ff              first
#define ss              second
#define all(a)          (a).begin(), (a).end()
#define rall(a)         (a).rbegin(), (a).rend()
#define eb              emplace_back
#define pb              push_back
#define allUpper(a)     transform(all(a), a.begin(), :: toupper)
#define allLower(a)     transform(all(a), a.begin(), :: tolower)
#define LINE            cerr << __LINE__ << " ";
#define memo(a, b)      memset(a, b, sizeof a)
#define ook             order_of_key
#define fbo             find_by_order

//#define int             long long int

int dr[] = {1, -1, 0, 0}; // 4 Direction - DOWN, UP, RIGHT, LEFT
int dc[] = {0, 0, 1, -1};
//int dr[] = {0, 0, 1, -1, 1, 1, -1, -1}; // 8 Direction - RIGHT, LEFT, DOWN, UP, RIGHT-DOWN, LEFT-DOWN, UP-RIGHT, UP-LEFT
//int dc[] = {1, -1, 0, 0, 1, -1, 1, -1};
//int dr[] = {-1, 1, -2, -2, -1, 1, 2, 2}; // knight Moves
//int dc[] = {-2, -2, -1, 1, 2, 2, 1, -1};

static const int maxn = 1e5 + 5;
static const int logn = 19;
static const long long mod = 1e9 + 7;
static const long long INF = 1e7;

vector < vector <int> > graph;
int depth[maxn];
int father[maxn][logn];

void dfs(int u = 1, int p = 0) {
      for (int i = 1; i < logn; i++) {
            father[u][i] = father[ father[u][i - 1] ][i - 1];
      }
      depth[u] = depth[p] + 1;
      for (int v : graph[u]) {
            if (v == p) {
                  continue;
            }
            father[v][0] = u;
            dfs(v, u);
      }
}

int find_lca(int u, int v) {
      if (depth[u] < depth[v]) {
            swap(u, v);
      }
      for (int i = logn - 1; i >= 0; i--) {
            if (depth[ father[u][i] ] >= depth[v]) {
                  u = father[u][i];
            }
      }
      if (u == v) {
            return u;
      }
      for (int i = logn - 1; i >= 0; i--) {
            if (father[u][i] != father[v][i]) {
                  u = father[u][i];
                  v = father[v][i];
            }
      }
      return father[u][0];
}

int dist(int u, int v) {
      int lca = find_lca(u, v);
      int d = depth[u] + depth[v] - 2 * depth[lca];
      return d;
}

int get_common(int a, int b, int c, int d) {
      int sum1 = dist(a, b) + dist(c, d);
      int sum2 = min(dist(a, c) + dist(b, d), dist(a, d) + dist(b, c));
      if (sum1 < sum2) {
            return 0;
      }
      return (sum1 - sum2) / 2 + 1;
}

signed main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(nullptr);
      cout.precision(12);

      #ifndef ONLINE_JUDGE
          freopen("in.txt", "r", stdin);
      #endif // ONLINE_JUDGE

      int n, q;
      cin >> n >> q;
      graph.resize(n + 1);
      for (int v = 2; v <= n; v++) {
            int u;
            cin >> u;
            graph[u].push_back(v);
            graph[v].push_back(u);
      }
      dfs();
      while (q--) {
            vector <int> vec(3);
            for (int &x : vec) {
                  cin >> x;
            }
            sort(all(vec));
            int max_dist = 0;
            do {
                  int s = vec[0];
                  int f = vec[1];
                  int t = vec[2];
                  int my_common = get_common(s, f, f, t);
                  MAX(max_dist, my_common);
            } while (next_permutation(all(vec)));
            cout << max_dist << endl;
      }

      #ifndef ONLINE_JUDGE
            cerr << endl << "Time : " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
      #endif // ONLINE_JUDGE
}
