# 🧮 Simple Calculator using OOP in C++

Welcome to the **Simple Calculator** project! This calculator is implemented in C++ using **Object-Oriented Programming (OOP)** principles, showcasing encapsulation, abstraction, and modular design.

## 🚀 Features

- **Addition** ➕: Add numbers to the current result.
- **Subtraction** ➖: Subtract numbers from the current result.
- **Multiplication** ✖️: Multiply the current result by a number.
- **Division** ➗: Divide the current result by a number (handles division by zero gracefully).
- **Cancel Last Operation** ❌: Undo the most recent operation.
- **Clear Calculator** 🗑️: Reset the calculator to its initial state.
- **Print Results** 🖨️: Display intermediate and final results on the console.

## 🛠️ Code Structure

The project is built around the `clsCalculator` class, which encapsulates all calculator functionalities. Key components include:

- **Private Members:**

  - `_LastNumber`: Stores the last entered number.
  - `_PreviosResult`: Stores the result before the last operation.
  - `_Result`: Stores the current result.
  - `_IdentifyOperation`: Describes the last operation performed.
  - `_IsZeroNumber`: Utility function to check if a number is zero.

- **Public Methods:**
  - `Add(float Number)`
  - `Subtract(float Number)`
  - `Multiply(float Number)`
  - `Divide(float Number)`
  - `CancelLastOperation()`
  - `Clear()`
  - `PrintResult()`
  - `GetFinalResult()`

## 💻 Usage

To use the calculator, instantiate the `clsCalculator` class and call its methods based on your desired operations.

### Example:

```cpp
clsCalculator Calculator;

Calculator.Clear();
Calculator.Add(20);
Calculator.Subtract(5);
Calculator.Multiply(2);
Calculator.Divide(0); // Gracefully handles division by zero
Calculator.Divide(3);
Calculator.CancelLastOperation();

cout << "Final Result = " << Calculator.GetFinalResult();

Result After Clear 0 is: 0
Result After Adding 20 is: 20
Result After Subtracting 5 is: 15
Result After Multiplying 2 is: 30
Result After Dividing 0 is: 30
Result After Dividing 3 is: 10
Result After Cancelling Last Operation 0 is: 30
Final Result = 30
```
