#include<bits/stdc++.h>

using namespace std;

int main(){
    float a;
    cin>>a;
    
    if(a>=9.0) cout<<"VERY TOXIC";
    else if(5.0<=a && a<=8.9) cout<<"TOXIC";
    else cout<<"SAFE";
    
    return 0;
}

