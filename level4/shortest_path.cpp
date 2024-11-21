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
const int N=200050,M=1000000007;
const ll INF=1e18+7;
vector<pair<int,ll> >connect[N];
ll mincost[N];
int trace[N];
int main(){
    ios_base::sync_with_stdio(NULL); cin.tie(nullptr); cout.tie(nullptr);
//    freopen(".inp","r",stdin);
//    freopen(".out","w",stdout);
    int n,m,x,y;
    ll z,cost;
    cin>>n>>m;
    for(int i=0;i<m;++i){
        cin>>x>>y>>z;
        connect[x].pb({y,z});
        connect[y].pb({x,z});
    }
    for(int i=1;i<=n;++i){
        mincost[i]=INF;
    }
    mincost[1]=0;
    priority_queue<pair<ll,int> >que;
    que.push({0,1});
    trace[1]=1;
    while(!que.empty()){
        z=-que.top().fi; x=que.top().se;
        que.pop();
        if(z!=mincost[x]) continue;
        for(auto tmp:connect[x]){
            y=tmp.fi; cost=z+tmp.se;
            if(cost<mincost[y]){
                mincost[y]=cost;
                que.push({-cost,y});
                trace[y]=x;
            }
        }
    }
    if(mincost[n]==INF){
        cout<<-1;
        return 0;
    }
    cout<<mincost[n]<<endl;
    stack<int>res;
    x=n;
    res.push(x);
    while(x!=trace[x]){
        x=trace[x];
        res.push(x);
    }
    while(!res.empty()){
        cout<<res.top()<<' ';
        res.pop();
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

