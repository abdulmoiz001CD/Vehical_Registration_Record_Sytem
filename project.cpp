#include <iostream>
#include <string>
using namespace std;
#include <fstream> 


struct reg_Data {
    string ownerName;
    string vehicalName;
    string vehicalType;
};



// Function to take input
void inputData(reg_Data &d) {
    cout << "Owner Name: ";
    getline(cin, d.ownerName);

    cout << "Vehicle Name: ";
    getline(cin, d.vehicalName);

    cout << "Vehicle Type: ";
    getline(cin, d.vehicalType);
}


// Function to display data
void displayData(const reg_Data &d) {
    cout << "\n--- Vehicle Registration Info ---\n";
    cout << "Owner Name: " << d.ownerName << endl;
    cout << "Vehicle Name: " << d.vehicalName << endl;
    cout << "Vehicle Type: " << d.vehicalType << endl;
}


// Add a function to save the data
void save_to_file(const reg_Data &d){
    ofstream outFile("vehicle_data.txt", ios::app);

    if(outFile.is_open()){
        outFile << "Owner Name: " << d.ownerName << endl;
        outFile << "Vehicle Name: " << d.vehicalName << endl;
        outFile << "Vehicle Type: " << d.vehicalType << endl;
        outFile << "--------------------------" << endl;
        outFile.close();
        cout << "✅ Data saved to file successfully.\n";
    }
    else{
         cout << "❌ Error opening file.\n";
    }

}




void add_new_regstn() {
    reg_Data d;

    // Input once
    inputData(d);

    // Show data
    displayData(d);

    char confirm;
    cout << "\nConfirm registration? (Y to confirm / E to edit): ";
    cin >> confirm;
    cin.ignore(); // Clear newline after char input

    if (confirm == 'E' || confirm == 'e') {
        cout << "\n--- Editing Information ---\n";
        inputData(d);  // Reuse the same input function
    }

    // Final Display
    displayData(d);

    save_to_file(d);
}


void searchVehicle() {
    int searchOption;
    string keyword;
    string searchField;

    cout << "\nSearch by:\n";
    cout << "1. Owner Name\n";
    cout << "2. Vehicle Name\n";
    cout << "3. Vehicle Type\n";
    cout << "Enter option (1-3): ";
    cin >> searchOption;
    cin.ignore(); // Clear input buffer

    switch (searchOption) {
        case 1:
            searchField = "Owner Name: ";
            break;
        case 2:
            searchField = "Vehicle Name: ";
            break;
        case 3:
            searchField = "Vehicle Type: ";
            break;
        default:
            cout << "Invalid option.\n";
            return;
    }

    cout << "Enter search term: ";
    getline(cin, keyword);

    ifstream inFile("vehicle_data.txt");
    if (!inFile.is_open()) {
        cout << "❌ Error opening file.\n";
        return;
    }

    string line;
    bool found = false;

    while (getline(inFile, line)) {
        if (line.find(searchField + keyword) != string::npos) {
            found = true;
            cout << "\n--- Record Found ---\n";
            cout << line << endl;

            // Show next 2 lines (remaining part of the record)
            for (int i = 0; i < 2; ++i) {
                if (getline(inFile, line)) {
                    cout << line << endl;
                }
            }
            cout << "--------------------------\n";
        }
    }

    inFile.close();

    if (!found) {
        cout << "❌ No matching record found.\n";
    }
}




// Display All Registered Vehicles from the file.
void displayAllVehicles() {
    ifstream inFile("vehicle_data.txt");

    if (!inFile.is_open()) {
        cout << "❌ Could not open file. No data found.\n";
        return;
    }

    string line;
    bool hasData = false;

    cout << "\n--- All Registered Vehicles ---\n";

    while (getline(inFile, line)) {
        hasData = true;
        cout << line << endl;
    }

    if (!hasData) {
        cout << "📂 No vehicle records found.\n";
    }

    inFile.close();
}



int main(){
    int choice;

    do {
        cout << "\nMenu Options:\n";
        cout << "1. Add New Registration\n";
        cout << "2. Search Vehicle\n";
        cout << "3. Display All Vehicle\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // Add this line here

      

switch (choice) {
    case 1:
        add_new_regstn();
        break;
    case 2:
        searchVehicle();
    case 3:
        displayAllVehicles();
    case 0:
        cout << "Exiting program. Goodbye!\n";
        break;
    default:
        cout << "Invalid choice. Please try again.\n";
        break;
}

    } 
    
    while(choice != 0);

    return 0;
}
