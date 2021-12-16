# Problem Statement

## [C. Paprika and Permutation](https://codeforces.com/contest/1617/problem/C)


## My solution :  (Accepted)

    If any nos are in the range [1,n], we do not change them. So, we add the other nos to 'u' and the missing nos in permutation to 'z'.
    If we find n % a, where a is [1,n-1], we can see that n%a upto a=n/2 is irregular, but from [n-1,n/2+1], it is of range [1,n/2-1].
    So, we just have to find if all nos. in 'z' fall in these ranges of every available no. in 'u'.
    But, as n increases, the range of [1,n/2-1] increases.
    Thus, we check the smallest no. in 'u' with smallest in 'z'. So, we sort both and compare their respective nos if they fall in the above range.
    If any of them don't, we print -1,
    Else, we print size of 'u'.
  
        
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
            ll i, j, k, m, n, a=0, b=0, c=0, d=0, e=0, f=0, ans = 0;
            string s;
            cin >> n;
            vt v(n), u, w, z;
            map<ll,ll> mp;
            f(n) {
                w.pb(i+1);
                cin >> v[i];
                mp[v[i]]++;
            }
            f(n) {
                if (mp[i+1] >= 1) mp[i+1]--, w[i] = 0;
            }
            f(n) {
                if (w[i] != 0) z.pb(w[i]);
            }
            for (auto [x,y] : mp) while (y--) u.pb(x);
            sort(all(u));
            // de(u);
            // de(z);
            f(sz(z)) {
                if (z[i]*2 + 1 > u[i]) {
                    cout << "-1\n";
                    return;
                }
            }
            cout << sz(z) << "\n";
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



    Time Complexity  : O(t*n*logn)
                       t test cases
                       Since in each test case, we sort 'u' and 'z'.

    Space Complexity : O(n)  
                       Since extra space is used.
   
  
  
