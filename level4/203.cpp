#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=100050;

ll a[N];
ll seg[4*N];
ll lazy[4*N];

void Build(int x,int L,int R){
    lazy[x]=0;
    if(L==R){
        seg[x]=a[L];
        return;
    }
    int mid=(L+R)/2;
    Build(2*x,L,mid);
    Build(2*x+1,mid+1,R);
    seg[x]=seg[2*x]+seg[2*x+1];
    return;
}

void Update_Lazy(int x,int L,int R){
    if(lazy[x]==0) return;
    seg[x]+=lazy[x]*(R-L+1);
    if(L!=R){
        lazy[2*x]+=lazy[x];
        lazy[2*x+1]+=lazy[x];
    }
    lazy[x]=0;
    return;
}

void Update(int x,int L,int R,int lo,int hi,ll val){
    if(L>hi or R<lo) return;
    else if(L>=lo and R<=hi){
        lazy[x]+=val;
        Update_Lazy(x,L,R);
        return;
    }
    Update_Lazy(x,L,R);
    int mid=(L+R)/2;
    Update(2*x,L,mid,lo,hi,val);
    Update(2*x+1,mid+1,R,lo,hi,val);
    seg[x]=seg[2*x]+seg[2*x+1];
    return;
}

ll Query(int x,int L,int R,int lo,int hi){
    if(L>hi or R<lo) return 0;
    Update_Lazy(x,L,R);
    if(L>=lo and R<=hi) return seg[x];
    int mid=(L+R)/2;
    ll ans=Query(2*x,L,mid,lo,hi)+Query(2*x+1,mid+1,R,lo,hi);
    seg[x]=seg[2*x]+seg[2*x+1];
    return ans;
}

int main(){
    ios_base::sync_with_stdio(NULL); cin.tie(nullptr); cout.tie(nullptr);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;++i) cin>>a[i];
    Build(1,1,n);
    while(q--){
        int t,x,y,z;
        cin>>t>>x>>y;
        if(t==1){
            cin>>z;
            Update(1,1,n,x,y,z);
        }
        else cout<<Query(1,1,n,x,y)<<endl;
    }
    return 0;
}

