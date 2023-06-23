/* @Author
 * Student Name:  İbrahim Taha Tüzgen
 * Student ID : 150210717
 */

#include <string>
#include <iostream>
#include "university.h"

using namespace std;

University::University() : name{""}, country{""} {} // This is the default constructor for the "University" class, it initializes the name and country values as empty strings, and does not assign any value to other members for randomization.

University::University(string name, float weightGPA, float weightGRE, float weightTOEFL, float bias, string country) // This is the constructor that we use for creating a university. Parameters in it are automatically assigned to the members of the created object.
{                                                                                                                    // I used the setters instead of direct assigning because maybe some checking mechanisms will be necessary later in the setters.
    set_name(name);
    WeightValues weights;
    weights.GPAWeight = weightGPA;
    weights.GREWeight = weightGRE;
    weights.TOEFLWeight = weightTOEFL;
    set_weightValues(weights);
    set_bias(bias);
    set_country(country);
}

University::~University() {} // Because this class does not contain any pointer member, we do not delete anything in the destructor. Nonetheless, I created it for a complete class definition.
// Getters and setters are assigning and returning the member values directly.
void University::set_name(string name)
{
    this->name = name;
}

string University::get_name() const
{
    return this->name;
}

void University::set_weightValues(University::WeightValues weightValues)
{
    this->weightValues.GPAWeight = weightValues.GPAWeight;
    this->weightValues.GREWeight = weightValues.GREWeight;
    this->weightValues.TOEFLWeight = weightValues.TOEFLWeight;
}

University::WeightValues University::get_weightValues() const
{
    return this->weightValues;
}

void University::set_bias(float bias)
{
    this->bias = bias;
}

float University::get_bias() const
{
    return this->bias;
}

void University::set_country(string country)
{
    this->country = country;
}

string University::get_country() const
{
    return this->country;
}

bool University::evaluate_student(const Student &student) const                       // This function takes the student as a parameter as pass by reference.
{                                                                                     // If it was pass by value, the copy constructor would be called every time that this function is called.
    float weightedGPA = this->get_weightValues().GPAWeight * student.get_GPA();       // GPA of the student is multiplied by the GPA weight of the university, and assigned to a variable.
    float weightedGRE = this->get_weightValues().GREWeight * student.get_GRE();       // GRE of the student is multiplied by the GRE weight of the university, and assigned to a variable.
    float weightedTOEFL = this->get_weightValues().TOEFLWeight * student.get_TOEFL(); // TOEFL of the student is multiplied by the TOEFL weight of the university, and assigned to a variable.
    float studentValue = weightedGPA + weightedGRE + weightedTOEFL + this->bias;      // The total point of the student is calculated with the summation of the weighted values of GPA, GRE and TOEFL with the bias.
    student.increment_numberOfApplications();                                         // The number of applications of the student is incremented after this application.
    if (studentValue >= 0)                                                            // As the document explains, if the z value is more than or equal to 0, it will be true.
    {
        cout << student.get_name() + " is admitted to " + name + "." << endl;
        return 1;
    }
    else                                                                              // else it is false.
    {
        cout << student.get_name() + " is rejected from " + name + "." << endl;
        return 0;
    }
}