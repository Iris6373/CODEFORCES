# Problem Statement

## [B. Swaps](https://codeforces.com/contest/1573/problem/B)


## My solution :  (Accepted)

    Let's consider the given example, 
    7 5 9 1 3
    2 4 6 10 8
    
    If 7 stays in the same position and we need to make changes in 'b' suct that a is lexicographically smaller than b.
    The minimum would be 3 since we can bring 10 to 1st pos with 3 swaps (6,10  ->  4,10  ->  2,10)
    
    In case of 5, we first bring 5 to 1st pos in 1 swap and the most recent element in 'b' which is greater than 5 is 6, 2 swaps for it = 3
  
    Similarly, as we go forwards, the no. of swaps to bring that element in a to 1st index would be its (pos-1).
    To make it lexicographically smaller than b, we find the recent greater element in b and bring it to 1st pos (pos-1).
    
    We can do the same thing for b, but here we find the recent least element in 'a' smaller than the current element in 'b'
    
    To summarize, it looks like this :
    
    0+3  1+2  2+3  3+0  4+1
     7    5    9    1    3
     
     2    4    6   10    8
    0+3  1+3  2+1  3+0  4+0
    
    The least out of them is 3.
    But this approach takes O(N) for every element to find its recent smaller or greater number.
    Inorder to optimize this, we use 2 maps, 'odd' and 'even' which store the occurences of next greater or smaller elements.
    
    First, we initialize the values of all odd and even elements  with -1.
    Next, while traversing through array 'a' :
        if even[u[i]+1] is not -1, we skip this iteration
        else we update 'even' from u[i]+1 and assign even[u[i]+1] = i
             This is done until the even[u[i]+1] is -1 with step up of 2.
             
    The same process is repeated for array 'b' with a few differences.
    if odd[v[i]+1] is not -1, we skip this iteration
        else we update 'odd' from v[i]-1 and assign odd[v[i]-1] = i
             This is done until the odd[v[i]-1] is -1 with step up of -2.
    
    After this pre-processing, we traverse through both maps and find answer by,
    ans = min({ans, i+odd[u[i]], i+even[v[i]]})


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

        void solve() {  
            ll i, j, k, m, n, a=0, b=0, x, y, c, d, ans = INT_MAX, f=0;
            string s;
            map<ll,ll> odd, even;
            cin >> n;
            f(2*n) {
                if ((i+1)%2 != 0) {
                    odd[i+1] = -1;
                }
                else even[i+1] = -1;
            }
            vt v(n), u(n);
            f(n) {
                cin >> u[i]; 
                if (even[u[i]+1] != -1) continue;
                for (j=u[i]+1;j<=2*n;j+=2) {
                    if (even[j] != -1) break;
                    even[j] = i;
                }
                // de(even);
            }
            f(n) {
                cin >> v[i]; 
                if (odd[v[i]-1] != -1) continue;
                for (j=v[i]-1;j>=1;j-=2) {
                    if (odd[j] != -1) break;
                    odd[j] = i;
                }
                // de(odd);
            }
            // de(odd);
            // de(even);
            f(n) {
                ans = min(ans, i+odd[u[i]]);
                ans = min(ans, i+even[v[i]]);
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
            //cerr << "Time Elapsed: " << ((db)(clock()-clk))/CLOCKS_PER_SEC << "\n";
            return 0;
        }   


    Time Complexity  : O(t*n*log(n))
                       t test cases
                       n for scanning and traversing each string
                       log(n) for storing each number (can be reduced to O(1) using unorderd_map)

    Space Complexity : O(n)  
                       Since we use a map to store the values for each number. 
   
  
  
