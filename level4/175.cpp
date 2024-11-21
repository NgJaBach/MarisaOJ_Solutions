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
const int N=200050,M=1000000007;
const ll INF=1e18+7;

vector<pair<int,int> >gay[N];
ll mincost[N],cnt[N];

void solve(){
    int n,m,x,y,z;
    cin>>n>>m;
    while(m--){
        cin>>x>>y>>z;
        gay[x].pb({y,z});
        gay[y].pb({x,z});
    }
    for(int i=1;i<=n;++i){
        mincost[i]=INF;
        cnt[i]=0;
    }
    mincost[1]=0;
    cnt[1]=1;
    priority_queue<pair<ll,int> >que;
    ll cost,ncost;
    que.push({0,1});
    while(!que.empty()){
        tie(cost,x)=que.top();
        que.pop();
        cost=-cost;
        if(cost!=mincost[x]) continue;
        for(auto tmp:gay[x]){
            tie(y,z)=tmp;
            ncost=cost+z;
            if(ncost<mincost[y]){
                mincost[y]=ncost;
                cnt[y]=cnt[x];
                que.push({-ncost,y});
            }
            else if(ncost==mincost[y]) cnt[y]=(cnt[y]+cnt[x])%M;
        }
    }
    cout<<cnt[n];
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

