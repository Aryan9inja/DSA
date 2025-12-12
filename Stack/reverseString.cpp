#include <iostream>
#include <stack>

int main() {
    std::string str;
    std::cout << "Enter a string to be reversed:\n";
    std::cin >> str;
    std::stack<char> s;

    for (char c : str) s.push(c);

    std::cout<<"Reversed string is\n";
    while(!s.empty()){
        std::cout<<s.top();
        s.pop();
    }

    return 0;
}