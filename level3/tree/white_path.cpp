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
int a[N],h[N];
vector<int>gay[N];
void dfs(int u,int p){
    h[u]=h[p]+1;
    a[u]+=a[p];
    for(auto v:gay[u]){
        if(v==p) continue;
        dfs(v,u);
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
//    freopen(".inp","r",stdin);
//    freopen(".out","w",stdout);
    int n,x,y;
    string s;
    cin>>n;
    cin>>s;
    for(int i=1;i<=n;++i) a[i]=(s[i-1]-'0');
    for(int i=1;i<n;++i){
        cin>>x>>y;
        gay[x].pb(y);
        gay[y].pb(x);
    }
    dfs(1,0);
    int cnt=0;
    for(int i=1;i<=n;++i) if((h[i]-a[i])>a[i]) ++cnt;
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

