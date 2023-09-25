// ObjectPool.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

#include <iostream>
#include <vector>
using namespace std; // don't default to using this, I'm just lazy

// Class for the computer
class Computer
{
public:
    // Computer constructor and destructor
    Computer(string EmployeeName) { User = EmployeeName; };
    ~Computer() {};

    // Properties of the computer
    string User;
};

// Class for the supply shop
class Shop
{
public:
    // Shop constructor and destructor
    Shop() {};
    ~Shop() {};

    // Create a computer instance and assign it to an employee
    void BuyComputer(vector<Computer>& Computers, string EmployeeName) { Computers.push_back(Computer(EmployeeName)); }
};

// Class for a company that uses computers
class Company
{
public:
    // Company constructor and destructor
    Company() { Supplier = new Shop(); };
    ~Company() {};

    // List of computers used by employees
    vector<Computer> Computers;

    // The supplier the company uses for their computers
    Shop* Supplier;

    // Function to hire an employee and give them a computer
    void HireEmployee(string EmployeeName) { Supplier->BuyComputer(Computers, EmployeeName); cout << "Hired " << EmployeeName << endl; }

    // Function to fire an employee and delete their computer
    void FireEmployee(string EmployeeName)
    {
        // Loop through all the computers
        for (vector<Computer>::iterator Looper = Computers.begin(); Looper != Computers.end(); Looper++)
        {
            // If the computer's user name matches the fired employee
            if (Looper->User == EmployeeName)
            {
                // Erase the computer from the list of computers and shrink the list to fill the gap
                Computers.erase(Looper);
                Computers.shrink_to_fit();
                cout << EmployeeName << " fired.\n";
                return;
            }
        }
        // If we get here, we don't have an employee by that name
        cout << "Employee " << EmployeeName << " not found.\n";
    }
};

int main()
{
    // Make a company
    Company BusinessCo = Company();

    // Hire a few employees
    string Names[100] = {"Dangelo Nielsen", "Adam Shelton", "Wendy Olson", "Danny Petersen", "Miriam Roy", "Ali Copeland", "Justice Harris", "Kaliyah Curtis", "Macey Vaughn", "Kinley Madden", "Jayden Bowman", "Ashly Marks", "Carmen Christian", "Brooks Berger", "Willow Cunningham", "Alexis Stark", "Brynn Mcdaniel", "Kasey Fields", "Dalton Poole", "Aldo Crosby", "Franco Drake", "Alexis Green", "Maurice Brewer", "Marcos Gordon", "Sharon Crawford", "Kareem Melton", "Cheyenne Stafford", "Deon Schultz", "Jeffrey Fuentes", "Johnathan Ortiz", "Bella Cherry", "Julianne Vaughan", "Braylon Villarreal", "Maritza Shea", "Abigail Gentry", "Karma Mcfarland", "Samir Lucas", "Zaria Perez", "Myles Booth", "Catalina Bartlett", "Leland Bruce", "Janessa Boone", "Rebekah Santiago", "Cason Gordon", "Turner Foster", "Alison Escobar", "Christopher Salas", "Lisa Wyatt", "Jakobe Finley", "Bailey Bryant", "Carolyn Owen", "Brenda Foley", "Danielle Carney", "Jose Stokes", "Diamond Tanner", "Cara Lewis", "Camren Hines", "Keon Mcbride", "Nigel Pratt", "Kristen Hancock", "Maeve Waters", "Haley Wilkinson", "Landyn Gordon", "Renee Wu", "Rebecca Heath", "Kasen Ballard", "Daniela Wilkinson", "Alexandra Blankenship", "Deacon Andersen", "Zane Fowler", "Jair Steele", "David Curtis", "Kolton Roberson", "Kael Castaneda", "Jovany Cervantes", "George Lynch", "Makenna Nixon", "Gilberto Eaton", "Alma Oliver", "Bryson Mora", "Anna Sexton", "Dylan Banks", "Nolan Edwards", "Eleanor Cobb", "Kenny Ballard", "Rowan Conrad", "Ayanna Kelly", "Jesus Boyer", "Dexter Ford", "Darien Mcintosh", "Mckayla Kline", "Aliza Adkins", "Cameron Mcclure", "Georgia Jensen", "Gilberto Gutierrez", "Jimena Cortez", "Todd Joseph", "Kelton Michael", "Julia Boyer", "Jesus Stewart"};
    for (string Name : Names) BusinessCo.HireEmployee(Name);

    // Fire some employees
    BusinessCo.FireEmployee("Danny Petersen");
    BusinessCo.FireEmployee("Makenna Nixon");
    BusinessCo.FireEmployee("Nigel Pratt");
    BusinessCo.FireEmployee("Cameron Mcclure");

    // Hire replacements
    BusinessCo.HireEmployee("Alice Allison");
    BusinessCo.HireEmployee("Bob Bobson");
    BusinessCo.HireEmployee("Chuck Charlson");
    BusinessCo.HireEmployee("David Davidson");
}

