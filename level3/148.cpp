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
const int N=5005,M=1000000007;
const ll INF=1e18+7;

int n;
ll a[N];
ll dp[N][N][2];

ll back(const int &x,const int &y,const bool &turn){
    if(x==y){
        if(turn) return a[x];
        return -a[x];
    }
    if(dp[x][y][turn]!=-1) return dp[x][y][turn];
    if(turn) return dp[x][y][turn]=max(a[x]+back(x+1,y,false),a[y]+back(x,y-1,false));
    return dp[x][y][turn]=min(-a[x]+back(x+1,y,true),-a[y]+back(x,y-1,true));
}

void solve(){
    cin>>n;
    for(int i=1;i<=n;++i){
        for(int j=i;j<=n;++j){
            dp[i][j][0]=-1;
            dp[i][j][1]=-1;
        }
        cin>>a[i];
    }
    cout<<back(1,n,true);
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

