#include<bits/stdc++.h>

using namespace std;

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    int tich=1;
    while(b>0){
        tich=(tich*a)%c;
        --b;
    }
    cout<<tich;
    return 0;
}


