#include<bits/stdc++.h>

using namespace std;

void dequy(int n,int pos,string s){ // n - do dai string, pos - vi tri dang xet, s - xau nhi phan dang tao
    if(pos==n){
        cout<<s<<endl;
        return;
    }
    dequy(n,pos+1,s+'0');
    dequy(n,pos+1,s+'1');
    return;
}

int main(){
    int n;
    cin>>n;
    dequy(n,0,"");
    return 0;
}


