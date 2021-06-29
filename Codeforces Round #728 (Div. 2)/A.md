# Problem Statement

[A. Pretty Permutations](https://codeforces.com/contest/1541/problem/A)


## My solution : 

      Inorder to reduce the total distance, we can just swap the adjacent positions and print them.
      In case of odd numbers, we print the first 'n-3' numbers as the above logic and 
      print the last '3' numbers in any order that is not matching with its index.
      
      
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
          ll ans = INT_MAX, n, l, i, j, k, m;
          string s;
          cin >> n;
          vt v(n);
          f(n) v[i] = i+1;
          if (n%2 == 0) {
              f(n) {
                  cout << v[i+1] << " " << v[i] << " ";
                  i++;
              }
          }
          else {
              n -= 3;
              f(n) {
                  cout << v[i+1] << " " << v[i] << " ";
                  i++;
              }
              n += 3;
              cout << v[n-2] << " " << v[n-1] << " " << v[n-3];
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
      
      
    Time Complexity  : O(T*N)
                       T test cases
                       O(N) for each test case

    Space Complexity : O(N)  
                       Since we used a vector is used to store its indices.
                       
    
    We can also a variable to keep track of the value to print intead of using a vector. 
