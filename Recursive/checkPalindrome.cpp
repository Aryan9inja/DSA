#include <iostream>
#include <vector>
using namespace std;

void reverseStr(string& str,int s,int e){
    if(s>e) return;

    swap(str[s],str[e]);

    reverseStr(str,s+1,e-1);
}

bool checkPalindrome(string& str){
    string original=str;
    reverseStr(str,0,str.size()-1);
    return str==original;
}

bool checkPali(string& str,int s, int e){
    if(s>e) return true;

    if(str[s]==str[e]){
        return checkPali(str,s+1,e-1);
    }

    return false;
}

int main() {
    string str="nitiniya";
    cout<<checkPali(str,0,str.size()-1);
    return 0;
}