#include <iostream>
#include <string>

#include "TelefonbuchServer.h"
using namespace std;

TelefonbuchServer::TelefonbuchServer(int port)
{
	// 1) ServerSocket() - erzeugt einen Serversocket
	// ToDo
	//int SERVER_PORT = 5586;
	server = new ServerSocket(port);
	cout << "--Server ist gestartet--";
	daten = new Telefonbuch();
	daten->toString();
}

TelefonbuchServer::~TelefonbuchServer(void)
{
	delete server;
	delete daten;
}

void TelefonbuchServer::start()
{
	string anfrageName = "";
	string antwort;
	// ToDo


		// 3) accept() - erzeugt einen ArbeitsSocket (workSocket), wenn ein Client eine Verbindung anfragt
		//    Der Aufruf von accept() blockiert solange, bis ein Client Verbindung aufnimmt

		// ToDo
	Socket* socket = server->accept();
	cout << "Client verbunden!" << endl;


	while(anfrageName != "EXIT")
	{
		// 5b) Kommunikation mit read() write()
		// To
		anfrageName = socket->readLine();
		if (anfrageName == "EXIT")
		{
			break;
		}
		cout << "Der ausgegebene Text: " << anfrageName << endl;
		socket->write(daten->nrSuche(anfrageName));

	}

	// 7) ArbeitsSocket abmelden
	// ToDo
	socket->close();
// 8) ServerSocket abmelden
// ToDo
	server->close();
}