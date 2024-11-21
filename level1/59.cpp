#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N=200005,M=1e9+7;
const ll INF=1e18+7;

ll a[N],prefsum[N];

int main(){
    ios_base::sync_with_stdio(NULL); cin.tie(nullptr); cout.tie(nullptr);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        prefsum[i]=prefsum[i-1]+a[i];
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        cout<<(prefsum[y]-prefsum[x-1])<<endl;
    }
    return 0;
}


