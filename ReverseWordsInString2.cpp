#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void reverseWords(vector<char>& s) {
    reverse(s.begin(), s.end());

    int n = s.size();
    int start = 0;

    for (int end = 0; end <= n; ++end) {
        if (end == n || s[end] == ' ') {
            reverse(s.begin() + start, s.begin() + end);
            start = end + 1;
        }
    }
}


vector<char> tokenize(string s) {
    vector<char> tokenized;

    for(int i=0;i<s.size();i++){
        tokenized.push_back(s[i]);
    }
    return tokenized;
}

int main() {
    string s = "The sky is blue";

    vector<char> tokenized=tokenize(s);

    for(char c: tokenized){
        cout<<c;
    }

    reverseWords(tokenized);

    cout<<"\nAns is:\n";
    for(char c: tokenized){
        cout<<c;
    }
    return 0;
}