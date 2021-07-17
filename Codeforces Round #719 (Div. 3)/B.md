// Problem : https://codeforces.com/contest/1520/problem/B

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
    if (n <= 9) {
        cout << n << "\n";
        return;
    }
    string st="", s = to_string(n);
    f(sz(s)) st += s[0];
    if (s == st) {
        a = s[0] - '0';
        a += (sz(s)-1)*9;
        cout << a << "\n";
    }
    else {
        //cout << "yes\t";
        a = s[0] - '0';
        a--;
        b = stoi(st);
        //cout << n << " " << b << "\n";
        if (n > b) a++;
        if (a == -1) a = 0;
        a += (sz(s)-1)*9;
        cout << a << "\n";
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
