# Problem Statement

## [B. Pleasant Pairs](https://codeforces.com/contest/1541/problem/B)


## My solution : 

    We use the brute-force approach with small modification.
    Since (i+j) can never exceed 2*n-1, we break the loop once it exceeds.
  
        
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
            ll i, j, k, n, a=0;
            cin >> n;
            vp v;
            f(n) {
                cin >> k;
                a = i+1;
                v.pb({k,a});
            }
            sort(all(v));
            a = 0;
            f1(i,n) {
                f2(j,i+1,n) {
                    ll p = v[i].F, q = v[i].S, r = v[j].F, s = v[j].S;
                    if (p*r == q+s) a++;
                    if (p*r > 2*n) break;
                }
            }
            cout << a << "\n";
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

   
   
    Time Complexity  : O(t*n*log(n))
                       t test cases
                       Each test case take O(n*log(n)) time to count number of pairs.

    Space Complexity : O(1)  
                       Since no auxillary space other than input matrix is used.
