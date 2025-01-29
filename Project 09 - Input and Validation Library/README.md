# 📌 Custom Input and Validation Class Library

## 📖 Overview

This C++ project provides a **Custom Input and Validation Class Library** using **Object-Oriented Programming (OOP)**. It helps validate numeric inputs and date values with a set of utility functions.

## 🚀 Features

✅ Validate whether a number is within a given range (supports `int`, `float`, and `double`).
✅ Validate whether a date is within a given range.
✅ Read integer and double values safely from user input.
✅ Prevent invalid input using `cin.fail()` handling.
✅ Ensure correct date validation with the `clsDate` class.

### **`clsInputValidate`**

This class provides static functions to:

- 📌 Check if a number is within a specified range.
- 📌 Check if a date is between two given dates.
- 📌 Read and validate integer and double inputs from the user.
- 📌 Validate if a date is correctly formatted.

## 🛠️ Usage

### **Checking if a number is in range**

```cpp
int num = 50;
if (clsInputValidate::IsNumberBetween(num, 10, 100)) {
    cout << "✅ Number is within range!" << endl;
} else {
    cout << "❌ Number is out of range!" << endl;
}
```

### **Reading an integer from user input**

```cpp
int userAge = clsInputValidate::ReadIntNumber("Enter your age: ");
cout << "You entered: " << userAge << endl;
```

### **Validating a date**

```cpp
clsDate myDate(2025, 2, 15);
if (clsInputValidate::IsValideDate(myDate)) {
    cout << "✅ Valid date!" << endl;
} else {
    cout << "❌ Invalid date!" << endl;
}
```

## 📂 File Structure

```
📦 Project Directory
 ├── 📜 clsInputValidate.h  # Header file containing validation functions
 ├── 📜 clsDate.h           # Date handling class (Required for date validation)
 ├── 📜 main.cpp            # Example usage and testing
```

## 📌 Dependencies

- C++ Standard Library (`iostream`, `limits`)
- `clsDate` class for date validation

## 🙌 Contributions

Contributions are welcome! Feel free to submit issues or pull requests. 😊
