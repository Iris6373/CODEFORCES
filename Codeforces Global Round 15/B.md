# Problem

## [B. Running for Gold](https://codeforces.com/contest/1552/problem/B)


# Solution

## 1) My Solution - Sorting and Comparison - BETTER

    First, we store the index of each runner with his marathon positions in a vector of pairs.
    Next, we sort the vector with a custom compare funcetion.
    This function sorts each pair according to the number of races won among the current two players.
    
    Thus, after sorting the first player in the sorted vector should be the gold medal winner.
    But we have to check if this player defeats all the other players.
    If he doesn't, we print -1.
    
    If he beats all the players, we print his index.
    
   
   ### Code (.cpp)
   
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
        template <class T, class V> void _p(pair <T, V> p) {cout << "{"; _p(p.F); cout << ","; _p(p.S); cout << "}";}
        template <class T> void _p(vector <T> v) {cout << "[ "; for (T i : v) {_p(i); cout << " ";} cout << "]";}
        template <class T> void _pr(vector <T> v) { for (T i : v) {_p(i); cout << " ";} }
        template <class T> void _p(set <T> v) {cout << "[ "; for (T i : v) {_p(i); cout << " ";} cout << "]";}
        template <class T> void _p(multiset <T> v) {cout << "[ "; for (T i : v) {_p(i); cout << " ";} cout << "]";}
        template <class T, class V> void _p(map <T, V> v) {cout << "[ "; for (auto i : v) {_p(i); cout << " ";} cout << "]";}

        static bool comp (const pair<vector<ll>,ll> x, const pair<vector<ll>,ll> y) {
            ll k, a=0, b=0;
            vt u = x.F, v = y.F;
            f1(k,5) if (u[k] < v[k]) a++;
            f1(k,5) if (u[k] > v[k]) b++;
            if (a >= 3) return 1;
            else return 0;
        }

        void solve() {  
            ll i, j, k, m, n, a=0, b=0, x, y, c, d, ans = 0;
            cin >> n;
            vector<pair<vector<ll>,ll>> v;
            f(n) {
                vt u(5);
                f1(j,5) cin >> u[j];
                v.pb({u,i+1});
            }
            if (n == 1) {
                cout << 1 << "\n";
                return;
            }
            sort(all(v),comp);
            // de(v);
            i = 0;
            vt u = v[0].F;
            f2(j,1,n) {
                a=0, b=0;
                vt w = v[j].F;
                f1(k,5) if (u[k] < w[k]) a++;
                f1(k,5) if (u[k] > w[k]) b++;
                if (a >= 3) c = 1;
                else { c = 0; break; }
            } 
            if (c == 1) cout << v[0].S << "\n";
            else cout << "-1\n";
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
        
        
    Time Complexity  :  O(T*N*log(N))
                        Since for each test case we sort the vector of pairs
    Space Complexity :  O(N)
                        Since we store each athlete record in a vector


## 2) Compare without sorting - OPTIMAL

    Instead of sortting the vectors, we just compare all the athlete records with the 'winner' record.
    We have to check if this player defeats all the other players.
    If he doesn't, we print -1.
    
    If he beats all the players, we print his index.
    
    
    Time Complexity  :  O(T*N)
                        Since for each test case we iterate through the vector of pairs
    Space Complexity :  O(N)
                        Since we store each athlete record in a vector

