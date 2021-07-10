# Problem Statement

## [A. Exciting Bets](https://codeforces.com/contest/1543/problem/A)


## My solution :  (Accepted)

    The GCD of 'a' and 'b' is always |a-b|.
    The exception is when a == b, where the answer is {0,0}.
    Else, we either increase or decrease 'a' and 'b'.
    
    Since we need to minimize number of moves, we take the minimum.
    
    Thus the answer for this case is min(abs(a-b)-(min(a,b)%abs(a-b)), (min(a,b)%abs(a-b))).
  
        
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
          cin >> a >> b;
          if (a == b) cout << "0 0";
          else if (abs(a-b) == 1) cout << "1 0";
          else {
              cout << abs(a-b) << " ";
              y = min(abs(a-b)-(min(a,b)%abs(a-b)), (min(a,b)%abs(a-b)));
              cout << y;
          }
          cout << "\n";
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


    Time Complexity  : O(t)
                       t test cases
                       O(1) per test case

    Space Complexity : O(1)  
                       Since no auxillary space is used.
   
  
