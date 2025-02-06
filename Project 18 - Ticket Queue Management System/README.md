# 🎟️ Ticket Queue Management System

Welcome to the **Ticket Queue Management System**! 🎉 This C++ project demonstrates a queue management system using Data Structures and Object-Oriented Programming (OOP). It's a simple yet powerful way to simulate issuing tickets, serving clients, and managing a queue line efficiently. 🚀

## 📖 Overview

This project is a console-based application that mimics a ticketing system often seen in banks, hospitals, or service centers. Clients take a ticket and wait their turn to be served. The system keeps track of waiting clients, served clients, and provides estimated wait times. It's a practical example of how queues and other data structures can be utilized in real-world scenarios. 🏢

## ✨ Features

- **Issue Tickets**: Clients can take a ticket and join the queue. 🆕
- **Serve Clients**: Serve the next client in line. 🎯
- **Display Queue Info**: View total tickets, served clients, and waiting clients. 📊
- **Visualize Tickets**: Print tickets in Left-to-Right or Right-to-Left order. 🔄
- **Estimate Wait Time**: Calculate expected serve time for clients. ⏳

## 🛠️ Getting Started

### Prerequisites

Make sure you have the following installed on your system:

- A C++ compiler (like GCC or Clang)
- C++11 or later support

## 🎮 Usage

Once you run the application, you'll be prompted with options to issue tickets, serve clients, and view queue information. Interact with the menu to simulate a real ticket queue system.

Here's a basic example of how you might use the system in code:

```cpp
#include "clsQueueLine.h"

int main() {
    clsQueueLine queue("A", 5); // Prefix 'A' with an expected serve time of 5 minutes

    queue.IssueTicket(); // Client takes a ticket
    queue.IssueTicket(); // Another client takes a ticket

    queue.PrintInfo(); // Display queue information
    queue.PrintAllTickets(); // Show all tickets in the queue

    queue.ServeNextClient(); // Serve the next client
    queue.PrintInfo(); // Display updated queue information

    return 0;
}
```

## 📝 Code Explanation

The system is built around two main classes: `clsQueueLine` and `clsTicket`.

### **clsTicket**

This class represents a single ticket in the system.

- **Properties**:

  - `string _Prifix`: Prefix for the ticket (e.g., "A").
  - `short _Counter`: Ticket number.
  - `string _CurrentDateTime`: Date and time the ticket was issued.
  - `short _WaitingClients`: Number of clients waiting.
  - `short _ExpectedServeTime`: Expected time to serve the client.

- **Key Methods**:
  - `GetTicketName()`: Returns the full ticket name (prefix + counter).
  - `PrintTicket()`: Prints the ticket details in a formatted manner.

### **clsQueueLine**

This class manages the queue of tickets.

- **Properties**:

  - `queue<clsTicket> QueueLine`: The ticket queue.
  - `string _Prifix`: Ticket prefix.
  - `short _ExpectedTime`: Expected serve time per client.
  - `short _TotalTickets`: Total number of tickets issued.

- **Key Methods**:
  - `IssueTicket()`: Issues a new ticket and adds it to the queue.
  - `ServeNextClient()`: Removes the next client from the queue.
  - `PrintInfo()`: Displays information about the queue.
  - `PrintTicketsLineRTL()`: Prints tickets from Right-to-Left.
  - `PrintTicketsLineLTR()`: Prints tickets from Left-to-Right.
  - `PrintAllTickets()`: Prints all tickets in the queue.

## 📋 Sample Output

When running the application, you might see output similar to:

```
_________________________________

                A1

        2023-10-05 14:23:15
        Waiting Clients = 3
            Serve Time In
            15 Minutes.

_________________________________

Queue Info
_________________________________

-> Prifix           =  A
-> Total Tickets    =  5
-> Served Clients   =  2
-> Waiting Clients  =  3
_________________________________
```

## 📝 Notes

- The project uses `clsDate` class for handling date and time. Make sure to include it in your project.
- Error handling is minimal; consider adding checks as needed.
- Customize the ticket prefix and expected serve time when initializing `clsQueueLine`.

## 🗒️ Future Improvements

- Implement a graphical user interface for better user experience. 🎨
- Add functionality for different service types with separate queues. 🔧
- Implement persistent storage to save queue state between sessions. 💾

## 🙌 Acknowledgments

- Thanks to the C++ community for their continuous support and resources. 🌟
- Inspired by real-world ticketing systems to provide a practical learning experience. 🎯

Feel free to explore, modify, and enhance the system to suit your needs! If you have any questions or suggestions, don't hesitate to reach out. Happy coding! 💻
