## 📚Custom My Stack Class Library 🚀

Welcome to the **Custom My Stack Class Library** project! This C++ library demonstrates how to implement a stack data structure using a doubly linked list and object-oriented programming (OOP) principles. 📚✨

## Overview 📖

This project provides a custom implementation of a stack class (`clsMyStack`) that leverages a doubly linked list (`clsDblLinkedList`). The stack supports common operations like push, pop, top, bottom, reverse, and more. It’s a great example of combining data structures with OOP in C++.

## Features ✨

- **Template Class**: Generic implementation using templates to accommodate any data type.
- **Doubly Linked List Integration**: Utilizes a custom doubly linked list for internal storage.
- **Standard Stack Operations**: Push, pop, peek (top), and size functionalities.
- **Extended Capabilities**: Insert, update, reverse, and clear operations for advanced control.
- **Efficient Memory Management**: Dynamic allocation ensures optimal use of resources.

# API Reference 📚

## Stack Operations 🏗

### `void push(T Value)`

- **Description:** Adds an item to the top of the stack.
- **Parameters:**
  - `Value` - The item to be added.

### `void pop()`

- **Description:** Removes the item at the top of the stack.

### `T Top()`

- **Description:** Returns the item at the top without removing it.
- **Returns:** The top item of type `T`.

### `short Size()`

- **Description:** Retrieves the number of items in the stack.
- **Returns:** The size of the stack.

### `void Clear()`

- **Description:** Removes all items from the stack.

## Additional Methods 🛠

### `void Print()`

- **Description:** Prints all the items in the stack from top to bottom.

### `T Bottom()`

- **Description:** Returns the item at the bottom of the stack.
- **Returns:** The bottom item of type `T`.

### `T GetItem(int Index)`

- **Description:** Retrieves an item at a specific index.
- **Parameters:**
  - `Index` - The position of the item.
- **Returns:** The item at the specified index.

### `void UpdateItem(int Index, T NewValue)`

- **Description:** Updates the item at the given index with a new value.

### `void InsertAfter(int Index, T NewValue)`

- **Description:** Inserts a new item after the specified index.

### `void InsertAtFront(T Value)`

- **Description:** Inserts an item at the front of the stack.

### `void InsertAtBack(T Value)`

- **Description:** Inserts an item at the back (bottom) of the stack.

### `void Reverse()`

- **Description:** Reverses the order of the items in the stack.
