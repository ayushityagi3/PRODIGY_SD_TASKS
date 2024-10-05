#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Contact {
    string name;
    string phoneNumber;
    string email;
};

void addContact(vector<Contact>& contacts) {
    Contact newContact;
    cout << "Enter name: ";
    cin.ignore(); // To clear the newline character left in the input buffer
    getline(cin, newContact.name);
    cout << "Enter phone number: ";
    getline(cin, newContact.phoneNumber);
    cout << "Enter email address: ";
    getline(cin, newContact.email);
    contacts.push_back(newContact);
    cout << "Contact added successfully!" << endl;
}

void viewContacts(const vector<Contact>& contacts) {
    if (contacts.empty()) {
        cout << "No contacts to display." << endl;
        return;
    }

    cout << "Contact List:" << endl;
    for (size_t i = 0; i < contacts.size(); ++i) {
        cout << i + 1 << ". " << contacts[i].name << ", " 
             << contacts[i].phoneNumber << ", " 
             << contacts[i].email << endl;
    }
}

void editContact(vector<Contact>& contacts) {
    int index;
    viewContacts(contacts);
    cout << "Enter the contact number you want to edit: ";
    cin >> index;

    if (index < 1 || index > contacts.size()) {
        cout << "Invalid contact number!" << endl;
        return;
    }

    cout << "Editing contact: " << contacts[index - 1].name << endl;
    cout << "Enter new name (leave empty to keep unchanged): ";
    cin.ignore();
    string newName;
    getline(cin, newName);
    if (!newName.empty()) {
        contacts[index - 1].name = newName;
    }

    cout << "Enter new phone number (leave empty to keep unchanged): ";
    string newPhoneNumber;
    getline(cin, newPhoneNumber);
    if (!newPhoneNumber.empty()) {
        contacts[index - 1].phoneNumber = newPhoneNumber;
    }

    cout << "Enter new email address (leave empty to keep unchanged): ";
    string newEmail;
    getline(cin, newEmail);
    if (!newEmail.empty()) {
        contacts[index - 1].email = newEmail;
    }

    cout << "Contact updated successfully!" << endl;
}

void deleteContact(vector<Contact>& contacts) {
    int index;
    viewContacts(contacts);
    cout << "Enter the contact number you want to delete: ";
    cin >> index;

    if (index < 1 || index > contacts.size()) {
        cout << "Invalid contact number!" << endl;
        return;
    }

    contacts.erase(contacts.begin() + index - 1);
    cout << "Contact deleted successfully!" << endl;
}

void saveContactsToFile(const vector<Contact>& contacts) {
    ofstream file("contacts.txt");
    for (const auto& contact : contacts) {
        file << contact.name << "\n" << contact.phoneNumber << "\n" << contact.email << "\n";
    }
    file.close();
}

void loadContactsFromFile(vector<Contact>& contacts) {
    ifstream file("contacts.txt");
    string line;
    Contact contact;

    while (getline(file, contact.name)) {
        getline(file, contact.phoneNumber);
        getline(file, contact.email);
        contacts.push_back(contact);
    }
    file.close();
}

int main() {
    vector<Contact> contacts;
    loadContactsFromFile(contacts);

    int choice;
    do {
        cout << "\nContact Management System\n";
        cout << "1. Add New Contact\n";
        cout << "2. View Contacts\n";
        cout << "3. Edit Contact\n";
        cout << "4. Delete Contact\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addContact(contacts);
                break;
            case 2:
                viewContacts(contacts);
                break;
            case 3:
                editContact(contacts);
                break;
            case 4:
                deleteContact(contacts);
                break;
            case 5:
                saveContactsToFile(contacts);
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
    } while (choice != 5);

    return 0;
}
