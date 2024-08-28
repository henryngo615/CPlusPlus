/* 
 PROGRAMMER:       	Henry Ngo 
 Program Description: Read student records to struct and manipulate the student data.    
*/ 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cassert>

using namespace std;
#include "type.h"

//global constants
const int MAX_STUDENTS = 100; 

// functions prototypes 
int ReadStudents(ifstream &infile, StudentType student[]); 
void PrintStudents(StudentType student[], int numOfStudents); 
void PrintSingle(StudentType &student); 
int ValidClass(StudentType student[], int numOfID, string StudentID); 
void SortStudent(StudentType student[], int numOfID); 

int main() {
  StudentType student[MAX_STUDENTS]; 
  string StudentID; 
  bool StudentSearch= false; 
  ifstream infile;
  int numOfStudents; 
  int StudentIndex; 
  infile.open("grades.dat");
  assert(infile);  

  char c;
  string temp; 
  infile.get(c); 
  infile.get(c); 

  getline(infile, temp); 
cout << "CLass" << temp << endl;

  numOfStudents = ReadStudents(infile, student); 
  PrintStudents(student, numOfStudents); 

  cout << "Enter a valid Class ID: "; 
  getline(cin, StudentID);

  while(StudentSearch == false){
    StudentIndex = ValidClass(student, numOfStudents, StudentID); 
    if (StudentIndex == -1){
      cout << endl;
      cout << "Enter a valid Class ID: "; 
      getline(cin, StudentID);

    }
    else{
      PrintSingle(student[StudentIndex]);
      StudentSearch = true;  
    } 
  }

  cout << "Sorting student records by name . . .\n" << endl; 
  SortStudent(student, numOfStudents); 
  PrintStudents(student, numOfStudents); 


  infile.close(); 
  return 0;
}

int ReadStudents(ifstream &infile, StudentType student[]){
  int index = 0; 
  int numOfStudents = 0; 
  
  while (index < MAX_STUDENTS && infile >> student[index].c_number){
    infile >> student[index].name;
    infile >> student[index].cla; 
    infile >> student[index].ola;
    infile >> student[index].quiz;
    infile >> student[index].homework;
    infile >> student[index].exam;
    infile >> student[index].bonus;
    index++;

  }
  numOfStudents = index; 
  return numOfStudents; 
}

void PrintStudents(StudentType student[], int numOfStudents){
  cout << "Here is the information of the " << numOfStudents << " students:\n" << endl; 
  cout << left << setw(15) << "ClassID" << setw(18) << "Name" << setw(15) << "CLA" << setw(14) << "OLA" << setw(11) << "Quiz" << setw(19) << "Homework" << setw(13) << "Exam" << "Bonus\n" << endl; 
  
  for (int i = 0; i < numOfStudents; i++){
    cout << setw(15) << student[i].c_number << setw(18) << student[i].name << setw(15) << student[i].cla << setw(14) << student[i].ola << setw(11) << student[i].quiz << setw(19) << student[i].homework << setw(13) << student[i].exam << student[i].bonus << endl; 
  }
  cout << endl;
}

void PrintSingle(StudentType &student){
  cout << "Information for student with ID: " << student.c_number << endl; 
  cout << "Name: " << student.name << endl; 
  cout << "CLA: " << student.cla << endl; 
  cout << "OLA: " << student.ola << endl; 
  cout << "Quiz: " << student.quiz << endl; 
  cout << "Homework: " << student.homework << endl; 
  cout << "Exam: " << student.exam << endl; 
  cout << "Bonus: " << student.bonus << endl; 
  cout << endl;
}

int ValidClass(StudentType student[], int numOfID, string StudentID){
  int SearchIndex; 
  for (int i = 0; i < numOfID; i++){
    if (StudentID == student[i].c_number){
      return i;
    }
  }
    return -1; 
}

void SortStudent(StudentType student[], int numOfID){
  bool sorted = false; 
  StudentType temp; 
  int last = numOfID - 1; 

  while(!sorted){
    sorted = true; 
    for (int i = 0; i < last; i++){
      if(student[i].name > student[i + 1].name){
        temp = student[i];
        student[i] = student[i+1]; 
        student[i + 1] = temp; 
        sorted = false;

      }
    }
    last--; 
  }
  return;
}