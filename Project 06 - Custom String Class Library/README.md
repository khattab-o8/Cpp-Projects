# 🧵 Custom String Class Library

Welcome to the **Custom String Class Library**! This C++ library is a powerful tool for string manipulation using Object-Oriented Programming (OOP). It provides various utilities to work with strings, such as counting words, transforming cases, and more.

---

## 📚 Features

Here are some of the awesome features this library offers:

1. **🔤 String Properties:**

   - Get or set the string value with ease using `Value` property.

2. **📏 String Length:**

   - Determine the length of a string or the instance.

3. **📝 Word Count:**

   - Count the number of words in a string.

4. **✍️ Transform Cases:**

   - Uppercase the first letter of each word.
   - Lowercase the first letter of each word.
   - Convert all characters to uppercase or lowercase.
   - Invert the case of all characters.

5. **🔍 Letter Counting:**

   - Count vowels, capital letters, small letters, or specific letters (case-sensitive or not).

6. **✂️ String Splitting and Joining:**

   - Split strings by a delimiter.
   - Join strings with a custom delimiter.

7. **🧹 String Trimming:**

   - Trim spaces from the left, right, or both sides.

8. **🔄 Reversing Words:**

   - Reverse the order of words in a string.

9. **🔧 Replace Words:**

   - Replace specific words in a string.

10. **❌ Remove Punctuations:**
    - Remove all punctuation characters from a string.

---

## 🚀 Usage Examples

### 🆕 Creating an Instance

```cpp
  clsString myString("Hello World!");
  cout << myString.Value << endl; // Outputs: Hello World!
```

📏 Get Length of a String

```cpp
  cout << myString.Length() << endl; // Outputs: 12
```

📝 Count Words

```cpp
  cout << myString.CountWords() << endl; // Outputs: 2
```

✍️ Transform Cases

```cpp
  myString.UpperAllString();
  cout << myString.Value << endl; // Outputs: HELLO WORLD!

  myString.LowerFirstLetterOfEachWord();
  cout << myString.Value << endl; // Outputs: hELLO wORLD!
```

🧹 Trim Strings

```cpp
  clsString trimmedString("   Extra spaces   ");
  trimmedString.Trim();
  cout << trimmedString.Value << endl; // Outputs: Extra spaces
```

🔄 Reverse Words in String

```cpp
  myString.ReverseWordsInString();
  cout << myString.Value << endl; // Outputs: World Hello
```

❌ Remove Punctuations

```cpp
  clsString punctuated("Hello, World!");
  punctuated.RemovePunctuations();
  cout << punctuated.Value << endl; // Outputs: Hello World
```
