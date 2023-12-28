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
    char loop;
    RoomList* room = new RoomList [15];

    do{
        int choice;
        bool error = false;

        do{
            cout << "+===================+" << endl
                << "      Main Menu" << endl
                << "+===================+" << endl
                << "1. Reservation" << endl
                << "2. Check-In" << endl
                << "3. Check-Out" << endl
                << "Enter choice: ";
            cin >> choice;
            system("CLS");

            if(choice == 1){

                cout << "+===================+" << endl
                    << "     Reservation" << endl
                    << "+===================+" << endl;

            }
            else if(choice == 2){

                cout << "+===================+" << endl
                    << "     Check-In" << endl
                    << "+===================+" << endl
                    << endl;

            }
            else if(choice == 3){

                cout << "+===================+" << endl
                    << "     Check-Out" << endl
                    << "+===================+" << endl;

            }
            else{
                cout << "ERROR: Not available option..." << endl;
                error = true;
            }

        } while(error);
        
        cout<<"Do you want to continue the program? (y/n): ";
        cin>>loop;

    } while(loop == 'y' || loop == 'Y');

    system("PAUSE");
    return 0;
}