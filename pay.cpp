// Created by Nicholas Webster

#include "person.cpp"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <list>

void readData(vector<Person> &empVec) {

  string fName, lName, cName;
  int eID;
  float hWorked, pRate;
  Person newPerson;

  ifstream myFile("input.txt");

  while(myFile >> fName >> lName >> eID >> cName >> hWorked >> pRate) {
    newPerson.setFirstName(fName);
    newPerson.setLastName(lName);
    newPerson.setEmployeeId(eID);
    newPerson.setCompanyName(cName);
    newPerson.setHoursWorked(hWorked);
    newPerson.setPayRate(pRate);

    empVec.push_back(newPerson);
  }
  myFile.close();
}

void getCompanies(vector<Person> &empVec, vector<string> &cmpVec) {

  //set first element of cmpVec to first company name since
  // no possible duplicates with vector size of one
  cmpVec.push_back(empVec.at(0).getCompanyName());

  string newWord;

  // newWord is set to a companyName from empVec.
  // Then iteratres through cmpVec checking for duplicates.
  // If duplicate, break. If unique, push_back
  for (int i=1; i<empVec.size(); i++) {
    newWord = empVec.at(i).getCompanyName();
    for (int j=0; j<cmpVec.size(); j++) {
      if (cmpVec.at(j) == newWord) {
        break;
      } else {
        if (j == cmpVec.size() - 1) {
          cmpVec.push_back(newWord);
        }
      }
    }
  }
}

void printHighestPaid(vector<Person> &empVec) {

  int   arrayPos   = 0;
  float highestAmt = empVec.at(arrayPos).totalPay();

  for (int i=1; i<empVec.size(); i++) {
    if (empVec.at(i).totalPay() > highestAmt) {
      highestAmt = empVec.at(i).totalPay();
      arrayPos = i;
    }
  }
  cout << "Highest paid: " << empVec.at(arrayPos).fullName() << endl;
  cout << "Employee ID: " << empVec.at(arrayPos).getEmployeeId() << endl;
  cout << "Employer: " << empVec.at(arrayPos).getCompanyName() << endl;
  cout << "Total Pay: $" << setprecision(2) << fixed
                        << empVec.at(arrayPos).totalPay() << endl;

}

void seperateAndSave(vector<Person> &empVec, vector<string> &cmpVec) {



  for(int j = 0; j<cmpVec.size(); j++) {
    ofstream myFile(cmpVec.at(j) + ".txt");
    float cmpTotalPay = 0;
    for(int i=0; i<empVec.size(); i++) {
      if(empVec.at(i).getCompanyName() == cmpVec.at(j)) {
        cmpTotalPay += empVec.at(i).totalPay();
        myFile << setw(9) << left << empVec.at(i).getFirstName() << " "
               << setw(9) << left << empVec.at(i).getLastName() << " "
               << setw(3) << right << empVec.at(i).getEmployeeId() << " "
               << setw(10) << left << empVec.at(i).getCompanyName() << " $"
               << setprecision(2) << fixed
               << empVec.at(i).totalPay() << endl;
      }
    }
    myFile << "Total: $" << cmpTotalPay << endl;
    myFile.close();
  }
}

int main () {

  vector<Person> employees;
  vector<string> companyNames;

  readData(employees);

  getCompanies(employees, companyNames);

  printHighestPaid(employees);

  seperateAndSave(employees, companyNames);

}
