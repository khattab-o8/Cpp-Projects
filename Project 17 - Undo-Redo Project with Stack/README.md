# Undo-Redo Stack Project 📝🔄

Welcome to the **Undo-Redo Stack Project**! This C++ project showcases how to implement undo and redo functionality using stacks, embracing both data structures and object-oriented programming principles.

## Overview 🌟

Ever wanted to know how applications like text editors or drawing tools offer undo and redo features? This project demystifies that by providing a simple yet effective implementation using C++:

- **Undo Functionality**: Revert to previous states effortlessly.
- **Redo Functionality**: Reapply actions you've undone.
- **Stack Utilization**: Leverage the power of LIFO (Last-In, First-Out) with `std::stack`.
- **OOP Design**: Encapsulate data and behavior within a class for clean and maintainable code.

## How It Works 🔍

- **Set a Value**: Update `_Value` and push the old value onto the `_Undo` stack.
- **Undo**: Revert `_Value` to the last state from `_Undo`, and push the current state onto `_Redo`.
- **Redo**: Reapply the last undone state from `_Redo`, pushing the current state back onto `_Undo`.

## Usage Example 🚀

Let's see it in action:

```cpp
int main() {
    clsMyString myString;
    myString.Set("Hello");
    myString.Set("Hello, World!");

    cout << myString.Get() << endl; // Outputs: Hello, World!

    myString.Undo();
    cout << myString.Get() << endl; // Outputs: Hello

    myString.Redo();
    cout << myString.Get() << endl; // Outputs: Hello, World!

    return 0;
}
```

## Why Use Stacks? 📚

Stacks are perfect for undo-redo functionality because they naturally operate in a LIFO manner:

- **Undo Stack `_Undo`**: Keeps track of previous states. Every time you perform a new action, the current state is pushed onto this stack.
- **Redo Stack `_Redo`**: Stores states that have been undone. If you undo an action, you can redo it by popping from this stack.

### Visual Representation 🗂️

Imagine the stacks as two piles of books:

```
Undo Stack          Redo Stack
-----------         -----------
|    "Hi"   |       |           |
|   "Hello" |       |           |
|-----------|       |-----------|
```

- **Current Value**: `"Hello, World!"`
- **Undo**: Move `"Hello, World!"` to `_Redo` and pop `"Hello"` from `_Undo` to `_Value`.
- **Redo**: Move `"Hello"` back to `_Undo` and pop `"Hello, World!"` from `_Redo` to `_Value`.

## Diving Deeper 🤔

- **Data Encapsulation**: The `_Value`, `_Undo`, and `_Redo` members are private, ensuring they can't be altered directly from outside the class.
- **State Management**: By pushing and popping states, we maintain a history that can be navigated seamlessly.

## Potential Enhancements ✨

- **Limit Stack Size**: Implement a maximum stack size to prevent excessive memory usage.
- **Generic Implementation**: Modify the class to handle undo-redo for different data types using templates.
- **Error Handling**: Provide feedback when undo or redo actions are not possible (e.g., when stacks are empty).

## Conclusion 🏆

This project serves as a fundamental example of how undo-redo mechanisms work under the hood. By understanding this concept, you can implement more complex features in applications that require state management.

Feel free to explore, modify, and expand upon this code to suit your needs. Happy coding! 🎉
