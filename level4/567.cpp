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
const int N=105,M=1000000007;
const ll INF=1e18+7;

ll floyd[N][N],lmao[N][N];

void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(i==j) floyd[i][j]=0;
            else floyd[i][j]=INF;
        }
    }
    while(m--){
        int x,y,z;
        cin>>x>>y>>z;
        floyd[x][y]=min(floyd[x][y],(ll)z);
        floyd[y][x]=min(floyd[y][x],(ll)z);
    }
    for(int k=1;k<=n;++k){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                floyd[i][j]=min(floyd[i][j],floyd[i][k]+floyd[k][j]);
            }
        }
    }
    ll ans=INF;
    for(int x=1;x<=n;++x){
        for(int y=1;y<=n;++y){
            for(int i=1;i<=n;++i){
                for(int j=1;j<=n;++j){
                    lmao[i][j]=floyd[i][j];
                }
            }
            lmao[x][y]=0;
            lmao[y][x]=0;
            for(int i=1;i<=n;++i){
                for(int j=1;j<=n;++j){
                    lmao[i][j]=min(lmao[i][j],lmao[i][x]+lmao[y][j]);
                    lmao[i][j]=min(lmao[i][j],lmao[i][y]+lmao[x][j]);
                }
            }
            ll sum=0;
            for(int i=1;i<=n;++i){
                for(int j=i;j<=n;++j){
                    sum+=lmao[i][j];
                }
            }
            ans=min(ans,sum);
        }
    }
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

