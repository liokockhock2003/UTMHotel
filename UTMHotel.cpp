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
#include "UTMHotelFunction.hpp"
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

void Customer::checkIn(Reservation reserve[], int count)
{
   
}

void Customer::checkOut(Customer cust[], int custId, int count)
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

void Reservation::createReservation(Room room[], int roomIndex)
{
    
}

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

bool ReservationList::isEmpty(){
    return head == NULL; 
}

Reservation* ReservationList::InsertNode(double x){
    //stop here
}