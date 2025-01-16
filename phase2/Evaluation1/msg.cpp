
#include<iostream>
#include<vector>
#include<climits>
#include<string>
#include<thread>
#include<algorithm>
#include<unistd.h>
#include<cstring>
#include<sys/msg.h>
#include<sys/wait.h>
#define MSG_KEY 1234


using namespace std;

class Surgery {
private:
    string surgeryId;
    int Duration;

public:
    Surgery(string surgeryId, int Duration) : surgeryId(surgeryId), Duration(Duration) {}

    int getDuration() {
        return this->Duration;
    }
};

// Define the message buffer structure
struct msg_buffer {
    long msg_type;
    int size;
    int data[1000];
    int sum;
};

void findSum(int a[], int& sum, int& size ) {
    for (int i = 0; i < size; i++) {
        sum += a[i];
    }
}

void client(vector<Surgery>& vec, int msgid) {
    msg_buffer message;


    message.msg_type = 1;
    message.size = vec.size();
    msgsnd(msgid, &message, sizeof(message),0);
    cout << "client send size : "<< message.size <<endl;



    message.msg_type = 2;
    for (int i = 0; i < message.size; i++) {
        message.data[i] = vec[i].getDuration();
    }
    msgsnd(msgid, &message, sizeof(message.data), 0);
    cout << "Client Sent durations : ";
    for(int i = 0; i<message.size; i++){
		cout << " "<<message.data[i] << " ";
	}
	cout << endl;


    msgrcv(msgid, &message, sizeof(message), 3, 0);
     int sum = message.sum;

    cout << "Total sum in client side sent from server : " << sum << endl;
}

void server(int msgid) {

    msg_buffer message;

    msgrcv(msgid, &message,sizeof(message),1,0);
    cout << "server received size : "<< message.size <<endl;


    msgrcv(msgid, &message, sizeof(message.data), 2, 0);
	cout << "new array created in server : ";
    for(int i = 0; i<message.size; i++){
		cout << " "<<message.data[i] << " ";
	}
    cout <<endl;
    int sum = 0;
    findSum(message.data, sum, message.size);

    message.msg_type = 3;
    message.sum = sum;
    msgsnd(msgid, &message, sizeof(message), 0);
    cout << "Sum sent to client : " << message.sum << endl;
}

int main() {
    vector<Surgery> vec;
    vec.emplace_back("am1", 2);
    vec.emplace_back("am2", 5);
    vec.emplace_back("am3", 6);
    vec.emplace_back("am4", 3);
    vec.emplace_back("am5", 1);

    int msgid = msgget(MSG_KEY, 0666 | IPC_CREAT);

    pid_t pid = -1;
    {
        pid = fork();
        if (pid == 0) {
        client(vec, msgid);
        return 0;
        }
    }
    {
        pid = fork();
        if (pid == 0) {
        server(msgid);
        return 0;
        }
    }

    wait(nullptr);

    msgctl(msgid, IPC_RMID, nullptr);

    return 0;
}
