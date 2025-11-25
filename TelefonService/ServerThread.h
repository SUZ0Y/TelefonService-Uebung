#pragma once
#include "Thread.h"
#include "Telefonbuch.h"
#include "Socket.hpp"
#include "ServerSocket.hpp"
using namespace std;
#include <string>
#include <iostream>

class ServerThread : public Thread
{
private:
	Socket* workSocket;
	Telefonbuch* daten;
	int clientID;

public:
	ServerThread(Socket* work, Telefonbuch* dat, int id) : workSocket(work), daten(dat), clientID(id) {}

	void run() override {
		string anfrageName = "";
		string antwort;
		// ToDo

		while (anfrageName != "EXIT")
		{
			// 5b) Kommunikation mit read() write()
			// ToDo
			anfrageName = workSocket->readLine();
			if (anfrageName == "EXIT") {
				break;
			}
			//if(anfrageName != "EXIT")workSocket->write(daten->nrSuche(anfrageName));
			workSocket->write(daten->nrSuche(anfrageName));
			cout << "Client [" << clientID << "] geantwortet\n";
		}

		// 7) ArbeitsSocket abmelden
		// ToDo
		workSocket->close();
		delete workSocket;
		workSocket = nullptr;
		cout << "Client [" << clientID << "] hat die Verbindung beendet\n";
	}
};