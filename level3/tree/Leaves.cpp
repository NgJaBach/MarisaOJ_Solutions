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
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
//    freopen(".inp","r",stdin);
//    freopen(".out","w",stdout);
    int n,x,y,cnt=0;
    cin>>n;
    if(n==1){
        cout<<1;
        return 0;
    }
    for(int i=1;i<n;++i){
        cin>>x>>y;
        gay[x].pb(y);
        gay[y].pb(x);
    }
    for(int i=1;i<=n;++i){
        if((int)gay[i].size()==1) ++cnt;
    }
    cout<<min(n-1,cnt);
    return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
3
1 2
1 3
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |

------------------------------    |
==================================+
*/

