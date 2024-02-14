#include <iostream>
using namespace std;
class Parking_Spot {
public:
    int Time, Price,Token;
    string status;
    Parking_Spot() :status("___"){}
};
class Queue {
public:
    Queue* next;
};
int No_ofVehicle=0;
Queue* head = NULL;
Parking_Spot P_Arr[5][10],P_obj;
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
void Park() {
    cout << "Enter for how many hours:  ";
    cin >> P_obj.Time;
    int row, clmn;
    if (P_obj.Time >= 3) {
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
    P_Arr[row][clmn].Time = P_obj.Time;
    P_Arr[row][clmn].Price = P_obj.Time * 150;
    P_Arr[row][clmn].Token = row * 10 + clmn;
    cout << "Your Token is: " << P_Arr[row][clmn].Token << endl;
}
void Depart() {
    int token, row, clmn;
    cout << "Enter Your Token number: ";
    cin >> token;
    row = token / 10;
    clmn = token % 10;
    cout << "Your Total Price is:" << P_Arr[row][clmn].Price << endl;
    P_Arr[row][clmn].status = "___";
}
void Enqueue(){
    cout << "Enqueud Sucessfully!!!" << endl;
    No_ofVehicle++;
    cout<<"There are "<< No_ofVehicle<<" Vehicles in Queue"<<endl;
    Queue *New_node = new Queue;
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
            delete temp1;
        }
        else {
            while (temp2->next != NULL) {
                temp1 = temp2;
                temp2 = temp1->next;
            }
            temp1->next = NULL;
            delete temp2;
        }
        Park();
    }
    No_ofVehicle--;
}
int main()
{
    int option;
    cout << "\t\t\t\tWELCOME TO PARKING MANAGEMENT CONSOLE!!!!!!!" << endl<<endl;
    do {
        cout << "Press 1 To Enque,2 To Dequeue,3 To Depart,0 To Exit Console: ";
        cin >> option;
        switch (option) {
        case 1:
            Enqueue();
            break;
        case 2:
            Dequeue();
            Display_Parkingspot();
            break;
        case 3:
            Depart();
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
                
