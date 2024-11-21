#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N=200005,M=1e9+7;
const ll INF=1e18+7;

ll sumleft[N],sumright[N],a[N];
ll maxright[N],maxleft[N];

int main(){
    ios_base::sync_with_stdio(NULL); cin.tie(nullptr); cout.tie(nullptr);
    int n;
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    maxleft[0]=-INF; maxright[n+1]=-INF;
    for(int i=1;i<=n;++i){
        sumleft[i]=max(sumleft[i-1]+a[i],a[i]);
        maxleft[i]=max(maxleft[i-1],sumleft[i]);
    }
    for(int i=n;i>=1;--i){
        sumright[i]=max(sumright[i+1]+a[i],a[i]);
        maxright[i]=max(maxright[i+1],sumright[i]);
    }
    ll ans=-INF;
    for(int i=1;i<n;++i) ans=max(ans,maxleft[i]+maxright[i+1]);
    cout<<ans;
    return 0;
}


