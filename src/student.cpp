/* @Author
 * Student Name:  İbrahim Taha Tüzgen
 * Student ID : 150210717
 */

#include <string>
#include <iostream>
#include "student.h"

using namespace std;

Student::Student() // This is the default constructor for the "Student" class.
{   
    cout << "Undefined student logged in to the system." << endl;
}

Student::Student(string name, float GPA, int GRE, int TOEFL) // This constructor is to assign the given initial values to the created object.
{
    set_name(name);
    set_GPA(GPA);
    set_GRE(GRE);
    set_TOEFL(TOEFL);
    cout << name + " logged in to the system." << endl;
}

Student::Student(const Student &originalStudent) // This copy constructor assigns the every member value of the given Student to the new Student object in its initializer.
    : name{originalStudent.name}, GPA{originalStudent.GPA}, GRE{originalStudent.GRE}, TOEFL{originalStudent.TOEFL}, numberOfApplications{originalStudent.numberOfApplications}
{
    cout << name + " logged in to the system." << endl;
}

Student::~Student() // This destructor is for the log out message.
{
    cout << name + " logged out of the system with " + to_string(numberOfApplications) + " application(s)" << endl;
}
// Getters and setters of this class are assigning and returning the member values directly without any controll.
string Student::get_name() const
{
    return this->name;
}

void Student::set_name(string name)
{
    this->name = name;
}

float Student::get_GPA() const
{
    return this->GPA;
}

void Student::set_GPA(float GPA)
{
    this->GPA = GPA;
}

int Student::get_GRE() const
{
    return this->GRE;
}

void Student::set_GRE(int GRE)
{
    this->GRE = GRE;
}

int Student::get_TOEFL() const
{
    return this->TOEFL;
}

void Student::set_TOEFL(int TOEFL)
{
    this->TOEFL = TOEFL;
}

int Student::get_numberOfApplications() const
{
    return this->numberOfApplications;
}

void Student::set_numberOfApplications(int numberOfApplications)
{
    this->numberOfApplications = numberOfApplications;
}

void Student::increment_numberOfApplications() const // This function is created to avoid declaring the setter of the numberOfApplications as const.
{
    this->numberOfApplications += 1;
}