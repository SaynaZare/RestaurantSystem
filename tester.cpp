#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

// Enum to represent the role of staff members
enum class StaffRole {
    Manager,
    Delivery,
    Receptionist,
    Chef,
    Customer
};

// Base class for employees
class Staff {
protected:
    string Name;
    string Address;
    string PhoneNo;
    StaffRole Role;
public:
    // Constructor
    Staff(string name, string address, string phoneNo, StaffRole role) : Name(name), Address(address), PhoneNo(phoneNo), Role(role) {}

    // Display staff information
    void DisplayStaffInfo()
    {
        cout << "Name: " << Name << endl
            << "Address: " << Address << endl
            << "Phone Number: " << PhoneNo << endl
            << "Role: " << RoleToString() << endl;
    }

    // Convert role to string
    string RoleToString()
    {
        switch (Role)
        {
        case StaffRole::Manager: return "Manager";
        case StaffRole::Delivery: return "Delivery";
        case StaffRole::Receptionist: return "Receptionist";
        case StaffRole::Chef: return "Chef";
        case StaffRole::Customer: return "Customer";
        }
        return ""; // Added to fix missing return statement
    }

    // Getter functions
    StaffRole getRole() const {
        return Role;
    }

    string getName()
    {
        return Name;
    }

    string getAddress()
    {
        return Address;
    }

    string getPhoneNo()
    {
        return PhoneNo;
    }
};

class Manager : public Staff
{
public:
    Manager(string name, string address, string phoneNo) : Staff(name, address, phoneNo, StaffRole::Manager) {}

    void DisplayStaffInfo() override
    {
        cout << "Role: Manager" << endl;
        Staff::DisplayStaffInfo();
    }
};

class Delivery : public Staff
{
public:
    Delivery(string name, string address, string phoneNo) : Staff(name, address, phoneNo, StaffRole::Delivery) {}

    void DisplayStaffInfo() override
    {
        cout << "Role: Delivery" << endl;
        Staff::DisplayStaffInfo();
    }
};

class Receptionist : public Staff
{
public:
    Receptionist(string name, string address, string phoneNo) : Staff(name, address, phoneNo, StaffRole::Receptionist) {}

    void DisplayStaffInfo() override {
        cout << "Role: Receptionist" << endl;
        Staff::DisplayStaffInfo();
    }
};

// Class for storing food menu items
class FoodMenu
{
private:
    string ItemName;
    int availability;
    double price;
public:
    FoodMenu() = default;

    // Get item name from user
    void addItem()
    {
        getline(cin >> ws, ItemName);
    }

    // Return item name
    string getname()
    {
        return ItemName;
    }

    // Get price from user
    void addPrice()
    {
        cin >> price;
    }

    // Return price
    double getPrice()
    {
        return price;
    }

    // Get availability from user
    void addAvailability()
    {
        cin >> availability;
    }

    // Return availability
    int getAvailability()
    {
        return availability;
    }

    // Collect data from user about the food item
    void addData()
    {
        cout << "Enter new food item: ";
        addItem();
        cout << "Enter the price of " << ItemName << ": ";
        addPrice();
        cout << "Enter availability: ";
        addAvailability();
    }

    // Display item information
    void displayItemInfo()
    {
        cout << ItemName << endl;
        cout << availability << endl;
        cout << price << " pounds" << endl;
    }

    // Read food menu items from file
    void readFromFile_Food()
    {
        ifstream inFile("FoodMenu.txt");
        if (!inFile)
        {
            cout << "Unable to open file FoodMenu.txt" << endl;
            return;
        }

        while (inFile >> ws && getline(inFile, ItemName) && inFile >> price >> availability)
        {
            // Display loaded data (optional)
            cout << "Item: " << ItemName << ", Price: " << price << ", Availability: " << availability << endl;
        }

        inFile.close();
    }

    // Write food menu items to file
    void writeToFile_Food()
    {
        ofstream outFile("FoodMenu.txt", ios::app); // Open file in append mode
        if (!outFile)
        {
            cout << "Unable to open file FoodMenu.txt for writing" << endl;
            return;
        }

        outFile << ItemName << endl;
        outFile << price << endl;
        outFile << availability << endl;

        outFile.close();
    }
};

int main()
{
    FoodMenu foodItem;

    // Test writing data to file
    foodItem.addData();
    foodItem.writeToFile_Food();

    // Test reading data from file
    foodItem.readFromFile_Food();

    return 0;
}
