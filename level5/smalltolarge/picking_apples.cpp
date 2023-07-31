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
queue<ll>tree[N];
vector<int>gay[N];
ll val[N];
int lim[N];
vector<ll>dfs(int u,int p){
    if(lim[u]==0) return {};
    vector<ll>A,B,C;
    int x,y,n,m;
    A.pb(val[u]);
    for(auto v:gay[u]){
        if(v==p) continue;
        B=dfs(v,u);
        n=(int)A.size(); m=(int)B.size();
        C.clear();
        x=0; y=0;
        for(int i=0;i<min(n+m,lim[u]);++i){
            if(x==n) C.pb(B[y++]);
            else if(y==m) C.pb(A[x++]);
            else{
                if(A[x]>=B[y]) C.pb(A[x++]);
                else C.pb(B[y++]);
            }
        }
        swap(A,C);
    }
    return A;
}
int main(){
    ios_base::sync_with_stdio(NULL); cin.tie(nullptr); cout.tie(nullptr);
//    freopen(".inp","r",stdin);
//    freopen(".out","w",stdout);
    int n,x,y;
    cin>>n;
    for(int i=1;i<=n;++i) cin>>val[i];
    for(int i=1;i<=n;++i) cin>>lim[i];
    for(int i=1;i<n;++i){
        cin>>x>>y;
        gay[x].pb(y);
        gay[y].pb(x);
    }
    vector<ll>ans=dfs(1,1);
    ll sum=0;
    for(auto tmp:ans) sum+=tmp;
    cout<<sum;
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

