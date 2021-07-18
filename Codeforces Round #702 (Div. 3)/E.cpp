// Problem : https://codeforces.com/contest/1490/problem/E

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
    ll i, j, k, m, n;
    string s1, s2;
    cin >> n;
    vt v(n), u(n,0);
    vector<pair<int,int>> p;
    f(n) {
        cin >> v[i];
        p.pb({v[i],i+1});
    }
    sort(all(p));
    u[0] = p[0].F;
    for (i=1;i<n;i++) {
        if (p[i].F > u[i-1]) p[i-1].F = -1; 
        u[i] = u[i-1]+p[i].F;
    }
    u.clear();
    for (i=n-1;i>=0;i--) {
        if (p[i].F != -1) u.pb(p[i].S);
        else break;
    }
    sort(all(u));
    cout << sz(u) << "\n";
    f(sz(u)) cout << u[i] << " ";
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
