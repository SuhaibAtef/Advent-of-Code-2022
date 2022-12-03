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
    string str,str1,str2; 
    ll score=0;
    while(cin>>str){
    cin>>str1 ;
    cin>>str2 ;
    
    for(int i=0;i<(int)str.length();i++){
        if(str2.find(str[i])!=string::npos&&str1.find(str[i])!=string::npos){
            score+=mapingChar(str[i]);
            break;
        }
    }}
    cout<<score<<endl;
    return 0;
}