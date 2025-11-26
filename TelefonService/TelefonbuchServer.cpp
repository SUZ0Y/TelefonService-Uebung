#include <iostream>
#include <string>
#include "Thread.h"
#include "TelefonbuchServer.h"
#include "ServerThread.h"
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
	int count = 0;

	// ToDo


		// 3) accept() - erzeugt einen ArbeitsSocket (workSocket), wenn ein Client eine Verbindung anfragt
		//    Der Aufruf von accept() blockiert solange, bis ein Client Verbindung aufnimmt
	ServerThread* speicherST[3] = {};
		// ToDo
	while (true)
	{
		cout << "Warte auf Cient-Verbindung..." << endl;
		Socket* socket = server->accept();
		cout << "Client verbunden! [" << count << "]" << endl;
		bool foundfreethread = false;
		while (count == 3 && !foundfreethread) 
		{
			for (int i = 0; i < 3; i++)
			{
				if (!speicherST[i]->isRunning()) 
				{
					speicherST[i]->join();
					speicherST[i]->setWorkSocket(socket);
					speicherST[i]->start();
					foundfreethread = true;
					break;
				}
			}
		}
		if (count < 3) 
		{
			count++;
			ServerThread* t = new ServerThread(socket, daten, count);
			speicherST[count - 1] = t;
			t->start();
		}
	}


	//while(anfrageName != "EXIT")
	//{
	//	// 5b) Kommunikation mit read() write()
	//	// To
	//	anfrageName = socket->readLine();
	//	if (anfrageName == "EXIT")
	//	{
	//		break;
	//	}
	//	cout << "Der ausgegebene Text: " << anfrageName << endl;
	//	socket->write(daten->nrSuche(anfrageName));

	//}

	// 7) ArbeitsSocket abmelden
	// ToDo
	/*socket->close();*/
// 8) ServerSocket abmelden
// ToDo
	server->close();
}