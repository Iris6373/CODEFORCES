# Problem Statement

## [C. Monsters And Spells](https://codeforces.com/contest/1626/problem/C)


## My solution :  (Accepted)

     This problem can be pictured as Merge Intervals problem.
     Here, we create intervals, using 'k' and 'h' vectors. [k-h, k].
     Next, we sort them.
     Next, we merge intervals by condition, If end of recent interval >= start of current interval
     Finally, we caluclate Mana of interval [a,b] by (b-a+1)*(b-a+2)/2.
  
        
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
              ll i, j, m, n, a=0, b=0, c=0, d=0, e=0, f=0, w=0, x=0, y=0, z=0, ans = 0;
              string s;
              cin >> n;
              vp v, an;
              vt k(n), h(n);
              f(n) cin >> k[i];
              f(n) cin >> h[i];
              f(n) {
                  v.pb({k[i]-h[i]+1,k[i]});
              }
              sort(all(v));
              an.pb(v[0]);
              // de(v);
              // de(an);
              f(n-1) {
                  auto [x,y] = an.back();
                  if (y >= v[i+1].F) {
                      an.pop_back();
                      an.pb({min(x,v[i+1].F), max(y,v[i+1].S)});
                  }
                  else an.pb(v[i+1]);
                  // de(an);
              }
              f(sz(an)) {
                  auto [x,y] = an[i];
                  // de(x); de(y);
                  z = y-x+1;
                  ans += z*(z+1)/2;
              }
              cout << ans << "\n";
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
  
          

    Time Complexity  : O(t*n*log(n))
                       t test cases
                       Each test case takes O(n*log(n)) time. 

    Space Complexity : O(n)
                       Since extra space is used.
