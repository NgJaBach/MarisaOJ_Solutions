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
vector<ll>gay;
int main(){
    ios_base::sync_with_stdio(NULL); cin.tie(nullptr); cout.tie(nullptr);
//    freopen(".inp","r",stdin);
//    freopen(".out","w",stdout);
    int n,k;
    ll a,maxis=-INF;
    cin>>n>>k;
    for(int i=0;i<n;++i){
        cin>>a;
        gay.pb(a);
        maxis=max(maxis,a);
    }
    ll L,R,mid,ans=INF,sum;
    int cnt;
    L=maxis; R=INF;
    while(L<=R){
        mid=(L+R)/2;
        sum=0; cnt=1;
        for(int i=0;i<n;++i){
            if((sum+gay[i])>mid){
                ++cnt;
                sum=gay[i];
            }
            else sum+=gay[i];
        }
        if(cnt>k) L=mid+1;
        else{
            ans=min(ans,mid);
            R=mid-1;
        }
    }
    cout<<ans;
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

