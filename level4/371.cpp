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

struct node{
    int x;
    ll cost,minis,bigcost;
    bool operator < (const node &other) const {
        return cost>other.cost;
    }
    tuple<int,ll,ll,ll>get() const {
        return mt(x,cost,minis,bigcost);
    }
};

ll a[N],mincost[N],dp[N];
vector<tuple<int,int,int> >gay[N];

void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        mincost[i]=INF;
        dp[i]=INF;
    }
    while(m--){
        int x,y,w,l;
        cin>>x>>y>>w>>l;
        gay[x].pb(mt(y,w,l));
        gay[y].pb(mt(x,w,l));
    }
    mincost[n]=0;
    {
        priority_queue<pair<ll,int> >que;
        que.push({0,n});
        while(!que.empty()){
            int x;
            ll cost;
            tie(cost,x)=que.top();
            que.pop();
            cost=-cost;
            if(cost!=mincost[x]) continue;
            for(auto tmp:gay[x]){
                int y,w,l;
                tie(y,w,l)=tmp;
                ll ncost=cost+w;
                if(ncost<mincost[y]){
                    mincost[y]=ncost;
                    que.push({-ncost,y});
                }
            }
        }
    }
    dp[1]=a[1]+mincost[1];
    priority_queue<node>que;
    que.push({1,0,mincost[1],0});
    while(!que.empty()){
        int x;
        ll cost,minis,bigcost;
        tie(x,cost,minis,bigcost)=que.top().get();
        que.pop();
        if((cost+a[x]+minis)!=dp[x]) continue;
//        cout<<x<<" "<<cost<<" "<<minis<<" "<<bigcost<<" -> "<<cost+minis+a[x]<<endl;
        for(auto tmp:gay[x]){
            int y,w,l;
            tie(y,w,l)=tmp;
            ll nminis=min(minis,mincost[y]);
            ll ncost;
            if(nminis<minis) ncost=bigcost+w;
            else ncost=cost+w+l;
            if((ncost+nminis+a[y])<dp[y]){
                dp[y]=ncost+nminis+a[y];
                que.push({y,ncost,nminis,bigcost+w});
            }
        }
    }
    ll ans=INF;
    for(int i=1;i<=n;++i) ans=min(ans,dp[i]);
//    cout<<"mincost:"<<endl;
//    for(int i=1;i<=n;++i) cout<<mincost[i]<<endl;
//    cout<<"dp:"<<endl;
//    for(int i=1;i<=n;++i) cout<<dp[i]<<endl;
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

