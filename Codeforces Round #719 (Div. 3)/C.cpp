// Problem : https://codeforces.com/contest/1520/problem/C

/**
    author:  Iris_6373       
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vt;
typedef pair<ll, ll> pr;
typedef vector<pr> vp;
typedef map<ll, ll> mp;
#define F first;
#define S second;
#define mpr make_pair
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
    ll i, j, k, x, m, n=0, a=0, b=0, c=0, d=0, e=0, w=0;
    cin >> n;
    if (n == 1) cout << "1\n";
    else if (n == 2) cout << "-1\n";
    else if (n == 3) cout << "2 9 7\n4 6 3\n1 8 5\n";
    else {
        vector<vector<int>> v( n , vector<int> (n, 0));
        a = 1;
        f(n) {
            f1(j,n) v[i][j] = a, a++;
        }
        // f(n) {
        //     f1(j,n) { cout << v[i][j] << " "; } 
        //     cout << " \n";
        // }
        b = 0;
        if (n%2) b = 1;
        fo(j,b,n,2) {
            fo(i,0,n,1) {
                swap(v[i][j],v[i][j+1]);
            }
        }
        b++;
        fo(j,b,n-1,2) {
            fo(i,0,n,1) {
                swap(v[i][j],v[i][j+1]);
            }
        }
        f(n) {
            f1(j,n) { cout << v[i][j] << " "; } 
            cout << " \n";
        }
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    //cout << fixed << setprecision(7);
    ll t;
    cin >> t;
    //t = 1;
    while (t--) {
        solve();
    }
    //cerr << "Time Elapsed: " << ((double)(clock()-clk))/CLOCKS_PER_SEC << "\n";
    return 0;
}
