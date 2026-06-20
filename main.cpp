#include <iostream>
#include <vector>
using namespace std;

struct Book {
    int id;
    string title;
    bool issued;
};

int main() {
    vector<Book> books;
    int choice;

    do {
        cout << "\n===== Library Management System =====\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Search Book\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if(choice == 1) {
            Book b;
            cout << "Enter Book ID: ";
            cin >> b.id;

            cin.ignore();
            cout << "Enter Book Title: ";
            getline(cin, b.title);

            b.issued = false;
            books.push_back(b);

            cout << "Book Added Successfully!\n";
        }

        else if(choice == 2) {
            if(books.empty()) {
                cout << "No Books Available!\n";
            } else {
                cout << "\nBook List:\n";
                for(auto &b : books) {
                    cout << "ID: " << b.id
                         << " | Title: " << b.title
                         << " | Status: "
                         << (b.issued ? "Issued" : "Available")
                         << endl;
                }
            }
        }

        else if(choice == 3) {
            int id;
            cout << "Enter Book ID: ";
            cin >> id;

            bool found = false;
            for(auto &b : books) {
                if(b.id == id) {
                    cout << "Book Found!\n";
                    cout << "Title: " << b.title << endl;
                    cout << "Status: "
                         << (b.issued ? "Issued" : "Available")
                         << endl;
                    found = true;
                    break;
                }
            }

            if(!found)
                cout << "Book Not Found!\n";
        }

        else if(choice == 4) {
            int id;
            cout << "Enter Book ID to Issue: ";
            cin >> id;

            bool found = false;
            for(auto &b : books) {
                if(b.id == id) {
                    found = true;

                    if(!b.issued) {
                        b.issued = true;
                        cout << "Book Issued Successfully!\n";
                    } else {
                        cout << "Book Already Issued!\n";
                    }
                    break;
                }
            }

            if(!found)
                cout << "Book Not Found!\n";
        }

        else if(choice == 5) {
            int id;
            cout << "Enter Book ID to Return: ";
            cin >> id;

            bool found = false;
            for(auto &b : books) {
                if(b.id == id) {
                    found = true;

                    if(b.issued) {
                        b.issued = false;
                        cout << "Book Returned Successfully!\n";
                    } else {
                        cout << "Book Was Not Issued!\n";
                    }
                    break;
                }
            }

            if(!found)
                cout << "Book Not Found!\n";
        }

    } while(choice != 6);

    cout << "Thank You!\n";
    return 0;
}
