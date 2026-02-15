#include <queue>
#include <iostream>
using namespace std;

int main(){
    // Max heap by default
    priority_queue<int> pq;
    pq.push(28);
    pq.push(45);
    pq.push(32);
    pq.push(29);
    pq.push(65);

    cout<<"Top element: "<<pq.top()<<"\n";

    return 0;
}