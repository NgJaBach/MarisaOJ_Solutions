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

vector<pair<int,ll> >gay[N];
ll mincost[N][11];

void solve(){
    int n,m,x,y,z,pz;
    cin>>n>>m;
    while(m--){
        cin>>x>>y>>z;
        gay[x].pb({y,z});
        gay[y].pb({x,z});
    }
    for(int i=1;i<=n;++i) for(int j=0;j<=10;++j) mincost[i][j]=INF;
    mincost[1][0]=0;
    priority_queue<tuple<ll,int,int> >que;
    ll cost,ncost;
    que.push(mt(0,0,1));
    while(!que.empty()){
        tie(cost,pz,x)=que.top();
        que.pop();
        cost=-cost;
//        cout<<"--> "<<cost<<" "<<pz<<" "<<x<<endl;
        if(cost!=mincost[x][pz]) continue;
        for(auto tmp:gay[x]){
            tie(y,z)=tmp;
            if(pz){
                ncost=cost+pz*z;
                if(ncost<mincost[y][0]){
                    mincost[y][0]=ncost;
                    que.push(mt(-ncost,0,y));
                }
            }
            else{
                if(cost<mincost[y][z]){
                    mincost[y][z]=cost;
                    que.push(mt(-cost,z,y));
                }
            }
        }
    }
    ll ans=mincost[n][0];
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
3 3
1 2 1
2 3 2
1 3 3
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |

------------------------------    |
==================================+
*/

