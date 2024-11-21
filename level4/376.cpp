// Dreaming the Impossible

#include<bits/stdc++.h>

using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long int ll;
typedef unsigned long long ull;
typedef long double ld;
#define pb push_back
#define pob pop_back
#define emp emplace_back
#define mp make_pair
#define upb upper_bound
#define lwb lower_bound
#define rev reverse
#define fi first
#define se second
#define gcd __gcd
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pld pair<ld,ld>
#define getl(s) getline(cin, s);
#define bend(a) a.begin(),a.end()
#define mset(a) memset(a, 0, sizeof(a))
#define setpre(x) fixed << setprecision(x)
#define endl '\n'
const int N=1005,M=1000000007;
const ll INF=1e18+7;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<vector<int>>dp(n+1, vector<int>(1 << (2*k+1), 0));
    // So cach sap xep khi: xet den gia tri i,
    // bitmask j cho biet cach day dung nhung cach sap xep nao (max 2*k+1 cach) -k <- | -> +k
    dp[0][0] = 1;                                                       // Khong lam gi - Thang Ngot
    for(int i = 1; i <= n; ++i){                                        // xet gia tri 1->n (duyet tu trai sang phai)
        for(int j = 0; j < (1 << (2*k+1)); ++j){                        // xet tat ca bitmask
            int state = (j >> 1);                                       // Khi sang phai thi phai bo qua cach sap xep o vi tri ben trai cung
            for(int bit = 0; bit < (2*k+1); ++bit){                                 // kiem tra co bit nao chua bat = cach chua dung den
                int pos = i + (bit - k);                                            // vi tri sap xep vao
                if(!(state & (1 << bit)) and (pos >= 1) and (pos <= n)){
                    dp[i][state^(1<<bit)] = (dp[i][state^(1<<bit)] + dp[i-1][j]) % M;
                }
            }
        }
    }
    ll ans = 0;
    for(int i = 0; i < (1 << (2*k+1)); ++i)
        ans = (ans + dp[n][i]) % M;
    cout<<ans;
    return;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
//    freopen(".inp","r",stdin);
//    freopen(".out","w",stdout);
    int t=1;
    while(t--){
        solve();
        cout<<endl;
    }
    return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |

------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |

------------------------------    |
==================================+
*/