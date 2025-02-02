# 🎯 Custom Queue Class Library (C++) 🚀

A custom Queue data structure implementation in C++ using Object-Oriented Programming (OOP) principles and Doubly Linked List implementation. 📚

## 🌟 Features

- 🏗️ Template-based implementation for generic data handling
- ⚡ Efficient queue operations (push/pop) in O(1) time complexity
- 🔄 Reversible queue elements
- 📏 Dynamic size management
- ✅ Standard queue operations with extended functionality
- 🛠️ Exception-safe implementation
- 📈 Based on doubly linked list for efficient memory management

## 🧰 Class Methods

# Queue Class Methods

This document outlines the methods available for the queue implementation.

## Methods

| Method                      | Description                       |
| --------------------------- | --------------------------------- |
| `push(T Item)`              | Add element to end 📌             |
| `pop()`                     | Remove first element 🗑️           |
| `front()`                   | Get first element 🥇              |
| `back()`                    | Get last element 🏁               |
| `Size()`                    | Get queue size 📏                 |
| `IsEmpty()`                 | Check if empty 🕳️                 |
| `Reverse()`                 | Reverse queue order 🔄            |
| `GetItem(int Index)`        | Access element by index 📍        |
| `UpdateItem(int Index, T)`  | Modify element by index ✏️        |
| `InsertAfter(int Index, T)` | Insert new element after index ➕ |
| `InsertAtFront(T)`          | Add to front ⏩                   |
| `InsertAtBack(T)`           | Add to back ⏪                    |
| `Clear()`                   | Remove all elements 🧹            |
| `Print()`                   | Display queue contents 📄         |

## Usage

To use these methods in your project, simply call the corresponding function on your queue instance. For example:

````cpp
Queue<int> myQueue;
myQueue.push(10);
int firstElement = myQueue.front();
myQueue.pop();

## 🚦 Usage

```cpp
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

````

## 📚 Example Use Cases

🗄️ Task scheduling system
📶 Network packet management
🎮 Game event handling
📊 Data buffering operations
🔄 Breadth-First Search (BFS) algorithms
