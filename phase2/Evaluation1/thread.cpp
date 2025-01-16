#include<iostream>
#include<vector>
#include<climits>
#include<string>
#include<thread>
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

void findSum(vector<Surgery>& vec,int& sum) {
	for(int i = 0; i<5; i++) {
		sum = sum + vec[i].getDuration();
	}
}

void findMin(vector<Surgery>& vec,int& min) {
	int fh = vec.size()/2;
	for(int i=0; i<fh; i++) {
		int a = vec[i].getDuration();
		if(a < min) {
			min = a;
		}
	}
}

void findMax(vector<Surgery>& vec,int& max) {
	int fh = vec.size()/2;
	int lh = 5 - fh;
	for(int i=fh; i<lh; i++) {
		int a = vec[i].getDuration();
		if(a > max) {
			max = a;
		}
	}
}

int main() {
	vector<Surgery>vec;
	int sum = 0;
	int min = INT_MAX;
	int max = INT_MIN;

	vec.emplace_back("am1",2);
	vec.emplace_back("am2",5);
	vec.emplace_back("am3",6);
	vec.emplace_back("am4",3);
	vec.emplace_back("am5",1);


	// int sum = findSum(vec);
	// int min = findMin(vec);
	// int max = findMax(vec);

	thread thrSum(findSum,ref(vec),ref(sum));
	thread thrMin(findMin,ref(vec),ref(min));
	thread thrMax(findMax,ref(vec),ref(max));

	thrSum.join();
	thrMin.join();
	thrMax.join();

	cout << "sum :" << sum <<  endl;
	cout <<"min :" << min <<  endl;
	cout << "max :" << max <<  endl;

	return 0;


}
