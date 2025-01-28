# 🚀 Custom Utility Class Library

## 📖 Overview

Welcome to the **Custom Utility Class Library**! This C++ project provides a comprehensive utility class, `clsUtil`, designed to simplify common operations in your applications. The library leverages object-oriented programming (OOP) principles to deliver clean and reusable code.

## 🌟 Features

- **🔢 Random Number Generation:**
  Generate random numbers within a specified range.

- **🔠 Random Character and String Generation:**

  - Generate random characters (small letters, capital letters, digits, or mixed).
  - Create random words or keys of customizable length.

- **🔄 Swap Functions:**

  - Swap integers, doubles, strings, or custom `clsDate` objects.

- **🔀 Array Utilities:**

  - Shuffle integer or string arrays.
  - Fill arrays with random numbers, words, or keys.

- **🔐 Text Encryption and Decryption:**

  - Encrypt and decrypt text using a specified key.

- **📏 Formatting Tools:**
  - Add customizable tab spaces to strings.

## 🛠️ How to Use

### 1. Initialize Random Seed

To ensure random operations produce different results each time, initialize the random seed:

```cpp
clsUtil::Srand();
```

### 2. Generate Random Numbers

```cpp
int randomNum = clsUtil::RandomNumber(1, 100);
```

### 3. Create Random Words and Keys

```cpp
string word = clsUtil::GenerateWord(clsUtil::enCharType::CapitalLetter, 5);
string key = clsUtil::GenerateKey(clsUtil::enCharType::MixChars);
```

### 4. Encrypt and Decrypt Text

```cpp
string encrypted = clsUtil::EncryptText("Hello", 3);
string decrypted = clsUtil::DecryptText(encrypted, 3);
```

### 5. Shuffle Arrays

```cpp
int arr[100] = {1, 2, 3, 4, 5};
clsUtil::ShuffleArray(arr, 5);
```

### 6. Swap Values

```cpp
int a = 5, b = 10;
clsUtil::Swap(a, b);
```

## 📂 Project Structure

- **`clsUtil.h`**: Contains the utility class definition.
- **`clsDate.h`**: (Optional) Dependency for date swapping functionality.

## 💻 Prerequisites

- C++ compiler supporting modern standards (C++11 or later).

## 📋 Example

Here’s a quick demonstration of the library:

```cpp
#include "clsUtil.h"
#include <iostream>

int main() {
    clsUtil::Srand();

    int randomNum = clsUtil::RandomNumber(1, 50);
    std::cout << "Random Number: " << randomNum << std::endl;

    std::string word = clsUtil::GenerateWord(clsUtil::enCharType::SamallLetter, 6);
    std::cout << "Random Word: " << word << std::endl;

    std::string encrypted = clsUtil::EncryptText("Hello", 5);
    std::cout << "Encrypted Text: " << encrypted << std::endl;

    return 0;
}
```

## 🙌 Contributing

Feel free to contribute to this project by submitting issues or pull requests. Let’s make it better together!
