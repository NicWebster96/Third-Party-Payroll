// Created by Nicholas Webster

#include "person.cpp"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

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
  //testing
  cout << "There are " << empVec.size() << " employees in readData. (should be 16)" << endl;

  myFile.close();
}

void getCompanies(vector<Person> &empVec, vector<string> &cmpVec) {

  //testing that empVec is correct
  cout << "There are " << empVec.size() << " employees in getCompanies. (should be 16)" << endl;
  //testing that cmpVec is empty
  cout << "There are " << cmpVec.size() << " companies in cmpVec before. (should be 0)" << endl;

  //first company name is pushed back since there cannot be
  // any duplicates with only one element
  cmpVec.push_back(empVec.at(0).getCompanyName());
  cout << "First company pushed back to cmpVec is " << cmpVec.at(0) << endl;

  string newWord;

  // newWord is set to a companyName from empVec
  // for loop iteratres through cmpVec checking for duplicates
  // if duplicate, break. If unique, push_back
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
  //testing after removing duplicates
  cout << "There are " << cmpVec.size() << " companies in cmpVec after. (should be 5)" << endl;

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

void seperateAndSave() {

}

int main () {

  vector<Person> employees;
  vector<string> companyNames;

  readData(employees);

  getCompanies(employees, companyNames);

  printHighestPaid(employees);

//  seperateAndSave(employees, companyNames);

}
