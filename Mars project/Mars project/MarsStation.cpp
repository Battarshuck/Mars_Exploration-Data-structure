#include "MarsStation.h"

int Rover_Polar::ID = 0;
int Rover_Emergency::ID = 0;

MarsStation::MarsStation()
{
	UserInterface = new UI();
	current_day = 0;
}

void MarsStation::Load()
{	
	UserInterface->Read_File(Event_list); // fills the queue with events
}


UI* MarsStation::get_UI() const
{
	return UserInterface;
}

void MarsStation::simulate()
{
	
	while (current_day != 20)
	{
		current_day++;
		//1-Events to be formulated [a]
		check_events();
		//2-check if in-execution missions are done, to return rovers (mostafa) [ sh8al 3l execution ]
		// mn in execution le available aw checkup


		//3-Check first for emergency mission then polar to assign them to rover (hashish)
		

		//4-movement of rovers through lists (hashish)  [ sh8al 3l waiting ] 
		// mn available to in execution
		
	
		//5-printing in the UI class (farah) [e,f]

	}
	// UI.save
}

void MarsStation::check_events()
{
	Event* temp;
	while (true)
	{
		Event_list.peek(temp);
		if (temp->get_ExecuteDay() != current_day)
			return;

		Event_list.dequeue(temp);

		temp->Execute(missions_emergency, missions_polar);
	}
}
