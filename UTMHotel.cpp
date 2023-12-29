/****************************** UTM HOTEL ******************************\
Project: UTMHotel
Data Structure & Algorithm
Semester 1, 2023/2024

Section: 10
Member 1's Name: AHMAD SAIFUDIN BIN NARDI SUSANTO A22EC0035
Member 2's Name: LIO KOCK HOCK A22EC0185

<Implementation File>
Class definition

See https://github.com/Saifdn/UTMHotel.

\************************************************************************/

#include "UTMHotel.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

/*=========================================================
    Definition class Customer
=========================================================*/
Customer::Customer()
{
}

Customer::Customer(int customerId, string name, string contact, int InDate[], int OutDate[])
{
    this->customerId = customerId;
    this->name = name;
    this->contact = contact;
    for (int i = 0; i < 3; i++)
    {
        checkInDate[i] = InDate[i];
        checkOutDate[i] = OutDate[i];
    }
}

Customer::~Customer()
{
}

int Customer::getCustomerId() { return customerId; }

string Customer::getName() { return name; }

string Customer::getContact() { return contact; }

int Customer::getCheckInDate(int i) { return checkInDate[i]; }

int Customer::getCheckOutDate(int i) { return checkOutDate[i]; }

void Customer::displayCustomerDetails()
{
    
}

/*=========================================================
    Definition class Reservation
=========================================================*/
Reservation::Reservation()
{
}

Reservation::Reservation(int reservationId, int customerId, int roomNumber, int Date[])
{
    this->reservationId = reservationId;
    this->customerId = customerId;
    this->roomNumber = roomNumber;
    for (int i = 0; i < 3; i++)
    {
        reservationDate[i] = Date[i];
    }
}

Reservation::~Reservation()
{
}

int Reservation::getReservationId() { return reservationId; }

int Reservation::getCustomerId() { return customerId; }

int Reservation::getRoomNumber() { return roomNumber; }

int Reservation::getReservationDate(int i) { return reservationDate[i]; }

void Reservation::displayReservationDetails()
{
    
};

/*=========================================================
    Definition class Billing
=========================================================*/
Billing::Billing() {}

Billing::Billing(int customerId, int roomNumber, float totalAmount, int Date[])
{
    this->customerId = customerId;
    this->roomNumber = roomNumber;
    this->totalAmount = totalAmount;
    for (int i = 0; i < 3; i++)
    {
        billingDate[i] = Date[i];
    }
}

Billing::~Billing()
{
}

int Billing::getCustomerId() { return customerId; }

int Billing::getroomNumber() { return roomNumber; }

float Billing::getTotalAmount() { return totalAmount; }

int Billing::getbillingDate(int i) { return billingDate[i]; }

void Billing::displayBillingDetails()
{
    
}

/*=========================================================
    Definition class Room
=========================================================*/
Room::Room() {}

Room::Room(int roomNumber, string type, float roomRate, bool isAvailable)
{
    this->roomNumber = roomNumber;
    this->type = type;
    this->roomRate = roomRate;
    this->isAvailable = isAvailable;
}

int Room::getRoomNumber() { return roomNumber; }

string Room::getType() { return type; }

float Room::getRoomRate() { return roomRate; }

void Room::setAvailability(bool availability) { isAvailable = availability; }

bool Room::getAvailability() { return isAvailable; }

void Room::displayRoomDetails()
{
   
}


/*=========================================================
    Definition class ReservationList
=========================================================*/
ReservationList::ReservationList(void){
    head = NULL;
}

bool ReservationList::IsEmpty(){
    return head == NULL; 
}

Reservation* ReservationList::InsertReservation(int custId, int reservationId, int roomNum, int reservationDate[]){
    int currIndex = 0;
    Reservation* currNode = head;
    Reservation* prevNode = NULL;

    while(currNode && reservationId > currNode->getReservationId()){
        prevNode = currNode;
        currNode = currNode->next;
        currIndex++;
    }

    Reservation* newNode = new Reservation(custId, reservationId, roomNum, reservationDate);

    if(currIndex ==0){
        newNode->next = head;
        head = newNode;
    }
    else{
        newNode->next = prevNode->next;
        prevNode->next = newNode;
    }
    return newNode;
};

int ReservationList::askReservation(int reservationDate[]){
    int roomNum, date;

    cout<<"Enter Room Number that you desire: ";
    cin>>roomNum;

    cout<<"Enter Day     : ";
    cin>>date;
    reservationDate[0] = date;
    cout<<"Enter Month   : ";
    cin>>date;
    reservationDate[1] = date;
    cout<<"Enter Year    : ";
    cin>>date;
    reservationDate[2] = date;
    
    return roomNum; 
}

void ReservationList::DisplayReservationList(){
    Reservation* currNode = head;
    
    while(currNode != NULL){
        cout << left
            << setw(4) << currNode->getCustomerId()
            << setw(4) << currNode->getReservationId()
            << setw(6) << currNode->getRoomNumber() <<endl;
        currNode = currNode->next;
    }
}

int ReservationList::DeleteNode(int custId){
    Reservation* prevNode = NULL;
    Reservation* currNode = head;
    int currIndex = 1;
    while(currNode && custId != currNode->getCustomerId()) {
        prevNode = currNode;
        currNode = currNode->next;
        currIndex++;
    }
    if(currNode){
        if(prevNode){
            prevNode->next = currNode->next;
            delete currNode;
        }
        else{
            head = currNode->next;
            delete currNode;
        }
        return currIndex;
    }
    return 0;
}

/*=========================================================
    Definition class RoomList
=========================================================*/

Room* RoomList::InsertRoom(Room* x){

    int currIndex = 0;
    Room* currNode = head;
    Room* prevNode = NULL;

    while(currNode && x->getRoomNumber() > currNode->getRoomNumber()){
        prevNode = currNode;
        currNode = currNode->next;
        currIndex++;
    }

    Room* newNode = new Room;
    newNode = x;

    if(currIndex ==0){
        newNode->next = head;
        head = newNode;
    }
    else{
        newNode->next = prevNode->next;
        prevNode->next = newNode;
    }
    return newNode;
}

void RoomList::ReadList(){

    fstream file;
    file.open("Room/room.txt", ios::in);

    int roomNumber;
    string type;
    float price;
    int availability;
    int count = 0;

    while (file >> roomNumber >> type >> price >> availability && count < 15)
    {
        Room* temp = new Room(roomNumber, type, price, availability);
        InsertRoom(temp);
        count++;
    }

    file.close();

}

void RoomList::DisplayRoomList(int roomNum[]){

    int count = 0;
    Room* currNode = head;
    
    while(currNode != NULL){
        if(roomNum[count] != currNode->getRoomNumber()){
            cout << left
            << setw(4) << currNode->getRoomNumber()
            << setw(8) << currNode->getType()
            << setw(3) << "RM "
            << setw(4) << currNode->getRoomRate() << " per night" << endl;
            count++;
        }
        currNode = currNode->next;
        
    }

}

/*=========================================================
    Definition class RoomList
=========================================================*/
CustomerList::CustomerList(void){
    head = NULL;
}

Customer* CustomerList::InsertCustomer(int custId, string name, string contact, int inDate[], int outDate[]){
    
    int currIndex = 0;
    Customer* currNode = head;
    Customer* prevNode = NULL;

    while(currNode && custId > currNode->getCustomerId()){
        prevNode = currNode;
        currNode = currNode->next;
        currIndex++;
    }

    Customer* newNode = new Customer(custId, name, contact, inDate, outDate);

    if(currIndex ==0){
        newNode->next = head;
        head = newNode;
    }
    else{
        newNode->next = prevNode->next;
        prevNode->next = newNode;
    }
    return newNode;
}

int CustomerList::askCustomer(int inDate[], int outDate[], string& custName, string& custContact){
    int custID, date;

    cout<<"Enter your Customer ID: "<<endl;
    cin>>custID;

    cout<<"Enter your Name:"<<endl;
    cin>>custName;

    cout<<"Enter your Phone Number:"<<endl;
    cin>>custContact;


    cout<<"Check-In Date!"<<endl;
    cout<<"Enter Day     : ";
    cin>>date;
    inDate[0] = date;
    cout<<"Enter Month   : ";
    cin>>date;
    inDate[1] = date;
    cout<<"Enter Year    : ";
    cin>>date;
    inDate[2] = date;

    cout<<"Check-Ou Date!"<<endl;
    cout<<"Enter Day     : ";
    cin>>date;
    outDate[0] = date;
    cout<<"Enter Month   : ";
    cin>>date;
    outDate[1] = date;
    cout<<"Enter Year    : ";
    cin>>date;
    outDate[2] = date;
    
    return custID; 
}

void CustomerList::DisplayCustomerList(){
    Customer* currNode = head;
    
    while(currNode != NULL){
            cout << left
            << setw(4) << currNode->getCustomerId()
            << setw(8) << currNode->getName()
            << setw(8) << currNode->getContact()<<endl;
        currNode = currNode->next;
        
    }
}