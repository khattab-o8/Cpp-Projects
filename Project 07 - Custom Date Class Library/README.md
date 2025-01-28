# 📅 Custom Date Class Library

Welcome to the **Custom Date Class Library**! This C++ project leverages Object-Oriented Programming (OOP) principles to provide a robust and versatile class for handling and manipulating dates.

---

## ✨ Features

- **Date Initialization**: Create date objects with various formats (e.g., system date, custom date strings, specific day order in a year).
- **Leap Year Support**: Determine whether a year is a leap year.
- **Date Validations**: Check the validity of dates.
- **Calendar Utilities**:
  - Print monthly and yearly calendars.
  - Display weekdays and month names.
- **Date Calculations**:
  - Difference in days between two dates.
  - Add days to a specific date.
  - Check if a date is the last day of the month.
- **Age Calculation**: Compute age in days.
- **Comparison Utilities**: Compare dates for equality or order.

---

### Example Usage

Here's a quick example to get you started:

```cpp
#include <iostream>
#include "clsDate.h"
using namespace std;

int main() {
    clsDate today;  // System date
    today.Print();  // Print today's date

    clsDate customDate(25, 12, 2025);  // Custom date: Christmas 2025
    customDate.PrintMonthCalendar();  // Print December 2025 calendar

    clsDate anotherDate("01/01/2000");  // Custom date from string
    cout << "Days from the beginning of the year: " << anotherDate.DaysFromTheBeginingOfYear() << endl;

    return 0;
}
```

---

## 🛠️ Functions Overview

### Constructors

- **Default Constructor**: Initializes the date to the current system date.
- **Parameterized Constructors**: Create dates using day/month/year, string, or day order in a year.

### Static Methods

- `GetSystemDate()`
- `isLeapYear(Year)`
- `NumberOfDaysInAMonth(Month, Year)`
- `PrintMonthCalendar(Month, Year)`
- `PrintYearCalendar(Year)`
- `GetDifferenceInDays(Date1, Date2)`

### Instance Methods

- `Print()`
- `IsValid()`
- `PrintMonthCalendar()`
- `PrintYearCalendar()`
- `IncreaseDateByOneDay()`
- `GetDifferenceInDays(Date2)`

---

## 💡 Why Use This Library?

- Simplifies date manipulation.
- Avoids common pitfalls with manual date calculations.
- A great example of OOP design in C++.

---

## 📬 Contributing

Contributions are welcome! Feel free to submit issues or pull requests.
