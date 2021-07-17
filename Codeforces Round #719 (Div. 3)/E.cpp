// Problem : https://codeforces.com/contest/1520/problem/E

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
    ll i, j, k, m, n, a=0, b=0, c=0, d=0, e=0, w, f[500][500];
    string s, s2;
    cin >> n >> s;
    ll st=-1, ed=-1, ct=0, left=0;
    f(n) {
        if (s[i] == '*') {
            ct++;
            if (st == -1) st = i;
            ed = i;
        }
    }
    if (st == ed || ct == ed-st+1) cout << "0\n";
    else {
        ll ans = 0;
        f(n) {
            if (s[i] == '*') left++;
            else {
                ans += min(left, ct-left);
            }
        }
        cout << ans << "\n";
    }
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
