/* This program focus on a system which is used for 
login into system or to register a new system */

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// making a function for new user registration
void registerUser() {
    string username, password; // username and password are in string datatype to ensure versitality of name and pass
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

// operating file "users" to enter new data
    ofstream file("usersinfo.txt", ios::app);
    if (file.is_open()) {
        file << username << " " << password << endl; // entering new data
        file.close();
        cout << "Registration successful!" << endl;
    } else {
        cout << "Unable to open file for writing." << endl;
    }
}

// creating a function for users to login
bool loginUser() {
    string username, password, storedUsername, storedPassword;
    cout << "Enter username: "; // taking inpur of username and password for verification
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file("usersinfo.txt");
    if (file.is_open()) {
        while (file >> storedUsername >> storedPassword) {
            if (storedUsername == username && storedPassword == password) //verifyring provided username and passwords
            {
                file.close();
                return true;
            }
        }
        file.close();
    } else {
        cout << "Unable to open file for reading." << endl;
    }
    return false;
}

int main() {
    int choice;
    do {
        // displaying the available options
        cout << "1. Register\n2. Login\n3. Exit\nEnter your choice: ";
        cin >> choice;

        // using stwitch case to operate on the data entered by user
        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                if (loginUser()) {
                    cout << "Login successful!" << endl;
                } else {
                    cout << "Invalid username or password." << endl;
                }
                break;
            case 3:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}
