# Problem Statement

## [C. Need for Pink Slips](https://codeforces.com/contest/1543/problem/C)


## My solution :  (Accepted)

    The quest is over, if a Pink slip is the item drawn.
    To find the expected number of races, we can do Brute Force - Recursive DFS,
    which finds all combinations of C,M,P and its probability.
    
    The parameters of the recursive function are a, b, c, x, y, z.
    Here, y calculates the number of draws and z calculaes the probability.
    
    The code is self-explanatory.
  
        
   ### Code : (.cpp)  
      
          // Iris_6373

          #include <bits/stdc++.h>
          using namespace std;
          typedef long long ll;
          typedef long double db;
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

          db ans = 0;

          void fun(char ch, db a, db b, db c, db x, ll y, db z) {
              if (ch == 'p' || c == (db)1) {
                  ans += (db)y*z*c;
                  return; 
              }
              else if (ch == 'c') {
                  z = (db)z*a;
                  if (a > x) {
                      a -= x;
                      if (b > 0+1e-9) b += (db)x/2, c += (db)x/2;
                      else c += x;
                  }
                  else {
                      if (b > 0+1e-9) b += (db)a/2, c += (db)a/2;
                      else c += a;
                      a = 0;
                  }
                  if (a > 0+1e-9) fun('c',a,b,c,x,y+1,z);
                  if (b > 0+1e-9) fun('m',a,b,c,x,y+1,z);
                  fun('p',a,b,c,x,y+1,z);
              }
              else {
                  z = (db)z*b;
                  if (b > x) {
                      b -= x;
                      if (a > 0+1e-9) a += (db)x/2, c += (db)x/2;
                      else c += x;
                  }
                  else {
                      if (a > 0+1e-9) a += (db)b/2, c += (db)b/2;
                      else c += b;
                      b = 0;
                  }
                  if (a > 0+1e-9) fun('c',a,b,c,x,y+1,z);
                  if (b > 0+1e-9) fun('m',a,b,c,x,y+1,z);
                  fun('p',a,b,c,x,y+1,z);
              }
          }


          void solve() {  
              ll i, j, k, n;
              db a, b, c, x;
              ans = 0;
              cin >> a >> b >> c >> x;
              fun('c',a,b,c,x,1,1);
              fun('m',a,b,c,x,1,1);
              fun('p',a,b,c,x,1,1);
              cout << prec(12) << ans << "\n";
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
      

    Time Complexity  : O(t*2^22)
                       t test cases
                       O(2^22) per test case
   
  
