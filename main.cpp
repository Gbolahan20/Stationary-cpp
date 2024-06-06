#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Stationery {
    string name;
    int quantity;
    double price;
};

void addStationery() {
    Stationery stationery;
    cout << "Enter stationery name: ";
    cin >> stationery.name;
    cout << "Enter quantity: ";
    cin >> stationery.quantity;
    cout << "Enter price: ";
    cin >> stationery.price;

    ofstream file("stationery.txt", ios::app);
    file << stationery.name << " " << stationery.quantity << " " << stationery.price << endl;
    file.close();
}

void displayStationery() {
    ifstream file("stationery.txt");
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

/*
void updateQuantity() {
    string name;
    int quantity;
    cout << "Enter stationery name: ";
    cin >> name;
    cout << "Enter new quantity: ";
    cin >> quantity;

    ifstream file("stationery.txt");
    ofstream temp("temp.txt");
    string line;
    while (getline(file, line)) {
        Stationery stationery;
        stringstream ss(line);
        ss >> stationery.name >> stationery.quantity >> stationery.price;
        if (stationery.name == name) {
            stationery.quantity = quantity;
        }
        temp << stationery.name << " " << stationery.quantity << " " << stationery.price << endl;
    }
    file.close();
    temp.close();
    remove("stationery.txt");
    rename("temp.txt", "stationery.txt");
}

*/



void updateQuantity() {
    Stationery stationery;
    fstream file, ftemp;
    string name;
    int quantity, count = 0;
    cout << "Enter stationery name: ";
    cin >> name;
    file.open("stationery.txt", ios::in);
    ftemp.open("temp.txt", ios::out | ios::app);
    if (!file) {
        cout << "Database Failed To Open!" << endl;
    } else {
        file >> stationery.name >> stationery.quantity >> stationery.price;
        while(!file.eof()) {
            if (name == stationery.name) {
                cout << "Enter new quantity: ";
                cin >> quantity;
                ftemp << stationery.name << " " << quantity << " " << stationery.price << endl;
                count = 1;
                cout << "Account Updated!" << endl;
            } else 
                ftemp << stationery.name << " " << stationery.quantity << " " << stationery.price << endl;
                file >> stationery.name >> stationery.quantity >> stationery.price; 
            
        } 
        if (count == 0) {
            cout << "Record Not Found!" << endl;
        }
    }
    system("pause");
    file.close();
    ftemp.close();
    remove("stationery.txt");
    rename("temp.txt", "stationery.txt");
}


int main() {
    int choice;
    while (true) {
        cout << "1. Add Stationery\n2. Display Stationery\n3. Update Quantity\n4. Exit\n";
        cin >> choice;
        switch (choice) {
            case 1:
                addStationery();
                break;
            case 2:
                displayStationery();
                break;
            case 3:
                updateQuantity();
                break;
            case 4:
                exit(0);
            default:
                cout << "Invalid choice!\n";
        }
    }
    return 0;
}

