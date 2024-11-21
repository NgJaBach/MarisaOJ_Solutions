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
ll a[N],cnt[N];
pair<int,int>pp[N];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
//    freopen(".inp","r",stdin);
//    freopen(".out","w",stdout);
    int n,m,q,x,y;
    cin>>n>>m>>q;
    for(int i=1;i<=m;++i){
        cin>>x>>y;
        pp[i]=mp(x,y);
    }
    while(q--){
        cin>>x>>y;
        ++cnt[x]; --cnt[y+1];
    }
    for(int i=1;i<=m;++i){
        cnt[i]+=cnt[i-1];
        a[pp[i].fi]+=cnt[i];
        a[pp[i].se+1]-=cnt[i];
    }
    for(int i=1;i<=n;++i){
        a[i]+=a[i-1];
        cout<<a[i]<<" ";
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

