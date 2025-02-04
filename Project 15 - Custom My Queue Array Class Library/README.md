# 📚 Custom MyQueueArray Class Library

Welcome to the **Custom MyQueueArray Class Library**! 🎉 This C++ project showcases a dynamic queue implementation using arrays, emphasizing key concepts in Data Structures and Object-Oriented Programming (OOP).

## 🚀 Features

- **Dynamic Queue Implementation** 🌀
- **Enqueue (`push`) and Dequeue (`pop`) Operations** 📥📤
- **Access Front and Back Elements** 🎯
- **Queue Reversal Capability** 🔄
- **Item Insertion and Update at Specific Positions** 🛠️
- **Check if the Queue is Empty** ❔
- **Retrieve Queue Size** 📏
- **Clear All Elements** 🧹

## 🛠️ Getting Started

### Prerequisites

- C++ Compiler (e.g., GCC, Clang)
- Basic understanding of C++ Templates and OOP

### Installation

Include the header files in your project:

```cpp
#include "clsMyQueueArr.h"
#include "clsDynamicArray.h"
```

## 📄 Class Overview

### clsMyQueueArr

A templated class providing a queue interface with underlying dynamic array storage.

#### Public Methods

- `void push(T Value)`  
  Add an element to the back of the queue. ➕
- `void pop()`  
  Remove the front element from the queue. ➖
- `void Print()`  
  Display all elements in the queue. 🖨️
- `short Size()`  
  Get the number of elements in the queue. 🔢
- `bool IsEmpty()`  
  Check if the queue is empty. ✅
- `T front()`  
  Access the front element. 🎯
- `T back()`  
  Access the back element. 🎯
- `T GetItem(int Index)`  
  Retrieve an item at a specific index. 🔍
- `void Reverse()`  
  Reverse the order of elements in the queue. 🔄
- `void UpdateItem(int Index, T NewValue)`  
  Update the value of an item at a specific index. 🛠️
- `void InsertAfter(int Index, T NewValue)`  
  Insert a new item after a specific index. 📝
- `void InsertAtFront(T Value)`  
  Insert an item at the front of the queue. 🏁
- `void InsertAtBack(T Value)`  
  Insert an item at the back of the queue. 🎬
- `void Clear()`  
  Remove all elements from the queue. 🧹

## 📝 Usage Example

Here's a quick example to get you started:

```cpp
#include <iostream>
#include "clsMyQueueArr.h"

int main() {
    clsMyQueueArr<int> myQueue;

    // Enqueue elements
    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);

    // Display the queue
    std::cout << "Queue elements: ";
    myQueue.Print(); // Output: 1 2 3

    // Access front and back elements
    std::cout << "Front: " << myQueue.front() << std::endl; // Output: 1
    std::cout << "Back: " << myQueue.back() << std::endl;   // Output: 3

    // Dequeue an element
    myQueue.pop();

    // Display the queue after dequeue
    std::cout << "After pop, queue elements: ";
    myQueue.Print(); // Output: 2 3

    // Reverse the queue
    myQueue.Reverse();
    std::cout << "After reverse, queue elements: ";
    myQueue.Print(); // Output: 3 2

    // Clear the queue
    myQueue.Clear();
    std::cout << "Queue cleared. Is empty? " << (myQueue.IsEmpty() ? "Yes" : "No") << std::endl;

    return 0;
}
```

## 🌟 Additional Capabilities

- **Dynamic Array Integration**: Leverages `clsDynamicArray` for flexible storage management.
- **Error Handling**: Methods assume valid indices; ensure index bounds are checked in production code.
- **Template Class**: Supports any data type `T`, providing versatility. 🔧

## 📂 Project Structure

- `clsMyQueueArr.h`  
  Contains the `clsMyQueueArr` class template definition.
- `clsDynamicArray.h`  
  Includes the dynamic array implementation used internally.

## 🤖 Behind the Scenes

The `clsMyQueueArr` class encapsulates a `clsDynamicArray` instance, providing queue semantics on top of a dynamic array structure. This design demonstrates the power of composition in OOP, allowing for reusable and modular code components. 🧩

---

Elevate your understanding of data structures with this dynamic queue implementation! Dive deep, experiment, and happy coding! 🚀✨
