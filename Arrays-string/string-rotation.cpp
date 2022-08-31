// Check whether given string is a rotated substring of s1 or not
#include <bits/stdc++.h>
using namespace std;

bool is_substring(string& s1,string& s2){
    if(s1.size() != s2.size()) return false;
    string temp = s1+s1;
    int m = temp.size();
    int n = s2.size();
    for(int i=0;i<m;i++){
        if(temp[i]==s2[0]){
            bool flag = true;
            for(int j=0;j<n;j++){
                if(temp[i+j]!=s2[j]){
                    flag = false;
                    break;
                }
            }
            if(flag) return true;
        }
    }
    return false;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout<<boolalpha<<is_substring(s1,s2);
    return 0;
}