#include "./../bits/stdc++.h"
 
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    char a, b;
     int a,b,c,d,sum=0,sum2=0;
    char ch;
    while(cin>>a>>ch>>b>>ch>>c>>ch>>d){
        if((a<=c&&b>=d)||(c<=a&&d>=b))sum+=1;
        if((a<=c&&b>=c)||(a<=d&&b>=d)||(c<=a&&d>=a)||(c<=b&&d>=b))sum2+=1;
    }
 
    cout<<sum<<endl;
    cout<<sum2<<endl;
    return 0;
}
