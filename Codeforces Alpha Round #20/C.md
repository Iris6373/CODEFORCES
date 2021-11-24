# Problem Statement

## [C. Dijkstra?](https://codeforces.com/problemset/problem/20/C)


## 1) Dijkstra's algorithm + DFS backtracking :  (Accepted)

    Apply Dijstra's algorithm to find the shortest paths from node 1 to all nodes.
    Then from node 'n' backtrack to find its parent node by comparing the sum of (its distance from node 1 + current edge weight + distance from current node to n)
    and distance from 1 to n.
    Finally, reverse the order and print it.
    
    WARNING :  1. Use correct syntax for priority queue to store in ascending order.
               2. The maximum distance is greater than INT_MAX
        
        
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

          void correctSolution(int n, vt a, vt b) {

          }


          void solve() {  
              ll i, j, k, m, n, a=0, b=0, c=0, d=0, e=0, f=0, w=0, x=0, y=0, z=0;
              string s;
              cin >> m >> n;
              vt dist(m+1,1e11), parent(m+1,-1), ans;
              map<pair<ll,ll>,ll> mp;
              vector<vector<ll>> adj(m+1);
              f(n) {
                  cin >> a >> b >> c;
                  mp[{a,b}] = c;
                  mp[{b,a}] = c;
                  adj[a].pb(b);
                  adj[b].pb(a);
              }
              priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
              pq.push({0,1});
              dist[1] = 0;
              parent[1] = 1;
              while (pq.size()) {
                  ll size = pq.size();
                  auto [x,y] = pq.top();
                  pq.pop();
                  for (ll a : adj[y]) {
                      if (dist[a] > x+mp[{y,a}]) {
                          dist[a] = x+mp[{y,a}];
                          parent[a] = y;
                          pq.push({dist[a],a});
                      } 
                  }
              }
              if (dist[m] == 1e11) {
                  cout << "-1\n";
                  return;
              }
              ans.pb(m);
              a = m, b = 0, c = INT_MAX, d = 0;
              f = 0;
              while (1) {
                  for (ll e : adj[a]) {
                      if (d+mp[{a,e}]+dist[e] == dist[m]) {
                          ans.pb(e);
                          d += mp[{a,e}];
                          a = e;
                          break;
                      }
                  }
                  if (a == 1) break;
              }
              reverse(all(ans));
              f(sz(ans)) cout << ans[i] << " ";
          }

          int main() {
              ios::sync_with_stdio(0);
              cin.tie(0);
              srand(chrono::high_resolution_clock::now().time_since_epoch().count());
              cout << fixed << setprecision(7);
              ll t;
              // cin >> t;
              // while (t--) {
                  solve();
              // }
              //cerr << "Time Elapsed: " << ((db)(clock()-clk))/CLOCKS_PER_SEC << "\n";
              return 0;
          }   



    Time Complexity  : O(V*logE)
                       The Dijkstra algorithm takes linartithmetic time.
                       

    Space Complexity : O(V+E)  
                       Since we use map, vectors to store edges and vertices
                       
   
  
# Problem Statement

## [C. Dijkstra?](https://codeforces.com/problemset/problem/20/C)


## 1) Dijkstra's algorithm + DFS backtracking :  (Accepted)

    Apply Dijstra's algorithm to find the shortest paths from node 1 to all nodes.
    Then from node 'n' backtrack to find its parent node by comparing the sum of (its distance from node 1 + current edge weight + distance from current node to n)
    and distance from 1 to n.
    Finally, reverse the order and print it.
    
    WARNING :  1. Use correct syntax for priority queue to store in ascending order.
               2. The maximum distance is greater than INT_MAX
        
        
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

          void correctSolution(int n, vt a, vt b) {

          }


          void solve() {  
              ll i, j, k, m, n, a=0, b=0, c=0, d=0, e=0, f=0, w=0, x=0, y=0, z=0;
              string s;
              cin >> m >> n;
              vt dist(m+1,1e11), parent(m+1,-1), ans;
              map<pair<ll,ll>,ll> mp;
              vector<vector<ll>> adj(m+1);
              f(n) {
                  cin >> a >> b >> c;
                  mp[{a,b}] = c;
                  mp[{b,a}] = c;
                  adj[a].pb(b);
                  adj[b].pb(a);
              }
              priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
              pq.push({0,1});
              dist[1] = 0;
              parent[1] = 1;
              while (pq.size()) {
                  ll size = pq.size();
                  auto [x,y] = pq.top();
                  pq.pop();
                  for (ll a : adj[y]) {
                      if (dist[a] > x+mp[{y,a}]) {
                          dist[a] = x+mp[{y,a}];
                          parent[a] = y;
                          pq.push({dist[a],a});
                      } 
                  }
              }
              if (dist[m] == 1e11) {
                  cout << "-1\n";
                  return;
              }
              ans.pb(m);
              a = m, b = 0, c = INT_MAX, d = 0;
              f = 0;
              while (1) {
                  for (ll e : adj[a]) {
                      if (d+mp[{a,e}]+dist[e] == dist[m]) {
                          ans.pb(e);
                          d += mp[{a,e}];
                          a = e;
                          break;
                      }
                  }
                  if (a == 1) break;
              }
              reverse(all(ans));
              f(sz(ans)) cout << ans[i] << " ";
          }

          int main() {
              ios::sync_with_stdio(0);
              cin.tie(0);
              srand(chrono::high_resolution_clock::now().time_since_epoch().count());
              cout << fixed << setprecision(7);
              ll t;
              // cin >> t;
              // while (t--) {
                  solve();
              // }
              //cerr << "Time Elapsed: " << ((db)(clock()-clk))/CLOCKS_PER_SEC << "\n";
              return 0;
          }   



    Time Complexity  : O(V*logE)
                       The Dijkstra algorithm takes linartithmetic time.
                       

    Space Complexity : O(V+E)  
                       Since we use map, vectors to store edges and vertices
