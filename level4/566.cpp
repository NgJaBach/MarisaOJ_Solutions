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

struct node{
    int type; // 0 add, 1 query
    int id;
    int x,y;
};

vector<node>times[1005];
vector<pii>connect[N];
ll floyd[N][N],ans[50005];
bool activate[N];

void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<=1000;++i) times[i].clear();
    for(int i=1;i<=n;++i){
        activate[i]=false;
        connect[i].clear();
        int x;
        cin>>x;
        times[x].pb({0,0,i,0});
    }
    while(m--){
        int x,y,z;
        cin>>x>>y>>z;
        connect[x].pb({y,z});
        connect[y].pb({x,z});
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(i==j) floyd[i][j]=0;
            else floyd[i][j]=INF;
        }
    }
    int q;
    cin>>q;
    for(int i=0;i<q;++i){
        int x,y,t;
        cin>>x>>y>>t;
        times[t].pb({1,i,x,y});
    }
    for(int i=0;i<=1000;++i){
        for(auto tmp:times[i]){
            if(tmp.type==0){
                int x=tmp.x;
                activate[x]=true;
                for(auto shit:connect[x]){
                    int y,z;
                    tie(y,z)=shit;
                    if(activate[y] and z<floyd[x][y]){
                        for(int u=1;u<=n;++u){
                            if(!activate[u]) continue;
                            for(int v=1;v<=n;++v){
                                if(!activate[v]) continue;
                                floyd[u][v]=min(floyd[u][v],floyd[u][x]+floyd[y][v]+z);
                                floyd[u][v]=min(floyd[u][v],floyd[u][y]+floyd[x][v]+z);
                            }
                        }
                    }
                }
            }
            else{
                ans[tmp.id]=floyd[tmp.x][tmp.y];
                if(ans[tmp.id]==INF) ans[tmp.id]=-1;
            }
        }
    }
    for(int i=0;i<q;++i) cout<<ans[i]<<endl;
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
