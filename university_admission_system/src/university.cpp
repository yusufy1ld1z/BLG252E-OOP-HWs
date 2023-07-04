/* @Author
 * Student Name:  Yusuf Yildiz
 * Student ID : 150210006
 */

#include "../include/university.h"
#include "../include/student.h"
#include <iostream>

University::University(std::string name, float wGPA, float wGRE, float wTOEFL, float bias, std::string country)
{
    this->uni_name = name;
    this->wGPA = wGPA;
    this->wGRE = wGRE;
    this->wTOEFL = wTOEFL;
    this->bias = bias;
    this->country = country;
}
void University::evaluate_student(const Student &student) // Taken as const reference to not call copy constructor
{
    float z = this->wGPA * student.get_gpa() + this->wGRE * student.get_gre() +
              this->wTOEFL * student.get_toefl() + this->bias; // Given formula implemented
    if (z >= 0)                                                // If stuent is qualified
    {
        std::cout << student.get_name() << " is admitted to " << this->uni_name << "." << std::endl;
    }
    else // If student is not qualified
    {
        std::cout << student.get_name() << " is rejected from " << this->uni_name << "." << std::endl;
    }
    student.increment_num_of_app();
}