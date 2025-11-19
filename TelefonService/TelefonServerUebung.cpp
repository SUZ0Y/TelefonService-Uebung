#include <iostream>
#include "TelefonbuchServer.h"
#include "MeinThread.h"

using namespace std;
#define SERVERPORT 54321
#define SERVERIP "127.0.0.1"


int main()
{
	// Mehr sollte in der main() nicht stehen!

	TelefonbuchServer* srv = new TelefonbuchServer(SERVERPORT);
	cout << "------------SERVER--------------" << endl;
	srv->start();

	MeinThread mt;

	if (mt.start())
	{
		cout << "Main: MeinThread wurde gestartet" << endl;
		mt.join();
		cout << "Main: MeinThread fertig" << endl;
	}
	else {
		cout << "MeinThread konnte nicht gestartet werden!" << endl;
	}


	delete srv;
	return 0;
}