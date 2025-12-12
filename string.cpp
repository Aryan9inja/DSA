#include <iostream>
#include <vector>
#include <cctype> 
using namespace std;

int strLength(char name[]) {
    int buffer = 0;
    while (name[buffer] != 0) {
        buffer++;
    }
    return buffer;
}


string sanitizeString(string& s) {
    string sanitizedString = "";
    for (char c : s) {
        if (isalnum(c)){
            sanitizedString += tolower(c);
        }
    }
    return sanitizedString;
}

string strReverse(char name[], int n) {
    for (int i = 0, j = n - 1;i < j;i++, j--) {
        swap(name[i], name[j]);
    }
    return name;
}

char toLowerCase(char ch){
    if(ch>='a' && ch<='z'){
        return ch;
    }else{
        return ch-'A'+'a';
    }
}

int main() {
    // char name[20];

    // cout<<"Enter your name\n";
    // cin>>name;

    // cout<<"Length of string is\n";
    // cout<<strLength(name)<<"\n";

    // cout<<"Reversed string is\n";
    // cout<<strReverse(name,strLength(name));

    string s = "c1 O$d@eeD o1c";
    string s1= sanitizeString(s);
    cout<<s1<<"\n";

    cout<<toLowerCase('A');
    return 0;
}