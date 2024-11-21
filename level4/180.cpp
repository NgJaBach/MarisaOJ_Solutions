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

vector<pair<ll,int> >gay[N];
pair<ll,int>mincost[N];

void solve(){
    int n,m,x,y,z;
    cin>>n>>m;
    while(m--){
        cin>>x>>y>>z;
        gay[x].pb({y,z});
        gay[y].pb({x,z});
    }
    for(int i=1;i<=n;++i) mincost[i]={INF,M};
    priority_queue<pair<ll,int> >que;
    ll cost,ncost,val;
    int maxis;
    que.push({0,1});
    mincost[1]={0,0};
    while(!que.empty()){
        tie(val,x)=que.top();
        que.pop();
        val=-val; cost=val+mincost[x].se;
        if(val!=mincost[x].fi) continue;
        for(auto tmp:gay[x]){
            tie(y,z)=tmp;
            ncost=cost+z;
            maxis=max(mincost[x].se,z);
            val=ncost-maxis;
            if((val<mincost[y].fi) or ((val==mincost[y].fi) and (maxis<mincost[y].se))){
                mincost[y]={val,maxis};
                que.push({-val,y});
            }
        }
    }
    cout<<(mincost[n].fi==INF?-1:mincost[n].fi);
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

