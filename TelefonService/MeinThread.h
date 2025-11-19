#pragma once
#include <iostream>
#include "Thread.h"

using namespace std;

class MeinThread : public Thread
{
	void run() override {

		for (int i = 0; i <= 3; i++)
		{
			cout << "MeinThread.h : MyThread Schritt [" << i << "]\n";
		}
		cout << "MeinThread.h : MyThread laueft!" << endl;
	}

};

