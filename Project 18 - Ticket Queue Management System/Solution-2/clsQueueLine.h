#pragma once
#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <iomanip>
#include "clsDate.h"
using namespace std;

class clsQueueLine {
private:

	class clsTicket {
	private:

		string _Prifix;
		short _Counter;
		string _TicketName;
		string _CurrentDateTime;
		short _WaitingClients;
		short _ExpectedServeTime;

	public:

		clsTicket(string Prifix, short Counter, string CurrentDateTime, short WaitingClients, short ExpectedServeTime) {
			_Prifix = Prifix;
			_Counter = Counter;
			_CurrentDateTime = CurrentDateTime;
			_WaitingClients = WaitingClients;
			_ExpectedServeTime = ExpectedServeTime;
		}

		string GetTicketPrifix() {
			return _Prifix;
		}

		short GetNumberOfTickets() {
			return _Counter;
		}

		string GetTicketName() {
			return (_Prifix + to_string(_Counter));
		}

		string GetTicketDateTime() {
			return _CurrentDateTime;
		}

		short GetWaitingClients() {
			return _WaitingClients;
		}

		short GetExpectedTimeToServe() {
			return _ExpectedServeTime;
		}

		short GetAvgServeTimeInMin() {
			return (_ExpectedServeTime * _WaitingClients);
		}

		void PrintTicket() {
			cout << setw(25) << left << " " << "_______________________________\n\n";
			cout << setw(38) << left << " " << GetTicketName() << "\n\n";
			cout << setw(30) << left << " " << GetTicketDateTime() << "\n";
			cout << setw(30) << left << " " << "Waiting Clients = " << GetWaitingClients() << "\n";
			cout << setw(32) << left << " " << "Serve Time In\n";
			cout << setw(33) << left << " " << GetAvgServeTimeInMin() << " Minutes.\n";

			cout << setw(25) << left << " " << "_______________________________\n\n";
		}

	};

	queue <clsTicket> QueueLine;

	string _Prifix;
	short _ExpectedTime;
	short _TotalTickets;

public:

	clsQueueLine(string Prifix, short ExpectedTime) {
		_Prifix = Prifix;
		_ExpectedTime = ExpectedTime;
		_TotalTickets = 0;
	}

	void IssueTicket() {
		_TotalTickets++;

		clsTicket Ticket(_Prifix, _TotalTickets, clsDate::GetSystemDateTimeString(), WaitingClients(), _ExpectedTime);
		QueueLine.push(Ticket);
	}

	short WaitingClients() {
		return QueueLine.size();
	}

	short ServedClients() {
		return (_TotalTickets - WaitingClients());
	}

	void ServeNextClient() {
		QueueLine.pop();
	}

	void PrintInfo() {
		cout << "\n\n";

		if (QueueLine.empty()) {
			cout << setw(25) << left << " " << "_______________________________\n\n";
			cout << setw(33) << left << " " << "Queue Is Empty\n";
			cout << setw(25) << left << " " << "_______________________________\n\n";
			return;
		}

		cout << setw(25) << left << " " << "_______________________________\n\n";
		cout << setw(35) << left << " " << "Queue Info\n";
		cout << setw(25) << left << " " << "_______________________________\n\n";

		cout << setw(27) << left << " " << "-> Pfifix           =  " << _Prifix << "\n";
		cout << setw(27) << left << " " << "-> Total Tickets    =  " << _TotalTickets << "\n";
		cout << setw(27) << left << " " << "-> Served Clients   =  " << ServedClients() << "\n";
		cout << setw(27) << left << " " << "-> Waiting Clients  =  " << WaitingClients() << "\n";
		cout << setw(25) << left << " " << "_______________________________\n";
	}

	void PrintTicketsLineRTL() {
		if (QueueLine.empty()) {
			cout << "\n\n" << setw(15) << left << " " << "No Tickets :    ";
			return;
		}

		queue <clsTicket> TempQueue = QueueLine;

		cout << "\n\n" << setw(15) << left << " " << "Tickets :    ";

		while (!TempQueue.empty()) {
			cout << " " << TempQueue.front().GetTicketName() << " <--  ";
			TempQueue.pop();
		}
	}

	void PrintTicketsLineLTR() {
		if (QueueLine.empty()) {
			cout << "\n\n" << setw(15) << left << " " << "No Tickets :    ";
			return;
		}

		queue <clsTicket> TempQueue = QueueLine;
		stack <clsTicket> TempStack;

		while (!TempQueue.empty()) {
			TempStack.push(TempQueue.front());

			TempQueue.pop();
		}

		cout << "\n\n" << setw(15) << left << " " << "Tickets :    ";

		while (!TempStack.empty()) {
			cout << " " << TempStack.top().GetTicketName() << " -->  ";
			TempStack.pop();
		}
	}

	void PrintAllTickets() {
		if (QueueLine.empty()) {
			cout << "\n\n\n";
			cout << setw(30) << left << " " << "--- No Tickets ---\n";
			return;
		}

		queue <clsTicket> TempQueue = QueueLine;

		cout << "\n\n\n";
		cout << setw(25) << left << " " << setw(8) << left << " " << "--- Tickets ---\n";
		while (!TempQueue.empty()) {
			TempQueue.front().PrintTicket();
			TempQueue.pop();
		}
	}

};

