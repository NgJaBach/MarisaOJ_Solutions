#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pll pair<ll,ll>
#define fi first
#define se second

const int N=1000005;

const int base=311;
const int mod1=1e9+7;
const int mod2=1e9+9;

pll basepow[N];
void HashInit(){
    basepow[0]={1,1};
    for(int i=1;i<N;++i){
        basepow[i].fi=(basepow[i-1].fi*base)%mod1;
        basepow[i].se=(basepow[i-1].se*base)%mod2;
    }
    return;
}
struct Hashing{
    pll hashstr[N];
    int n;
    void Create(const string &s){
        n=(int)s.size();
        hashstr[0]={0,0};
        for(int i=1;i<=n;++i){
            hashstr[i].fi=(hashstr[i-1].fi*base+s[i-1])%mod1;
            hashstr[i].se=(hashstr[i-1].se*base+s[i-1])%mod2;
        }
        return;
    }
    int counting(int m,pll hashval){
        pll num;
        int cnt=0;
        for(int i=m;i<=n;++i){
            num.fi=(hashstr[i].fi-(hashstr[i-m].fi*basepow[m].fi)%mod1+mod1)%mod1;
            num.se=(hashstr[i].se-(hashstr[i-m].se*basepow[m].se)%mod2+mod2)%mod2;
            if(num==hashval) ++cnt;
        }
        return cnt;
    }
};

int main(){
    HashInit();
    string a,b;
    cin>>a>>b;
    Hashing S,T;
    S.Create(a);
    T.Create(b);
    cout<<S.counting(T.n,T.hashstr[T.n]);
    return 0;
}

