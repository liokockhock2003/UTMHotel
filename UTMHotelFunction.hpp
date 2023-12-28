/****************************** UTM HOTEL ******************************\
Project: UTMHotel
Data Structure & Algorithm
Semester 1, 2023/2024

Section: 10
Member 1's Name: AHMAD SAIFUDIN BIN NARDI SUSANTO A22EC0035
Member 2's Name: LIO KOCK HOCK A22EC0185

<Specification File>
Function declaration

See https://github.com/Saifdn/UTMHotel.

\************************************************************************/

#ifndef UTMHOTELFUNCTION_H
#define UTMHOTELFUNCTION_H

#include "UTMHotel.hpp"

void bubbleSort(Room[], int);

void mergeSort(Customer[], int, int);

void quickSortRoomNumber(Room[], int, int);

void quickSortCustID(Customer[], int, int);

void quickSortRoomNumber(Reservation[], int, int);

void quickSortBillID(Billing[], int, int);

int binarySearch(int, int, Customer[]);

int binarySearch(int, int, Room[]);

int binarySearch(int, int, Reservation[]);

void checkFile(fstream &);

void readRoom(Room[]);

int readReservation(Reservation[]);

int readCustomer(Customer[]);

int printAvailableRoom(Room[]);

#endif