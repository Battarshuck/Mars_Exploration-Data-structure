#include "MarsStation.h"

int Rover::ID = 0;

MarsStation::MarsStation()
{
	UserInterface = new UI();
	current_day = 0;
}

void MarsStation::Load()
{	
	UserInterface->Read_File(Event_list, rovers_emergency, rovers_polar); // fills the queue with events
}


UI* MarsStation::get_UI() const
{
	return UserInterface;
}

void MarsStation::simulate()
{
	
	while (current_day != 30)
	{
		if (current_day == 24)
		{
			if (current_day == 24)
			{

			}
		}
		current_day++;
		//1-Events to be formulated [a]
		check_events();
		//2-check if in-execution missions are done, to return rovers (mostafa) [ sh8al 3l execution ]
		// mn in execution le available aw checkup


		//3-Check first for emergency mission then polar to assign them to rover (hashish)
		//4-movement of rovers through lists (hashish)  [ sh8al 3l waiting ] 
		// mn available to in execution
		Assign_Emergency_Mission();
		Assign_Polar_Mission();

		
	
		//5-printing in the UI class (farah) [e,f]

	}
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

void MarsStation::Assign_Emergency_Mission()
{
	Mission* mission;
	Rover* rover;
	while (missions_emergency.getsize() != 0) // there are missions in the PriQ
	{
		if (rovers_emergency.getsize() != 0) // there are available E rovers
		{
			mission = missions_emergency.extract_max(); // returns the mission of highest priority
			rover = rovers_emergency.extract_max();		// returns the fastest E rover
			rover->set_Mission(mission); // assigns mission to E rover

			mission->set_WaitingDays(current_day);		// sets mission waiting days
			mission->set_ExDays(((Rover_Emergency*)rover)->get_Speed()); // sets mission execution day
			mission->set_CompletionDay();				// sets mission completion day

			rovers_inexecution.insert(rover, (mission->get_CompletionDay()) * -1);
			// moves rover from available to inexecution list
			// the -ve sign is added to be sorted ascendingly according to completion day

			rover->set_Num_Mission(rover->get_Num_Missions() + 1);  // increases number of missions
																	// done by rover

		}
		else if (rovers_polar.getsize() != 0) // there are avaible P rovers
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

			rover->set_Num_Mission(rover->get_Num_Missions() + 1);  // increases number of missions
																	// done by rover
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
		if (rovers_polar.getsize() != 0)    // there are avaibale P rovers
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

			rover->set_Num_Mission(rover->get_Num_Missions() + 1);  // increases number of missions
																	// done by rover
		}
		else  // no available rovers
		{
			return;
		}
	}
}