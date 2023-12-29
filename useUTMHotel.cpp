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
// #include "UTMHotel.cpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{

    RoomList *room = new RoomList;
    ReservationList *reservation = new ReservationList;
    CustomerList *customer = new CustomerList;

    int customerCount = 0, roomNum[15], custId, reservationDate[3], custInDate[3], custOutDate[3];
    string custName = " ", custContact = " ";
    char loop;

    do
    {
        int choice;
        bool error = false;

        do
        {
            cout << "+===================+" << endl
                 << "      Main Menu" << endl
                 << "+===================+" << endl
                 << "1. Reservation" << endl
                 << "2. Check-In" << endl
                 << "3. Check-Out" << endl
                 << "4. Display List" << endl
                 << "Enter choice: ";
            cin >> choice;
            system("CLS");

            if (choice == 1)
            {

                cout << "+===================+" << endl
                     << "     Reservation" << endl
                     << "+===================+" << endl;

                if (customerCount == 0)
                {
                    room->ReadList();
                }

                room->DisplayRoomList(roomNum);

                roomNum[customerCount] = reservation->askReservation(reservationDate);
                reservation->InsertReservation(customerCount + 1, customerCount + 1, roomNum[customerCount], reservationDate);

                reservation->DisplayReservationList();
                customerCount++;
            }
            else if (choice == 2)
            {

                cout << "+===================+" << endl
                     << "     Check-In" << endl
                     << "+===================+" << endl
                     << endl;

                custId = customer->askCustomer(custInDate, custOutDate, custName, custContact);
                customer->InsertCustomer(custId, custName, custContact, custInDate, custOutDate);
                customer->DisplayCustomerList();

                reservation->DeleteNode(custId);
                reservation->DisplayReservationList();
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

                int index = customer->FindNode(custId);
                customer->DeleteNode(index);
                customer->DisplayCustomerList();
            }
            else if (choice == 4)
            {

                cout << "+===================+" << endl
                     << "     Display List" << endl
                     << "+===================+" << endl
                     << "1. Reservation List" << endl
                     << "2. Customer List" << endl
                     << "Enter choice: ";
                cin >> choice;

                if (choice == 1)
                {
                    reservation->DisplayReservationList();
                }
                else if (choice == 2)
                {
                    customer->DisplayCustomerList();
                }
                else
                {
                    cout << "ERROR: Not available option..." << endl;
                    error = true;
                }
            }
            else
            {
                cout << "ERROR: Not available option..." << endl;
                error = true;
            }

        } while (error);

        cout << endl
             << "Do you want to continue the program? (y/n): ";
        cin >> loop;

        system("CLS");

    } while (loop == 'y' || loop == 'Y');

    system("PAUSE");
    return 0;
}