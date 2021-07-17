# Problem

## [Arithmetic Square](https://codingcompetitions.withgoogle.com/kickstart/round/00000000004361e3/000000000082b813)


# Solution 

## 1) Check for a valid AP 

     There are 8 possible APs in a a3x3 matrix. (3 rows, 3 columns and 2 diagonals)
     
     The 1st and 3rd rows are independent of v[1][1].
     Thus, we check if they form an AP by verifying this : 1st row :  v[0][2]-v[0][1] = v[0][1]-v[0][0]
     If it is satisfied, we add 1 to ans.
     Similarly, this is done for 3rd row, 1st and 3rd columns.
     
     For the other 4 sequences, we use this strategy.
     Let's consider the middle row.
     the middle row can form an AP only if abs(v[0][1]-v[2][1]) % 2 == 0.
     This is done so that the 'd' (AP : a, a+d, a+2d, .., a+(n-1)d) of the AP is an integer. 
     If the condition is passed, we calculate the middle element using this : min(v[0][1],v[2][1]) + abs(v[2][1]-v[0][1])/2
     Next, we add this value to a map.
     
     Similarly, this is done for 2nd col and other 2 diagonals.
     Finally, we add the maximum frequency in the map, which increase total number of APs.
     
        
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
              ll a1 = 0, a2 = 0, a3 = 0, a4 = 0, b = 0, n, x, y, c, d, ans = 0;
              vector<vector<ll>> v(3,vector<ll>(3,0));
              map <ll,ll> mp;
              cin >> v[0][0] >> v[0][1] >> v[0][2] >> v[1][0] >> v[1][2] >> v[2][0] >> v[2][1] >> v[2][2];
              if (v[0][2]-v[0][1] == v[0][1]-v[0][0]) ans++;
              if (v[2][2]-v[1][2] == v[1][2]-v[0][2]) ans++;
              if (v[2][0]-v[1][0] == v[1][0]-v[0][0]) ans++;
              if (v[2][2]-v[2][1] == v[2][1]-v[2][0]) ans++;
              if ((v[2][2]-v[0][0]) % 2 == 0) { 
                  a1 = min(v[0][0],v[2][2]) + abs(v[2][2]-v[0][0])/2; 
                  mp[a1]++; 
              }
              if ((v[0][2]-v[2][0]) % 2 == 0) {
                  a2 = min(v[0][2],v[2][0]) + abs(v[0][2]-v[2][0])/2;
                  mp[a2]++;
              }
              if ((v[2][1]-v[0][1]) % 2 == 0) {
                  a3 = min(v[0][1],v[2][1]) + abs(v[2][1]-v[0][1])/2, mp[a3]++;
              }
              if ((v[1][2]-v[1][0]) % 2 == 0) {
                  a4 = min(v[1][0],v[1][2]) + abs(v[1][2]-v[1][0])/2, mp[a4]++;
              }
              b = 0;
              for (auto z : mp) {
                  if (z.S > b) b = z.S;
              }
              cout << "Case #" << z+1 << ": " << ans+b << "\n";
              z++;
          }
          return 0;
      }   


     Time Complexity  : O(t) 
                        Since we have 't' test cases and each test case takes only O(1) time
     Space Complexity : O(1)
                        Since no auxillary space is used.
