#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Staff {
protected:
    string Name;
    string Address;
    string PhoneNo;

public:
    Staff(string name, string address, string phoneNo) : Name(name), Address(address), PhoneNo(phoneNo) {}

    void DisplayStaffInfo() {
        cout << "Name: " << Name << endl
            << "Address: " << Address << endl
            << "Phone Number: " << PhoneNo << endl;
    }
};
class Customer : public Staff
{
private:
    string customerID;
public:
    Customer(string name, string address, string phoneNo, string ID) : Staff(name, address, phoneNo), customerID(ID) {
        // Generating customer ID based on name and unique part of phone number, foundation for having customer loyalty programs..
        string uniqueID = phoneNo.substr(phoneNo.size() - 2);
        customerID = name + uniqueID;
    }
};


class Manager : public Staff {
public:
    Manager(string name, string address, string phoneNo) : Staff(name, address, phoneNo) {}
};

class Receptionist : public Staff {
public:
    Receptionist(string name, string address, string phoneNo) : Staff(name, address, phoneNo) {}
};

class Delivery : public Staff {
public:
    Delivery(string name, string address, string phoneNo) : Staff(name, address, phoneNo) {}
};

class Chef : public Staff {
private:
    string CuisineSpeciality;

public:
    Chef(string name, string address, string phoneNo, string cuisine) : Staff(name, address, phoneNo), CuisineSpeciality(cuisine) {}

    void DisplayStaffInfo() override {
        Staff::DisplayStaffInfo();
        cout << "Cuisine Speciality: " << CuisineSpeciality << endl;
    }


    void DisplayEmployee(const vector<Staff*>& staff) {
        for (const auto& s : staff) {
            cout << "\n\n * * Staff * *\n\n";
            s->DisplayStaffInfo();
        }
    }

    void addStaff() {
        string Name, Address, PhoneNo;
        int input;

        cout << "Enter Employee name: ";
        getline(cin >> ws, Name);

        cout << "Enter Employee address: ";
        getline(cin >> ws, Address);

        cout << "Enter Employee phone number: ";
        getline(cin >> ws, PhoneNo);

        cout << "Enter the Employee type: (1 for Receptionist, 2 for Delivery Staff, 3 for Manager, 4 for Chef): ";
        cin >> input;

        switch (input) {
        case 1:
            staff.push_back(new Receptionist(Name, Address, PhoneNo));
            break;
        case 2:
            staff.push_back(new Delivery(Name, Address, PhoneNo));
            break;
        case 3:
            staff.push_back(new Manager(Name, Address, PhoneNo));
            break;
        case 4:
        {
            string CuisineSpeciality;
            cout << "Enter Chef's Cuisine Speciality: ";
            cin >> CuisineSpeciality;
            staff.push_back(new Chef(Name, Address, PhoneNo, CuisineSpeciality));
            break;
        }
        default:
            cout << "Invalid Input! Try again." << endl;
            break;
        }
    }
};


class FoodMenu {
private:
    string ItemName;
    int availability = 0; // value
    double price = 0;
    double PopularityRating = 0;

public:
    void addItem() {
        getline(cin >> ws, ItemName);
    }

    void addPrice() {
        cin >> price;
    }

    void addAvailability() {
        cin >> availability;
    }

    void addData()
    {
        cout << "Enter new food item: " << endl;
        addItem();
        cout << "Enter the price of " << ItemName << ": " << endl;
        addPrice();
        cout << "Enter availability: " << endl;
        addAvailability();
    }
};

class Owner
{
private:
    int option;
    bool progress = true;
    vector<Staff*>& staff;
    Chef chefObj;
public:
    Owner(vector<Staff*>& s) : staff(s) {}

    void start_Owner()
    {
        while (progress)
        {
            cout << "choose from options below " << endl;
            cout << "1. Add staff. " << endl;
            cout << "2. Add food items. " << endl;
            cout << "3. manage and edit availability of itmes. " << endl;
            cout << "4. edit food price. " << endl;
            cout << "5. set upper limit for delivery. " << endl;
            cout << "6. generate today's report. " << endl;
            cout << "7. load previous data. " << endl;
            cout << "8. save and quit." << endl;
            //--------------------------------------------
            cin >> option;
            if (option > 8 || option < 1) {
                cout << "invalid input! try again." << endl;
                cin >> option;
            }
            switch (option) {
            case 1:
                chefObj.addStaff();
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            }
        }

    }
};

class Menu {
private:
    int choice;
    vector<FoodMenu> FoodItems;
    Owner ownerObj;

public:

    void addFoodData()
    {
        FoodMenu foodobj;
        foodobj.addData();
        FoodItems.push_back(foodobj);
    }

    void MainMenu()
    {
        cout << "Restaurant Take-away system: " << endl;
        cout << "Press 1 for customer_experience mode" << endl;
        cout << "Press 2 for owner_experience mode" << endl;

        cin >> choice;

        if (cin.fail() || choice > 2 || choice < 1) {
            cout << "Invalid Input! Try again." << endl;
            cin >> choice;
        }

        switch (choice) {
        case 1:
            // Customer service mode
            break;
        case 2:
            ownerObj.start_Owner();
            break;
        }
    }
};

int main()
{

    Menu MenuObj;
    MenuObj.MainMenu();

}
