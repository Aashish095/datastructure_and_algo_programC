#include<iostream>
using namespace std;

int main(){
    string s;
    cin >> s;

    int x;
    for(int i=0;i<s.size();i++){
        int x=s[i]-'a';
        s[i]='z'-x;
    }

    cout << s;
    return 0;



    

}


