#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N=200005,M=1e9+7;
const ll INF=1e18+7;

ll binmul(ll a,ll b,ll c){
    ll ans=0;
    while(b){
        if(b&1) ans=(ans+a)%c;
        a=(a<<1)%c;
        b>>=1;
    }
    return ans;
}

ll binpow(ll a,ll b,ll c){
    ll ans=1;
    while(b){
        if(b&1) ans=binmul(ans,a,c);
        a=binmul(a,a,c);
        b>>=1;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(NULL); cin.tie(nullptr); cout.tie(nullptr);
    ll a,b,c;
    cin>>a>>b>>c;
    cout<<binpow(a,b,c);
    return 0;
}


