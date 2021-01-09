#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "Management.h"
#include "Management.cpp"
#include "Date.h"
#include "Date.cpp"
#include "Manager.h"
#include "Manager.cpp"
#include "NewManagement.h"
#include "NewManagement.cpp"
#include "Person.h"
#include "Person.cpp"
#include "Tenant.h"
#include "Tenant.cpp"
#include "NewerManagement.h"
#include "NewerManagement.cpp"
using namespace std;

int main()
{
 int userInput;
 string firstName, lastName, searchedName;

 //Creates two Management objects that take in the names of the CSV files
 NewerManagement management1("Tenants.csv", "Managers.csv");
 NewerManagement management2("Tenants2.csv", "Managers2.csv");

 cout << "Reading in .CSV files..." << "\n";
 //Reads all of the input files for both Management objects.
 management1.readTenantFile();
 management1.readManagerFile();
 management2.readTenantFile();
 management2.readManagerFile();
 cout << ".CSV files succesfully loaded!" << "\n";

 cout << "\n";
 cout << "What would you like to do?" << "\n";
 cout << "Press 1 to Search for a Tenant." << "\n";
 cout << "Press 2 to Display managers." << "\n";
 cout << "Press 0 to Exit." << "\n";
 cin >> userInput;

 //General User Interaface
 while(userInput != 0)
 {
   if(userInput == 1)
   {
     cout << "Enter First Name of Tenant: ";
     cin >> firstName;
     cout << "Enter Last Name of Tenant: ";
     cin >> lastName;
     searchedName = firstName + " " + lastName;
     management1.searchAndModifyTenant(searchedName);
   }
  
   if(userInput == 2)
   {
    management1.displayAndModifyManagers();
   }

   cout << "What would you like to do?" << "\n";
   cout << "Press 1 to Search for a Tenant." << "\n";
   cout << "Press 2 to Display managers." << "\n";
   cout << "Press 0 to Exit." << "\n";
   cin >> userInput;
 }


 return 0;   
}

