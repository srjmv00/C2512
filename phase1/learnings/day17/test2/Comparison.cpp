#include<string>

#include "Surgery.h"
using std::string;

// constructor
	Surgery::Surgery(string p_SurgeryID, int p_Duration)
	{
		SurgeryID = p_SurgeryID;
		Duration = p_Duration;
	}
