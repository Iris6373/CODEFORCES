# Problem Statement

## [D. Weights Assignment For Tree Edges](https://codeforces.com/contest/1611/problem/D)


## My solution :  (Accepted)

     If the permutation p is not in the order of the tree, then ans = -1.
     For checking it, we see if every node is valid in the permuatation iff its parent is already visited.
     Let a be root of the given tree.
     Also, p[0] must be a, since it has the least distance.
     
     Now, to find the weights of each edge,
          First, initialize distance of a = 0.
          Then assign i (2 to n) to all in 'b' array.
          The above values are root to node weights sum.
          
          Since we need individual weights,
          From i = 1 to n, ans[i] = mp[b[i]] - mp[p[b[i]]].
          (i.e) Sum of weights from root to node - sum of weights from root to node's parent = edge weight.
          
        
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
          #define pb push_back
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
          template <class T> void _p(priority_queue <T> pq);
          template <class T, class V> void _p(pair <T, V> p) {cout << "{"; _p(p.F); cout << ","; _p(p.S); cout << "}";}
          template <class T> void _p(vector <T> v) {cout << "[ "; for (T i : v) {_p(i); cout << " ";} cout << "]";}
          template <class T> void _pr(vector <T> v) { for (T i : v) {_p(i); cout << " ";} }
          template <class T> void _p(set <T> v) {cout << "[ "; for (T i : v) {_p(i); cout << " ";} cout << "]";}
          template <class T> void _p(priority_queue <T> v) {cout << "[ "; while (v.size()) {_p(v.top()); v.pop(); cout << " ";} cout << "]";}
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


          void solve() {  
              ll i, j, k, m, n, a=0, c=0, d=0, e=0, f=0, w=0, x=0, y=0, z=0;
              string s;
              cin >> n;
              vt b(n+1), p(n+1), vis(n+1,0), ans(n+1,0);
              map<ll,ll> mp;
              f(n) { cin >> p[i+1]; if (p[i+1] == i+1) a = i+1; }
              f(n) cin >> b[i+1];
              vis[a] = 1;
              // de(vis);
              if (b[1] != a) {
                  cout << "-1\n";
                  return;
              }
              f2(i,1,n+1) {
                  if (vis[p[b[i]]] == 1) vis[b[i]] = 1;
                  else {
                      cout << "-1\n";
                      return;
                  }
                  // de(vis);
              }
              // de(mp);
              // mp[a] = 0;
              // priority_queue<ll> pq;
              // pq.push(0);
              // f2(i,2,n+1) {
              //     // de(val);
              //     // de(mp);
              //     x = pq.top();
              //     mp[b[i]] = x+1;
              //     pq.push(x+1);
              //     de(mp);
              //     de(pq);
              // }
              // mp[a] = 0;
              // // de(mp);
              // f2(i,2,n+1) {
              //     // de(mp[i]); de(mp[i-1]);
              //     if (mp[b[i]] <= mp[b[i-1]]) {
              //         cout << "-1\n";
              //         return;
              //     }
              // }
              mp[a] = 0;
              ans[a] = 0;
              // de(mp);
              f2(i,2,n+1) {
                  mp[b[i]] = i;
                  ans[b[i]] = i-mp[p[b[i]]];    
              }
              // de(mp);
              f(n) cout << ans[i+1] << " ";
              cout << "\n";
              // cout << ans << "\n";
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


    Time Complexity  : O(t*n)
                       t test cases
                       Each test case takes O(n) time. 

    Space Complexity : O(n)
                       A vector as extra space is used.
