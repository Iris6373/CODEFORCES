# Problem Statement

## [A. AB Balance](https://codeforces.com/contest/1606/problem/A)


## My solution :  (Accepted)

    The absolute difference in the occurences of 'ab and 'ba' is always 1, because the extra a's and b's in the string, does not change it.
    (e.g)  aabbaa is same as aba
    The a's and b's inside the string contribute to both, except the ends.
    
    Thus, if the occurences of 'ab and 'ba' are same, we print the same string,
    else if 'ab' > 'ba', then we can either change s[0] to 'b' or s[n-1] to 'a'.
    else we can either change s[0] to 'a' or s[n-1] to 'b'.
    
        
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


          void solve() {  
              ll i, j, k, m, n, x, y, ans = 0, f=0, a=0, b=0;
              string s;
              cin >> s;
              f(sz(s)-1) {
                  if (s.substr(i,2) == "ab") a++;
                  else if (s.substr(i,2) == "ba") b++;
              }
              if (a == b) {
                  cout << s << "\n";
              }
              else if (a > b) {
                  s[0] = 'b';
                  cout << s << "\n";
              }
              else {
                  s[sz(s)-1] = 'b';
                  cout << s << "\n";
              }
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
                       Since we linearly pass the string once

    Space Complexity : O(1)  
                       Since no extra space is used.
   
  
  
