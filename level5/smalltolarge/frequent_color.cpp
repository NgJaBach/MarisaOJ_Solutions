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
map<int,int>meo[N];
vector<pair<int,int> >official[N];
vector<int>gay[N];
void dfs(int u,int p){
    for(auto v:gay[u]){
        if(v==p) continue;
        dfs(v,u);
        if((int)meo[u].size()>(int)meo[v].size()) swap(meo[u],meo[v]);
        for(auto tmp:meo[v]) meo[u][tmp.fi]+=tmp.se;
    }
    for(auto tmp:meo[u]) official[u].pb({tmp.se,tmp.fi});
    sort(bend(official[u]));
    return;
}
int main(){
    ios_base::sync_with_stdio(NULL); cin.tie(nullptr); cout.tie(nullptr);
//    freopen(".inp","r",stdin);
//    freopen(".out","w",stdout);
    int n,a,q;
    int x,y;
    cin>>n>>q;
    for(int i=1;i<=n;++i){
        cin>>a;
        ++meo[i][a];
    }
    for(int i=1;i<n;++i){
        cin>>x>>y;
        gay[x].pb(y);
        gay[y].pb(x);
    }
    dfs(1,1);
    
//    cout<<endl;
//    for(int i=1;i<=n;++i){
//        for(auto tmp:official[i]) cout<<"{"<<tmp.fi<<","<<tmp.se<<"},";
//        cout<<endl;
//    }
//    cout<<endl;
    int m,L,R,mid,pos;
    while(q--){
        cin>>x>>y;
        m=(int)official[x].size();
        L=0; R=m-1; pos=m;
        while(L<=R){
            mid=(L+R)/2;
            if(official[x][mid].fi<y) L=mid+1;
            else{
                pos=min(pos,mid);
                R=mid-1;
            }
        }
        cout<<(m-pos)<<endl;
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

