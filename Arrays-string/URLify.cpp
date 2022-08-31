#include<iostream>
using namespace std;

void URLify(string& s,int m){
    int i=0,n=s.size();
    int numOfSpaces=0;
    while(i<m){
        if(s[i]==' ') numOfSpaces++;
        i++;
    }
    int extendedLen = m+2*numOfSpaces;
    i=extendedLen-1;
    for(int j=m-1;j>=0;j--){
        if(s[j]!=' '){
            s[i--]=s[j];
        }
        else{
            s[i--]='0';
            s[i--]='2';
            s[i--]='%';
        }
    }
}

int main(){
    string s;
    int m;
    getline(cin,s);
    cin>>m;
    URLify(s,m);
    cout<<s;
    return 0;
}