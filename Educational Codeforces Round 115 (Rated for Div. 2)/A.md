# Problem Statement

## [A. Computer Game](https://codeforces.com/contest/1598/problem/A)


## My solution :  (Accepted)

     
  
        
   ### Code : (.cpp)  
      
          // Iris_6373
 
          #include <bits/stdc++.h>
          using namespace std;
          typedef long long ll;
          typedef unsigned long long ull;
          typedef long double ld;
          typedef vector<ll> vt;
          typedef map<ll, ll> mp;
          typedef pair<ll, ll> pr;
          typedef vector<pr> vp;
          #define F first
          #define S second
          #define mp make_pair
          #define l(x) (ll)(x).length()
          #define pb emplace_back
          #define sz(x) (ll)(x).size()
          #define all(c) (c).begin(), (c).end()
          #define uni(a) (a).erase(unique(all(a)), (a).end())
          #define prec(n) fixed << setprecision(n)
          #define bitcount(n) __builtin_popcountll(n)
          #define gcd(x, y) __gcd(x, y)
          #define deb(x) cout << #x << " is " << x << "\n"
          #define fo(i, a, b, s) for (ll i=(a); (s)>0?i<(b):i>(b); i+=(s))
          #define f(e) fo(i, 0, e, 1)
          #define f1(i, e) fo(i, 0, e, 1)
          #define f2(i, a, b) fo(i, a, b, 1)
          const ll mod = 1000000007;
          auto clk = clock();

          #ifndef ONLINE_JUDGE
          #define de(x) cout << #x << " = "; _p(x); cout << "\n";
          #else
          #define de(x)
          #endif

          void _p(ll t) {cout << t;}
          void _p(int t) {cout << t;}
          void _p(string t) {cout << t;}
          void _p(char t) {cout << t;}
          void _p(ld t) {cout << t;}
          void _p(double t) {cout << t;}
          void _p(ull t) {cout << t;}

          template <class T, class V> void _p(pair <T, V> p);
          template <class T> void _p(vector <T> v);
          template <class T> void _p(set <T> v);
          template <class T, class V> void _p(map <T, V> v);
          template <class T> void _p(multiset <T> v);
          template <class T, class V> void _p(pair <T, V> p) {cout << "{"; _p(p.F); cout << ","; _p(p.S); cout << "}";}
          template <class T> void _p(vector <T> v) {cout << "[ "; for (T i : v) {_p(i); cout << " ";} cout << "]";}
          template <class T> void _pr(vector <T> v) { for (T i : v) {_p(i); cout << " ";} }
          template <class T> void _p(set <T> v) {cout << "[ "; for (T i : v) {_p(i); cout << " ";} cout << "]";}
          template <class T> void _p(multiset <T> v) {cout << "[ "; for (T i : v) {_p(i); cout << " ";} cout << "]";}
          template <class T, class V> void _p(map <T, V> v) {cout << "[ "; for (auto i : v) {_p(i); cout << " ";} cout << "]";}
          template <class T, class V> void _p(unordered_map <T, V> v) {cout << "[ "; for (auto i : v) {_p(i); cout << " ";} cout << "]";}

          #define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
          template<typename ...Args>
          void logger(string vars, Args&&... values) {
              cout << vars << " = ";
              string delim = "";
              (..., (cout << delim << values, delim = ", "));
          }

          void test_cases(int t, int n, int a) {
              srand(time(NULL));
              int T = rand() % t + 1, N;
              cout << T << "\n";
              while (T--) {
                  cout << N << "\n";
                  f(T) cout << (rand() % a + 1) << '\n';
                  cout << "\n";
              }
          }

          void correctSolution() {

          }


          bool dfs(vector<string> &v, ll i, ll j, vector<vector<ll>> &vis, ll n) {
              // cout << i << " " << j << "\n";
              if (i < 0 || j < 0 || i >= 2 || j >= n || vis[i][j] == 1 || v[i][j] == '1') return 0;
              bool a,b,c,d,e,f,g,h;
              vis[i][j] = 1;
              if (i == 1 && j == n-1) return 1;
              a = dfs(v,i-1,j,vis,n);
              b = dfs(v,i+1,j,vis,n);
              c = dfs(v,i,j+1,vis,n);
              d = dfs(v,i,j-1,vis,n);
              e = dfs(v,i-1,j-1,vis,n);
              f = dfs(v,i+1,j-1,vis,n);
              g = dfs(v,i-1,j+1,vis,n);
              h = dfs(v,i+1,j+1,vis,n);
              // cout << i << " " << j << "\t" << a << " " << b << " " << c << " " << d << "\n"; 
              return (a || b || c || d || e || f || g || h);
          }


          void solve() {  
              ll i, j, k, m, n, a=0, b=0, x, y, z, c, d, ans = 0, f=0;
              string s;
              cin >> n;
              vector<string> v;
              vector<vector<ll>> vis(2,vector<ll>(n,0));
              f(2) {
                  cin >> s;
                  v.pb(s);
              }
              i = 0, j = 0;
              // de("\n");
              f1(k,n) {
                  // de(i); de(j);
                  if (i == 1 && j == n-1)  {
                      cout << "YES\n";
                      // de(i); de(j);
                      return;
                  }
                  while (j+1 < n && v[i][j+1] == '0') j++;
                  if (i == 1 && j == n-1)  {
                      cout << "YES\n";
                      // de(i); de(j);
                      return;
                  }
                  i ^= 1;
                  while (j+1 < n && v[i][j+1] == '0') j++;
                  if (i == 1 && j == n-1)  {
                      cout << "YES\n";
                      // de(i); de(j);
                      return;
                  }
              }
              cout << "NO\n";
          }

          int main() {
              ios::sync_with_stdio(0);
              cin.tie(0);
              srand(chrono::high_resolution_clock::now().time_since_epoch().count());
              cout << fixed << setprecision(7);
              ll t;
              cin >> t;
              while (t--) {
                  solve();
              }
              //cerr << "Time Elapsed: " << ((db)(clock()-clk))/CLOCKS_PER_SEC << "\n";
              return 0;
          }   


    Time Complexity  : O(t)
                       t test cases
                       Each test case takes O(1) time. 

    Space Complexity : O(n)  
