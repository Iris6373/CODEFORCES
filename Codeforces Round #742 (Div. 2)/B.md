# Problem Statement

## [B. MEXor Mixup](https://codeforces.com/contest/1567/problem/B)


## My solution :  (Accepted)

      First, we need atleast 'a' elements in the array since the MEX of th earray is 'a'.
      If the XOR of first 'a' elements is 0, then ans is 'a'.
      If not,
          we compute c = (xor of all nos.)^b
          If c is not MEX, we add c to the array, thus a+1
          Else we need extra 2 elements, whose xor is equal to c. 
          For e.g. c^1, 1 (xor of both = c)
        
      The xor of all 'n' numbers can be calculated in O(1) by using the formula, 
          1- Find the remainder of n by moduling it with 4. 
          2- If rem = 0, then xor will be same as n. 
          3- If rem = 1, then xor will be 1. 
          4- If rem = 2, then xor will be n+1. 
          5- If rem = 3 ,then xor will be 0.
        
        
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

            void solve() {  
                ll i, j, k, m, n, a=0, b=0, x, y, c, d, ans = 0, f=0;
                string s;
                cin >> n;
                vt v(3000010,0);
                f(300009) {
                    v[i+1] ^= (i+1)^v[i];
                }
                while (n--) {
                    cin >> a >> b;
                    c = v[a-1];
                    // de(c);
                    if (c == b) ans = a;
                    else {
                        d = c^b;
                        if (d != a) ans = a+1;
                        else {
                            if (d < a) ans = a+1;
                            else ans = a+2;
                        }
                    }
                    cout << ans << "\n";
                }
            }

            int main() {
                ios::sync_with_stdio(0);
                cin.tie(0);
                srand(chrono::high_resolution_clock::now().time_since_epoch().count());
                cout << fixed << setprecision(7);
                ll t = 1;
                // cin >> t;
                while (t--) {
                    solve();
                }
                //cerr << "Time Elapsed: " << ((db)(clock()-clk))/CLOCKS_PER_SEC << "\n";
                return 0;
            }   


    Time Complexity  : O(N)
                       Since we already compute Xor of all n numbers and constant time for each test case.

    Space Complexity : O(N)  
                       Since we use another vector to store the values of xor
   
  
  
