/****************************** UTM HOTEL ******************************\
Project: UTMHotel
Data Structure & Algorithm
Semester 1, 2023/2024

Section: 10
Member 1's Name: AHMAD SAIFUDIN BIN NARDI SUSANTO A22EC0035
Member 2's Name: LIO KOCK HOCK A22EC0185

<Specification File>
Class declaration

See https://github.com/Saifdn/UTMHotel.

\************************************************************************/

#ifndef UTMHOTEL_H
#define UTMHOTEL_H

#include <string>
#include <fstream>

using namespace std;

class Room
{
private:
    int roomNumber;
    string type;
    float roomRate;
    bool isAvailable;

public:
    Room();
    Room(int, string, float, bool);
    int getRoomNumber();
    string getType();
    float getRoomRate();
    void setAvailability(bool);
    bool getAvailability();
    void displayRoomDetails();
};

class Reservation
{
private:
    int reservationId;
    int customerId;
    int roomNumber;
    int reservationDate[3];

public:
    Reservation();
    Reservation(int, int, int, int[]);
    ~Reservation();
    int getReservationId();
    int getCustomerId();
    int getRoomNumber();
    int getReservationDate(int);
    void displayReservationDetails();
    void createReservation(Room room[], int);
};

class Customer
{
private:
    int customerId;
    string name;
    string contact;
    int checkInDate[3];
    int checkOutDate[3];

public:
    Customer();
    Customer(int, string, string, int[], int[]);
    ~Customer();
    int getCustomerId();
    string getName();
    string getContact();
    int getCheckInDate(int);
    int getCheckOutDate(int);
    void displayCustomerDetails();
    void checkIn(Reservation reservation[], int count);
    void checkOut(Customer[], int, int);
};

class Billing
{
private:
    int customerId;
    int roomNumber;
    float totalAmount;
    int billingDate[3];

public:
    Billing();
    Billing(int, int, float, int[]);
    ~Billing();
    int getCustomerId();
    int getroomNumber();
    float getTotalAmount();
    int getbillingDate(int);
    void displayBillingDetails();
};

#endif