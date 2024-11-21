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
#define mt make_tuple
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
const int N=200050,M=1000000007;
const ll INF=1e18+7;

ll mincost[N][6];
vector<pair<int,int> >gay[N];

void solve(){
    int n,m,k,x,y,z;
    cin>>n>>m>>k;
    while(m--){
        cin>>x>>y>>z;
        gay[x].pb({y,z});
        gay[y].pb({x,z});
    }
    for(int i=1;i<=n;++i){
        for(int j=0;j<=k;++j){
            mincost[i][j]=INF;
        }
    }
    mincost[1][0]=0;
    priority_queue<tuple<ll,int,int> >que;
    ll cost,ncost;
    int ticket;
    que.push(mt(0,0,1));
    while(!que.empty()){
        tie(cost,ticket,x)=que.top();
        que.pop();
        cost=-cost;
        if(cost!=mincost[x][ticket]) continue;
        for(auto tmp:gay[x]){
            tie(y,z)=tmp;
            if(ticket<k) if(cost<mincost[y][ticket+1]){
                mincost[y][ticket+1]=cost;
                que.push(mt(-cost,ticket+1,y));
            }
            ncost=cost+z;
            if(ncost<mincost[y][ticket]){
                mincost[y][ticket]=ncost;
                que.push(mt(-ncost,ticket,y));
            }
        }
    }
    ll ans=INF;
    for(int i=0;i<=k;++i) ans=min(ans,mincost[n][i]);
    if(ans==INF) ans=-1;
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

