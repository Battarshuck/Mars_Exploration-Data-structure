#pragma once
#include "Mission.h"
class Mission_Emergency :
    public Mission
{
private:
    int sig;
    int priority;

    void calculate_priority(); //utility function

public:
    Mission_Emergency(int, int, int, int);
    int get_sig() const;
    int get_proprity() const;
};

