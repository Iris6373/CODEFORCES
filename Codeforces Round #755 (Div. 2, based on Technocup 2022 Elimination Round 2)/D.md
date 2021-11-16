# Problem Statement

## [D. Guess the Permutation](https://codeforces.com/contest/1589/problem/D)


## My solution :  (Accepted)

    Consider this sequence with i=4, j=9, k=13 and after applying the operation, we get :
    
    1  2  3    4  5  6  7  8    9  10 11 12 13   14 15
    1  2  3    8  7  6  5  4    13 12 11 10  9   14 15
    
    At each of the break points, we can see that (i,i+1), (j,j+1), (k,k+1) have same number of inversions.
    We can apply binary search to find the no. of inversions between 1 and (i | j | k) and find them.
    But each takes log2(10^9) = 29. So, total operations are 29*3 = 87 > 40 operations allowed.
    
    Thus, we can apply binary search only once and somehow use it to find the others.
    
    First, let's find total inversions, tot.
    
    So, let's find 'k'. We use l=1 and r=(b+c/2), where b = 1, c = n (initially).
    Then we change r in further operations and find inversions from 1 to r and compare with the total inversions (tot)
  
    After finding 'k', we find 'j' using a hidden trick.
    The no. of inversions i.e (1,j) - (1,j-1) = no. of inversions at k.
    This gives the length j to k, as there are (no. of inversions at k + 1) elements in that range. 
    Thus, we found 'j'.
    
    Similarly, we can 'i' except this time we should use the no. of inversions at j-1 : (1,j-1) - (1,j-2).
    This is because the no. of inversions at j-1 and j are same.
    Thus, we found 'i'.
        
        
   ### Code : (.cpp)  
      
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
          #define pb emplace_back
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
          template <class T, class V> void _p(unordered_map <T, V> v) {cout << "[ "; for (auto i : v) {_p(i); cout << " ";} cout << "]";}

          #define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
          template<typename ...Args>
          void logger(string vars, Args&&... values) {
              cout << vars << " = ";
              string delim = "";
              (..., (cout << delim << values, delim = ", "));
          }

          void test_cases(int t, int n, int a) {
              srand(time(NULL));
              int T = rand() % t + 1, N;
              cout << T << "\n";
              while (T--) {
                  cout << N << "\n";
                  f(T) cout << (rand() % a + 1) << '\n';
                  cout << "\n";
              }
          }

          void correctSolution() {

          }


          void solve() {  
              ll i, j, k, m, n, tot, a=0, b=1, x, y, c, d, ans = 0, f=0;
              string s;
              cin >> n;
              b = 1; c = n;
              k = n;
              cout << "? " << b << " " << c << endl;
              cin >> tot;
              while (b < c) {
                  d = (b+c)/2;
                  cout << "? " << 1 << " " << d << endl;
                  cin >> x;
                  if (x < tot) {
                      b = d;
                  }
                  else {
                      c = d;
                  }
                  k = min(k,c);
                  if (b == c-1) break;
              }
              cout << "? " << 1 << " " << k << endl;
              cin >> a;
              cout << "? " << 1 << " " << k-1 << endl;
              cin >> b;
              j = k - (a-b);
              cout << "? " << 1 << " " << j-1 << endl;
              cin >> a;
              cout << "? " << 1 << " " << j-2 << endl;
              cin >> b;
              i = j - (a-b) - 1;
              cout << "! " << i << " " << j << " " << k << endl;
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



    Time Complexity  : O(log(N))
                       t test cases
                       To be precise 1 + log2(10^9) + 2 + 2 = 33 operations at worst case.

    Space Complexity : O(1)
                       No extra space is used.
                       
   
  
  
