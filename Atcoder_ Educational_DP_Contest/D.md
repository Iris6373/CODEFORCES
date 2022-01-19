# Problem Statement

## [D - Knapsack 1](https://atcoder.jp/contests/dp/tasks/dp_d)


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

          // #define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
          // template<typename ...Args>
          // void logger(string vars, Args&&... values) {
          //     cout << vars << " = ";
          //     string delim = "";
          //     (..., (cout << delim << values, delim = ", "));
          // }


          ll dfs(vt& v, ll i, ll n, ll k, vt& w, vector<vt>& dp) {
              // de(v); de(w);
              // de(dp);
              // cout << i << " " << k << "\n";
              if (i == n || k == 0) return 0;
              // cout << i << " " << k << " " << v[i] << " " << w[i] << "\n";
              if (dp[i][k] != -1) return dp[i][k];
              ll a = 0LL, b = 0LL;
              if (k-w[i] >= 0) a = v[i] + dfs(v,i+1,n,k-w[i],w,dp);
              // cout << i << " " << a << "\n";
              b = dfs(v,i+1,n,k,w,dp);
              // cout << i << "\t" << a << " " << b << "\n";
              return dp[i][k] = max(a,b);
          }


          void solve() {  
              ll i, j, k, m, n, a=0, b=0, c=0, x, y, z, d, ans = 0, f=0, cost = 0;
              string s;
              cin >> n >> k;
              vt v(n), w(n);
              vector<vt> dp(n+1, vt (k+1,-1));
              f(n) {
                  cin >> w[i] >> v[i];
              }
              ans = dfs(v,0,n,k,w,dp);
              // de(dp);
              cout << ans;
          }

          int main() {
              ios::sync_with_stdio(0);
              cin.tie(0);
              srand(chrono::high_resolution_clock::now().time_since_epoch().count());
              cout << fixed << setprecision(7);
              ll t=1;
              // cin >> t;
              while (t--) {
                  solve();
              }
              //cerr << "Time Elapsed: " << ((db)(clock()-clk))/CLOCKS_PER_SEC << "\n";
              return 0;
          }   



    Time Complexity  : O()
                       

    Space Complexity : O()  
                       
   
  
  
