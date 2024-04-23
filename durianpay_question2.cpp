/*
Calculate minimum number of characters to be added in front of a string to make it a palindrome
Example
- Input : str = "ABC"
- Output : 2
We can make above string palindrome as "CBABC"
by adding 'B' and 'C' at front.
- Input : str = "AACECAAAA";
- Output : 2
We can make above string palindrome as AAAACECAAAA
by adding two A's at front of string.
*/ 

#include<iostream>
#include<vector>
using namespace std;

bool isPal(string &str) {
    int n = size(str);
    for(int i = 0; i < n/2; i++){
        if(str[i] != str[n-1-i]) return false;
    }
    return true;
}

int getMinNumOfEle(string str){
    int ans = 0;
    while(size(str)){
        if(isPal(str)) {
            break;
        }
        str.pop_back();
        ans++;
    }
    return ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        cout<<getMinNumOfEle(str)<<endl;
    }
    return 0;
}