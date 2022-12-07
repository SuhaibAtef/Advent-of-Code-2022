#include "./../bits/stdc++.h"
using namespace std;

int main() {
    stack<char,list<char>> s1({'G','T','R','W'});
    stack<char,list<char>> s2({'G','C','H','P','M','S','V','W'});
    stack<char,list<char>> s3({'C','L','T','S','G','M'});
    stack<char,list<char>> s4({'J','H','D','M','W','R','F'});
    stack<char,list<char>> s5({'P','Q','L','H','S','W','F','J'});
    stack<char,list<char>> s6({'P','J','D','N','F','M','S'});
    stack<char,list<char>> s7({'Z','B','D','F','G','C','S','J'});
    stack<char,list<char>> s8({'R','T','B'});
    stack<char,list<char>> s9({'H','N','W','L','C'});
    list <stack<char,list<char>>> stacks = {s1,s2,s3,s4,s5,s6,s7,s8,s9}; 
    list<stack<char,list<char>>>::iterator it = stacks.begin();
    list<stack<char,list<char>>>::iterator it2 = stacks.begin();
    string s;
    int j,a,b;
    char c; 
    while(cin>>s>>j>>s>>a>>s>>b){
        it = stacks.begin();
        it2 = stacks.begin();
        advance(it, a-1);
        advance(it2, b-1);
        // Part-1
        // for(int i=0;i<j;i++){
        //     c = (*it).top();
        //     (*it).pop();
        //     (*it2).push(c);
        // }
        stack<char> tempStack;
        for(int i=0;i<j;i++){
            c = (*it).top();
            (*it).pop();
            tempStack.push(c);
            
        }
        while (!tempStack.empty()){
            c = tempStack.top();
            tempStack.pop();
            (*it2).push(c);
        }
    }
    it = stacks.begin();
    for(int i =0;i<9;i++){
        cout << (*it).top();
        advance(it,1);
    }
    return 0;
}