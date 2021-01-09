#include <iostream>
#include <string>
#include "NewerManagement.h"
using namespace std;

NewerManagement :: NewerManagement(string newTenant_FileName, string newManager_FileName):
NewManagement(newTenant_FileName, newManager_FileName)
{
}

NewerManagement :: ~NewerManagement(){}

//Searches the Tenant array for the specified Tenant and gives option to modify it.
void NewerManagement :: searchAndModifyTenant(string tenantName)
{
 //Declaring variables   
 int userInput;  
 int tenantIndex = 0; 

 //Scans through the entire Tenant Array  
 for(int i = 0; i < 100; i++)
 {
  //If it finds a name that matches user entered search name.  
  if(tenantArr[i].getName() == tenantName)
  {
   //Saves the current index where the tenant was found.   
   tenantIndex = i;
   cout << "\n" << "Tenant found!" << "\n";
   break;
  }
 }
 
 //Creates a copy of the found Tenant and displays it's info.
 Tenant newTenant = tenantArr[tenantIndex];
 newTenant.printInfo();
 //Asks for UserInput before continuing.
 cout << "\n";
 cout << "Would you like to modify this Tenant?" << "\n";
 cout << "Press 1 to Modify this current Tenant." << "\n";
 cout << "Press 0 to Exit." << "\n";
 cin >> userInput;

 //If the User decides they want to modify the searched Tenant
 if(userInput == 1)
 {
   //Calls the modifyTenant function and stores the result in a newly created Tenant.  
   Tenant updatedTenant = modifyTenant(newTenant);
   //Overrides the Tenant stored in the array with the newly updated Tenant.
   tenantArr[tenantIndex] = updatedTenant; 
   cout << "\n" << "Tenant has been modified!" << "\n";
 }
}

//Takes in a Tenant object and provides a User Interface to modify the components within the given tenant object.
Tenant NewerManagement :: modifyTenant(Tenant newTenant)
{
  //Declaring variable to hold new data.  
  int userInput, newUnitNumber, newAge, newDay, newMonth, newYear;
  double newRent;
  string newName, newFirstName, newLastName, newGender, newJob;  

  //User Interface for modification
  cout << "\n";
  cout << "What field would you like to modify?" << "\n";
  cout << "Press 1 for Name." << "\n";
  cout << "Press 2 for Age." << "\n";
  cout << "Press 3 for Gender." << "\n";
  cout << "Press 4 for Job." << "\n";
  cout << "Press 5 for unit number." << "\n";
  cout << "Press 6 for move-in date." << "\n";
  cout << "Press 7 for monthly rent." << "\n";
  cout << "Press 0 to quit." << "\n";
  cin >> userInput;

  //While loop that continues to modify Tenant object until User is satisfied.
  while(userInput != 0)
  {
    if(userInput == 1)
    {
      cout << "Enter new First Name: ";
      cin >> newFirstName;
      cout << "Enter new Last Name: ";
      cin >> newLastName;
      newName = newFirstName + " " + newLastName;
      newTenant.setName(newName);
      cout << "Name of Tenant has been changed!" << "\n";  
    }

    if(userInput == 2)
    {
      cout << "Enter new Age: ";
      cin >> newAge;
      newTenant.setAge(newAge);
      cout << "Age of Tenant has been changed!" << "\n";
    }

    if(userInput == 3)
    {
      cout << "Enter new Gender: ";
      cin >> newGender;
      newTenant.setGender(newGender);
      cout << "Geneder of Tenant has been changed!" << "\n";
    }

    if(userInput == 4)
    {
      cout << "Enter new Job: ";
      cin >> newJob;
      newTenant.setJob(newJob);
      cout << "Job of Tenant has been changed!" << "\n";
    }

    if(userInput == 5)
    {
      cout << "Enter new Unit Number: ";
      cin >> newUnitNumber;
      newTenant.setUnitNumber(newUnitNumber);
      cout << "Unit Number of Tenant has been changed!" << "\n";
    }

    if(userInput == 6)
    {
      cout << "Enter the new Move In Date: " << "\n";
      cout << "Enter Day: ";
      cin >> newDay;
      cout << "\n" << "Enter Month: ";
      cin >> newMonth;
      cout << "\n" << "Enter Year: ";
      cin >> newYear;
      Date newDate(newDay, newMonth, newYear); 
      newTenant.setMovingIn_Date(newDate);
      cout << "Move In Date of Tenant has been changed!" << "\n";
    }

    if(userInput == 7)
    {
      cout << "Enter new Monthly Rent: ";
      cin >> newRent;
      newTenant.setMonthlyRent(newRent);
      cout << "Monthly Rent of Tenant has been changed!" << "\n";
    }
    
    newTenant.printInfo();
    cout << "\n";
    cout << "What field would you like to modify?" << "\n";
    cout << "Press 1 for Name." << "\n";
    cout << "Press 2 for Age." << "\n";
    cout << "Press 3 for Gender." << "\n";
    cout << "Press 4 for Job." << "\n";
    cout << "Press 5 for unit number." << "\n";
    cout << "Press 6 for move-in date." << "\n";
    cout << "Press 7 for monthly rent." << "\n";
    cout << "Press 0 to quit." << "\n";
    cin >> userInput;
  }
  
  //Returns the newly updated Tenant.
  Tenant updatedTenant = newTenant;
  return updatedTenant;
}

void NewerManagement :: displayAndModifyManagers()
{
 int userInput, index;

 //Goes through Manager Array and prints it out.  
 for(int i = 0; i < 2; i++)
 {
   managerArr[i].printInfo();
   cout << "\n";   
 }   

 //Prompts user to ask if they want to modify one of the managers.
 cout << "\n" << "Would you like to modify these Managers?" << "\n";
 cout << "Press 1 to Modify a Manager." << "\n";
 cout << "Press 0 to Exit." << "\n";
 cin >> userInput;
 
 while(userInput != 0)
 {
  //Prompts user to decide on which manager to modify.   
  cout << "\n" << "Which Manager would you like to Modify?" << "\n";
  cout << "Press 1 to Modify Manager 2." << "\n";
  cout << "Press 2 to Modify Manager 3." << "\n";
  cout << "Press 0 to Exit." << "\n";
  
  //If statements that modifiy the chosen manager, then updates the manager array.
  if(userInput == 2)
  {
    Manager newManager = managerArr[0];   
    Manager updatedManager = modifyManager(newManager);
    managerArr[0] = updatedManager;
    cout << "Manager has been modified!" << "\n";
  }

  if(userInput == 3)
  {
    Manager newManager = managerArr[1];   
    Manager updatedManager = modifyManager(newManager);
    managerArr[1] = updatedManager;
    cout << "Manager has been modified!" << "\n";
  }

  cout << "\n" << "Would you like to modify these Managers?" << "\n";
  cout << "Press 1 to Modify a Manager." << "\n";
  cout << "Press 0 to Exit." << "\n";
  cin >> userInput;
 }
}

//Modifies data stored in one of two manager Objects.
Manager NewerManagement :: modifyManager(Manager newManager)
{
 //Initializing variables.  
 string newFirstName, newLastName, newName, newGender;
 int userInput, newAge, newDay, newMonth, newYear;
 double newSalary, newBonus;

 //User interface for manager modifcation.
 cout << "\n";
 cout << "What would you like modify?" << "\n";
 cout << "Press 1 for Name." << "\n";
 cout << "Press 2 for Age." << "\n";
 cout << "Press 3 for Gender." << "\n";
 cout << "Press 4 for Hired date." << "\n";
 cout << "Press 5 for Salary." << "\n";
 cout << "Press 6 for Bonus." << "\n";
 cout << "Press 0 to Exit." << "\n";
 cin >> userInput;

 //While loop that continues to modify Manager object until User is satisfied.
 while(userInput != 0)
 {
  if(userInput == 1)
  {
   cout << "Enter new First Name: ";
   cin >> newFirstName;
   cout << "Enter new Last Name: ";
   cin >> newLastName;
   newName = newFirstName + " " + newLastName;
   newManager.setName(newName);
   cout << "Name of Manager has been changed!" << "\n";  
  }
  
  if(userInput == 2)
  {
   cout << "Enter new Age: ";
   cin >> newAge;
   newManager.setAge(newAge);
   cout << "Age of Manager has been changed!" << "\n";
  }

  if(userInput == 3)
  {
   cout << "Enter new Gender: ";
   cin >> newGender;
   newManager.setGender(newGender);
   cout << "Gender of Manager has been changed!" << "\n";
  }
  
  if(userInput == 4)
  {
   cout << "Enter the new Hired Date: " << "\n";
   cout << "Enter Day: ";
   cin >> newDay;
   cout << "\n" << "Enter Month: ";
   cin >> newMonth;
   cout << "\n" << "Enter Year: ";
   cin >> newYear;
   Date newDate(newDay, newMonth, newYear); 
   newManager.setHired_Date(newDate);
   cout << "Hired Date of Manager has been changed!" << "\n";
  }

  if(userInput == 5)
  {
   cout << "Enter new Salary: " << "\n";
   cin >> newSalary;
   newManager.setSalary(newSalary);
   cout << "Salary of Manager has been changed!" << "\n";
  }

  if(userInput == 6)
  {
   cout << "Enter new Bonus: " << "\n";
   cin >> newBonus;
   newManager.setBouns(newBonus);
   cout << "Bonus of Manager has been changed!" << "\n";
  }
  
  cout << "\n";
  cout << "What would you like modify?" << "\n";
  cout << "Press 1 for Name." << "\n";
  cout << "Press 2 for Age." << "\n";
  cout << "Press 3 for Gender." << "\n";
  cout << "Press 4 for Hired date." << "\n";
  cout << "Press 5 for Salary." << "\n";
  cout << "Press 6 for Bonus." << "\n";
  cout << "Press 0 to Exit." << "\n";
  cin >> userInput;
 }
 
 //Returns the newly modified manager.
 Manager updatedManager = newManager;
 return updatedManager;
}