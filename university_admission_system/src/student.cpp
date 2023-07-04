/* @Author
 * Student Name:  Yusuf Yildiz
 * Student ID : 150210006
 */

#include "../include/student.h"
#include <string>
#include <iostream>

Student::Student(std::string name, float GPA, int GRE, int TOEFL)
{
    this->set_name(name);
    this->GPA = GPA;
    this->GRE = GRE;
    this->TOEFL = TOEFL;
    this->num_of_app = 0; // Initially zero

    std::cout << name << " logged in to the system." << std::endl;
}

Student::Student(const Student &student)
{
    this->set_name(student.name);
    this->GPA = student.GPA;
    this->GRE = student.GRE;
    this->TOEFL = student.TOEFL; // num_of_app didnt't copied because it needs to be initially zero logically
    this->num_of_app = 0;        // Initially zero

    std::cout << student.name << " logged in to the system." << std::endl;
}
// Getter and setter methods implemented
std::string Student::get_name() const
{
    return this->name;
}

void Student::set_name(std::string name)
{
    this->name = name;
}

float Student::get_gpa() const
{
    return this->GPA;
}

int Student::get_gre() const
{
    return this->GRE;
}

int Student::get_toefl() const
{
    return this->TOEFL;
}

void Student::increment_num_of_app() const
{
    this->num_of_app += 1;
}

Student::~Student() // Destructor
{
    std::cout << this->name << " logged out of the system with " << this->num_of_app << " application(s)." << std::endl;
}