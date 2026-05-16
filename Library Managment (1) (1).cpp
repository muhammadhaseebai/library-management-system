#include<iostream>
#include<string>
using namespace std;

// ---------------- BOOK CLASS ---------------- 
class Book {
    int bookID;
    string title;
    string author;
    bool isIssued;

public:
    Book() {
        isIssued = false;
    }

    void input() {
        cout << "Enter Book ID: ";
        cin >> bookID;
        cin.ignore();

        cout << "Enter Title: ";
        getline(cin, title);

        cout << "Enter Author: ";
        getline(cin, author);

        isIssued = false;
    }

    void display() {
        cout << "\nBook ID: " << bookID;
        cout << "\nTitle: " << title;
        cout << "\nAuthor: " << author;
        cout << "\nStatus: " << (isIssued ? "Issued" : "Available") << endl;
    }

    int getID() { return bookID; }

    bool getStatus() { return isIssued; }

    void issueBook() { isIssued = true; }

    void returnBook() { isIssued = false; }
};

// ---------------- MEMBER CLASS ----------------
class Member {
    int memberID;
    string name;

public:
    void input() {
        cout << "Enter Member ID: ";
        cin >> memberID;
        cin.ignore();

        cout << "Enter Member Name: ";
        getline(cin, name);
    }

    void display() {
        cout << "\nMember ID: " << memberID;
        cout << "\nName: " << name << endl;
    }

    int getID() { return memberID; }
};

// ---------------- LIBRARY CLASS ----------------
class Library {
    Book books[50];
    Member members[50];

    int bookCount = 0;
    int memberCount = 0;

public:
    void addBook() {
        books[bookCount].input();
        bookCount++;
    }

    void showBooks() {
        for(int i = 0; i < bookCount; i++)
            books[i].display();
    }

    void addMember() {
        members[memberCount].input();
        memberCount++;
    }

    void issueBook() {
        int id;
        cout << "Enter Book ID to issue: ";
        cin >> id;

        for(int i = 0; i < bookCount; i++) {
            if(books[i].getID() == id) {
                if(!books[i].getStatus()) {
                    books[i].issueBook();
                    cout << "Book Issued Successfully!\n";
                } else {
                    cout << "Book already issued!\n";
                }
                return;
            }
        }
        cout << "Book not found!\n";
    }

    void returnBook() {
        int id;
        cout << "Enter Book ID to return: ";
        cin >> id;

        for(int i = 0; i < bookCount; i++) {
            if(books[i].getID() == id) {
                if(books[i].getStatus()) {
                    books[i].returnBook();
                    cout << "Book Returned Successfully!\n";
                } else {
                    cout << "Book was not issued!\n";
                }
                return;
            }
        }
        cout << "Book not found!\n";
    }
};

// ---------------- MAIN ----------------
int main() {
    Library lib;
    int choice;

    do {
        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Book\n";
        cout << "2. Show Books\n";
        cout << "3. Add Member\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "0. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
        case 1:
            lib.addBook();
            break;

        case 2:
            lib.showBooks();
            break;

        case 3:
            lib.addMember();
            break;

        case 4:
            lib.issueBook();
            break;

        case 5:
            lib.returnBook();
            break;

        case 0:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while(choice != 0);

    return 0;
}
