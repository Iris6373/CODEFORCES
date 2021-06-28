# Problem

[B. Love Song](https://codeforces.com/contest/1539/problem/B)


## My solution :

    Using prefix sum, we calculate and store the value in vector.
    If a -> 1
       b -> 2
       ..
       z -> 26
    Similarly, we add and store these values.

    If a == 1, then we print v[b-1]
    Else v[b-1]-v[a-2]
    
    
    
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
            ll ans = 0, n, l, i, j, k, m, a, b;
            string s;
            cin >> n >> k >> s;
            vt v(sz(s),0);
            f(sz(s)) {
                j = s[i]-'a'+1;
                if (i == 0) v[i] = j;
                else v[i] += v[i-1]+j;
            }
            //f(sz(s)) cout << v[i] << " ";
            f(k) {
                cin >> a >> b;
                if (a < 2) cout << v[b-1] << "\n";
                else cout << v[b-1]-v[a-2] << "\n";
            }
            //cout << "\n";
            // vector<vector<ll>> v(m, vector <ll>(n,0));
            // f(m) {
            //     f1(j,n) {
            //         cin >> v[i][j];
            //     }
            // }

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
        
        
    Time Complexity : O(t + q)
                      O(t) to read the string
                      O(1) for each query

    Space Complexity : O(N)  Since a vector is used to store prefix sum
