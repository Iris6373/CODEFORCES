# Problem Statement

## [B. Nice Matrix](https://codeforces.com/contest/1422/problem/B)

 
## My solution :  (Accepted)

    For row and columns to be palindrome, the four corners (i.e) [i,j], [i,n-1-j], [m-1-i][j], [m-1-i][n-1-j] must be same.
    Inorder to minimise the steps, we must binary search to find the optimum value 
  
        
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
      #define fo(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
      #define f(e) fo(i, 0, e, 1)
      #define f1(i, e) fo(i, 0, e, 1)
      #define f2(i, a, b) fo(i, a, b, 1)
      const int mod = 1000000007;
      auto clk = clock();

      void solve() {  
          ll ans = 0, n, l, i, j, k, m;
          cin >> m >> n;
          vector<vector<ll>> v(m, vector <ll>(n,0));
          f(m) {
              f1(j,n) {
                  cin >> v[i][j];
              }
          }
          for (i=0;i<(m+1)/2;i++) {
              for (j=0;j<(n+1)/2;j++) {
                  ll a = v[i][j], b = v[i][n-1-j], c = v[m-1-i][j], d = v[m-1-i][n-1-j];
                  ll l = min({a,b,c,d}), h = max({a,b,c,d}), mi=0, an=INT_MAX;
                  while (l <= h) {
                      ll lo = abs(a-l) + abs(b-l) + abs(c-l) + abs(d-l);
                      ll hi = abs(a-h) + abs(b-h) + abs(c-h) + abs(d-h);
                      mi = l + (h-l)/2;
                      ll e = abs(a-mi) + abs(b-mi) + abs(c-mi) + abs(d-mi);
                      an = min(an,e);
                      if (lo < hi) h = mi-1;
                      else l = mi+1;
                  }
                  if (i == m-1-i || j == n-1-j) an /= 2; 
                  ans += an;
                  v[i][j] = mi;
                  v[i][n-1-j] = mi;
                  v[m-1-i][j] = mi;
                  v[m-1-i][n-1-j] = mi;
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
          //cerr << "Time Elapsed: " << ((double)(clock()-clk))/CLOCKS_PER_SEC << "\n";
          return 0;
      }
  

    Time Complexity  : O(t*m*n*log(max_element))
                       t test cases
                       m*n for scanning half the matrix
                       log(max_element) for doing binary search from 1 to max({v[i,j], v[i,n-1-j], v[m-1-i][j], v[m-1-i][n-1-j]})

    Space Complexity : O(1)  
                       Since no auxillary space other than input matrix is used.
   
  
  
## Efficient Soln:

    Instead of performing binary search, we just need to find the median of {v[i,j], v[i,n-1-j], v[m-1-i][j], v[m-1-i][n-1-j]}.
    Since median is the value closet to all 4 values.
  
      
       Time Complexity : O(t*m*n)
                         t test cases
                         m*n for scanning half the matrix

       Space Complexity : O(1)  Since no auxillary space other than input matrix is used.
       
