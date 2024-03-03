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

void solve(){
    int x, y ,p ,q; cin >> x >> y >> p >> q;
    queue<tuple<int,int,int>>Q;
    vector dp(2, vector(x + 1, vector<int>(y + 1 , 1e9)));
    dp[0][x][y] = 0;
    Q.push({0, x, y});
    int ans = 1e9;
    while (!Q.empty()) {
        tuple<int,int,int> now = Q.front();
        Q.pop();
        auto &[pos, le_sheep, le_wolf] = now;
        int r_sheep = x - le_sheep, r_wolf = y - le_wolf;
        if(!pos) {
            for (int i = 0; i <= le_sheep; i++) {
                for (int j = 0; i + j <= p && j <= le_wolf; j++) {
                    if ((le_sheep - i != 0) && (le_sheep - i + q < le_wolf - j)) continue;
                    if (r_sheep + i == x){
                        ans = min(ans, dp[0][le_sheep][le_wolf] + 1);
                        continue;
                    }
                    if(dp[0][le_sheep][le_wolf] + 1 < dp[1][le_sheep - i][le_wolf - j]) {
                        dp[1][le_sheep - i][le_wolf - j] = dp[0][le_sheep][le_wolf] + 1;
                        Q.push({1, le_sheep - i, le_wolf - j});
                    }
                }
            }
        }
        else{
            for (int i = 0; i <= r_sheep; i++) {
                for (int j = 0; i + j <= p && j <= r_wolf; j++) {
                    if ((r_sheep - i != 0) && (r_sheep - i + q < r_wolf - j)) continue;
                    if (dp[1][le_sheep][le_wolf] + 1 < dp[0][le_sheep + i][le_wolf + j]) {
                        dp[0][le_sheep + i][le_wolf + j] = dp[1][le_sheep][le_wolf] + 1;
                        Q.push({0, le_sheep + i, le_wolf + j});
                        continue;
                    }
                }
            }
        }
    }
    if (ans == 1e9) ans = -1;
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1; //cin >> t;
    while(t--) solve();
}