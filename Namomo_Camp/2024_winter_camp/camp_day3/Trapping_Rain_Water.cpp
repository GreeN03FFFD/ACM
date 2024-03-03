
#include<iostream>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#include<cstring>
#include<set>
#include<queue>
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
const int N   = 2E6 + 7;
using namespace std;
typedef long long i64;
ll ksm(ll a,ll b) {ll res=1;a%=mod; while(b){if(b&1)res=res*a%mod;b>>=1;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) {return b==0?a:gcd(b,a%b);}
ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
ll inv(ll x) {return ksm(x, mod-2);}

struct shit{
    int n;
    vector<ll>a;
    set<ll>S;
    ll sum = 0;
    shit(int sz){
        n = sz;
        a.resize(n + 2);
        a[0] = 0, a[n + 1] = 9e18;
        S.insert(0), S.insert(n + 1);
    }
    void add(int x, int v) {
            auto pre = --S.upper_bound(x), nxt = S.upper_bound(x);
            if (a[x] + v > a[*pre]) {
                sum += (*nxt - x) * (a[x] + v - a[*pre]);
                while (a[*nxt] <= a[x] + v) {
                    sum += (*next(nxt) - *nxt) * (a[x] + v - a[*nxt]);
                    nxt = S.erase(nxt);
                }
                S.insert(x);
            }
            a[x] += v;
    }
};

void solve(){
    ll n, maxa = 0, suma = 0; cin >> n;
    vector<ll> a(n + 2);
    for (int i = 1; i <= n; i++) cin >> a[i], maxa = max(maxa, a[i]), suma += a[i];

    shit f(n), g(n);
    for (int i = 1; i <= n; i++)
        f.add(i, a[i]), g.add(i, a[n - i + 1]);
    int q; cin >> q;
    while (q--) {
        int x, v; cin >> x >> v;
        suma += v, maxa = max(a[x] + v, maxa), a[x] += v;
        f.add(x, v), g.add(n - x + 1, v);
        cout << f.sum + g.sum - maxa * n - suma << '\n';
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1; cin >> t;
    while (t--) solve();
}

