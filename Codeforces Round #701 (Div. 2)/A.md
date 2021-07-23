# Problem

## [A. Add and Divide](https://codeforces.com/contest/1485/problem/A)


# My Solution

## 1) Opeation type 2 over 1

    There are 2 base cases.
    1) If a < b, operation 2 is enough, so 'ans' = 1
    2) If a == b, op 2 then op 1, so ans = 2
    
    If not of the above cases, we do the following:
    e = no. of '2' op, f = no. of '1' op
    If b == 1, we cannot reduce 'a' by dividing it by 1, so e = 1
    
    Next, we assign c = b+e and d = 1
    We find the minimum power of (b+e) > a, which is in d
    
    Now, f = d
    Next, we increase 'e' and see if new (e+f) < current (e+f).
    At one point, e+f reaches minimum beyond which it increases,
    which is our answer.
    
    
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
        #define l(x) (int)(x).length()
        #define pb push_back
        #define sz(x) (int)(x).size()
        #define all(c) (c).begin(), (c).end()
        #define uni(a) (a).erase(unique(all(a)), (a).end())
        #define prec(n) fixed << setprecision(n)
        #define bitcount(n) __builtin_popcountll(n)
        #define gcd(x, y) __gcd(x, y)
        #define deb(x) cout << #x << " is " << x << "\n"
        #define fo(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
        #define f(e) fo(i, 0, e, 1)
        #define f1(i, e) fo(i, 0, e, 1)
        #define f2(i, a, b) fo(i, a, b, 1)
        const int mod = 1000000007;
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
        template <class T> void _pr(vector <T> v) { for (T i : v) {_p(i); cout << " ";} cout << "\n"; }
        template <class T> void _p(set <T> v) {cout << "[ "; for (T i : v) {_p(i); cout << " ";} cout << "]";}
        template <class T> void _p(multiset <T> v) {cout << "[ "; for (T i : v) {_p(i); cout << " ";} cout << "]";}
        template <class T, class V> void _p(map <T, V> v) {cout << "[ "; for (auto i : v) {_p(i); cout << " ";} cout << "]";}


        void solve() {  
            ll i, j, n, m, k, q, ans = 0, a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
            cin >> a >> b;
            if (a < b) ans = 1;
            else if (a == b) ans = 2;
            else {
                e = 0;
                if (b == 1) { e = 1; }
                c = b+e;
                d = 1; 
                while (a >= c) {
                    c *= (b+e);
                    d++;
                } 
                f = d;
                ans = INT_MAX;
                c = b;
                while (e+f <= ans) {
                    ans = e+f;
                    e++;
                    while (pow(b+e,f) > a) f--;
                    f++;
                }
            }
            cout << ans << "\n";
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
    
