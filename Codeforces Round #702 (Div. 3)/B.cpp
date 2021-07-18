// Problem : https://codeforces.com/contest/1490/problem/B

// Iris_6373

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vt;
typedef pair<ll, ll> pr;
typedef vector<pr> vp;
typedef map<ll, ll> mp;
#define F first;
#define S second;
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
    ll i, j, k, m, n, a=0, b=0, c=0, d=0, e=0, w, ans = 0;
    string s1, s2;
    cin >> n;
    vt v(n);
    f(n) {
        cin >> v[i];
        if (v[i]%3 == 0) a++;
        else if (v[i]%3 == 1) b++;
        else c++;
    }
    e = n/3;
    //a = 5, b = 4, c = 0;
    if (a == b && b == c) { cout << "0\n"; return; }
    d = min({a,b,c});
    //cout << "a = " << a << "\t";
    //cout << "b = " << b << "\t";
    //cout << "c = " << c << "\t";
    if (c == d) {
        ans += (e-c);
        //cout << "ans = " << ans << "\n";
        b -= (e-c);
        //cout << "e = " << d << "\n";
        if (b > e) ans += abs(2*(e-b));
        else ans += abs(e-b);
        //cout << "ans = " << ans << "\n";
    }
    else if (b == d) {
        ans += (e-b);
        a -= (e-b);
        if (a > e) ans += abs(2*(e-a));
        else ans += abs(e-a);
    }
    else {
        ans += (e-a);
        c -= (e-a);
        if (c > e) ans += abs(2*(e-c));
        else ans += abs(e-c);
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
    //cerr << "Time Elapsed: " << ((double)(clock()-clk))/CLOCKS_PER_SEC << "\n";
    return 0;
}
