# Problem Statement

## [B. Customising the Track](https://codeforces.com/contest/1543/problem/B)


## My solution :  (Accepted)

    If the values are randomly distributed, then the inconvenience would be more.
    But if the values are equally distributed (upto the limit), then the inconvenience can be decreased.
    This is the optimal arrangement.
    
    Since we re allowed to ove cars from one track to another, the optimal number of cars on each track
    would the average number of cars of all the tracks.
    
    If the total number of cars(a) is not divisible by the total number of tracks(n), the remaining cars are 
    distributed to those number of tracks.
    
    Thus the minimum inconvenience is (a%n)*(n - a%n).
  
        
   ### Code : (.cpp)  
      
          // Iris_6373

          #include <bits/stdc++.h>
          using namespace std;
          typedef long long ll;
          typedef vector<ll> vt;
          typedef pair<ll, ll> pr;
          typedef vector<pr> vp;
          typedef map<ll, ll> mp;
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
          #define deb(x) cerr << #x << " is " << x << "\n"
          #define fo(i, a, b, s) for (ll i=(a); (s)>0?i<(b):i>(b); i+=(s))
          #define f(e) fo(i, 0, e, 1)
          #define f1(i, e) fo(i, 0, e, 1)
          #define f2(i, a, b) fo(i, a, b, 1)
          const int mod = 1000000007;
          auto clk = clock();


          void solve() {  
              ll i, j, k, n, a=0, b=0, x=0, y=0, ans = 0;
              cin >> n;
              vt v(n);
              f(n) {
                  cin >> v[i];
                  a += v[i];
              }
              cout << (a%n)*(n - a%n) << "\n";
              // cout << ans << "\n";
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
              //cerr << "Time Elapsed: " << ((double)(clock()-clk))/CLOCKS_PER_SEC << "\n";
              return 0;
          }   
      

    Time Complexity  : O(t*n)
                       t test cases
                       O(n) per test case for calculating total cars

    Space Complexity : O(1)  
                       Since no auxillary space other than input array is used.
   
  
