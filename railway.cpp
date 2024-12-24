#include <iostream>
#include <cstring>
using namespace std;

class Train {
private:
    int trainNumber;
    char trainName[50];
    char source[50];
    char destination[50];
    char trainTime[10];
    static int trainCount;

public:
    Train() { 
        trainNumber = 0;
        strcpy(trainName, "");
        strcpy(source, "");
        strcpy(destination, "");
        strcpy(trainTime, "");
    }

    Train(int number, const char* name, const char* src, const char* dest, const char* time) { 
        trainNumber = number;
        strcpy(trainName, name);
        strcpy(source, src);
        strcpy(destination, dest);
        strcpy(trainTime, time);
        trainCount++;
    }

    ~Train() { 
        trainCount--;
    }

    
    void setTrainDetails(int number, const char* name, const char* src, const char* dest, const char* time) {
        trainNumber = number;
        strcpy(trainName, name);
        strcpy(source, src);
        strcpy(destination, dest);
        strcpy(trainTime, time);
        trainCount++;
    }

    void getTrainDetails() const {
        cout << "Train Number: " << trainNumber << endl;
        cout << "Train Name: " << trainName << endl;
        cout << "Source: " << source << endl;
        cout << "Destination: " << destination << endl;
        cout << "Train Time: " << trainTime << endl;
    }

    int getTrainNumber() const {
        return trainNumber;
    }

    static int getTrainCount() {
        return trainCount;
    }
};

int Train::trainCount = 0;

class RailwaySystem {
private:
    Train trains[100];
    int totalTrains;

public:
    RailwaySystem() {
        totalTrains = 0;
    }

    void addTrain() {
        int number;
        char name[50], src[50], dest[50], time[10];
        cout << "Enter Train Number: ";
        cin >> number;
        cin.ignore();
        cout << "Enter Train Name: ";
        cin.getline(name, 50);
        cout << "Enter Source: ";
        cin.getline(src, 50);
        cout << "Enter Destination: ";
        cin.getline(dest, 50);
        cout << "Enter Train Time: ";
        cin.getline(time, 10);

        trains[totalTrains].setTrainDetails(number, name, src, dest, time);
        totalTrains++;
        cout << "Train added successfully!\n";
    }

    void displayAllTrains() const {
        if (totalTrains == 0) {
            cout << "No train records available.\n";
            return;
        }

        for (int i = 0; i < totalTrains; i++) {
            cout << "Train " << i + 1 << " details:\n";
            trains[i].getTrainDetails();
            cout << "----------------------\n";
        }
    }

    void searchTrainByNumber(int number) const {
        for (int i = 0; i < totalTrains; i++) {
            if (trains[i].getTrainNumber() == number) {
                cout << "Train found!\n";
                trains[i].getTrainDetails();
                return;
            }
        }
        cout << "Train with number " << number << " not found!\n";
    }
};

int main() {
    RailwaySystem system;
    int choice;

    do {
        cout << "\n--- Railway Reservation System Menu ---\n";
        cout << "1. Add New Train Record\n";
        cout << "2. Display All Train Records\n";
        cout << "3. Search Train by Number\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            system.addTrain();
            break;
        case 2:
            system.displayAllTrains();
            break;
        case 3: {
            int number;
            cout << "Enter Train Number to search: ";
            cin >> number;
            system.searchTrainByNumber(number);
            break;
        }
        case 4:
            cout << "Exiting the system. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}

