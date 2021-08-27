# Problem

## [B. Replace and Keep Sorted](https://codeforces.com/contest/1485/problem/B)
 

# My Solution 
    
## 1) Prefix Sum 

    We create a prefix array, which contains the total numbers less than v[i] and greater than v[i], but lesser than v[i+1].
    
    For each query, there are 3 cases
    1) If a == b, then ans is k-1, because we can replace any no. from [1,k] except v[i]
    2) If b-a == 1, then we take total numbers less than v[a-1] and greater than v[a-1], but lesser than v[b-1] and 
       numbers less than v[b-1], but greater than v[a-1] and greater than v[b-1], but lesser than k+1.
    3) Else we add prefix[b-1]-prefix[a-2] + left of a + right of b
    
    
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
            ll i, j, n, m, k, q, ans = 0, a = 0, b = 0, c = 0, d = 0, e = 0, g = 0;
            cin >> n >> q >> k;
            vt v(n), u(n,0);
            f(n) {
                cin >> v[i];
            }
            if (n == 1) {
                f(q) {
                    cin >> a >> b;
                    cout << k-1 << "\n";
                }
                return;
            }
            u[0] = v[0]-1 + v[1]-v[0]-1;
            f2(i,1,n-1) {
                u[i] = u[i-1] + v[i]-v[i-1]-1 + v[i+1]-v[i]-1;
            }
            u[n-1] = u[n-2] + v[n-1]-v[n-2]-1 + k-v[n-1];
            for (i=0;i<q;i++) {
                cin >> a >> b;
                if (a == b) c = k-1;
                else if (b-a == 1) {
                    if (a == 1) c = u[b-2] + v[b-1]-v[b-2]-1 + k-v[b-1];
                    else c = v[a-1]-1 + v[b-1]-v[a-1]-1 + v[b-1]-v[a-1]-1 + k-v[b-1];
                }
                else {
                    c = u[b-2]-u[a-1] + v[a-1]-1 + v[a]-v[a-1]-1 + v[b-1]-v[b-2]-1 + k-v[b-1];
                }
                cout << c << "\n";
            }
        }

        int main() {
            ios::sync_with_stdio(0);
            cin.tie(0);
            srand(chrono::high_resolution_clock::now().time_since_epoch().count());
            cout << fixed << setprecision(7);
            ll t=1;
            //cin >> t;
            while (t--) {
                solve();
            }
            //cerr << "Time Elapsed: " << ((db)(clock()-clk))/CLOCKS_PER_SEC << "\n";
            return 0;
}   
    
