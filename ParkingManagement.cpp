#include <iostream>
using namespace std;
class Parking_Spot {
public:
    int Time, Price,Token;
    string status,Name;
    Parking_Spot() :status("___"){}
};
class Queue {
public:
    int Time;
    string Name;
    Queue* next;
};
int No_ofVehicle=0;
Queue* head = NULL;
Parking_Spot P_Arr[5][10];
void Display_Parkingspot() {
    for (int i = 1; i <= 42; i++) { cout << "-"; }
    cout << endl << " ";
    for (int i = 0; i < 10; i++) {
        cout << "  " << i << " ";
    }
    cout << endl;
    for (int i = 0; i < 5; i++) {
        cout << i << " ";
        for (int j = 0; j < 10; j++) {
            cout << P_Arr[i][j].status << " ";
        }
        cout << endl << endl;
    }
    for (int i = 1; i <= 42; i++) { cout << "-"; }
    cout << endl << endl;
}
void Park(int Time,string Name) {
    int row, clmn;
    if (Time >= 3) {
        for (int i = 9; i >= 0; i--) {
            for (int j = 0; j < 5; j++) {
                if (P_Arr[j][i].status == "___") {
                    row = j;
                    clmn = i;
                    break;
                }
            }
            if (P_Arr[row][i].status == "___")
                break;
        }
    }
    else {
        for (int i = 5; i >= 0; i--) {
            for (int j = 0; j < 5; j++) {
                if (P_Arr[j][i].status == "___") {
                    row = j;
                    clmn = i;
                    break;
                }
            }
            if (P_Arr[row][i].status == "___")
                break;
        }
    }
    P_Arr[row][clmn].status = "|-|";
    P_Arr[row][clmn].Name = Name;
    P_Arr[row][clmn].Time = Time;
    if (Time == 1)
        P_Arr[row][clmn].Price = 120;
    else
        P_Arr[row][clmn].Price = 120 + (Time - 1) * 90;
    P_Arr[row][clmn].Token = row * 10 + clmn;
    cout <<Name<<", Your Token is: " << P_Arr[row][clmn].Token << endl;
}
void Depart() {
    int token, row, clmn;
    cout << "Enter Your Token number: ";
    cin >> token;
    row = token / 10;
    clmn = token % 10;
    cout << "Thanks For Using Our Service " << P_Arr[row][clmn].Name << endl;
    cout << "Your Total Price is:" << P_Arr[row][clmn].Price << endl;
    P_Arr[row][clmn].status = "___";
}
void Enqueue(int Time, string Name){
    cout << "Enqueud Sucessfully!!!" << endl;
    No_ofVehicle++;
    cout<<"There are "<< No_ofVehicle<<" Vehicles in Queue"<<endl;
    Queue *New_node = new Queue;
    New_node->Name = Name;
    New_node->Time = Time;
    if (head == NULL) {
        New_node->next = NULL;
        head = New_node;
    }
    else {
        New_node->next = head;
        head = New_node;
    }
}
void Dequeue() {
    Queue* temp1 = head,*temp2;
    if (temp1 == NULL) {
        cout << "No More Vehicle in Queue!!!!" << endl;
    }
    else {
        temp2 = temp1->next;
        if (temp2 == NULL) {
            head = NULL;
            Park(temp1->Time,temp1->Name);
            delete temp1;
        }
        else {
            while (temp2->next != NULL) {
                temp1 = temp2;
                temp2 = temp1->next;
            }
            temp1->next = NULL;
            Park(temp2->Time, temp2->Name);
            delete temp2;
        }
    }
    No_ofVehicle--;
}
int main()
{
    int option,check,Time;
    string Name;
    cout << "\t\t\t\tWELCOME TO PARKING MANAGEMENT CONSOLE!!!!!!!" << endl<<endl;
    cout << "Prices: " << endl;
    cout << "120 rs upto 1 hrs" << endl;
    cout << "90 for every additional hrs" << endl;
    do {
        cout << "Press 1 To Park,2 To Modify Queue,3 To Depart,4 To Display Parking,0 To Exit Console: ";
        cin >> option;
        switch (option) {
        case 1:
            cout << "Enter your Name: ";
            cin >> Name;
            cout << "Enter for how many hours:  ";
            cin >> Time;
            if (head == NULL)
                Park(Time,Name);
            else {
                cout << "Enqueuing in queue!!" << endl;
                Enqueue(Time, Name);
            }
            break;
        case 2:
            cout << "Enqueue(1) or dequeue(2): ";
            cin >> check;
            if (check == 1) {
                cout << "Enter your Name: ";
                cin >> Name;
                cout << "Enter for how many hours:  ";
                cin >> Time;
                Enqueue(Time, Name);
            }
            else
                Dequeue();
            break;
        case 3:
            Depart();
            break;
        case 4:
            Display_Parkingspot();
            break;
        case 0:
            break;
        Default:
            cout << "Invalid input" << endl;
            break;
        }
    } while (option != 0 );
}
                
