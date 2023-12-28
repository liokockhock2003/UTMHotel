/****************************** UTM HOTEL ******************************\
Project: UTMHotel
Data Structure & Algorithm
Semester 1, 2023/2024

Section: 10
Member 1's Name: AHMAD SAIFUDIN BIN NARDI SUSANTO A22EC0035
Member 2's Name: LIO KOCK HOCK A22EC0185

<Implementation File>
Function definition, algorithm

See https://github.com/Saifdn/UTMHotel.

\************************************************************************/

#include "UTMHotelFunction.hpp"
#include "UTMHotel.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

/*=========================================================
    Functions Definition
=========================================================*/
void checkFile(fstream &file)
{
    if (!file.is_open())
    {
        cout << "Error opening file!" << endl;
        exit(1);
    }
}

void readRoom(Room room[])
{

    fstream file;

    file.open("Room/room.txt", ios::in);

    checkFile(file);

    int roomNumber;
    string type;
    float price;
    int availability;
    int count = 0;

    while (file >> roomNumber >> type >> price >> availability && count < 15)
    {
        bool isAvailable = (availability == 1);
        room[count++] = Room(roomNumber, type, price, isAvailable);
    }

    file.close();
}

int readReservation(Reservation reserve[])
{
    fstream file;
    file.open("Reservation/reservation.txt", ios::in);
    checkFile(file);

    int reservationId;
    int customerId;
    int roomNumber;
    int reservationDate[3];
    int count = 0;

    while (file >> reservationId >> customerId >> roomNumber >> reservationDate[0] >> reservationDate[1] >> reservationDate[2] && count < 15)
    {
        reserve[count] = Reservation(reservationId, customerId, roomNumber, reservationDate);
        count++;
    }
    file.close();

    return count;
}

int readCustomer(Customer cust[])
{
    fstream file;
    file.open("Customer/customer.txt", ios::in);
    checkFile(file);

    int customerId;
    string name, contact;
    int checkInDate[3];
    int checkOutDate[3];
    int count = 0;

    while (file >> customerId >> name >> contact >> checkInDate[0] >> checkInDate[1] >> checkInDate[2] >> checkOutDate[0] >> checkOutDate[1] >> checkOutDate[2] && count < 15)
    {
        cust[count++] = Customer(customerId, name, contact, checkInDate, checkOutDate);
    }

    file.close();
    return count;
}

int printAvailableRoom(Room room[])
{
    int count = 0;

    cout << endl;
    for (int i = 0; i < 15; i++)
    {
        if (room[i].getAvailability())
        {
            cout << left
                 << setw(4) << room[i].getRoomNumber()
                 << setw(8) << room[i].getType()
                 << setw(3) << "RM "
                 << setw(4) << room[i].getRoomRate() << " per night" << endl;
            count++;
        }
    }

    return count;
}

/*=========================================================
    Improved Bubble Sort
=========================================================*/
void bubbleSort(Room data[], int n)
{
    Room temp;
    bool sorted = false;

    for (int pass = 1; (pass < n) && !sorted; ++pass)
    {
        sorted = true;
        for (int x = 0; x < n - pass; ++x)
        {
            if (data[x].getRoomRate() > data[x + 1].getRoomRate())
            {
                temp = data[x];
                data[x] = data[x + 1];
                data[x + 1] = temp;
                sorted = false;
            }
        }
    }
}

/*=========================================================
    Merge Sort
=========================================================*/
void merge(Customer data[], int first, int mid, int last)
{

    Customer tempData[100];

    int first1 = first;
    int last1 = mid;
    int first2 = mid + 1;
    int last2 = last;
    int index = first1;

    // for(; (first1 <= last1) && (first2 <= last2); ++index){

    //     int val1 = 0, val2 =0;

    //     int *array1 = data[first1].getCheckInDate();
    //     int *array2 = data[first2].getCheckInDate();

    //     for(int j = 0; j < 3; j++){
    //         val1 += array1[j];
    //         val2 += array2[j];
    //     }

    //     if(val1 < val2){
    //         tempData[index] = data[first1];
    //         ++first1;
    //     }
    //     else{
    //         tempData[index] = data[first2];
    //         ++first2;
    //     }
    // }

    // for(; first1 <= last1; ++first1, ++index){
    //     tempData[index] = data[first1];
    // }

    // for(; first2 <= last2; ++first2, ++index){
    //     tempData[index] = data[first2];
    // }

    // for(index = first; index <= last; ++index){
    //    data[index] = tempData[index];
    // }
}

void mergeSort(Customer data[], int first, int last)
{
    if (first < last)
    {
        int mid = (first + last) / 2;
        mergeSort(data, first, mid);
        mergeSort(data, mid + 1, last);
        merge(data, first, mid, last);
    }
}

/*=========================================================
    Quick Sort based on Room Number (room)
=========================================================*/
int partitionRoomNumber(Room room[], int first, int last)
{
    int pivot;
    Room temp;
    int loop, cutPoint, bottom, top;
    pivot = room[first].getRoomNumber(); // identify pivot
    bottom = first;
    top = last;
    loop = 1; // always TRUE

    while (loop)
    {
        while (room[top].getRoomNumber() > pivot)
        {
            top--;
        }
        while (room[bottom].getRoomNumber() < pivot)
        {
            bottom++;
        }
        if (bottom < top)
        {
            temp = room[bottom];
            room[bottom] = room[top];
            room[top] = temp;
        }

        else
        {
            loop = 0;
            cutPoint = top;
        }
    }
    return cutPoint;
}

void quickSortRoomNumber(Room room[], int first, int last)
{
    int cut;
    if (first < last)
    {
        cut = partitionRoomNumber(room, first, last);
        quickSortRoomNumber(room, first, cut);
        quickSortRoomNumber(room, cut + 1, last);
    }
}

/*=========================================================
    Quick Sort based on Room Number (reservation)
=========================================================*/
int partitionRoomNumber(Reservation reserve[], int first, int last)
{
    int pivot;
    Reservation temp;
    int loop, cutPoint, bottom, top;
    pivot = reserve[first].getRoomNumber(); // identify pivot
    bottom = first;
    top = last;
    loop = 1; // always TRUE

    while (loop)
    {
        while (reserve[top].getRoomNumber() > pivot)
        {
            top--;
        }
        while (reserve[bottom].getRoomNumber() < pivot)
        {
            bottom++;
        }
        if (bottom < top)
        {
            temp = reserve[bottom];
            reserve[bottom] = reserve[top];
            reserve[top] = temp;
        }

        else
        {
            loop = 0;
            cutPoint = top;
        }
    }
    return cutPoint;
}

void quickSortRoomNumber(Reservation reserve[], int first, int last)
{
    int cut;
    if (first < last)
    {
        cut = partitionRoomNumber(reserve, first, last);
        quickSortRoomNumber(reserve, first, cut);
        quickSortRoomNumber(reserve, cut + 1, last);
    }
}

/*=========================================================
    Quick Sort based on Customer ID
=========================================================*/
int partitionCustID(Customer cust[], int first, int last)
{
    int pivot;
    Customer temp;
    int loop, cutPoint, bottom, top;
    pivot = cust[first].getCustomerId(); // identify pivot
    bottom = first;
    top = last;
    loop = 1; // always TRUE

    while (loop)
    {
        while (cust[top].getCustomerId() > pivot)
        {
            top--;
        }
        while (cust[bottom].getCustomerId() < pivot)
        {
            bottom++;
        }
        if (bottom < top)
        {
            temp = cust[bottom];
            cust[bottom] = cust[top];
            cust[top] = temp;
        }

        else
        {
            loop = 0;
            cutPoint = top;
        }
    }
    return cutPoint;
}

void quickSortCustID(Customer cust[], int first, int last)
{
    int cut;
    if (first < last)
    {
        cut = partitionCustID(cust, first, last);
        quickSortCustID(cust, first, cut);
        quickSortCustID(cust, cut + 1, last);
    }
}

/*=========================================================
    Quick Sort based on Billing ID
=========================================================*/
// int partitionBillID(Billing bill[], int first, int last){
//     int pivot;
//     Billing temp;
//     int loop, cutPoint, bottom, top;
//     pivot = bill[first].getCustomerId(); //identify pivot
//     bottom = first; top = last;
//     loop=1; //always TRUE

//     while(loop)
//     {
//         while(bill[top].getBillingId()>pivot){top--;}
//         while(bill[bottom].getBillingId()<pivot){bottom++;}
//         if(bottom<top)
//         {
//             //swap Room Number
//             temp = bill[bottom];
//             bill[bottom] = bill[top];
//             bill[top] = temp;

//         }

//         else{
//             loop = 0;
//             cutPoint = top;
//         }
//     }
//     return cutPoint;
// }

// void quickSortBillID(Billing bill[], int first, int last){
//     int cut;
//     if(first<last){
//         cut = partitionBillID(bill, first, last);
//         quickSortBillID(bill, first, cut);
//         quickSortBillID(bill, cut+1, last);
//     }
// }

/*=========================================================
    Binary Search based on Customer ID
=========================================================*/
int binarySearch(int searchkey, int arraysize, Customer cust[])
{
    bool found = false;
    int index = -1;
    int middle, left = 0, right = arraysize - 1;

    while ((left <= right) && (!found))
    {
        middle = (left + right) / 2;
        if (cust[middle].getCustomerId() == searchkey)
        {
            index = middle;
            found = true;
        }

        else if (cust[middle].getCustomerId() > searchkey)
            right = middle - 1;

        else
            left = middle + 1;
    }
    return index;
}

/*=========================================================
    Binary Search based on Room Number
=========================================================*/
int binarySearch(int searchkey, int arraysize, Room room[])
{
    bool found = false;
    int index = -1;
    int middle, left = 0, right = arraysize - 1;

    while ((left <= right) && (!found))
    {
        middle = (left + right) / 2;
        if (room[middle].getRoomNumber() == searchkey)
        {
            index = middle;
            found = true;
        }

        else if (room[middle].getRoomNumber() > searchkey)
            right = middle - 1;

        else
            left = middle + 1;
    }
    return index;
}

/*=========================================================
    Binary Search based on Room Number
=========================================================*/
int binarySearch(int searchkey, int arraysize, Reservation reserve[])
{
    bool found = false;
    int index = -1;
    int middle, left = 0, right = arraysize - 1;

    while ((left <= right) && (!found))
    {
        middle = (left + right) / 2;
        if (reserve[middle].getRoomNumber() == searchkey)
        {
            index = middle;
            found = true;
        }

        else if (reserve[middle].getRoomNumber() > searchkey)
            right = middle - 1;

        else
            left = middle + 1;
    }
    return index;
}