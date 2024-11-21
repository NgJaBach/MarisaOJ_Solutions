// The Shadow Monarch

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
const int N=505,M=1000000007;
const ll INF=1e18+7;

ll a[N],pref[N],dp[N][N];

ll cal(int x,int y){
    return (pref[y]-pref[x-1])%100;
}

void solve(){
    int n;
    cin>>n;
    pref[0]=0;
    for(int i=1;i<=n;++i){
        dp[i][i]=0;
        for(int j=i+1;j<=n;++j) dp[i][j]=INF;
        cin>>a[i];
        pref[i]=a[i]+pref[i-1];
    }
    for(int i=2;i<=n;++i) dp[i-1][i]=a[i-1]*a[i];
    for(int k=3;k<=n;++k){
        for(int i=k;i<=n;++i){
            int x,y;
            x=i-k+1;
            y=i;
            for(int j=i-k+1;j<i;++j){
                dp[x][y]=min(dp[x][y],dp[x][j]+dp[j+1][y]+cal(x,j)*cal(j+1,y));
            }
        }
    }
    cout<<dp[1][n];
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

