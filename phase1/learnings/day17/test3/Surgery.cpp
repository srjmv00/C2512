#include<string>

#include "Surgery.h"
using std::string;


	bool Equals(const Surgery& first, const Surgery& second)
	{
		return(first.Duration == second.Duration);
	}
        bool NotEquals(const Surgery& first, const Surgery& second)
	{
		return (first.Duration != second.Duration);
	}
	bool GreaterThan(const Surgery& first, const Surgery& second)
	{
		return (first.Duration > second.Duration);
	}
	bool GreaterThanEquals(const Surgery& first, const Surgery& second)
	{
		return (first.Duration >= second.Duration);
	}
	bool LessThan(const Surgery& first, const Surgery& second)      
	{
		return (first.Duration < second.Duration);
	}
	bool LessThanEquals(const Surgery& first, const Surgery& second)
	{
		return (first.Duration <= second.Duration);
	}
    
