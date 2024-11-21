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
set<int>ex[N];
vector<int>gay[N];
int ans[N];
void dfs(int u,int p){
    for(auto v:gay[u]){
        if(v==p) continue;
        dfs(v,u);
        if((int)ex[u].size()<(int)ex[v].size()) swap(ex[u],ex[v]);
        for(auto tmp:ex[v]) ex[u].insert(tmp);
    }
    ans[u]=(int)ex[u].size();
    return;
}
int main(){
    ios_base::sync_with_stdio(NULL); cin.tie(nullptr); cout.tie(nullptr);
//    freopen(".inp","r",stdin);
//    freopen(".out","w",stdout);
    int n,x,y;
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>x;
        ex[i].insert(x);
    }
    for(int i=1;i<n;++i){
        cin>>x>>y;
        gay[x].pb(y);
        gay[y].pb(x);
    }
    dfs(1,1);
    for(int i=1;i<=n;++i) cout<<ans[i]<<" ";
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

