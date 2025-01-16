#include<iostream>
#include<vector>
#include<climits>
#include<string>
#include<thread>
#include<algorithm>
#include<unistd.h>
#include<cstring>

using namespace std;

class Surgery {
private:
	string surgeryId;
	int Duration;

public:
	Surgery(string surgeryId, int Duration):surgeryId(surgeryId),Duration(Duration) {}

	int getDuration() {
		return Duration;
	}
};

void findSum(int a[],int& sum, int& size) {
	for(int i = 0; i<size; i++) {
		sum = sum + a[i];
	}
}

void client( vector<Surgery>& vec, int& write_end_fd1, int& read_end_fd2) {
	int size =vec.size();
	write(write_end_fd1, &size, 4);
	
	cout << "array size sent to server : " << size << endl;
	int buffer[size];
	for(int i = 0; i < vec.size(); i++) {
		buffer[i]=(vec[i].getDuration());
	}
	write(write_end_fd1,
	      buffer,
	      sizeof(buffer));

	cout << "client sent the data to server: ";
	for(int i = 0; i<size; i++){
		cout << " "<<buffer[i] << " ";
	}
	cout << endl;

	close(write_end_fd1);
	sleep(3);

	int sum=0;
	read(read_end_fd2,
	     &sum,
	     sizeof(int));

	cout << "total sum received from server : "<< sum << endl;
	close(read_end_fd2);


}

void server(int& read_end_fd1,int& write_end_fd2) {
	sleep(3);

	int size;

	read(read_end_fd1,
	     &size,
	     sizeof(size));

	cout << "received size from client : "<< size << endl;

	int a[size];

	read(read_end_fd1,
	     a,
	     sizeof(int)*size);

	cout << "new array created in server : ";
	for(int i = 0; i<size; i++){
		cout << " "<<a[i] << " ";
	}
	cout <<endl;
	close(read_end_fd1);
	int s= 0;
	findSum(a,s,size);
	write(write_end_fd2,
	      &s,
	      sizeof(s));
	cout << "sum sent to client from server : " <<s<< endl;
	close(write_end_fd2);

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

	int pipe_fd1[2];
	int pipe_fd2[2];
	if(pipe(pipe_fd1)==-1) {
		perror("pipe");
		cout << "pipe not created" << endl;
		return 1;
	}
	if(pipe(pipe_fd2)==-1) {
		perror("pipe");
		cout << "pipe not created" << endl;
		return 1;
	}

	int& read_end_fd1 = pipe_fd1[0];
	int& write_end_fd1 = pipe_fd1[1];
	int& write_end_fd2 = pipe_fd2[1];
	int& read_end_fd2 = pipe_fd2[0];



	pid_t pid = -1;

	{
		pid = fork();
		if(0==pid) {
			close(read_end_fd1);
			client(vec,write_end_fd1,read_end_fd2);
			return 0;
		}
	}

	{
		pid = fork();
		if(0==pid) {
			close(write_end_fd1);
			server(read_end_fd1,write_end_fd2);
			return 0;
		}
	}


	sleep(3);

	return 0;


}
