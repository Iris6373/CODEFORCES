// Problem : https://codeforces.com/contest/1490/problem/A

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
    ll i, j, k, m, n, a=0, b=0, c=0, d=0, e=0, w, f[500][500];
    string s1, s2;
    cin >> n;
    vt v(n);
    f(n) {
        cin >> v[i];
    }
    for (i=0;i<n-1;i++) {
        if (v[i] > v[i+1]) {
            a = v[i];
            while (a > 2*v[i+1]) {
                b++;
                //cout << a << " " << v[i+1] << "\n";
                if (a & 1) a++;
                a /= 2;
            }
        }
        else if (v[i] < v[i+1]) {
            a = v[i+1];
            while (a > 2*v[i]) {
                b++;
                //cout << v[i] << " " << a << "\n";
                if (a & 1) a++;
                a /= 2;
            }
        }
    }
    cout << b << "\n";
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
