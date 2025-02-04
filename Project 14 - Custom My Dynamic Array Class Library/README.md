# 🚀 C++ Dynamic Array Class Library 📚

A custom dynamic array implementation in C++ using **templates** and **Object-Oriented Programming (OOP)** principles. This library provides a flexible and efficient way to manage dynamic arrays with a variety of built-in operations. 🧩

---

## 🌟 Features

- **Templated Class** 🔄: Supports any data type (e.g., `int`, `string`, custom objects).
- **Dynamic Resizing** 📏: Automatically adjusts the array size as elements are added/removed.
- **Common Operations** 🛠️:
  - Insert elements at the beginning, end, or any position.
  - Delete elements by index or value.
  - Reverse the array.
  - Check if the array is empty.
  - Clear the array.
- **Efficient Memory Management** 💾: Uses dynamic memory allocation for optimal performance.
- **Error Handling** 🚨: Validates indices and operations to prevent crashes.

---

## 📦 Installation

1. **Header-Only Library**: Simply include the `clsDynamicArray.h` file in your C++ project.

   ```cpp
   #include "clsDynamicArray.h"
   ```

2. **Compilation**: Ensure your compiler supports C++11 or later.

---

## 🛠️ Usage

### Creating a Dynamic Array

```cpp
clsDynamicArray<int> myArray(5); // Creates an array of size 5
```

### Basic Operations

```cpp
myArray.SetItem(0, 42);      // Set value at index 0
int value = myArray.GetItem(0); // Retrieve value

myArray.PrintList(); // Output: 42  0  0  0  0
```

### Inserting Elements

```cpp
myArray.InsertAtEnd(99);     // Insert 99 at the end
myArray.InsertAtBeginning(7); // Insert 7 at the start
myArray.InsertAfter(2, 55);  // Insert 55 after index 2
```

### Deleting Elements

```cpp
myArray.DeleteItemAt(3);     // Delete item at index 3
myArray.DeleteLastItem();    // Remove the last item
myArray.DeleteItem(42);      // Remove the first occurrence of 42
```

### Advanced Operations

```cpp
myArray.Reverse();           // Reverse the array
myArray.Resize(10);          // Resize to 10 elements
myArray.Clear();             // Clear all elements
```

---

## 📝 Example

```cpp
#include <iostream>
#include "clsDynamicArray.h"

int main() {
    clsDynamicArray<std::string> names(3);
    names.SetItem(0, "Alice");
    names.SetItem(1, "Bob");
    names.SetItem(2, "Charlie");

    names.InsertAtEnd("Diana");
    names.PrintList(); // Output: Alice  Bob  Charlie  Diana

    names.DeleteItem("Bob");
    names.PrintList(); // Output: Alice  Charlie  Diana

    return 0;
}
```

---

## 🧪 Testing

Add unit tests to verify functionality:

```cpp
// Example test case using a framework like Catch2
TEST_CASE("Dynamic Array Operations") {
    clsDynamicArray<float> arr(2);
    arr.SetItem(1, 3.14f);
    REQUIRE(arr.GetItem(1) == 3.14f);
}
```
