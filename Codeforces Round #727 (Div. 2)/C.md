# Problem Statement

[C. Stable Groups](https://codeforces.com/contest/1539/problem/C)


## My solution :

    Sort the input vector 'v'
    Inorder to find the number of students to be filled in each gap, we use a = (v[i]-v[i-1]-1)/x
    This value is added to vector 'gap'
    
    Sort the vector 'gap'
    Now, fill the additional students according to the sorted order of 'gap'
    
    If 'k' additional students are not enough, we break the loop and print (remaining gaps + 1)
    Else, 'k' students are sufficient to fill the vector and no breaking required, so print (1)
    
    
    
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
          ll ans = 0, n, l, i, j, k, m, a, b, x, t;
          string s;
          cin >> n >> k >> x;
          vt v(n), gap;
          f(n) {
              cin >> v[i];
          }
          sort(all(v));
          for (i=1;i<n;i++) {
              if (v[i]-v[i-1] > x) {
                  a = (v[i]-v[i-1]-1)/x;
                  gap.pb(a);
              }
          }
          // cout << k << "\n";
          // f(sz(gap)) cout << gap[i] << " "; cout << "\n";
          sort(all(gap));
          b = 0;
          f(sz(gap)) {
              if (k-gap[i] < 0) {
                  b = sz(gap)-i+1;
                  break;
              }
              k -= gap[i];
          }
          // cout << k << "\n";
          if (!b) cout << "1";
          else cout << b;
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
          //cerr << "Time Elapsed: " << ((double)(clock()-clk))/CLOCKS_PER_SEC << "\n";
          return 0;
      }
      
      
      
    Time Complexity : O(N*log(N))
                      For using STL sort function

    Space Complexity : O(N)  
                       Since additional vector 'gap' is used.
