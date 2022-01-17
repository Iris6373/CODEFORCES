# Problem Statement

## [B. Minor Reduction](https://codeforces.com/contest/1626/problem/B)


## My solution :  (Accepted)

     The given operation will always reduce the given number.
     So, inorder to obtain largest number, we have 2 conditions :
             1. If we can get the sum > 9 after adding 2 digits, we take the right most digits, as the first ones are more significant. (Refer 1st point).
             2. If not available, then we add the 1st 2 digits (a and b). 
                If we add any other pair of digits, the no. of digits gets reduced by 1 and the obtained number will always be less than the addition of 1st 2 digits.
                Since a+b >= a.
  
        
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
              ll i, j, k, m, n, a=0, b=0, c=0, d=0, e=0, f=0, w=0, x=0, y=0, z=0;
              string s, ans = "";
              cin >> s;
              // cout << s << "\n";
              n = sz(s);
              for (i=n-1;i>0;i--) {
                  a = s[i]-'0' + s[i-1]-'0';
                  if (a > 9) {
                      s[i] = '0' + a%10;
                      s[i-1] = '0' + a/10;
                      cout << s << "\n";
                      return;
                  }
              }
              // cout << s << "\n";
              string aa = "";
              a = s[0]-'0' + s[1]-'0';
              aa = '0'+a;
              aa += s.substr(2);
              cout << aa << "\n";
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

    Space Complexity : O(1)
                       No extra space is used.
