#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N=200005,M=1e9+7;
const ll INF=1e18+7;

ll a[N],maxis[N];

int main(){
    ios_base::sync_with_stdio(NULL); cin.tie(nullptr); cout.tie(nullptr);
    int n;
    ll ans=-INF;
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        maxis[i]=max(maxis[i-1]+a[i],a[i]);
        ans=max(ans,maxis[i]);
    }
    cout<<ans;
    return 0;
}


