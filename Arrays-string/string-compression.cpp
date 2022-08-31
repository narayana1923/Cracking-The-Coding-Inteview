#include <bits/stdc++.h>
using namespace std;

string compress_string(string& s){
    string ans;
    int n = s.size();
    for(int i=0;i<n;){
        ans+=s[i];
        int j = i;
        while(j<n && s[i]==s[++j]);
        ans+=to_string(j-i);
        i=j;
    }
    if(ans.size()>n) return s;
    return ans;
}

int main() {
    string s;
    cin>>s;
    cout<<compress_string(s);
    return 0;
}