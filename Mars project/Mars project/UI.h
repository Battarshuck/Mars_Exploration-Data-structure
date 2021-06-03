#pragma once
#include <windows.h>
#include "Event.h"
#include "Rover.h"
#include "Rover_Emergency.h"
#include "Rover_Polar.h"
#include "../data sturctures/Queue.h"
#include "../data sturctures/PriQ.h"

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
	int mode;

	void Fill_Events(ifstream& fin, Queue<Event*>& Event_List);  // Takes empty list of events from MarsStation
																 // and fills it with the events read from file

	void Fill_Rovers(ifstream& fin, PriQ<Rover*>& rovers_emergency,
		PriQ<Rover*>& rovers_polar);				// Takes empty list of rovers from Marstations
													// and fills it with the rovers read from file

public:
	UI();
	void Read_File(Queue<Event*>& Event_List, PriQ<Rover*>& rovers_emergency,
		PriQ<Rover*>& rovers_polar);	// reads input from file, and calls Fill_Events and Fill_Rovers
	
	int get_Num_P_Rovers() const;
	int get_Num_E_Rovers() const;
	int get_Checkup() const;
	int get_P_Checkup_Dur() const;
	int get_E_Checkup_Dur() const;
	int get_NumEvents() const;
	void Print(string,string,string,string,string,string) const;
	void getMode();
	void bye();
	~UI();
};

