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
    cout << "Customer ID      : " << customerId << endl
         << "Name             : " << name << endl
         << "Contact No.      : " << contact << endl;

    cout << "Check-in Date    : ";
    for (int i = 0; i < 3; i++)
    {
        cout << checkInDate[i] << "/";
    }
    cout << endl;

    cout << "Check-out Date    : ";
    for (int i = 0; i < 3; i++)
    {
        cout << checkOutDate[i] << "/";
    }
    cout << endl;
}

void Customer::checkIn(Reservation reserve[], int count)
{
    fstream file;
    file.open("Customer/customer.txt", ios::app);

    file << customerId << " " << name << " " << contact << " ";
    for (int i = 0; i < 3; i++)
    {
        file << checkInDate[i] << " ";
    }
    for (int i = 0; i < 3; i++)
    {
        file << checkOutDate[i] << " ";
    }
    file << endl;
    file.close();

    fstream outfile;
    outfile.open("Reservation/reservation.txt", ios::out);

    for (int i = 0; i < count; i++)
    {
        if (customerId != reserve[i].getCustomerId())
        {
            outfile << reserve[i].getReservationId() << " "
                    << reserve[i].getCustomerId() << " "
                    << reserve[i].getRoomNumber() << " "
                    << reserve[i].getReservationDate(0) << " "
                    << reserve[i].getReservationDate(1) << " "
                    << reserve[i].getReservationDate(2) << endl;
        }
    }

    outfile.close();
}

void Customer::checkOut(Customer cust[], int custId, int count)
{
    fstream file;
    file.open("Customer/customer.txt", ios::out);
    for (int i = 0; i < count; i++)
    {
        if (cust[i].getCustomerId() != custId)
        {
            file << cust[i].getCustomerId() << " " << cust[i].getName() << " " << cust[i].getContact() << " ";
            for (int j = 0; j < 3; j++)
            {
                file << cust[i].getCheckInDate(j) << " "
                     << cust[i].getCheckOutDate(j) << " ";
            }
            file << endl;
        }
    }
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
    cout << "Reservation ID   : " << reservationId << endl
         << "Customer ID      : " << customerId << endl
         << "Room Number      : " << roomNumber << endl;

    cout << "Reservation Date : ";
    for (int i = 0; i < 3; i++)
    {
        cout << reservationDate[i] << "/";
    }
    cout << endl;
};

void Reservation::createReservation(Room room[], int roomIndex)
{
    fstream outfile;
    outfile.open("Reservation/reservation.txt", ios::app);
    outfile << reservationId << " " << customerId << " " << roomNumber << " ";
    for (int i = 0; i < 3; i++)
    {
        outfile << reservationDate[i] << " ";
    }
    outfile << endl;

    readRoom(room);
    room[roomIndex].setAvailability(0);

    fstream file;
    file.open("Room/room.txt", ios::out);
    for (int i = 0; i < 15; i++)
    {
        file << room[i].getRoomNumber() << " " << room[i].getType() << " " << room[i].getRoomRate() << " " << room[i].getAvailability() << endl;
    }

    file.close();
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
    cout << endl
         << "| Billing Details" << endl
         << "Customer ID    : " << customerId << endl
         << "Room Number    : " << roomNumber << endl
         << "Total Amount   :  RM " << totalAmount << endl;

    cout << "Billing Date    : ";
    for (int i = 0; i < 3; i++)
    {
        if (i < 2)
            cout << billingDate[i] << "/";
        else
            cout << billingDate[i];
    }
    cout << endl;

    fstream file;
    file.open("Bill/bill.txt", ios::out);
    file << "*********************************" << endl
         << "|        UTM HOTEL BILL         |" << endl
         << "*********************************" << endl
         << " Welcome to UTM Hotel!" << endl
         << endl
         << " Customer ID  : " << customerId << endl
         << " Room Number  : " << roomNumber << endl
         << " Total Amount : RM " << totalAmount << endl
         << endl
         << "*********************************" << endl
         << "|        UTM HOTEL BILL         |" << endl
         << "*********************************" << endl
         << endl;

    file.close();
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
    cout << "Room Number    : " << roomNumber << endl
         << "Room Type      : " << type << endl
         << "Availability   : " << isAvailable << endl;
    cout << endl;
}