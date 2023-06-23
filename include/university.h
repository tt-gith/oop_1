/* @Author
 * Student Name:  İbrahim Taha Tüzgen
 * Student ID : 150210717
 */

#include <iostream>
#include <string>
#include "student.h"

using namespace std;

class University
{
    struct WeightValues // I wanted to store the weight variables in a common structure. Because it will only used for "University" class, I created it in this class.
    {
        float GPAWeight;
        float GREWeight;
        float TOEFLWeight;
    };

public: // Getters are declared as const to be used in const object from the class.
    University();                                                // Same as the Student class, this constructor is not needed in our project, declaring the default constructor and defining it would be prefered for coming requirements.
    University(string, float, float, float, float, string = ""); // This is the constructor that is used in the project. The first string is for "name", the floats are for "GPAWeight", "GREWeight", "TOEFLWeight" and "bias" respectively. The last string is for country. Because it is an optional parameter, the value of it is assigned here.
    ~University();                                               // Same as the constructor, this destructor is not needed in our project, but declaring the default destructor and defining it would be prefered for coming requirements.

    void set_name(string);   // Setter for the private member "name".
    string get_name() const; // Getter for the private member "name".

    void set_bias(float);   // Setter for the private member "bias".
    float get_bias() const; // Getter for the private member "bias".

    void set_weightValues(WeightValues);   // Setter for the private member "weightValues".
    WeightValues get_weightValues() const; // Getter for the private member "weightValues".

    void set_country(string);   // Setter for the private member "country".
    string get_country() const; // Getter for the private member "country".

    bool evaluate_student(const Student &) const; // This function is used to determine weather a student is accepted to an university or not.

private: // These are the required members of the University class.
    WeightValues weightValues;
    string name;
    float bias;
    string country;
};