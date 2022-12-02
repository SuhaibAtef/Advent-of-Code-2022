#include "./../bits/stdc++.h"
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int maxAns=0,maxAns1=0,maxAns2=0,sum=0;
    string blank;
    
    while(getline(cin,blank)){
        if(blank.length() == 0){
            if(maxAns<=sum){
                maxAns2=maxAns1;
                maxAns1=maxAns;
                maxAns=sum;
            }else if(maxAns>sum && maxAns1<=sum){
                maxAns2=maxAns1;
                maxAns1=sum;
            }else if(maxAns>sum && maxAns2<=sum && maxAns1>sum){
                maxAns2=sum;
            }
            sum=0;
        }else{
            sum+=stoi(blank);
        }
        
    }
    cout<<maxAns<<endl;
    cout<<maxAns+maxAns1+maxAns2<<endl;
    return 0;
}
