#pragma once
#include <mutex>
#include "Thread.h"
#include "Telefonbuch.h"
#include "Socket.hpp"
#include "ServerSocket.hpp"
using namespace std;
#include <string>
#include <iostream>

static mutex tmute;

class ServerThread : public Thread
{
private:
	Socket* workSocket;
	Telefonbuch* daten;
	int clientID;

public:
	ServerThread(Socket* work, Telefonbuch* dat, int id) : workSocket(work), daten(dat), clientID(id) {}
	void setWorkSocket(Socket* socket) { workSocket = socket; }
	void run() override;

	
};