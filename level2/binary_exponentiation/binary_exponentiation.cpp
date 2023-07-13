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
ll binmul(ull a,ull b,ull c){
    ull ans=0;
    a%=c;
    while(b>0){
        if(b&1) ans=(ans+a)%c;
        a=(a<<1)%c;
        b>>=1;
    }
    return ans;
}
ll binpow(ull a,ull b,ull c){
    ull ans=1;
    a%=c;
    while(b>0){
        if(b&1) ans=binmul(ans,a,c);
        a=binmul(a,a,c);
        b>>=1;
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(NULL); cin.tie(nullptr); cout.tie(nullptr);
//    freopen(".inp","r",stdin);
//    freopen(".out","w",stdout);
    ull a,b,c;
    cin>>a>>b>>c;
    cout<<binpow(a,b,c);
    return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
1000000000000000000 1000000000000000000 900000000000000000

645918143070891176 207009398034391759 588470336595964969
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |

------------------------------    |
==================================+
*/

