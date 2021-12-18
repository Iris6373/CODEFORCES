# Problem

## [C. Maximize the Intersections](https://codeforces.com/contest/1552/problem/C)

 
# My Solution

## 1) Joining Points i and i+k + Sorting chords wrt points

      First we store the points which are not joind by any chord in a avector of pairs 'v'
      Next, we join points v[i] with v[i+n-k]. This increase the maximum number of intersections.
      
      Finally, to calculate th etotal number of intersections,
      we store the intersection formed by the 2 pairs of points in a set.
      
      The size of the set is our answer.
    

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


       void solve() {  
           ll i, j, k, m, n, a=0, b=0, x, y, c, d, ans = 0;
           cin >> n >> k;
           vt u(2*n,1), w;
           vector<pair<ll,ll>> v;
           f(k) {
               cin >> a >> b;
               u[a-1] = 0;
               u[b-1] = 0;
               v.pb({min(a,b),max(a,b)});
           }
           f(2*n) {
               if (u[i] == 1) w.pb(i+1);
           }
           f(sz(w)/2) {
               v.pb({w[i],w[i+n-k]});
           }
           map <ll,ll> mp;
           f(sz(v)) {
               mp[v[i].F] = v[i].S;
           }
           sort(all(v));
           // de(v);
           set <pair<pair<ll,ll>,pair<ll,ll>>> sp;
           f(sz(v)) {
               f2(j,v[i].F+1,v[i].S) {
                   if (mp[j] > v[i].S) {
                       sp.insert({{v[i]},{j,mp[j]}});
                   }
               }
           }
           cout << sz(sp) << "\n";
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
        
    Time Complexity  :  O(T*N^2*log(N))
                        Since for each test case we run a nested loop to cdheck for intersection and each insertion into the set takes logarithmic time
    Space Complexity :  O(N^2)
                        Since in worst case if all the chords are intersecting, the max no. of intersections would be n*(n-1)/2.
