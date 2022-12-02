#include "./../bits/stdc++.h"
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    char a, b;
    ll score1 =0,score2=0;
    int solArray[7] = {0, 1, 2, 3, 1, 2, 3};
    // a(rock) b(paper) c(Scissors) 
    while(cin >> a >> b){
        int o = a-64;
        score1 += (int)(b-87);
        if((int)a == (int)(b-23)){
            score1 +=3;
        }else if((a=='A'&&b=='Y')||(a=='B'&&b=='Z')||(a=='C'&&b=='X')){
            score1 +=6;
        }
        if (b=='Y'){
            score2+= 3 + o;
        }else if (b=='X'){
            score2+= 0 + solArray[o+2];
        }else{
            score2+= 6 + solArray[o+1];
        }
    }
    cout<<score1<<endl;
    cout<<score2<<endl;
    return 0;
}
