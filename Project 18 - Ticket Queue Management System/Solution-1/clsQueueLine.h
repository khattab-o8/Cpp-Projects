#pragma once
#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <iomanip>
#include "clsDate.h"
using namespace std;

class clsQueueLine
{
private:

	class clsTickets
	{
	private:

		struct stTicket
		{
			short Counter = 0;
			string Prifix = "";
			string CurrentDate = "";
			string TicketNumber = "";
		};
		stTicket Ticket;

		string GetTicketNumber()
		{
			return (Ticket.Prifix + to_string(Ticket.Counter));
		}

	public:

		clsTickets(string Prifix, short Counter,string CurrentDate)
		{
			Ticket.Prifix = Prifix;
			Ticket.Counter = Counter;
			Ticket.CurrentDate = CurrentDate;
			Ticket.TicketNumber = GetTicketNumber();
		}

		friend class clsQueueLine;

	};

	clsTickets Ticket = clsTickets("", 0, "");

	queue <clsTickets> Original_Q_Tickets;
	queue <clsTickets> _TempQueue;
	stack <clsTickets> _TempStack;

	struct stOriginal_Q
	{
		string Prifix = "";
		string CurrentDateTime = "";
		short ExpectedTime = 0;
		short TicketCounter = 0;
		short ServedClients = 0;
		short WaitingClients = 0;
	};
	stOriginal_Q Original_Q;

	short CalculateWaitingClients()
	{
		return (Original_Q.TicketCounter - Original_Q.ServedClients);
	}
	short TimeInMinutes()
	{
		return (Original_Q.ExpectedTime * Original_Q.WaitingClients);
	}

public:

	clsQueueLine(string Prifix, int ExpectedTime)
	{
		Original_Q.Prifix = Prifix;
		Original_Q.ExpectedTime = ExpectedTime;
	}

	void IssueTicket()
	{
		Original_Q.TicketCounter++;

		Original_Q.CurrentDateTime = clsDate::GetSystemDateTimeString();

		Ticket = clsTickets(Original_Q.Prifix, Original_Q.TicketCounter, Original_Q.CurrentDateTime);
		Original_Q_Tickets.push(Ticket);
	}

	void PrintInfo()
	{
		cout << "\n\n";

		cout << setw(25) << left << " " << "_______________________________\n\n";
		cout << setw(25) << left << " " << setw(10) << left << " " << "Queue Info\n";
		cout << setw(25) << left << " " << "_______________________________\n\n";

		cout << setw(25) << left << " " << setw(2) << left << " " << "-> Pfifix           =  " << Original_Q.Prifix << "\n";
		cout << setw(25) << left << " " << setw(2) << left << " " << "-> Total Tickets    =  " << Original_Q.TicketCounter << "\n";
		cout << setw(25) << left << " " << setw(2) << left << " " << "-> Served Clients   =  " << Original_Q.ServedClients << "\n";
		cout << setw(25) << left << " " << setw(2) << left << " " << "-> Waiting Clients  =  " << CalculateWaitingClients() << "\n";

		cout << setw(25) << left << " " << "_______________________________\n";
	}

	void PrintTicketsLineRTL()
	{
		cout << "\n\n" << setw(15) << left << " " << "Tickets :    ";

		while (!Original_Q_Tickets.empty())
		{
			_TempQueue.push(Original_Q_Tickets.front());
			_TempStack.push(Original_Q_Tickets.front());

			cout << " " << Original_Q_Tickets.front().Ticket.TicketNumber << " <--  ";
			Original_Q_Tickets.pop();
		}

		
		//Mpve Data From Temp Queue To Original Queue.
		while (!_TempQueue.empty())
		{
			Original_Q_Tickets.push(_TempQueue.front());
			_TempQueue.pop();
		}
	}

	void PrintTicketsLineLTR()
	{
		cout << "\n\n" << setw(15) << left << " " << "Tickets :    ";

		while (!_TempStack.empty())
		{
			cout << " " << _TempStack.top().Ticket.TicketNumber << " -->  ";
			_TempStack.pop();
		}
	}

	void PrintAllTickets()
	{
		cout << "\n\n\n";
		cout << setw(25) << left << " " << setw(8) << left << " " << "--- Tickets ---\n";

		while (!Original_Q_Tickets.empty())
		{
			cout << setw(25) << left << " " << "_______________________________\n\n";
			cout << setw(38) << left << " " << Original_Q_Tickets.front().Ticket.TicketNumber << "\n\n";
			cout << setw(30) << left << " " << Original_Q_Tickets.front().Ticket.CurrentDate << "\n";
			cout << setw(30) << left << " " << "Waiting Clients = " << Original_Q.WaitingClients << "\n";
			cout << setw(32) << left << " " << "Serve Time In\n";
			cout << setw(33) << left << " " << TimeInMinutes() << " Minutes.\n";

			cout << setw(25) << left << " " << "_______________________________\n\n";

			Original_Q_Tickets.pop();
			Original_Q.WaitingClients++;
		}
	}

	void ServeNextClient()
	{
		Original_Q.ServedClients++;
	}
};

