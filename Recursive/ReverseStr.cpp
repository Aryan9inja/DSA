#include <iostream>
#include <vector>
using namespace std;

void reverseStr(string& str,int s,int e){
    if(s>e) return;

    swap(str[s],str[e]);

    reverseStr(str,s+1,e-1);
}

int main() {
    string str="abcde";
    reverseStr(str,0,str.size()-1);
    cout<<str;
    return 0;
}