# Problem Statement

## [Dice Combinations](https://cses.fi/problemset/task/1633)


## 1) Bottom Up DP + Extra Space - BETTER

     
  
        
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
              ll i, j, k, m, n, a=1, b=0, c=0, d=0, e=0, f=0, w=0, x=0, y=0, z=0, ans = 0;
              string s;
              cin >> n;
              n++;
              vt v(n+1,1);
              for (i=2;i<=n;i++) {
                  if (i <= 6) v[i] = a;
                  else v[i] = (v[i-1]+v[i-2]+v[i-3]+v[i-4]+v[i-5]+v[i-6]) % mod;
                  a = (a*2) % mod;
              }
              a = 0;
              cout << v[n] << "\n";
          }

          int main() {
              ios::sync_with_stdio(0);
              cin.tie(0);
              ll t=1;
              while (t--) {
                  solve();
              }
              return 0;
          }   


    Time Complexity  : O(N)
                       Since we linearly traverse once.
      
    Space Complexity : O(N)
                       Since a vector is used.
      

      
## 2) Bottom Up DP with no space - OPTIMAL

     
  
        
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
                ll i, j, k, m, n, a=1, b=0, c=0, d=0, e=0, f=0, w=0, x=0, y=0, z=0, ans = 0;
                string s;
                cin >> n;
                n++;
                vt v(7,1);
                for (i=2;i<=n;i++) {
                    if (i <= 6) v[i] = a;
                    else {
                        a = (v[1]+v[2]+v[3]+v[4]+v[5]+v[6]) % mod;
                        v[0] = v[1], v[1] = v[2], v[2] = v[3], v[3] = v[4], v[4] = v[5], v[5] = v[6], v[6] = a;
                    }   
                    a = (a*2) % mod;
                }
                if (n <= 6) cout << v[n] << "\n";
                else cout << v[6] << "\n";
            }

            int main() {
                ios::sync_with_stdio(0);
                cin.tie(0);
                ll t=1;
                while (t--) {
                    solve();
                }
                return 0;
            }       
      

    Time Complexity  : O(N)
                       Since we linearly traverse once.
      
    Space Complexity : O(1)
                       Since no extra space is used.      
