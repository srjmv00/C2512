#include <sys/types.h>
#include <sys/stat.h>
#include <iostream>
#include <fcntl.h>
#include <cstring>
#include <unistd.h>
#include <vector>

using namespace std;

class VaccinationRecord{
	private:
		string vaccinationId;
		int dosesAdministered;
	public:
		VaccinationRecord(string vaccinationId, int dosesAdministered){
			this -> vaccinationId = vaccinationId;
			this -> dosesAdministered = dosesAdministered;
		}

		int getDose(){ return this -> dosesAdministered; };

};

int main(){
	vector<VaccinationRecord> vaccinations;
	vaccinations.emplace_back("ID001", 3);
	vaccinations.emplace_back("ID002", 2);
	vaccinations.emplace_back("ID003", 1);
	vaccinations.emplace_back("ID004", 5);
	vaccinations.emplace_back("ID005", 4);

	int doses[vaccinations.size()] = {0};
	
	for(int i = 0; i < vaccinations.size(); i++){
		doses[i] = vaccinations[i].getDose();
	}

	
	int numOfElements = vaccinations.size();

	const char* pipe1 = "pipe1";
	const char* pipe2 = "pipe2";
	int pipe_two_read_fd, pipe_one_write_fd;
	pipe_one_write_fd = open(pipe1, O_WRONLY);
	pipe_two_read_fd = open(pipe2, O_RDONLY);
        
	if(pipe_one_write_fd == -1){
		perror("pipe1 open failure at client");
		return 1;
	}
	if(pipe_two_read_fd == -1){
		perror("pipe2 open failure at client");
		return 1;
	}

	write(pipe_one_write_fd, &numOfElements, sizeof(int));
	cout << "Client sent number of elements: " << numOfElements << endl ;

	write(pipe_one_write_fd, doses, sizeof(doses));
	cout << "Client sent doses : ";
	for(int dose:doses){
		cout << dose << "\t";
	}
	cout << endl;
	close(pipe_one_write_fd);

	sleep(1);

	int sum;
	read(pipe_two_read_fd, &sum, sizeof(int));
	cout << "sum received from server: " << sum << endl;

	close(pipe_two_read_fd);
	

	return 0;
}
