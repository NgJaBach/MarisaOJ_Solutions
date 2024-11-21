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

ll a[N],mincost[N],dp[N];
vector<pii>gay[N];

void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        mincost[i]=INF;
        dp[i]=INF;
        cin>>a[i];
    }
    while(m--){
        int x,y,z;
        cin>>x>>y>>z;
        gay[x].pb({y,z});
        gay[y].pb({x,z});
    }
    priority_queue<pair<ll,int> >que;
    que.push({0,n});
    mincost[n]=0;
    while(!que.empty()){
        ll sum;
        int x;
        tie(sum,x)=que.top();
        que.pop();
        sum=-sum;
        if(sum!=mincost[x]) continue;
        for(auto tmp:gay[x]){
            int y,z;
            tie(y,z)=tmp;
            ll nsum=sum+z;
            if(nsum<mincost[y]){
                mincost[y]=nsum;
                que.push({-nsum,y});
            }
        }
    }
    priority_queue<tuple<ll,int,ll> >baque;
    baque.push(mt(0,1,mincost[1]));
    dp[1]=a[1]+mincost[1];
    while(!baque.empty()){
        ll sum,minis;
        int x;
        tie(sum,x,minis)=baque.top();
        baque.pop();
        sum=-sum;
        if((sum+a[x]+minis)!=dp[x]) continue;
        for(auto tmp:gay[x]){
            int y,z;
            tie(y,z)=tmp;
            ll nsum=sum+z;
            if((nsum+a[y]+min(minis,mincost[y]))<dp[y]){
                dp[y]=nsum+a[y]+min(minis,mincost[y]);
                baque.push(mt(-nsum,y,min(minis,mincost[y])));
            }
        }
    }
    ll ans=INF;
    for(int i=1;i<=n;++i) ans=min(ans,dp[i]);
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


