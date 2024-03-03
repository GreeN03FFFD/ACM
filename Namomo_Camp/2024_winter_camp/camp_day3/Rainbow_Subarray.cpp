
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
ll ksm(ll a,ll b) {ll res=1;a%=mod; while(b){if(b&1)res=res*a%mod;b>>=1;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) {return b==0?a:gcd(b,a%b);}
ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
ll inv(ll x) {return ksm(x, mod-2);}

struct pval_set{
    multiset<ll> st, ed;
    ll pval;
    ll sum_st = 0, sum_ed = 0;
    pval_set(ll x){
        pval = x;
        ed.insert(x), sum_ed = x;
    }
    ll get_res() {
        return sum_ed - ll(ed.size()) * pval + ll(st.size()) * pval - sum_st;
    }
    void del(ll x){
        if(x >= pval) {
            auto it = ed.find(x);
            if (it != ed.end()) ed.erase(it), sum_ed -= x;
        }
        else {
            auto it = st.find(x);
            if (it != st.end()) st.erase(it), sum_st -= x;
        }
        rst();
    }
    void ins(ll x){
        if(x >= pval) ed.insert(x), sum_ed += x;
        else st.insert(x), sum_st += x;
        rst();
    }
    void rst(){
        if(int(ed.size()) - int(st.size()) > 1){
            auto it = ed.begin();
            sum_st += *it, sum_ed -= *it;
            st.insert(*it), ed.erase(it);
        }
        if(int(st.size()) - int(ed.size()) >= 1){
            auto it = prev(st.end());
            sum_st -= *it, sum_ed += *it;
            ed.insert(*it), st.erase(it);
        }
        pval = *ed.begin();
    }
};

void solve(){
    ll n, k; cin >> n >> k;
    vector<ll> v(n + 1);
    for (ll i = 1; i <= n; i++) cin >> v[i], v[i] -= i;
    pval_set S(v[1]);
    int ans = 1;
    for (int le = 1, r = 2; r <= n; r++) {
        S.ins(v[r]);
        ll res = S.get_res();
        while(res > k && le < r){
            S.del(v[le]), le++;
            res = S.get_res();
        }
        ans = max(ans, r - le + 1);
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
}
