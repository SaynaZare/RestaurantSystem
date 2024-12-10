#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

// Enum to represent the role of staff members
enum class StaffRole {
	Manager,
	Delivery,
	Receptionist,
	Chef,
	Customer
};

//base class for employees
class Staff {
protected:
	string Name;
	string Address;
	string PhoneNo;
	StaffRole Role;
public:
	// constructor
	Staff(string name, string address, string phoneNo, StaffRole role) : Name(name), Address(address), PhoneNo(phoneNo), Role(role) {}

	void DisplayStaffInfo()
	{
		cout << "Name: " << Name << endl
			<< "Address: " << Address << endl
			<< "Phone Number: " << PhoneNo << endl
			<< "Role: " << RoleToString() << endl;

	}

	string RoleToString()
	{
		switch (Role)
		{
		case StaffRole::Manager: return "Manager";
		case StaffRole::Delivery: return "Delivery";
		case StaffRole::Receptionist: return "Receptionist";
		case StaffRole::Chef: return "Chef";
		}
	}
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
protected:

public:

	Manager(string name, string address, string phoneNo) : Staff(name, address, phoneNo, StaffRole::Manager) {}

	void DisplayStaffInfo()
	{
		cout << "Role: Manager" << endl;
		Staff::DisplayStaffInfo();
	}
};

class Delivery : public Staff
{
protected:

public:

	Delivery(string name, string address, string phoneNo) : Staff(name, address, phoneNo, StaffRole::Delivery) {}

	void DisplayStaffInfo()
	{
		cout << "Role: Delivery" << endl;
		Staff::DisplayStaffInfo();
	}
};

class Receptionist : public Staff
{
protected:

public:

	Receptionist(string name, string address, string phoneNo) : Staff(name, address, phoneNo, StaffRole::Receptionist) {}

	void DisplayStaffInfo() {
		cout << "Role: Receptionist" << endl;
		Staff::DisplayStaffInfo();
	}
};

//gets customers info
class CustomerInfo : public Staff
{
protected:

	vector <Order> orders;
	string CustomerID = Name.substr(0, 5) + PhoneNo.substr(PhoneNo.length() - 2);
public:

	// Default constructor
	CustomerInfo() : Staff("", "", "", StaffRole::Customer), CustomerID("") {}

	// Parameterized constructor
	CustomerInfo(string name, string address, string phoneNo, string ID):Staff(name, address, phoneNo, StaffRole::Customer), CustomerID(ID){}


	void DisplayCustomerInfo()
	{
		cout << "Name: " << Name << endl
			<< "Address: " << Address << endl
			<< "Phone Number: " << PhoneNo << endl;
		cout << "Orders: " << endl;
		for (int i = 0; i < orders.size(); ++i)
		{
			orders[i].displayOrder(); // Call displayOrder on the Order object at index i
		}
	}

	void addName()
	{
		getline(cin >> ws, Name);
	}
	string getName()
	{
		return Name;
	}
	void addAdress()
	{
		getline(cin >> ws, Address);
	}
	string getAdress()
	{
		return Address;
	}

	void addPhoneNo()
	{
		getline(cin >> ws, PhoneNo);

		//validating user's input
		if (PhoneNo.length() > 11 || PhoneNo.length() < 11)
		{
			cout << "invalid input! try again." << endl;
			cout << "correct form: 073xxxxxxxx" << endl;
			getline(cin >> ws, PhoneNo);
		}
	}

	string getPhoneNo()
	{
		return PhoneNo;
	}

	void setItemName(const string& name)
	{
		Name = name;
	}

	void setPhoneNo(string p)
	{
		PhoneNo = p;
	}

	void setAddress(string address)
	{
		Address = address;
	}

	void addCustomerData()
	{
		CustomerInfo newCustomer;

		cout << "enter your name: " << endl;
		addName();
		cout << "enter your address: " << endl;
		addAdress();
		cout << "enter your phone number: " << endl;
		addPhoneNo();


	}
	void addOrder(Order order)
	{
		orders.push_back(order);
	}
	string getCustomerID()
	{
		return Name.substr(0, 5) + PhoneNo.substr(PhoneNo.length() - 2);
	}
};

//gets info for staff under chef catagory, staff base class is called in this class as well.
class Chef : public Staff {
private:
	string CuisineSpeciality;
public:
	Chef(string name, string address, string phoneNo, string cousine) : Staff(name, address, phoneNo, StaffRole::Chef), CuisineSpeciality(cousine) {}

	void DisplayStaffInfo()
	{
		cout << "Role: Chef" << endl;
		Staff::DisplayStaffInfo();
		cout << "cousine specialiy: " << CuisineSpeciality << endl;

	}

	string getCuisineSpeciality()
	{
		return CuisineSpeciality;
	}
	void setCuisineSpeciality(string& cuisine)
	{
		CuisineSpeciality = cuisine;
	}
};

// holds function that are related to food items, price, and availability
class FoodMenu
{
private:
	string Cuisine; // 1 = Italian,2 = persian
	string ItemName;
	int availability = 0; // value
	double price = 0;
	double PopularityRating = 0;
public:

	FoodMenu() = default;

	//get item name from user
	void addItem()
	{
		getline(cin >> ws, ItemName);
	}

	//get price from user
	void addPrice()
	{
		cin >> price;
	}

	void addAvailability()
	{
		cin >> availability;
	}


	void setItemName(const string& name) {
		ItemName = name;
	}

	void setPrice(double p) {
		price = p;
	}

	void setAvailability(int avail) {
		availability = avail;
	}
	//return name 
	string getname()
	{
		setItemName(ItemName);
		return ItemName;
	}
	double getPrice()
	{
		setPrice(price);
		return price;
	}
	//return price
	string getPriceforFile()
	{
		return to_string(price);
	}
	int getAvailability()
	{
		setAvailability(availability);
		return availability;
	}
	string getAvailabilityforFile()
	{
		return to_string(availability);
	}

	// getting all data from user about the food item by calling previous functions
	void addData()
	{
		cout << "enter new food item : " << endl;
		addItem();
		cout << "enter the price of " << ItemName << ": " << endl;
		addPrice();
		cout << "enter availability: " << endl;
		addAvailability();

	}

	void displayItemInfo()
	{
		cout << ItemName << endl;
		cout << availability << endl;
		cout << price << " pounds" << endl;
	}

	//loading information for food menu from the file

};

class Restaurant {
private:
	int limit;
	vector<FoodMenu> FoodItems;
	vector <CustomerInfo> customers;
	CustomerInfo customerObj;
public:
	//constructor
	Restaurant() : limit(0) {}

	//adding customers to a vector
	void CustomerVector(CustomerInfo customerObj)
	{
		customers.push_back(customerObj);
	}
	//display the customers vector
	void displayCustomersAndOrders(vector<CustomerInfo>& customers)
	{
		cout << "List of Customers:\n";

		for (int i = 0; i < customers.size(); i++)
		{
			customers[i].DisplayCustomerInfo();
			cout << endl;
		}
	}
	//adding items to the foodItem vector
	void addFoodData()
	{
		LoadFromFile_Food();
		FoodMenu foodobj;
		foodobj.addData();
		FoodItems.push_back(foodobj);
	}

	void displayFullMenu()
	{
		cout << "------------------------------------------------------------------------" << endl;
		cout << "|                           Restaurant Menu                            |" << endl;
		cout << "------------------------------------------------------------------------" << endl;

		for (int i = 0; i < FoodItems.size(); i++)
		{
			cout << "Item" << i + 1 << ": " << setw(19) << left << FoodItems[i].getname() << " | ";
			cout << "Price: " << setw(6) << fixed << setprecision(2) << FoodItems[i].getPrice() << " pounds | ";
			cout << "Availability: " << setw(3) << FoodItems[i].getAvailability() << "  |" << endl;
			cout << "------------------------------------------------------------------------" << endl;
		}


	}

	void displayFoodItems()
	{
		for (int i = 0; i < FoodItems.size(); i++)
		{
			cout << i + 1 << ". " << FoodItems[i].getname() << endl;
		}
	}

	void displayAvailability()
	{
		cout << "Food\tAvailability" << endl;
		for (int i = 0; i < FoodItems.size(); i++)
		{

			cout << i + 1 << ". " << FoodItems[i].getname() << ":\t" << FoodItems[i].getAvailability() << endl;
		}
	}

	void displayPrice()
	{
		cout << "Food\tAvailability" << endl;
		for (int i = 0; i < FoodItems.size(); i++)
		{

			cout << i + 1 << ". " << FoodItems[i].getname() << ":\t" << FoodItems[i].getPrice() << "Pounds" << endl;
		}
	}

	// adds staff info and holds them in different vectors for different job roles.
	void addStaff(vector<Staff*>& staff)
	{
		string Name;
		string Address;
		string PhoneNo;
		string CuisineSpeciality;
		int input;

		cout << "Enter Employee name: ";
		getline(cin >> ws, Name);

		cout << "Enter Employee address: ";
		getline(cin >> ws, Address);

		cout << "Enter Employee phone number: ";
		getline(cin >> ws, PhoneNo);

		cout << "Enter the Employee type: (1 for Receptionist, 2 for Delivery Staff, 3 for Manager, 4 for cheff) : ";
		cin >> input;
		if (input < 4 || input > 1)
		{

			switch (input)

			{
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
				cout << "enter cuisine speciality (Italian or Persian). " << endl;
				cin >> CuisineSpeciality;
				if (CuisineSpeciality != "Persian" && CuisineSpeciality != "persian" && CuisineSpeciality != "Italian" && CuisineSpeciality != "italian")
				{
					cout << "invalid input! try again." << endl;
					cin >> CuisineSpeciality;
				}
				staff.push_back(new Chef(Name, Address, PhoneNo, CuisineSpeciality));
				break;

			}
		}

		else
		{
			cout << "Inalid Input! try again. ";
			cin >> input;
		}
	}

	void setLimit()
	{

		cout << "enter the upperlimit for delivery orders.";
		cin >> limit;
		cout << "upper limit is saved!" << endl;

	}

	void displayUpperLimit()
	{
		cout << "upper limit has been set to " << limit << "orders for today" << endl;
	}

	void WriteToFile_Food()
	{
		ofstream outFile; // creating the fileobject
		outFile.open("FoodMenu.txt"); //opening the file
		outFile << FoodItems.size() << endl;
		for (int i = 0; i < FoodItems.size(); i++)
		{
			outFile << FoodItems[i].getname() << endl;
			outFile << FoodItems[i].getPrice() << endl;
			outFile << FoodItems[i].getAvailabilityforFile() << endl;
			//add a part that would indicate the cuisine type

			outFile << "CheckPoint" << endl; // seperating each Food item info by seting checkpoint

		}
		outFile.close(); // Close the file stream
	}

	vector<FoodMenu> LoadFromFile_Food()
	{
		vector<FoodMenu>loadedFoodItems;
		FoodMenu foodobj;
		ifstream InFile;
		InFile.open("FoodMenu.txt"); //opening file 

		if (!InFile)
		{
			cout << "Unable to open file FoodMenu.txt" << endl;

		}

		int size;
		InFile >> size;
		InFile.ignore(); // Consume newline character

		for (int i = 0; i < size; i++)
		{
			FoodMenu foodobj;
			string itemName, priceStr, availabilityStr, check;

			getline(InFile, itemName);
			getline(InFile, priceStr);
			getline(InFile, availabilityStr);
			getline(InFile, check); // Consume the "CheckPoint" line

			foodobj.setItemName(itemName);
			double price = stod(priceStr);
			int availability = stoi(availabilityStr);
			foodobj.setPrice(price);
			foodobj.setAvailability(availability);
			FoodItems.push_back(foodobj);
			loadedFoodItems.push_back(foodobj);
		}
		return loadedFoodItems;
		InFile.close();
	}

};

//owner menu
class Owner {

private:

	Restaurant Restaurantobj;
	FoodMenu foodobj;
	vector<Staff*> staff; // Initialize this vector
	vector<FoodMenu> FoodItems;
	bool progress;
	int option;

public:

	// Constructor to initialize member variables
	Owner() : progress(true), option(0) {}

	//display staff info
	void DisplayEmployee(vector<Staff*>& staff)
	{
		cout << "List of Employees:\n";

		// Loop through each staff member
		for (Staff* s : staff)
		{
			// Display common staff information
			s->DisplayStaffInfo();

			// Checking if the staff member is a Chef
			if (s->getRole() == StaffRole::Chef)
			{
				// Casting to Chef pointer
				Chef* chefPtr = static_cast<Chef*>(s);
				if (chefPtr) // Checking if the cast was successful
				{
					// Display cuisine specialty for Chef
					cout << "Cuisine Speciality: " << chefPtr->getCuisineSpeciality() << endl;
				}
			}

			cout << endl; // Add an empty line between each staff member's info
		}
	}
	vector<Staff*>& getStaff()
	{
		return staff;
	}

	//saving staff information on "staffInformation.txt
	void WriteToFile_Staff()
	{
		ofstream outputFile("staffInformation.txt"); // Creating the file object

		if (!outputFile.is_open()) // Check if the file is opened successfully
		{
			cout << "Unable to open file staffInformation.txt" << endl;
			return;
		}

		// Writing the number of staff members
		outputFile << staff.size() << endl;

		// Loop through each staff member
		for (size_t i = 0; i < staff.size(); i++)
		{
			// Writing common staff information
			outputFile << staff[i]->getName() << endl;
			outputFile << staff[i]->getAddress() << endl;
			outputFile << staff[i]->getPhoneNo() << endl;
			outputFile << "Role: " << staffRoleToString(staff[i]->getRole()) << endl;

			// Checking if the staff member is a Chef
			if (staff[i]->getRole() == StaffRole::Chef)
			{
				// Casting to Chef pointer
				Chef* chefPtr = static_cast<Chef*>(staff[i]);
				if (chefPtr) // Checking if the cast was successful
				{
					// Writing cuisine specialty for Chef
					outputFile << chefPtr->getCuisineSpeciality() << endl;
				}
			}

			// Adding a checkpoint to separate each staff info
			outputFile << "CheckPoint" << endl;

		}

		// Close the file stream
		outputFile.close();
	}
	void LoadFromFile_staff()
	{
		ifstream InFile;
		InFile.open("staffInformation.txt"); // Open the file

		// Other code...

		int size;
		InFile >> size;
		InFile.ignore(); // Consume newline character

		for (int i = 0; i < size; i++)
		{
			string name, address, phoneNo, roleStr, cuisine, check;
			getline(InFile, name);
			getline(InFile, address);
			getline(InFile, phoneNo);
			getline(InFile, roleStr);
			if (roleStr == "Role: Chef")
			{
				// Read cuisine if the role is Chef
				getline(InFile, cuisine);
			}
			getline(InFile, check); // Consume the "CheckPoint" line

			// Convert the role string to StaffRole enum
			StaffRole role;
			if (roleStr == "Role: Manager")
				role = StaffRole::Manager;
			else if (roleStr == "Role: Delivery")
				role = StaffRole::Delivery;
			else if (roleStr == "Role: Receptionist")
				role = StaffRole::Receptionist;
			else if (roleStr == "Role: Chef")
				role = StaffRole::Chef;
			else
			{
				cout << "Invalid role found in file!" << endl;
				continue; // Skip this staff member
			}

			// Create the appropriate derived class object based on role
			switch (role)
			{
			case StaffRole::Manager:
				staff.push_back(new Manager(name, address, phoneNo));
				break;
			case StaffRole::Delivery:
				staff.push_back(new Delivery(name, address, phoneNo));
				break;
			case StaffRole::Receptionist:
				staff.push_back(new Receptionist(name, address, phoneNo));
				break;
			case StaffRole::Chef:
				staff.push_back(new Chef(name, address, phoneNo, cuisine));
				break;
			}
		}

		InFile.close(); // Close the file stream
	}



	string staffRoleToString(StaffRole role)
	{
		switch (role)
		{
		case StaffRole::Manager:
			return "Manager";
		case StaffRole::Delivery:
			return "Delivery";
		case StaffRole::Receptionist:
			return "Receptionist";
		case StaffRole::Chef:
			return "Chef";
		}
	}



	void startOwner()
	{

		while (progress)
		{
			//owners main menu
			cout << "|------------------------------------------|" << endl;
			cout << "|       Choose from options provided       |" << endl;
			cout << "|------------------------------------------|" << endl;
			cout << "|1. Add staff.                             |" << endl;
			cout << "|2. display list of staff                  |" << endl;
			cout << "|3. Add food items.                        |" << endl;
			cout << "|4. list of food                           |" << endl;
			cout << "|5. manage and edit availability of itmes. |" << endl;
			cout << "|6. edit food price.                       |" << endl;
			cout << "|7. set upper limit for delivery.          |" << endl;
			cout << "|8. generate today's report.               |" << endl;
			cout << "|9. load previous data.                    |" << endl;
			cout << "|10. save and quit form owner menu.        |" << endl;
			cout << "|------------------------------------------|" << endl;

			cin >> option;
			// validating input before using the switch case.
			if (option > 10 || option < 1) {
				cout << "invalid input! try again." << endl;
				cin >> option;
			}

			switch (option)
			{
			case 1:
				Restaurantobj.addStaff(staff);
				break;
			case 2:
				DisplayEmployee(staff);
				break;
			case 3:
				Restaurantobj.addFoodData();
				break;
			case 4:
				cout << "list of food items: " << endl;
				Restaurantobj.displayFoodItems();
				break;
			case 5:

				Restaurantobj.displayAvailability();
				char ans;
				cout << " would you like to change any item's availability? (y/n) " << endl;
				cin >> ans;
				if (ans == 'y' || ans == 'Y')
				{
					int index;
					cout << " which items availability would you like to change? " << endl;
					cin >> index;
					FoodItems[index - 1].addAvailability();
					cout << "changes saved successfully " << endl;
				}
				else
				{
					progress = true;
				}
				break;
			case 6:

				Restaurantobj.displayPrice();

				int index;
				cout << " which items price would you like to change? " << endl;
				cin >> index;
				FoodItems[index - 1].addPrice();
				cout << "changes saved successfully " << endl;
				break;
			case 7:
				Restaurantobj.setLimit();
				break;
			case 8:
				break;
			case 9:
				Restaurantobj.LoadFromFile_Food();
				break;
			case 10:

				WriteToFile_Staff();
				Restaurantobj.WriteToFile_Food();

				cout << "Data saved successfully!" << endl;
				cout << "Exiting owner mode ..." << endl;

				progress = false;
				break;
			}
		}
	}
};

//customer menu 
class Customer
{
private:
	CustomerInfo customerObj;
	Restaurant Restaurantobj;
	FoodMenu foodobj;
	vector<CustomerInfo> customers;
	vector<FoodMenu> FoodItems;
	bool progress;
	int option;


public:

	// Constructor to initialize member variables
	Customer() : progress(true), option(0) {}

	//function to add customer and orders
	void addCustomerAndOrder() {
		string name, address, phone, customerID;
		int qty;
		double price;
		cout << "Enter customer details:" << endl;
		cout << "Name: ";
		getline(cin, name);
		cout << "Address: ";
		getline(cin, address);
		cout << "Phone: ";
		getline(cin, phone);
		CustomerInfo customer(name, address, phone,customerID);

		cout << "Enter order details:" << endl;
		cout << "Quantity: ";
		cin >> qty;
		cout << "Price per item: ";
		cin >> price;
		cin.ignore(); // Clear input buffer
		cout << "Item name: ";
		string itemName;
		getline(cin, itemName);
		Order order(itemName, qty, price);
		customer.addOrder(order);

		Restaurantobj.CustomerVector(customer);
	}

	

	void WriteToFile_Customer()
	{
		ofstream outputFile; // creating the file object
		outputFile.open("CustomerInformation.txt"); //opening the file

		outputFile << customers.size() << endl;

		for (int i = 0; i < customers.size(); i++)
		{
			outputFile << customers[i].getName() << endl;
			outputFile << customers[i].getAddress() << endl;
			outputFile << customers[i].getPhoneNo() << endl;
			outputFile << customers[i].getCustomerID() << endl;

			outputFile << "CheckPoint"; // seperating each staff info by setting checkpoint


		}
		outputFile.close(); // Close the file stream
	}

	void LoadFromFile_customer()
	{
		ifstream InFile;
		InFile.open("CustomerInformation.txt"); // Open the file

		if (!InFile)
		{
			cout << "Unable to open file CustomerInformation.txt" << endl;
			return; // Exit the function if file opening fails
		}

		int size;
		InFile >> size;
		InFile.ignore(); // Consume newline character

		for (int i = 0; i < size; i++)
		{
			string name, address, phoneNo, customerID, check;
			getline(InFile, name);
			getline(InFile, address);
			getline(InFile, phoneNo);
			getline(InFile, customerID);
			getline(InFile, check); // Consume the "CheckPoint" line

			// Create a new CustomerInfo object with the read data
			CustomerInfo newCustomer(name, address, phoneNo, customerID);

			// Store the new customer in the customers vector
			customers.push_back(newCustomer);
		}

		InFile.close(); // Close the file stream
	}




	//customer Main Menu
	void startCustomer()
	{
		while (progress) {
			cout << "|----------customer mode------------|" << endl;
			cout << "|press 1 for new customer           |" << endl;
			cout << "|press 2 for existing customers     |" << endl;
			cout << "|-----------------------------------|" << endl;

			cout << "enter your choice: ";
			cin >> option;

			//validating input
			while (option > 2 || option < 1)

			{
				cout << "invalid input! try again." << endl;
				cout << "enter your choice: ";
				cin >> option;

			}

			switch (option)
			{
			case 1:
				customerObj.addCustomerData();
				cout << "your information has been submitted." << endl;
				cout << "your unique customerID is " << customerObj.getCustomerID() << endl;
				customers.push_back(customerObj);
				WriteToFile_Customer();
				progress = false;
				break;
			case 2:
				LoadFromFile_customer();
				Restaurantobj.displayCustomersAndOrders(customers);
				string cID;
				cout << "welcome back!" << endl;
				cout << "what is your customerID? " << endl;
				cin >> cID;
				progress = false;
				break;
			}
		}
	}
};

class Order {
private:
	string itemName;
	int quantity;
	double pricePerItem;

public:
	// Constructor to initialize the order
	Order(string name, int qty, double price) : itemName(name), quantity(qty), pricePerItem(price) {}

	// Function to calculate total price for this order
	double getTotalPrice() const {
		return quantity * pricePerItem;
	}

	// Function to display order details
	void displayOrder() const {
		cout << quantity << " " << itemName << " - Price per item: " << pricePerItem << " Pounds" << endl;
		cout << "Total: " << getTotalPrice() << " Pounds" << endl;
	}
};
class Orders
{
private:
	vector<CustomerInfo> customers;
	Restaurant RestaurantObj;
	vector<FoodMenu> FoodItems;
	vector <Order> orderList;
	bool progress = true;
	int option = 0, quantity = 0;
	char ans;

public:

	void placeOrder()
	{
		// Load food items from file before displaying the menu
		FoodItems = RestaurantObj.LoadFromFile_Food();

		while (progress)
		{
			RestaurantObj.displayFullMenu();
			int size = FoodItems.size();
			cout << "Please select an item from the food menu: ";
			cin >> option;

			// Validate input based on FoodItems size
			if (option <= 0 || option > size)
			{
				cout << "Invalid input! Please try again." << endl;
				continue;
			}

			cout << "How many " << FoodItems[option - 1].getname() << " would you like to order? ";
			cin >> quantity;

			// Check if the quantity exceeds availability
			if (quantity > FoodItems[option - 1].getAvailability())
			{
				cout << "Sorry, only " << FoodItems[option - 1].getAvailability() << " items are left." << endl;
				continue;
			}

			// Create a new order object and add it to the order list
			Order newOrder(FoodItems[option - 1].getname(), quantity, FoodItems[option - 1].getPrice());
			orderList.push_back(newOrder);

			cout << "Order placed successfully!" << endl;
			cout << "Submitted!" << endl;

			cout << "Would you like to add to your order? (y/n) ";
			cin >> ans;

			if (ans != 'y' && ans != 'Y')
			{
				progress = false;
			}
		}
	}

	void addOrder( Order& order)
	{
		orderList.push_back(order);
	}

	// Function to display customers and orders
	void displayCustomersAndOrders() {
		RestaurantObj.displayCustomersAndOrders(customers);
	}

	void displayOrderedFood() 
	{
		for (size_t i = 0; i < orderList.size(); ++i) {
			orderList[i].displayOrder();
			cout << endl;
		}
	}
};
//main menu calls customer or owner menu 
class Menu {
private:
	Owner ownerobj;
	Customer customerobj;
	Orders orderobj;
	Restaurant RestaurantObj;
	int choice;
	bool keepgoing = true;

public:
	//constructor
	Menu() : choice(0) {}



	void menu() {

		while (keepgoing)
		{
			cout << "Restaurant Take-away system:        " << endl;
			cout << "press 1 for customer_experience mode" << endl;
			cout << "press 2 for owner_experience mode   " << endl;
			cout << "press 3 to exit the programm        " << endl;

			cout << "enter your choice:";
			cin >> choice;

			// validatig input
			if (cin.fail() || choice > 3 || choice < 1)
			{
				cout << "ivalid nput! try again." << endl;
				cin >> choice;
			}

			switch (choice)
			{
			case 1:
				customerobj.startCustomer();
				char ans;
				cout << "would you like to place an order? (y/n)" << endl;
				cin >> ans;
				if (ans == 'y' || ans == 'Y')
				{
					orderobj.placeOrder();
					orderobj.displayOrderedFood();
				}
				break;
			case 2:
				ownerobj.LoadFromFile_staff();
				ownerobj.startOwner();
				break;
			case 3:
				cout << "Goodbye!" << endl;
				keepgoing = false;
				break;

			}
		}
	}
};

//this will call the main menu and from there different classes and function will be called based on the requirements of the user.
int main()
{

	Menu MenuObj;

	MenuObj.menu();
}

