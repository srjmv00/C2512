
#include <iostream>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <cstring>
#include <vector>

#define SHM_KEY 1234

class Surgery {
public:
    std::string SurgeryId;
    int Duration;

    Surgery(std::string SurgeryId, int Duration) : SurgeryId(SurgeryId), Duration(Duration) {}

    std::string getSurgeryId() const { return SurgeryId; }
    int getDuration() const { return Duration; }
};

struct SharedMemory {
    int dur[5];
    int sum;
    bool dataReady;       
    bool serverDone;      
};

void client(int& shmid) { 
    SharedMemory* sharedMem = (SharedMemory*)shmat(shmid, nullptr, 0);

   
    std::vector<Surgery> vec;
    vec.emplace_back("am1", 2);
    vec.emplace_back("am2", 5);
    vec.emplace_back("am3", 6);
    vec.emplace_back("am4", 3);
    vec.emplace_back("am5", 1);

    
    for (int i = 0; i < 5; ++i) {
        sharedMem->dur[i] = vec[i].getDuration();
    }

    std::cout << "Client sent dur: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << sharedMem->dur[i] << " ";
    }
    std::cout << std::endl;

    
    sharedMem->dataReady = true;

    
    while (!sharedMem->serverDone) {
        sleep(1);  
    }

  
    std::cout << "Client received sum from server: " << sharedMem->sum << std::endl;

    shmdt(sharedMem);
}

void server(int& shmid) { 
    SharedMemory* sharedMem = (SharedMemory*)shmat(shmid, nullptr, 0);


    while (!sharedMem->dataReady) {
        sleep(1);  
    }

    
    std::cout << "Server received dur: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << sharedMem->dur[i] << " ";
    }
    std::cout << std::endl;

   
    sharedMem->sum = 0;
    for (int i = 0; i < 5; ++i) {
        sharedMem->sum += sharedMem->dur[i];
    }

    std::cout << "Server calculated sum: " << sharedMem->sum << std::endl;

   
    sharedMem->serverDone = true;

    shmdt(sharedMem);
}

int main() {
 
    int shmid = shmget(SHM_KEY, sizeof(SharedMemory), 0666 | IPC_CREAT);

    if (shmid == -1) {
        std::cerr << "Shared memory allocation failed!" << std::endl;
        return 1;
    }

    {
    pid_t pid = fork();
        if (pid == 0) {
            server(shmid);
            shmctl(shmid, IPC_RMID, nullptr);  
            return 0;
        }
    }

   
    sleep(1);
    {
        int pid = fork();
        if (pid == 0) {
            
            client(shmid);
            return 0;
        }
    }

    
    wait(nullptr);
    wait(nullptr);

    return 0;
}
