#include<bits/stdc++.h>

using namespace std;

void dequy(int n,int pos,string s){
    if(pos==n){
        cout<<s<<endl;
        return;
    }
    if(s.back()!='A') dequy(n,pos+1,s+"A");
    if(s.back()!='B') dequy(n,pos+1,s+"B");
    if(s.back()!='C') dequy(n,pos+1,s+"C");
    return;
}

int main(){
    int n;
    cin>>n;
    dequy(n,1,"A");
    dequy(n,1,"B");
    dequy(n,1,"C");
    return 0;
}


