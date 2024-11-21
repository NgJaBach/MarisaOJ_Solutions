// NgJaBach: Forever Meadow <3

#include<bits/stdc++.h>

using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long int ll;
typedef unsigned long long ull;
#define pb push_back
#define pob pop_back
#define mp make_pair
#define upb upper_bound
#define lwb lower_bound
#define bend(a) a.begin(),a.end()
#define rev(x) reverse(bend(x))
#define mset(a) memset(a, 0, sizeof(a))
#define fi first
#define se second
#define gcd __gcd
#define getl(s) getline(cin, s);
#define setpre(x) fixed << setprecision(x)
#define endl '\n'
const int N=1050,M=1000000007;
const ll INF=1e18+7;
ll dp[N],a[N];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
//    freopen(".inp","r",stdin);
//    freopen(".out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;++i) cin>>a[i];
    mset(dp);
    dp[0]=1;
    for(int i=1;i<=n;++i){
        for(int j=k;j>=1;--j){
            dp[j]=(dp[j]+(dp[j-1]*a[i])%M)%M;
        }
    }
//    for(int i=0;i<=k;++i) cout<<dp[i]<<" "; cout<<endl;
    cout<<dp[k];
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
