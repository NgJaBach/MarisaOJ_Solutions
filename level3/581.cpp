#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N=500005;
const ll INF=1e18+7;

const int base=311;
const int mod=1e9+7;

ll basepow[N],hashing[N];
int gethash(const int &x,const int &y){
    return (hashing[y] - hashing[x-1]*basepow[y-x+1]%mod + mod)%mod;
}
int n;
string s;
void init(){
    basepow[0]=1;
    for(int i=1;i<=n;++i) basepow[i]=(basepow[i-1]*base)%mod;
    for(int i=1;i<=n;++i) hashing[i]=(hashing[i-1]*base+s[i])%mod;
    return;
}
int lp[N],pr[N];
void init_prime(){
    int idx=0;
    for(int i=2;i<=n;++i){
        if(!lp[i]){
            pr[idx++]=i;
            lp[i]=i;
        }
        for(int j=0;j<idx;++j){
            if(i*pr[j]>n) break;
            lp[i*pr[j]]=pr[j];
            if(i%pr[j]==0) break;
        }
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(NULL); cin.tie(nullptr); cout.tie(nullptr);
    
    cin>>n;
    cin>>s; s="$"+s;
    init(); init_prime();
    
    int q;
    cin>>q;
    while(q--){
        int x,y;
        cin>>x>>y;
        int len=y-x+1;
        int p=lp[len];
        int ans=len;
        while(p){
            int k=ans/p;
            if(gethash(x,y-k)==gethash(x+k,y)) ans=k;
            len/=p;
            p=lp[len];
        }
        cout<<ans<<endl;
    }
    return 0;
}










