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

vector<pair<int,ll> >gay[N];
int a[N];
map<int,int>ex;
ll mincost[N];

void solve(){
    int n,u,v,cnt;
    ll L,R,X;
    cin>>n>>L>>R>>X>>u>>v;
    cnt=n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        if(!ex[a[i]]) ex[a[i]]=++cnt;
        gay[i].pb({ex[a[i]],X});
        gay[ex[a[i]]].pb({i,0});
    }
    for(int i=1;i<=cnt;++i) mincost[i]=INF;
    for(int i=2;i<=n;++i) gay[i-1].pb({i,R});
    for(int i=1;i<n;++i) gay[i+1].pb({i,L});
    priority_queue<pair<ll,int> >que;
    ll cost,ncost;
    int x,y,z;
    que.push({0,u});
    mincost[u]=0;
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
                que.push({-ncost,y});
            }
        }
    }
    cout<<mincost[v];
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

