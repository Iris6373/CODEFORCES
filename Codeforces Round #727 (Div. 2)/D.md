# Problem Statement

[D. PriceFixed](https://codeforces.com/contest/1539/problem/D)


## My solution : 

      From the problem statement, it is clear that
      For every i-th product, the price becomes 1 if b[i] items are bought.
      
      Inorder to get maximum profit, we must first products of the type whose b[i] is the largest so far.
      That is why, we store the [a[i],b[i]] in a vector of pairs(v) and sort it based on decreasing order of b[i].  
      
      Then usng two-pointers technique, we compare current pair with last pair.
      According to the products bought so far, we buy either of them (by parts or full).
      
      The code is self-explanatory.
      
      
      
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

          bool cmp(const pair<ll,ll> &a, const pair<ll,ll> &b) {
              return (a.second > b.second);
          }

          void solve() {  
              ll ans = 0, n, l, i, j, k, m, a, b, x, c, d;
              cin >> n;
              vp v;
              f(n) {
                  cin >> a >> b;
                  x += a;
                  v.pb({a,b});
              }
              sort(all(v),cmp);
              c = 0;
              i = 0;
              x = 0;
              while (v.size()) {
                  a = v[i].F, b = v[i].S;
                  auto y = v.back();
                  c = y.F, d = y.S;
                  if (i == v.size()-1) {
                      if (x+a >= b) {
                          if (b >= x) {
                              ans += (b-x)*2;
                              a -= (b-x);
                          } 
                          ans += a;
                      }
                      else ans += 2*a;
                      break;
                  }
                  else if (a+x <= d) {
                      x += a;
                      ans += 2*a;
                      i++;
                  }
                  else if (x >= d) {
                      x += c;
                      ans += c;
                      v.pop_back();
                  }
                  else if (a+x > d) {
                      ans += 2*(d-x);
                      if (d-x == a) i++;
                      else v[i].F -= (d-x);
                      x += (d-x);
                      x += c;
                      ans += c;
                      v.pop_back();
                  } 
              }
              cout << ans;
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
          
          

     Time Complexity  : O(N*log(N))
                        Sorting using STL takes O(N*log(N)) and two-pointers take O(N) time

     Space Complexity : O(N)  
                        Since we use a vector of pairs to store a[i] and b[i]


