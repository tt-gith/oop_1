/* @Author
 * Student Name:  İbrahim Taha Tüzgen
 * Student ID : 150210717
 */

#include <string>
#include <iostream>

using namespace std;
/*In this file, the class "Student" is created, and the members of it are declared.*/
class Student
{
public:
    Student();                        // This constructor is not needed in our project, declaring the default constructor and defining it would be prefered for coming requirements.
    Student(string, float, int, int); // This is the constructor that we used in the project. The string is for name, the float is for GPA, and the integers are for GRE and TOEFL respectively.
    Student(const Student &);         // This is the copy constructor of the Student class.

    ~Student(); // This is the destructor of the Student class.

    void set_name(string);   // Setter for the private member "name".
    string get_name() const; // Getter for the private member "name".

    void set_GPA(float);   // Setter for the private member "GPA".
    float get_GPA() const; // Getter for the private member "GPA".

    void set_GRE(int);   // Setter for the private member "GRE".
    int get_GRE() const; // Getter for the private member "GRE".

    void set_TOEFL(int);   // Setter for the private member "TOEFL".
    int get_TOEFL() const; // Getter for the private member "TOEFL".

    void set_numberOfApplications(int);   // Setter for the private member "numberOfApplications".
    int get_numberOfApplications() const; // Getter for the private member "numberOfApplications".

    void increment_numberOfApplications() const; // This function is to increment the "numberOfApplications" 1. It is used to avoid making the "set_numberOfApplications" const.

private: // These are the required members of the Student class.
    string name{""};
    float GPA{0};
    int GRE{0};
    int TOEFL{0};
    mutable int numberOfApplications{0};
};