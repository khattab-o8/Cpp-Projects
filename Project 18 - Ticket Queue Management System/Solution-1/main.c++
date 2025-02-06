#include <iostream>
#include <string>
#include "clsQueueLine.h"
using namespace std;

int main()
{
    system("color 0d");

    clsQueueLine PayBillsQueue("A0", 10);
    clsQueueLine SubscriptionsQueue("B0", 5);

    PayBillsQueue.IssueTicket();
    PayBillsQueue.IssueTicket();
    PayBillsQueue.IssueTicket();
    PayBillsQueue.IssueTicket();
    PayBillsQueue.IssueTicket();

    cout << "\nPay Bills Queue Info:\n";
    PayBillsQueue.PrintInfo();

    PayBillsQueue.PrintTicketsLineRTL();
    PayBillsQueue.PrintTicketsLineLTR();

    PayBillsQueue.PrintAllTickets();

    PayBillsQueue.ServeNextClient();
    PayBillsQueue.ServeNextClient();
    cout << "\nPay Bills Queue After Serving Two Client(2)\n";
    PayBillsQueue.PrintInfo();


    cout << "\nSubscriptions Queue Info:\n";

    SubscriptionsQueue.IssueTicket();
    SubscriptionsQueue.IssueTicket();
    SubscriptionsQueue.IssueTicket();

    SubscriptionsQueue.PrintInfo();

    SubscriptionsQueue.PrintTicketsLineRTL();
    SubscriptionsQueue.PrintTicketsLineLTR();

    SubscriptionsQueue.PrintAllTickets();

    SubscriptionsQueue.ServeNextClient();
    cout << "\nSubscriptions Queue After Serving One Client(s)\n";
    SubscriptionsQueue.PrintInfo();


    system("pause > 0");
    return 0;
}