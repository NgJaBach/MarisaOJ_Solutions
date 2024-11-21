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
vector<int>gay[N];
bool ok[N];
void dfs(int u){
    ok[u]=false;
    for(auto v:gay[u]) if(ok[v]) dfs(v);
    return;
}
int main(){
    ios_base::sync_with_stdio(NULL); cin.tie(nullptr); cout.tie(nullptr);
//    freopen(".inp","r",stdin);
//    freopen(".out","w",stdout);
    int n,m,x,y,cnt=0;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        ok[i]=true;
    }
    while(m--){
        cin>>x>>y;
        gay[x].pb(y);
        gay[y].pb(x);
    }
    for(int i=1;i<=n;++i){
        if(!ok[i]) continue;
        dfs(i);
        ++cnt;
    }
    cout<<cnt;
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

