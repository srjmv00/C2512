#include<iostream>
#include<vector>
#include<climits>
#include<string>
#include<algorithm>

using namespace std;

class Surgery {
private:
	string surgeryId;
	int Duration;

public:
	Surgery(string surgeryId, int Duration):surgeryId(surgeryId),Duration(Duration) {}

	int getDuration() {
		return this->Duration;
	}
};

int findSum(vector<Surgery>& vec) {
	int sum = 0;
	for(int i = 0; i<5; i++) {
		sum = sum + vec[i].getDuration();
	}
	return sum;
}

int findMin(vector<Surgery>& vec) {
	int min =INT_MAX;
	int fh = vec.size()/2;
	for(int i=0; i<fh; i++) {
		int a = vec[i].getDuration();
		if(a < min) {
			min = a;
		}
	}
	return min;
}

int findMax(vector<Surgery>& vec) {
	int max =INT_MIN;
	int fh = vec.size()/2;
	int lh = 5 -fh;
	for(int i=0; i<lh; i++) {
		int a = vec[i].getDuration();
		if(a > max) {
			max = a;
		}
	}
	return max;
}

int main() {
	vector<Surgery>vec;

	vec.emplace_back("am1",2);
	vec.emplace_back("am2",5);
	vec.emplace_back("am3",6);
	vec.emplace_back("am4",3);
	vec.emplace_back("am5",1);


	int sum = findSum(vec);
	int min = findMin(vec);
	int max = findMax(vec);

	cout << "sum" << sum <<  endl;
	cout <<"min" << min <<  endl;
	cout << "max" << max <<  endl;

	return 0;


}
