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
ll binmul(ll a,ll b,ll c){
    ll ans=0;
    a%=c;
    while(b>0){
        if(b%2) ans=(ans+a)%c;
        a=(a*2)%c;
        b/=2;
    }
    return ans;
}
ll binpow(ll a,ll b,ll c){
    ll ans=1;
    a%=c;
    while(b>0){
        if(b%2) ans=binmul(ans,a,c);
        a=binmul(a,a,c);
        b/=2;
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(NULL); cin.tie(nullptr); cout.tie(nullptr);
//    freopen(".inp","r",stdin);
//    freopen(".out","w",stdout);
    ll n,A,B,C;
    cin>>n;
    A=binpow(3,(n+2)/3,M);
    B=binpow(3,(n+1)/3,M);
    C=binpow(4,n/3,M);
//    cout<<A<<" "<<B<<" "<<C<<endl;
    cout<<binmul(A,binmul(B,C,M),M);
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

