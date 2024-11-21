#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=1000005;

const int base=311;
const int mod=1e9+7;

ll basepow[N];
void HashInit(){
    basepow[0]=1;
    for(int i=1;i<N;++i) basepow[i]=(basepow[i-1]*base)%mod;
    return;
}
struct Hashing{
    ll hashstr[N];
    int n;
    void Create(const string &s){
        n=(int)s.size();
        hashstr[0]=0;
        for(int i=1;i<=n;++i) hashstr[i]=(hashstr[i-1]*base+s[i-1])%mod;
        return;
    }
    int counting(int m,int hashval){
        ll num;
        int cnt=0;
        for(int i=m;i<=n;++i){
            num=(hashstr[i]-(hashstr[i-m]*basepow[m])%mod+mod)%mod;
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

