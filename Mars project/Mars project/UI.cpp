#include "UI.h"

//UI::UI(int P_Num, int E_num, int P_Speed, int E_Speed,
//	int Check_Num, int P_Check_Time, int E_Check_Time, int N)
//{
//	P_Rovers = P_Num;
//	E_Rovers = E_num;
//	Avg_P_Speed = P_Speed;
//	Avg_E_Speed = E_Speed;
//	Checkup = Check_Num;
//	P_Checkup_Dur = P_Check_Time;
//	E_Checkup_Dur = E_Check_Time;
//	Num_Events = N;
//}

UI::UI()
{

}

int UI::get_NumEvents()
{
	return Num_Events;
}

void UI::Read_File(Queue<Event*>& Event_List, PriQ<Rover*>& rovers_emergency, PriQ<Rover*>& rovers_polar)
{
	string filename;
	cout << "Enter file name to be loaded: ";
	cin >> filename;
	filename += ".txt"; // adds .txt extension to filename

	ifstream fin (filename); // opens file to read from

	if (fin.is_open()) // makes sure file was opened successfully
	{
		Fill_Rovers(fin, rovers_emergency, rovers_polar); // fills the rover lists
		Fill_Events(fin, Event_List);					  // fills the event list
	}

	fin.close(); // closes file so other handles could use it later on

}

void UI::Fill_Events(ifstream& fin, Queue<Event*>& Event_List)
{
	char type;
	int event_day, id, distance, num_days, sig;
	
	fin >> Num_Events;
	for (int i = 0; i < Num_Events; i++)  // loads the data of each event
	{
		fin >> type >> type >> event_day >> id >> distance
			>> num_days >> sig;
		// Notice that type is overwritten first time
		// This is because the event is always formulation event anyway

		Event* Formulation = new Event(type, event_day, id, distance, num_days, sig);
		Event_List.enqueue(Formulation);
	}

}

void UI::Fill_Rovers(ifstream& fin, PriQ<Rover*>& rovers_emergency,
	PriQ<Rover*>& rovers_polar)
{
	Rover* rover = nullptr;

	// takes input from file
	fin >> P_Rovers >> E_Rovers;
	fin >> Avg_P_Speed >> Avg_E_Speed;
	fin >> Checkup >> P_Checkup_Dur >> E_Checkup_Dur;
	for (int i = 0; i < P_Rovers; i++)
	{
		rover = new Rover_Polar(Avg_P_Speed, Checkup, P_Checkup_Dur);	// creates the rover
		rovers_polar.insert(rover, ((Rover_Polar*)rover)->get_Speed()); // places it in the list, sorted
																		// descendingly according to speed
		//mission = new Mission_Emergency(id, distance, num_days, sig, event_day);
		//emergency.insert(mission, mission->get_priority());
	}
	for (int i = 0; i < E_Rovers; i++)
	{
		rover = new Rover_Emergency(Avg_E_Speed, Checkup, E_Checkup_Dur);		// creates the rover
		rovers_emergency.insert(rover, ((Rover_Emergency*)rover)->get_Speed()); // places it in the list, sorted
																				// descendingly according to speed
	}
}