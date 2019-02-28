// Created by Nicholas Webster

#include "person.cpp"
#include <iostream>
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
  myFile.close();
}

void getCompanies(vector<Person> &empVec, vector<string> &cmpVec) {

  string tmp, it;

  for (int i=0; i<empVec.size(); i++) {
    cmpVec.push_back(empVec.at(i).getCompanyName());
  }

  tmp = cmpVec.at(0);
  for(it = cmpVec.begin(); it != cmpVec.end(); it++) {
    if(it == tmp) {
      cmpVec.erase(cmpVec.at(tmp));
    }
  }

  cout << "There are " << cmpVec.size() << " companies." << endl; //testing

  // for (int i=0; i<empVec.size(); i++) {
  //   cmpVec.push_back(empVec.at(i).getCompanyName());
  // }

  // for (it = cmpVec.begin(); it != cmpVec.end(); it++) {
  //   if (tmp == it) {
  //     cmpVec.erase();
  //   }
  // }

}


void printHighestPaid() {

}

void seperateAndSave() {

}

int main () {

  vector<Person> employees;
  vector<string> companyNames;

  readData(employees);

  getCompanies(employees, companyNames);

//  printHighestPaid(vector employees);

//  seperateAndSave(vector employees, vector companyNames);

}
