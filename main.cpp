#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Bus{

private:
    string seats[11] = {"x", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};
public:
    void showReservation(){
        cout << seats[0] << "             " << endl;
        cout << seats[1] << "     " << seats[2] << endl;
        cout << seats[3] << "     " << seats[4] << endl;
        cout << seats[5] << "     " << seats[6] << endl;
        cout << seats[7] << "     " << seats[8] << endl;
        cout << seats[9] << "     " << seats[10] << endl;
    }
    void read(){
        ifstream in ("BUS\reservation.txt");
        in.read((char*)&seats,sizeof(seats));
        showReservation();
        in.close();

    }
    void reserve(){
        read();
        int n;
        cout << "Choose unreserved seat, please" << endl;
        cin >> n;
        if(n<=0){
            cout << "Error!" << endl;
          cout << "Choose unreserved seat, please" << endl;
            cin >> n;
        }
        while(seats[n] == "x"){
            cout << "This place has been already reserved" << endl;
          cout << "Choose unreserved seat, please" << endl;
            cin >> n;
        }
        if(n>0) seats[n] = "x";
        cout << "Congratulation! Your place has been reserved!" << endl;

    }
    void write(){
        system("cls");
        ofstream out("BUS\reservation.txt", ios::app|ios::binary);
        reserve();
        out.write((char*)&seats, sizeof(string));
        out.close();

    }



} bus;

int main()
{   cout << "Welcome to Bus Seat Reservation System" << endl;
    int ac;

    while(ac!=3){
        cout << endl;
        cout << "Choose the action" << endl;
        cout << "1. Reserve seat" << endl;
        cout << "2. Show the reserved seats" << endl;
        cout << "3. Exit" << endl;
        cout << endl;
        cin >> ac;
        cout << endl;

        switch (ac) {
        case 1 : bus.write();
            break;
        case 2 : bus.showReservation();
            break;
        }

    }


    return 0;
}
