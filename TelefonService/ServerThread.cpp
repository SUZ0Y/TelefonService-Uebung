#include "ServerThread.h"

void ServerThread::run()
{
	string anfrageName = "";
	string antwort;


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
