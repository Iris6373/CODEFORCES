// Problem : https://codeforces.com/contest/1490/problem/D

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

ll n;
vt arr;
ll lvl = 0;

void ini(ll n);
void fun(vt v, ll a, ll b, ll n, ll h);

void solve() {  
    ll i, j, k, m, c=0, d=0, e=0, w, f[500][500];
    string s1, s2;
    cin >> n;
    vt v(n);
    f(n) {
        cin >> v[i];
    }
    ini(n);
    fun(v,0,n-1,n,c);
    for (i=0;i<n;i++) cout << arr[i] << " ";
    cout << "\n";
    lvl = 0;
    arr.clear();
}

void ini(ll n) {
    for (int i=0;i<n;i++) arr.pb(0); 
}

void fun(vt v, ll a, ll b, ll n, ll h) {
    if (a >= 0 && b < n && b-a >= 0) {
        int c, d = INT_MIN;
        for (int i=a;i<=b;i++) {
            if (d < v[i]) {
                d = v[i];
                c = i;
            }
        }
        arr[c] = h;
        if (b-a == 0) return;
        fun(v,a,c-1,n,h+1);
        fun(v,c+1,b,n,h+1);
        //lvl--;
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
