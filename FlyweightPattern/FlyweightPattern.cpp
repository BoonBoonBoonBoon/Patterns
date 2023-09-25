// FlyweightPattern.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
using namespace std;

// Add a salary between 20,000 and 40,000 to list
void AddSalary(vector<int>& salaries)
{
    salaries.push_back(rand() % 20000 + 20000);
}

// Print salary at index
void PrintSalary(vector<int> salaries, int index)
{
    cout << index << ": " << salaries[index] << endl;
}

int main()
{
    // Decide how many salaries to make
    int count = 10000;

    // Create a list of salaries, keeping track of how long it takes to make the list
    vector<int> salaries;
    auto MakeStart = chrono::high_resolution_clock::now();
    for (int index = 0; index < count; index++) AddSalary(salaries);
    chrono::duration<double> MakeElapsed = chrono::high_resolution_clock::now() - MakeStart;

    // Print all salaries
    auto PrintStart = chrono::high_resolution_clock::now();
    for (int index = 0; index < count; index++) PrintSalary(salaries, index);
    chrono::duration<double> PrintElapsed = chrono::high_resolution_clock::now() - PrintStart;

    // Print results
    cout << "Time elapsed to populate list: " << MakeElapsed.count() << " seconds\n";
    cout << "Time elapsed to print list: " << PrintElapsed.count() << " seconds\n";
}

