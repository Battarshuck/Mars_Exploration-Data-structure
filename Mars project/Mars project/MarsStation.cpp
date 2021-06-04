#include "MarsStation.h"
#include <time.h>

MarsStation::MarsStation()
{
	UserInterface = new UI();
	current_day = 0;
	num_events = 0;
	Failure_Percentage = 10;
	Failed_Missions = 0;
	srand(time(NULL)); // changes the seed for rand()
}

int Rover::ID = 0;
void MarsStation::Load()
{	
	UserInterface->getMode();
	UserInterface->Read_File(Event_list, rovers_emergency, rovers_polar); // fills the queue with events
	num_events = Event_list.getSize();
}

bool MarsStation::If_Failed()
{
	
	int percentage = rand() % 101;		// generates a random number between 0 and 100
	return (percentage < Failure_Percentage);
}

void MarsStation::simulate()
{
	while (num_events != missions_completed.getSize())
	{
		current_day++;
		//1-Events to be formulated [a]
		check_events();

		//2-check if in-execution missions are done, to return rovers (mostafa) [ sh8al 3l execution ]
		// mn in execution le available aw checkup
		check_inExecution();
		check_inCheckup();


		//3-Check first for emergency mission then polar to assign them to rover (hashish)
		//4-movement of rovers through lists (hashish)  [ sh8al 3l waiting ] 
		// mn available to in execution
		Assign_Emergency_Mission();
		Assign_Polar_Mission();

		
	
		//5-printing in the UI class (farah) [e,f]
		OutputGenerator();
	}
	UserInterface->bye();
	// UI.save
}



void MarsStation::check_events()
{
	Event* temp;
	while (Event_list.peek(temp))
	{
		
		if (temp->get_ExecuteDay() != current_day)	// Mission shouldn't be formulated today
			return;

		Event_list.dequeue(temp);					// Mission should be formulated today

		temp->Execute(missions_emergency, missions_polar);  // moves the mission from EventList to WaitingList
	}
}


// Moves in execution missions to completed list
// Moves rover to available or checkup list
void MarsStation::check_inExecution()
{
	Rover* temp_rover;
	Mission* temp_mission;
	//checking if the first rover finished its mission
	while (!rovers_inexecution.isEmpty())
	{
		//cheking if it is empty, if not then check if it is the rover day to finish the mission
		if (rovers_inexecution.isEmpty() || rovers_inexecution.peek()->get_Mission()->get_CompletionDay() != current_day)
			return;

		temp_rover = rovers_inexecution.extract_max();	//extracting the mission
		temp_mission = temp_rover->get_Mission();		//getting the mission that it is holding

		temp_rover->set_Mission(nullptr);				//setting the current rover mission to nullptr

		
		// lw kda, hazawed el failure hena el awl
		if (If_Failed()) // mission failed
		{
			Failed_Missions++;
			temp_mission->set_FormulationDay(current_day);	// sets new formulation day

			// moves mission to waiting list again
			if (dynamic_cast<Mission_Emergency*>(temp_mission))		// emergency mission
			{
				missions_emergency.insert(temp_mission, ((Mission_Emergency*)temp_mission)->get_priority());
			}
			else if (dynamic_cast<Mission_Polar*>(temp_mission))	// polar mission
			{
				missions_polar.enqueue(temp_mission);
			}

			temp_rover->set_Num_Till_Checkup(0);	// rover needs checkup


		}
		else // mission succeeded
		{
			missions_completed.enqueue(temp_mission);	//sending the finished mission to the completed list

		}


		// moves rover to checkup if needed
		if (temp_rover->ReachCheckup())			//checking if the rover reached its checkup time
		{
			// to get the endDay of checkup, you must add the checkup duration(constant for all
			// rovers of the same type) plus the current day
			temp_rover->set_Checkup_endDay(temp_rover->get_Checkup_Dur() + current_day); 

			if (dynamic_cast<Rover_Emergency*>(temp_rover))
				rovers_emergency_checkup.enqueue(temp_rover);

			else if (dynamic_cast<Rover_Polar*>(temp_rover)) // checking again only to make sure it isn't nullptr
				rovers_polar_checkup.enqueue(temp_rover);

		}
		else // doesn't require checkup, so we return it to available list
		{
			if (dynamic_cast<Rover_Emergency*>(temp_rover))
				rovers_emergency.insert(temp_rover, ((Rover_Emergency*)temp_rover)->get_Speed());

			else if (dynamic_cast<Rover_Polar*>(temp_rover)) // checking again only to make sure it isn't nullptr
				rovers_polar.insert(temp_rover, ((Rover_Polar*)temp_rover)->get_Speed());
		}

	}
}

// moves rovers from checkup to available
void MarsStation::check_inCheckup()
{
	Rover* temp_rover;
	while (rovers_emergency_checkup.peek(temp_rover)) //peek also checks if it is empty or not
	{
		// checking if it is not the first rover's day
		// as all emergency rovers have the same duration
		// if it is not the day of the first, therefore it is not the day of the second either
		if (temp_rover->get_Checkup_endDay() != current_day)
			return;

		rovers_emergency_checkup.dequeue(temp_rover);
		temp_rover->set_Checkup_endDay(-1);

		rovers_emergency.insert(temp_rover, ((Rover_Emergency*)temp_rover)->get_Speed());
		// return it to available list

	}

	while (rovers_polar_checkup.peek(temp_rover)) //peek also checks if it is empty or not
	{
		// checking if it is not the first rover's day
		// as all polar rovers have the same duration
		// if it is not the day of the first, therefore it is not the day of the second either
		if (temp_rover->get_Checkup_endDay() != current_day)
			return;

		rovers_polar_checkup.dequeue(temp_rover);
		temp_rover->set_Checkup_endDay(-1);

		rovers_polar.insert(temp_rover, ((Rover_Polar*)temp_rover)->get_Speed());
		// return it to available list

	}
}

// assigns missions and moves rovers from available to in execution
void MarsStation::Assign_Emergency_Mission()
{
	Mission* mission;
	Rover* rover;
	while (!(missions_emergency.isEmpty())) // there are missions in the PriQ
	{
		if (!(rovers_emergency.isEmpty()))  // there are available E rovers
		{
			mission = missions_emergency.extract_max(); // returns the mission of highest priority
			rover = rovers_emergency.extract_max();		// returns the fastest E rover
			rover->set_Mission(mission);				// assigns mission to E rover

			mission->set_WaitingDays(current_day);		// sets mission waiting days
			mission->set_ExDays(((Rover_Emergency*)rover)->get_Speed()); // sets mission execution day
			mission->set_CompletionDay();				// sets mission completion day

			rovers_inexecution.insert(rover, (mission->get_CompletionDay()) * -1);
			// moves rover from available to inexecution list
			// the -ve sign is added to be sorted ascendingly according to completion day

			rover->set_Num_Mission(rover->get_Num_Missions() + 1);			// increases number of missions
																			// done by rover
			rover->set_Num_Till_Checkup(rover->get_Num_Till_Checkup() - 1); // reduces number of missions left
																			// till required checkup

		}
		else if (!(rovers_polar.isEmpty())) // there are avaible P rovers
		{
			mission = missions_emergency.extract_max(); // returns the mission of highest priority
			rover = rovers_polar.extract_max();			// returns fastest P rover
			rover->set_Mission(mission);				// assigns mission to P rover

			// setting dates of mission
			mission->set_WaitingDays(current_day);
			mission->set_ExDays(((Rover_Polar*)rover)->get_Speed());
			mission->set_CompletionDay();

			rovers_inexecution.insert(rover, (mission->get_CompletionDay()) * -1);
			// moves rover from available to inexecution list
			// the -ve sign is added to be sorted ascendingly according to completion day

			rover->set_Num_Mission(rover->get_Num_Missions() + 1);			// increases number of missions
																			// done by rover
			rover->set_Num_Till_Checkup(rover->get_Num_Till_Checkup() - 1); // reduces number of missions left
																			// till required checkup
		}
		else  // no available rovers
		{
			return;
		}
	}

}

void MarsStation::Assign_Polar_Mission()
{
	Mission* mission;
	Rover* rover;
	while (missions_polar.peek(mission)) // there are missions in the Queue
	{
		if (!(rovers_polar.isEmpty()))    // there are avaibale P rovers
		{
			missions_polar.dequeue(mission);	// returns mission to be assigned
			rover = rovers_polar.extract_max(); // returns fastest P rover
			rover->set_Mission(mission);		// assigns mission to rover

			// setting dates of missions
			mission->set_WaitingDays(current_day);
			mission->set_ExDays(((Rover_Polar*)rover)->get_Speed());
			mission->set_CompletionDay();

			rovers_inexecution.insert(rover, (mission->get_CompletionDay()) * -1);
			// moves rover from available to inexecution list
			// the -ve sign is added to be sorted ascendingly according to completion day

			rover->set_Num_Mission(rover->get_Num_Missions() + 1);			// increases number of missions
																			// done by rover
			rover->set_Num_Till_Checkup(rover->get_Num_Till_Checkup() - 1); // reduces number of missions left
																			// till required checkup
		}
		else  // no available rovers
		{
			return;
		}
	}
}

/* String-generating functions */
string  MarsStation::generateString_missionP(PriQ<Mission*> x) {
	string output = "";
	PriQ<Mission*> temp = x;
	output += "[";
	int size = temp.getSize();
	if (size == 0) return "";
	for (int i = 0;i < size;i++) {
		Mission* curr = temp.extract_max();
		output += to_string(curr->get_id());
		if (i == size - 1) continue;
		output += ",";
	}
	output += "]";
	return output;
}

string  MarsStation::generateString_missionQ(Queue<Mission*> x) {
	string output1 = "";
	string output2 = "";
	Queue<Mission*> temp = x;
	output1 += "[";
	output2 += "(";
	int size = temp.getSize();
	if (size == 0) return "";
	for (int i = 0;i < size;i++) {
		Mission* curr;
		temp.dequeue(curr);
		if (dynamic_cast<Mission_Emergency*>(curr)) {
			output1 += to_string(curr->get_id())+",";
		}
		else if (dynamic_cast<Mission_Polar*>(curr)) {
			output2 += to_string(curr->get_id())+ ",";
		}
	}
	if (output1 == "[") output1 = "";
	if (output2 == "(") output2 = "";
	if (output1 != "") output1.pop_back(), output1 += "]";
	if (output2 != "") output2.pop_back(), output2 += ")";
	return output1 + " " + output2;
}


string  MarsStation::generateString_roverQ(Queue<Rover*> x) {
	string output1 = "";
	string output2 = "";
	Queue<Rover*> temp = x;
	output1 += "[";
	output2 += "(";
	int size = temp.getSize();
	for (int i = 0;i < size;i++) {
		Rover* curr;
		temp.dequeue(curr);
		if (dynamic_cast<Rover_Emergency*>(curr)) {
			output1 += to_string(curr->get_ID()) + ",";
		}
		else if (dynamic_cast<Rover_Polar*>(curr)) {
			output2 += to_string(curr->get_ID()) + ",";
		}
	}
	if (output1 == "[") output1 = "";
	if (output2 == "(") output2 = "";
	if (output1 != "") output1.pop_back(), output1 += "]";
	if (output2 != "") output2.pop_back(), output2 += ")";
	return output1 + " " + output2;
}

string  MarsStation::generateString_rover_inExc(PriQ<Rover*> x) {
	string output1 = "";
	string output2 = "";
	PriQ<Rover*> temp = x;
	output1 += "[";
	output2 += "(";
	int size = temp.getSize();
	if (size == 0) return "";
	for (int i = 0;i < size;i++) {
		Rover* curr;
		curr = temp.extract_max();
		if (dynamic_cast<Rover_Emergency*>(curr)) {
			Mission* hold;
			hold = curr->get_Mission();
			output1 += to_string(hold->get_id()) + "/";
			output1 += to_string(curr->get_ID()) + ", ";
		}
		else if (dynamic_cast<Rover_Polar*>(curr)) {
			Mission* hold;
			hold = curr->get_Mission();
			output2 += to_string(hold->get_id()) + "/";
			output2 += to_string(curr->get_ID()) + ", ";
		}
	}
	if (output1 == "[") output1 = "";
	if (output2 == "(") output2 = "";
	if (output1 != "") output1.pop_back(), output1.pop_back(), output1 += "]";
	if (output2 != "") output2.pop_back(), output2.pop_back(), output2 += ")";
	return output1 + " " + output2;
}

string  MarsStation::generateString_rover_avail(PriQ<Rover*> x) {
	string output1 = "";
	string output2 = "";
	PriQ<Rover*> temp = x;
	output1 += "[";
	output2 += "(";
	int size = temp.getSize();
	if (size == 0) return "";
	for (int i = 0;i < size;i++) {
		Rover* curr;
		curr = temp.extract_max();
		if (dynamic_cast<Rover_Emergency*>(curr)) {
			output1 += to_string(curr->get_ID()) + ", ";
		}
		else if (dynamic_cast<Rover_Polar*>(curr)) {
			output2 += to_string(curr->get_ID()) + ", ";
		}
	}
	if (output1 == "[") output1 = "";
	if (output2 == "(") output2 = "";
	if (output1 != "") output1.pop_back(), output1.pop_back(), output1 += "]";
	if (output2 != "") output2.pop_back(), output2.pop_back(), output2 += ")";
	return output1 + " " + output2;
}


void MarsStation::OutputGenerator()
{
	string line1, line2, line3, line4, line5, line6;
	line1 = "Current Day:" + to_string(current_day);
	int wait_mission = missions_emergency.getSize() + missions_polar.getSize();
	int in_exec = rovers_inexecution.getSize();
	int available_rover = rovers_emergency.getSize() + rovers_polar.getSize();
	int in_checkup = rovers_polar_checkup.getSize() + rovers_emergency_checkup.getSize();
	int complete = missions_completed.getSize();

	line2 = to_string(wait_mission) + " Waiting Missions: " + generateString_missionP(missions_emergency) + " " + generateString_missionQ(missions_polar);
	line3 = to_string(in_exec) + " In-Execution Missions/Rovers: " + generateString_rover_inExc(rovers_inexecution);
	line4 = to_string(available_rover) + " Available Rovers: " + generateString_rover_avail(rovers_polar) + " " + generateString_rover_avail(rovers_emergency);
	line5 = to_string(in_checkup) + " In-Checkup Rovers: " + generateString_roverQ(rovers_emergency_checkup) + " " + generateString_roverQ(rovers_polar_checkup);
	line6 = to_string(complete) + " Completed Missions: " + generateString_missionQ(missions_completed);
	UserInterface->Print(line1, line2, line3, line4, line5, line6);
}