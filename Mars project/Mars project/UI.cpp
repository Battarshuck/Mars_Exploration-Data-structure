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

void UI::Read_File(Queue<Event*>& Event_List)
{
	string filename;
	cout << "Enter file name to be loaded: ";
	cin >> filename;
	filename += ".txt"; // adds .txt extension to filename

	ifstream fin (filename); // opens file to read from

	if (fin.is_open()) // makes sure file was opened successfully
	{
		// takes input from file
		fin >> P_Rovers >> E_Rovers;
		fin >> Avg_P_Speed >> Avg_E_Speed;
		fin >> Checkup >> P_Checkup_Dur >> E_Checkup_Dur;
		fin >> Num_Events;
	}


	Fill_Events(fin, Event_List); // fills the event list

	fin.close(); // closes file so other handles could use it later on

}

void UI::Fill_Events(ifstream& fin, Queue<Event*>& Event_List)
{
	char type;
	int event_day, id, distance, num_days, sig;
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