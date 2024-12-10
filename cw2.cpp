#include <iostream>
#include <vector>
#include <string>
using namespace std;

//base class
class Staff {
protected:
	string Name;
	string Address;
	string PhoneNo;
public:
	// constructor
	Staff(string name, string address, string phoneNo) : Name(name), Address(address), PhoneNo(phoneNo) {}
	
	void DisplayStaffInfo()
	{
		cout << "Name: " << Name << endl
			<< "Address: " << Address << endl
			<< "Phone Number: " << PhoneNo << endl;
	}
};

class Manager : public Staff 
{
protected:

public:
	
	Manager(string name, string address, string phoneNo) : Staff(name, address, phoneNo) {}

	void DisplayStaffInfo()
	{
		cout << "Name: " << Name << endl
			<< "Address: " << Address << endl
			<< "Phone Number: " << PhoneNo << endl;
	}
};
	
class Receptionist : public Staff
{
protected:

public:

	Receptionist(string name, string address, string phoneNo) : Staff(name, address, phoneNo) {}

	void DisplayStaffInfo()
	{
		cout << "Name: " << Name << endl
			<< "Address: " << Address << endl
			<< "Phone Number: " << PhoneNo << endl;
	}
};
class Delivery : public Staff
{
protected:

public:

	Delivery(string name, string address, string phoneNo) : Staff(name, address, phoneNo) {}

	void DisplayStaffInfo()
	{
		cout << "Name: " << Name << endl
			<< "Address: " << Address << endl
			<< "Phone Number: " << PhoneNo << endl;
	}
};


class Chef : public Staff{
private:
	string CuisineSpeciality;
public:
Chef(string name, string address, string phoneNo, string cousine) : Staff(name, address, phoneNo), CuisineSpeciality(cousine){}

	void DisplayCheffInfo()
	{
		cout << "Name: " << Name << endl
			<< "Address: " << Address << endl
			<< "Phone Number: " << PhoneNo << endl
			<< "cousine specialiy: " << CuisineSpeciality << endl;

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
void DisplayEmployee(vector<Staff*>& staff) 
{
	for (Staff* s : staff)
	{
		cout << "\n\n * *Staff * *\n\n";
		s->DisplayStaffInfo();
	}
}

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
	getline(cin >>ws, PhoneNo);

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
			staff.push_back(new Chef(Name, Address, PhoneNo, CuisineSpeciality));
			break;

	    }
	}
	else {
		cout << "Inalid Input! try again. ";
		cin >> input;
	
	
	}
}

class FoodMenu
{
private:
	string Cuisine; // 1 = Italian,2 = persian
	string ItemName;
	int Size = 5; // its assumed that each cuisine has 5 different dishes/items.
	int Availability[10];
	double price;
	double PopularityRating;
public:

	string list1[5] = { "Pasta", "Pizza", "Gelato", "Lasagna", "Rissoto" };
	double price1[5] = { 8, 12, 3.5 , 6, 10 };
	string list2[5] = { "Kebab", "Tahchin", "Fesenjoon", "Dolme", "Abgoosht" };
	double price2[5] = { 12, 8.5, 7, 4, 5 };
	
	//string* list1 = new string[Size];
	//string* list2 = new string[Size];

	// prints out Italian cuisine list
	void displaylist1()
	{
		for (int i = 0; i <= Size; i++) 
		{
			cout << list1[i];
		}
	}

	// prints out Persian cuisine list
	void displaylist2()
	{
		for (int i = 0; i <= Size; i++)
		{
			cout << list2[i];
		}
	}
	void editAlllist1() 
	{
		for (int i = 0; i <= Size; i++)
		{
			cout << "enter new items for Italian cuisine: " << endl;
			cout << i + 1 << ". Item: ";
			cin >> list1[i];
		}

	}
	void editAlllist2()
	{
		for (int i = 0; i <= Size; i++)
		{
			cout << "enter new items for Persian cuisine: " << endl;
			cout << i + 1 << ". Item: ";
			cin >> list2[i];
		}

	}
	void editOneItemlist1()
	{
		int input;
		// display the list
		cout << "choose which item would you like to change? " << endl;
			cin >> input;
			cout << "enter new item: ";
			getline(cin >> ws, list1[input - 1]);
	}
	void editOneItemlist2()
	{
		int input;
		// display the list
		cout << "choose which item would you like to change? " << endl;
		cin >> input;
		cout << "enter new item: ";
		getline(cin >> ws, list2[input - 1]);
	}
	void inputAvailability()
	{
		for (int i = 0; i <= Size; i++)
		{
				cout << "enter the availability of " << list1[i] << ": ";
				cin >> Availability[i];
		}
		for (int i = 0; i <= Size; i++)
		{
				cout << "enter the availability of " << list2[i] << ": ";
				cin >> Availability[i + 5];
		}
	}
};

class Menu {
private:
	int choice;
public:
	void menu() {
		cout << "Restaurant Take-away system: " << endl;
		cout << "press 1 for customer experience mode" << endl;
		cout << "press 2 for owner experience mode" << endl;

		cin >> choice;
		// validatig input
		if (cin.fail() || choice > 2 || choice < 1)
		{
			cout << "ivalid nput! try again." << endl;
			cin >> choice;
		}

		switch (choice) 
		{
		case 1:
			// customer service mode
			break;
		case 2:
			// owner mode
			break;

		}

	}
};
