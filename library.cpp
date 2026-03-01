#include <iostream>
#include <string>

using namespace std;

class LibraryMember {
private:
    static int idCounter; // Static variable to track IDs
    int memberID;
    string memberName;
    int booksIssued;
    string membershipType;

public:
    // Default Constructor
    LibraryMember() {
        memberID = ++idCounter; // Increment and assign unique ID
        memberName = "Unknown";
        booksIssued = 0;
        membershipType = "Standard";
    }

    // Function to set member details manually
    void setMemberDetails(string name, string type) {
        memberName = name;
        membershipType = type;
    }

    // Function to issue a book
    void issueBook() {
        if (booksIssued < 5) {
            booksIssued++;
            cout << "Book issued successfully to " << memberName << "." << endl;
        } else {
            cout << "Limit reached! Cannot issue more than 5 books." << endl;
        }
    }

    // Function to display details
    void displayDetails() {
        cout << "-----------------------------" << endl;
        cout << "Member ID: " << memberID << endl;
        cout << "Name: " << memberName << endl;
        cout << "Membership: " << membershipType << endl;
        cout << "Books Issued: " << booksIssued << endl;
        cout << "-----------------------------" << endl;
    }
};

// Initialize the static variable outside the class
int LibraryMember::idCounter = 1000; 

int main() {
    // Creating first object
    LibraryMember member1;
    member1.setMemberDetails("Alice Smith", "Premium");
    member1.issueBook();
    member1.issueBook();

    // Creating second object
    LibraryMember member2;
    member2.setMemberDetails("Bob Jones", "Student");
    member2.issueBook();

    // Displaying details to show unique IDs
    cout << "\nLibrary Member Registry:" << endl;
    member1.displayDetails();
    member2.displayDetails();

    return 0;
}