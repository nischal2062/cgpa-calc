#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Medicine {
    int id;
    string name;
    int quantity;
    float price;

};

vector<Medicine> inventory;
int nextId = 1;

void addMedicine() {
    Medicine med;
    med.id = nextId++;
    cout << "Enter medicine name: ";
    cin >> ws; // clear leftover newline
    getline(cin, med.name);
    cout << "Enter quantity: ";
    cin >> med.quantity;
    cout << "Enter price: ";
    cin >> med.price;
    inventory.push_back(med);
    cout << "Medicine added successfully!\n";
}

void viewInventory() {
    if (inventory.empty()) {
        cout << "Inventory is empty.\n";
        return;
    }

    cout << left << setw(5) << "ID" << setw(20) << "Name" << setw(10) << "Quantity" << "Price" << endl;
    cout << "------------------------------------------------------\n";
    for (const Medicine& med : inventory) {
        cout << left << setw(5) << med.id << setw(20) << med.name << setw(10) << med.quantity << med.price << endl;
    }
}

void searchMedicine() {
    string keyword;
    cout << "Enter medicine name to search: ";
    cin >> ws;
    getline(cin, keyword);
    bool found = false;
    for (const Medicine& med : inventory) {
        if (med.name.find(keyword) != string::npos) {
            cout << "Found: ID " << med.id << ", Name: " << med.name << ", Qty: " << med.quantity << ", Price: Rs. " << med.price << endl;
            found = true;
        }
    }
    if (!found) cout << "Medicine not found.\n";
}

void deleteMedicine() {
    int id;
    cout << "Enter medicine ID to delete: ";
    cin >> id;
    for (auto it = inventory.begin(); it != inventory.end(); ++it) {
        if (it->id == id) {
            inventory.erase(it);
            cout << "Medicine deleted successfully.\n";
            return;
        }
    }
    cout << "Medicine with ID " << id << " not found.\n";
}

int main() {
    int choice;
    do {
        cout << "\n=== Pharmacy Inventory Management ===\n";
        cout << "1. Add Medicine\n";
        cout << "2. View Inventory\n";
        cout << "3. Search Medicine\n";
        cout << "4. Delete Medicine\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addMedicine(); break;
            case 2: viewInventory(); break;
            case 3: searchMedicine(); break;
            case 4: viewInventory(); deleteMedicine(); break;
            case 5: cout << "Exiting program.\n"; break;
            default: cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
