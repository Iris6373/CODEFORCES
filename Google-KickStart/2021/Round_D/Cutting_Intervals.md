# Problem

## [Cutting Intervals](https://codingcompetitions.withgoogle.com/kickstart/round/00000000004361e3/000000000082b933)


# Solution 

## 1) Difference Array from 1 to 1e5 

     Using the concept of Difference array, it is possible to get the number of intervals common to a particular point.
     After that, we perform prefix sum which gives number of intervals common to this point.
     This vector is then sorted in non-increasing order.
     Finally, we add the values of top 'd' elements in this sorted vector to ans. 
     
     But this approach is not enough to pass the 2nd test case since we cannot store 10^13 elements!
     
        
   ### Code (.cpp)
   
      // Iris_6373
 
      #include <bits/stdc++.h>
      using namespace std;
      typedef long long ll;
      typedef unsigned long long ull;
      typedef long double ld;
      typedef vector<ll> vt;
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
      #define de(x) cout << #x << " = "; _print(x); cout << "\n";
      #else
      #define de(x)
      #endif

      void _print(ll t) {cout << t;}
      void _print(int t) {cout << t;}
      void _print(string t) {cout << t;}
      void _print(char t) {cout << t;}
      void _print(ld t) {cout << t;}
      void _print(double t) {cout << t;}
      void _print(ull t) {cout << t;}

      template <class T, class V> void _print(pair <T, V> p);
      template <class T> void _print(vector <T> v);
      template <class T> void _print(set <T> v);
      template <class T, class V> void _print(map <T, V> v);
      template <class T> void _print(multiset <T> v);
      template <class T, class V> void _print(pair <T, V> p) {cout << "{"; _print(p.F); cout << ","; _print(p.S); cout << "}";}
      template <class T> void _print(vector <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
      template <class T> void _print(set <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
      template <class T> void _print(multiset <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
      template <class T, class V> void _print(map <T, V> v) {cout << "[ "; for (auto i : v) {_print(i); cout << " ";} cout << "]";}


      int main() {
          ios::sync_with_stdio(0);
          cin.tie(0);
          srand(chrono::high_resolution_clock::now().time_since_epoch().count());
          cout << fixed << setprecision(7);
          ll t,z;
          z = 0;
          cin >> t;
          while (z < t) {
              ll i, j, k, a = 0, b = 0, n, x, y, c = 0, d, ans = 0;
              cin >> n >> d;
              vt v(1e5,0);
              f(n) {
                  cin >> a >> b;
                  if (b-a >= 1) ans++;
                  if (b-a > 1) v[a+1]++, v[b]--;
              }
              f2(j,1,1e5) v[j] += v[j-1];
              sort(all(v),greater<int>());
              i = 0;
              while (d--) ans += v[i++];
              cout << "Case #" << z+1 << ": " << ans << "\n";
              z++;
          }
          return 0;
      }   


     Time Complexity  : O(T*N*log(N)) 
                        Since we have 't' test cases and each test case takes only O(N*log(N)) time for sorting
     Space Complexity : O(N)
                        Since no auxillary space is used.
                        
            
            
## 2) Difference Array through sorted Hashmap

     Unlike using a vector, we use a map to increment mp[a+1] and decrement mp[b].
     As these pairs are sorted, we add these pairs to a vector.
     Next, we perform prefix sum on second element of the pair which gives number of intervals common to this point.
     Next, we need the number of points which is common the same number of intervals.
     This is done by storing the difference, v[i].first - v[i-1].first and v[i-1].second in a vector of pair (u).
     Next, we sort 'u' according to the second element of the pair. 
     
     Finally, we add u[i].first*u[i].second to ans until d>0 and i<u.size()
     
        
   ### Code (.cpp)
   
      // Iris_6373
 
      #include <bits/stdc++.h>
      using namespace std;
      typedef long long ll;
      typedef unsigned long long ull;
      typedef long double ld;
      typedef vector<ll> vt;
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
      #define de(x) cout << #x << " = "; _print(x); cout << "\n";
      #else
      #define de(x)
      #endif

      void _print(ll t) {cout << t;}
      void _print(int t) {cout << t;}
      void _print(string t) {cout << t;}
      void _print(char t) {cout << t;}
      void _print(ld t) {cout << t;}
      void _print(double t) {cout << t;}
      void _print(ull t) {cout << t;}

      template <class T, class V> void _print(pair <T, V> p);
      template <class T> void _print(vector <T> v);
      template <class T> void _print(set <T> v);
      template <class T, class V> void _print(map <T, V> v);
      template <class T> void _print(multiset <T> v);
      template <class T, class V> void _print(pair <T, V> p) {cout << "{"; _print(p.F); cout << ","; _print(p.S); cout << "}";}
      template <class T> void _print(vector <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
      template <class T> void _print(set <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
      template <class T> void _print(multiset <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
      template <class T, class V> void _print(map <T, V> v) {cout << "[ "; for (auto i : v) {_print(i); cout << " ";} cout << "]";}


      bool comp(const pr a, const pr b) {
          return a.S > b.S;
      }


      int main() {
          ios::sync_with_stdio(0);
          cin.tie(0);
          srand(chrono::high_resolution_clock::now().time_since_epoch().count());
          cout << fixed << setprecision(7);
          ll t,z;
          z = 0;
          cin >> t;
          while (z < t) {
              ll i, j, k, a = 0, b = 0, n, x, y, c = 0, d, ans = 0;
              cin >> n >> d;
              vp v, u;
              map <ll,ll> mp;
              f(n) {
                  cin >> a >> b;
                  if (b-a >= 1) ans++;
                  if (b-a > 1) mp[a+1]++, mp[b]--;
              }
              for (auto z : mp) v.pb({z.F,z.S});
              f2(i,1,sz(v)) v[i].S += v[i-1].S;
              f2(i,1,sz(v)) u.pb({v[i].F-v[i-1].F, v[i-1].S});
              sort(all(u),comp);
              i = 0;
              while (d > 0 && i < sz(u)) {
                  if (d >= u[i].F && u[i].S > 0) ans += u[i].F*u[i].S;
                  else {
                      ans += d*u[i].S;
                      break;
                  }
                  d -= u[i].F;
                  i++;
              }
              cout << "Case #" << z+1 << ": " << ans << "\n";
              z++;
          }
          return 0;
      }   


     Time Complexity  : O(T*N*log(N)) 
                        Since we have 't' test cases and each test case takes only O(N*log(N)) time for sorting ans storing in map
     Space Complexity : O(N)
                        Since no auxillary space is used.
