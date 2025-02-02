#include <iostream>
#include "clsMyQueue.h"
using namespace std;

int main()
{
    clsMyQueue <int> MyQueue;
  
    MyQueue.push(10);
    MyQueue.push(20);
    MyQueue.push(30);
    MyQueue.push(40);
    MyQueue.push(50);

    cout << "\nQueue : \n\n";
    MyQueue.Print();

    cout << "\n\nQueue size is : " << MyQueue.Size();
    cout << "\n\nQueue Front is : " << MyQueue.front();
    cout << "\n\nQueue Back is : " << MyQueue.back();

    MyQueue.pop();
    MyQueue.pop();

    cout << "\n\nQueue after pop : \n\n";
    MyQueue.Print();

    //Extension #1
    cout << "\n\n Item(2) : " << MyQueue.GetItem(2);
    
    //Extension #2
    MyQueue.Reverse();
    cout << "\n\nQueue after reverse() : \n";
    MyQueue.Print();

    //Extension #3
    MyQueue.UpdateItem(2, 600);
    cout << "\n\nQueue after updating Item(2) to 600 : \n";
    MyQueue.Print();

    //Extension #4
    MyQueue.InsertAfter(2, 800);
    cout << "\n\nQueue after Inserting 800 after Item(2) : \n";
    MyQueue.Print();

    //Extension #5
    MyQueue.InsertAtFront(1000);
    cout << "\n\nQueue after Inserting 1000 at front: \n";
    MyQueue.Print();

    //Extension #6
    MyQueue.InsertAtBack(2000);
    cout << "\n\nQueue after Inserting 2000 at back: \n";
    MyQueue.Print();

    //Extension #7
    MyQueue.Clear();
    cout << "\n\nQueue after Clear(): \n";
    MyQueue.Print();

    system("pause >0 ");
    return 0;
}