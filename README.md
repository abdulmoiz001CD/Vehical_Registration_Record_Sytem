# 🚗 Vehicle Registration System - C++ Project

This is a **simple console-based Vehicle Registration System** built using C++. It allows users to:

- Register vehicle information
- Search vehicles by owner, name, or type
- View all registered vehicle data
- Save and retrieve data from a text file

---

## 📁 Project Structure

VehicleRegistrationSystem/
├── vehicle_data.txt # Stores all registered vehicle records
├── main.cpp # Main program file
└── README.md # Project documentation

---

## 📌 Features

### ✅ Add New Vehicle Registration
- Enter **Owner Name**, **Vehicle Name**, and **Vehicle Type**
- Edit before saving if needed
- Saves data to `vehicle_data.txt` file

### 🔍 Search Vehicle Records
- Search by:
  - Owner Name
  - Vehicle Name
  - Vehicle Type
- Displays the matching record and its details

### 📋 Display All Vehicles
- View all registered vehicle entries from the file

---

## 💾 Data Format (vehicle_data.txt)

Each record is saved in this format:

Owner Name: Ali
Vehicle Name: Honda Civic
Vehicle Type: Car
yaml
Copy
Edit

---

## 🛠️ Requirements

- C++ Compiler (G++, MSVC, Clang, etc.)
- Basic terminal or command-line interface

---

## 🚀 How to Run

1. **Compile the code:**

   ```bash
   g++ main.cpp -o VehicleSystem
Run the program:


./VehicleSystem
Follow menu prompts to use the system

🧪 Sample Menu

Menu Options:
1. Add New Registration
2. Search Vehicle
3. Display All Vehicle
0. Exit


📌 Notes
All data is stored in a plain text file (vehicle_data.txt)

File is appended, not overwritten

Simple struct and file handling used for demonstration purposes

🤝 Author
Developed by: Abdul Moiz Shaikh
Language: C++
Contact: abdulmoizs2005@gmail.com

📃 License
This project is open-source and free to use under the MIT License.