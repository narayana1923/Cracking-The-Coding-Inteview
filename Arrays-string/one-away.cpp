#include <bits/stdc++.h>
using namespace std;

bool oneAway(string& s1,string& s2){
    unordered_map<char,int> m;
    for(char i:s1){
        m[i]++;
    }
    for(char i:s2){
        m[i]--;
    }
    int c = 0;
    for(auto i:m){
        if(i.second==-1 || i.second==1) c++; 
    }
    return c<=1;
}

int main() {
    string s1,s2;
    cin>>s1>>s2;
    cout<<boolalpha<<oneAway(s1,s2);
    return 0;
}