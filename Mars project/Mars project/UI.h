#pragma once

#include "Event.h"
#include "../data sturctures/Queue.h"

#include <iostream>
#include <fstream>
using namespace std;


class UI
{
private:
	int P_Rovers;		  // number of polar rovers
	int E_Rovers;		  // number of emergency rovers
	int Avg_P_Speed;	  // average speed of polar rover (Km/hr)
	int Avg_E_Speed;	  // average speed of emergency rover
	int Checkup;		  // number of missions before checkup
	int P_Checkup_Dur;	  // checkup duration for polar rovers
	int E_Checkup_Dur;	  // checkup duration for emergency rovers
	int Num_Events;		  // number of events
	//Event** Event_List = new Event* [Num_Events]; dh hyb2a fl marsstation

public:
	//UI(int, int, int, int, int, int, int, int);
	UI();

	void Read_File(Queue<Event>& Event_List);	// reads input from file, and calls Fill_Events

	void Fill_Events(ifstream& fin, Queue<Event>& Event_List);  // Takes empty list of events from MarsStation
											                	// and fills it with the events read from file
};

