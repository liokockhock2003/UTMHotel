/****************************** UTM HOTEL ******************************\
Project: UTMHotel
Data Structure & Algorithm
Semester 1, 2023/2024

Section: 10
Member 1's Name: AHMAD SAIFUDIN BIN NARDI SUSANTO A22EC0035
Member 2's Name: LIO KOCK HOCK A22EC0185

<Application File>
Main program

See https://github.com/Saifdn/UTMHotel.

\************************************************************************/

#include "UTMHotel.hpp"
#include "UTMHotelFunction.hpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{

    Room room[15];
    int choice;

    cout << "+===================+" << endl
         << "      Main Menu" << endl
         << "+===================+" << endl
         << "1. Reservation" << endl
         << "2. Check-In" << endl
         << "3. Check-Out" << endl
         << "Enter choice: ";
    cin >> choice;
    system("CLS");

    if (choice == 1)
    {
        cout << "+===================+" << endl
             << "     Reservation" << endl
             << "+===================+" << endl;

        readRoom(room);

        int sort1;
        cout << "1. Room Number " << endl
             << "2. Price" << endl
             << "Sort by: ";
        cin >> sort1;

        if (sort1 == 1)
            quickSortRoomNumber(room, 15 - 15, 15 - 1);
        else
            bubbleSort(room, 15);

        int numOfRooms = printAvailableRoom(room);

        int roomNum;
        cout << endl
             << "Enter room no. : ";
        cin >> roomNum;

        quickSortRoomNumber(room, 15 - 15, 15 - 1);
        int roomIndex = binarySearch(roomNum, 15, room);

        if (roomIndex >= 0)
        {
            int date[3];
            cout << endl;
            for (int i = 0; i < 3; i++)
            {
                if (i == 0)
                    cout << "Enter day   : ";
                else if (i == 1)
                    cout << "Enter month : ";
                else
                    cout << "Enter year  : ";
                cin >> date[i];
            }

            Reservation reservation(16 - numOfRooms, 16 - numOfRooms, roomNum, date);
            reservation.createReservation(room, roomIndex);
        }
    }
    else if (choice == 2)
    {
        cout << "+===================+" << endl
             << "     Check-In" << endl
             << "+===================+" << endl
             << endl;

        readRoom(room);
        string name, number;
        int roomNumber, inDate[3], outDate[3];

        cout << "Enter Name (First Name): ";
        cin >> name;
        cout << "Enter Phone Number     : ";
        cin >> number;
        cout << "Enter Room Reserved    : ";
        cin >> roomNumber;

        cout << endl;
        cout << "Check-In Date!!" << endl;
        for (int i = 0; i < 3; i++)
        {
            if (i == 0)
                cout << "Enter day      : ";
            else if (i == 1)
                cout << "Enter month    : ";
            else
                cout << "Enter year     : ";
            cin >> inDate[i];
        }

        cout << endl;
        cout << "Check-Out Date!!" << endl;
        for (int i = 0; i < 3; i++)
        {
            if (i == 0)
                cout << "Enter day      : ";
            else if (i == 1)
                cout << "Enter month    : ";
            else
                cout << "Enter year     : ";
            cin >> outDate[i];
        }

        Reservation reservation[15];
        int numberOfReservation = readReservation(reservation);

        quickSortRoomNumber(reservation, 0, numberOfReservation - 1);
        int index = binarySearch(roomNumber, numberOfReservation, reservation);

        if (index == -1)
        {
            cout << "Reservation does not exist..." << endl;
            system("PAUSE");
            exit(1);
        }

        Customer customer(reservation[index].getCustomerId(), name, number, inDate, outDate);
        customer.checkIn(reservation, numberOfReservation);

        int roomIndex = binarySearch(reservation[index].getRoomNumber(), 15, room);
        float total = ((outDate[0] + outDate[1] + outDate[2]) - (inDate[0] + inDate[1] + inDate[2])) * room[roomIndex].getRoomRate();

        Billing billing(reservation[index].getCustomerId(), roomNumber, total, inDate);
        billing.displayBillingDetails();
    }
    else if (choice == 3)
    {
        cout << "+===================+" << endl
             << "     Check-Out" << endl
             << "+===================+" << endl;

        int custId;
        cout << endl
             << "Enter the Customer ID to Check-Out: ";
        cin >> custId;

        Customer cust[15], customer;
        int numberOfCustomer = readCustomer(cust);

        customer.checkOut(cust, custId, numberOfCustomer);
    }
    else
    {
        cout << "ERROR: Not available option..." << endl;
        system("PAUSE");
        exit(1);
    }

    system("PAUSE");
    return 0;
}
