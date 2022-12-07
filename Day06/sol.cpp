#include "./../bits/stdc++.h"
using namespace std;

int main() {
    set<char> window;
    string s;
    cin>>s; 
    //for part 1 change 14 to 4
    for(int i=0;i<(int)s.length()-14;i++){
        for(int j=0;j<14;j++){
            window.insert(s[i+j]);    
        }
        if(window.size()==14){
            cout<<i+14;
            break;
        }else{
            window.clear();
        }
    }
    return 0;
}