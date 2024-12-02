

#include <string>
using std::string;

class Surgery
{
	private:
		string SurgeryID;
		int Duration;
		
		//behaviour
	public:
		friend bool Equals(const Surgery& first, const Surgery& second);
		friend bool NotEquals(const Surgery& first, const Surgery& second);
		friend bool GreaterThan(const Surgery& first, const Surgery& second);
		friend bool GreaterThanEquals(const Surgery& first, const Surgery& second);
		friend bool LessThan(const Surgery& first, const Surgery& second);
		friend bool LessThanEquals(const Surgery& first, const Surgery& second);

		// constructor
		Surgery(string p_SurgeryID, int p_Duration);
};

	bool Equals(const Surgery& first, const Surgery& second);
        bool NotEquals(const Surgery& first, const Surgery& second);
        bool GreaterThan(const Surgery& first, const Surgery& second);
        bool GreaterThanEquals(const Surgery& first, const Surgery& second);
        bool LessThan(const Surgery& first, const Surgery& second);
        bool LessThanEquals(const Surgery& first, const Surgery& second);

