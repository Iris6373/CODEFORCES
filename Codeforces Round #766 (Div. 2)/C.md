# Problem Statement

## [C. Not Assigning](https://codeforces.com/contest/1627/problem/C)


## My solution :  (Accepted)

     The tree with nodes' degree >= 3, will always result in -1 because,
     Let a, b, c be 3 prime numbers in a particular path.
     
     If 1 out of a, b, c is 2, then others must be odd or else 2+2 = 4, which is not prime.
     If others are odd, then addition of those would be even, so a or b or c can never be 2.
     
     So, let's assume all a, b, c are odd.
     If so, then addition of any 2 would be even, so they can never form a triplet.
     
     Therefore, trees without atmost degree 2 (skewed tree) satisfies the given condition.
  
     Thus, we find the starting point and assign 2 and 3 alternatively.
     
        
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
          template <class T> void _p(priority_queue <T> p);
          template <class T, class V> void _p(pair <T, V> p) {cout << "{"; _p(p.F); cout << ","; _p(p.S); cout << "}";}
          template <class T> void _p(vector <T> v) {cout << "[ "; for (T i : v) {_p(i); cout << " ";} cout << "]";}
          template <class T> void _pr(vector <T> v) { for (T i : v) {_p(i); cout << " ";} }
          template <class T> void _p(set <T> v) {cout << "[ "; for (T i : v) {_p(i); cout << " ";} cout << "]";}
          template <class T> void _p(priority_queue <T> p) {cout << "[ "; while (p.size()) {_p(p.top()); p.pop(); cout << " ";} cout << "]";}
          template <class T> void _p(multiset <T> v) {cout << "[ "; for (T i : v) {_p(i); cout << " ";} cout << "]";}
          template <class T, class V> void _p(map <T, V> v) {cout << "[ "; for (auto i : v) {_p(i); cout << " ";} cout << "]";}
          template <class T, class V> void _p(unordered_map <T, V> v) {cout << "[ "; for (auto i : v) {_p(i); cout << " ";} cout << "]";}

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
              ll i, j, k, m, n, a=0, b=0, c=0, d=0, e=0, f=0, w=0, x=0, y=0, z=0, ans = 0;
              string s;
              cin >> n;
              vector<vector<ll>> adj(n+2);
              vt vis(n+2,0);
              map<pair<ll,ll>,ll> mp;
              map<ll,pair<ll,ll>> v;
              w = n-1;
              f(w) {
                  cin >> a >> b;
                  v[i] = {a,b};
                  adj[a].pb(b);
                  adj[b].pb(a);
              }
              a = 0;
              f(n+1) {
                  if (adj[i].size() > 2) {
                      cout << "-1\n";
                      return;
                  }
                  else if (adj[i].size() == 1) {
                      a = i;
                      d = adj[i][0];
                  }
              }
              queue<pair<ll,ll>> q;
              q.push({a,d});
              c = 0;
              while (q.size()) {
                  auto [x,y] = q.front();
                  q.pop();
                  vis[x] = 1;
                  vis[y] = 1;
                  if (c%2 == 0) mp[{x,y}] = 2, mp[{y,x}] = 2;
                  else mp[{x,y}] = 3, mp[{y,x}] = 3;
                  c++;
                  for (ll z : adj[x]) if (!vis[z]) q.push({x,z});
                  for (ll z : adj[y]) if (!vis[z]) q.push({y,z});
              }
              f(w) {
                  cout << mp[v[i]] << " ";
              }
              cout << "\n";
          }

          int main() {
              ios::sync_with_stdio(0);
              cin.tie(0);
              ll t;
              cin >> t;
              while (t--) {
                  solve();
              }
              return 0;
          }   
  

    Time Complexity  : O(t*n)
                       t test cases
                       Each test case takes O(n) time. 

    Space Complexity : O(n)
                       Since extra space is used.
