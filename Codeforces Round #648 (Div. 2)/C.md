# Problem Statement

## [C. Rotation Matching](https://codeforces.com/problemset/problem/1365/C)


## My solution :  (Accepted)

      The key observation is performing k left-shifts are same as n-k right-shifts, so anyone can be done (here, let's take right).
      Moreover, a right cyclic shift of b is the same as performing a left cyclic shift on a and vice versa. So we don't need to perform any shifts on b.
      Now, we just have to find the no. of matchings under each and every rotation.
      
      By Brute force, it will O(N^2).
      To optimize this, we can assign the no of right-shifts required for a particular no. in 'b' to be in same position as in 'a' in a map.
      The maximum numbers under a particular no. of shifts is the answer.
        
        
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
            ll i, j, k, m, n, a=-1, b=-1, x, y, c=0, d, ans = 0, f=0;
            string s;
            cin >> n;
            vt p(n), q(n);
            unordered_map<ll,ll> fir, sec, an;
            f(n) cin >> p[i], fir[p[i]] = i;
            f(n) cin >> q[i], sec[q[i]] = i;
            f(n) {
                a = fir[i+1];
                b = sec[i+1];
                if (b <= a) an[a-b]++;
                else an[n-b+a]++;
                // de(an);
            }
            for (auto [x,y] : an) ans = max(ans,y);
            cout << ans;
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
                       Since we linearly traversed and unordered map is used whose time complexity for 1 element is O(1).

    Space Complexity : O(N)  
                       Since an unordered map is used as extra space.
   
  
  
