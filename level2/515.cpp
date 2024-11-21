#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N=200005,M=1e9+7;
const ll INF=1e18+7;

int a[N];

int main(){
    ios_base::sync_with_stdio(NULL); cin.tie(nullptr); cout.tie(nullptr);
    int n,t;
    cin>>n>>t;
    for(int i=1;i<=n;++i) cin>>a[i];
    while(t--){
        int x;
        cin>>x;
        int L,R,mid,ans;
        L=1; R=n; ans=-1;
        while(L<=R){
            mid=(L+R)/2;
            if(a[mid]>x) R=mid-1;
            else if(a[mid]<x) L=mid+1;
            else{
                ans=mid;
                break;
            }
        }
//        if(ans==-1) cout<<"khong co";
        cout<<ans<<endl;
    }
    return 0;
}


