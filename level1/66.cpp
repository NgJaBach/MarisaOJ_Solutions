#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N=1005,M=1e9+7;
const ll INF=1e18+7;

ll a[N][N],sum[N][N];

int main(){
    ios_base::sync_with_stdio(NULL); cin.tie(nullptr); cout.tie(nullptr);
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<=n;++i) sum[i][0]=0;
    for(int i=0;i<=m;++i) sum[0][i]=0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            sum[i][j]=a[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
        }
    }
    while(q--){
        int x,y,u,v;
        cin>>x>>y>>u>>v;
        cout<<sum[u][v]-sum[x-1][v]-sum[u][y-1]+sum[x-1][y-1]<<endl;
    }
    return 0;
}


