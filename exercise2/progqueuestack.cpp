#include <iostream>
#include "tailstack.h"

using namespace std;

int main(){

    Queue<string>* nameTail = new Queue<string>();
    Queue<int>* numberTail = new Queue<int>();

    nameTail->enqueue(new string("Primer mensaje"));
    nameTail->enqueue(new string("Segundo mensaje"));
    nameTail->enqueue(new string("Tercer mensaje"));

    int values[] = {1,2,3,4};

    numberTail->enqueue(&values[0]);
    numberTail->enqueue(&values[1]);
    numberTail->enqueue(&values[2]);
    numberTail->enqueue(&values[3]);

    cout<<*numberTail->front()<<endl;

    while(!nameTail->isEmpty()){
        cout<<*nameTail->dequeue()<<endl;
    }

    while(!numberTail->isEmpty()){
        cout<<*numberTail->dequeue()<<endl;
    }

    return 0;
}