# 📚 Custom Double Linked List Class Library

## 🚀 Introduction

This project is a **Custom Double Linked List** implementation in C++ using **Object-Oriented Programming (OOP)** and **Data Structures**. It provides various methods to manipulate the linked list efficiently.

## 🛠 Features

- ✅ Insert at the beginning
- ✅ Insert at the end
- ✅ Insert after a specific node
- ✅ Delete a node
- ✅ Delete the first node
- ✅ Delete the last node
- ✅ Find an element
- ✅ Print the list
- ✅ Get size of the list
- ✅ Reverse the list
- ✅ Clear the list
- ✅ Update an element

## 📂 File Structure

```
📦 Custom Double Linked List
 ┣ 📜 clsDblLinkedList.h  # Header file containing class definition
 ┗ 📜 main.cpp            # Example usage of the library
```

## 📝 Usage

### 1️⃣ Include the Header File

```cpp
#include "clsDblLinkedList.h"
```

### 2️⃣ Create an Instance

```cpp
clsDblLinkedList<int> myList;
```

### 3️⃣ Insert Elements

```cpp
myList.InsertAtBeginning(10);
myList.InsertAtEnd(20);
```

### 4️⃣ Print List

```cpp
myList.PrintList();
```

### 5️⃣ Find an Element

```cpp
clsDblLinkedList<int>::Node* foundNode = myList.Find(10);
if (foundNode) {
    cout << "Element found: " << foundNode->value << endl;
} else {
    cout << "Element not found!" << endl;
}
```

## 📌 Methods

| Method                                | Description                           |
| ------------------------------------- | ------------------------------------- |
| `InsertAtBeginning(T value)`          | Adds a new node at the beginning      |
| `InsertAtEnd(T value)`                | Adds a new node at the end            |
| `InsertAfter(Node* current, T value)` | Inserts a new node after a given node |
| `DeleteNode(Node*& NodeToDelete)`     | Deletes a specific node               |
| `DeleteFirstNode()`                   | Removes the first node                |
| `DeleteLastNode()`                    | Removes the last node                 |
| `Find(T value)`                       | Finds a node with the given value     |
| `PrintList()`                         | Prints the linked list                |
| `Size()`                              | Returns the size of the list          |
| `IsEmpty()`                           | Checks if the list is empty           |
| `Clear()`                             | Clears the list                       |
| `Reverse()`                           | Reverses the list                     |
| `GetNode(int index)`                  | Returns the node at a given index     |
| `GetItem(int index)`                  | Returns the value at a given index    |
| `UpdateItem(int index, T newValue)`   | Updates a value at a given index      |

## 🎯 Example Output

```
10  20  30
Element found: 10
List size: 3
```

## 🏗 Technologies Used

- 💻 C++
- 🔢 Data Structures (Double Linked List)
- 🏛 Object-Oriented Programming (OOP)

## 🏆 Contributing

Feel free to contribute! Open an issue or submit a pull request if you have suggestions or improvements.
