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
vector<pair<pair<int,int>,int> >gay;
int n,m,q,a[N],ans;
void back(int x){
    if(x>n){
        for(int i=0;i<q;++i){
            if((a[gay[i].fi.fi]+a[gay[i].fi.se])!=gay[i].se) return;
        }
        ++ans;
        return;
    }
    for(int i=1;i<=m;++i){
        a[x]=i;
        back(x+1);
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
//    freopen(".inp","r",stdin);
//    freopen(".out","w",stdout);
    int x,y,z;
    cin>>n>>m>>q;
    for(int i=0;i<q;++i){
        cin>>x>>y>>z;
        gay.pb({{x,y},z});
    }
    ans=0;
    back(1);
    cout<<ans;
    return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
2 2 1
1 2 3
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |

------------------------------    |
==================================+
*/

