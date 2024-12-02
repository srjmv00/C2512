#pragma once

#include <string>
using std::string;

class Surgery
{
	private:
		string SurgeryID;
		int Duration;
		
		//behaviour
	public:
		bool Equals(const Surgery& other);
		bool NotEquals(const Surgery& other);
		bool GreaterThan(const Surgery& other);
		bool GreaterThanEquals(const Surgery& other);
		bool LessThan(const Surgery& other);
		bool LessThanEquals(const Surgery& other);

		// constructor
		Surgery(string p_SurgeryID, int p_Duration);
};
