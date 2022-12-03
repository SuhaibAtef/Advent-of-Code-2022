#include "./../bits/stdc++.h"
using namespace std;
typedef long long ll;

int mapingChar(char c){
    if (islower(c)){
        return (c-96);
    }else{
        return (c-64+26);
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string str; 
    ll score=0;
    while(cin>>str){
    string str2 = str.substr (0,str.length()/2);
    string str3 = str.substr (str.length()/2,str.length()/2);
    for(int i=0;i<(int)str2.length();i++){
        if(str3.find(str2[i])!=string::npos){
            score+=mapingChar(str2[i]);
            break;
        }
    }}
    cout<<score<<endl;
    return 0;
}