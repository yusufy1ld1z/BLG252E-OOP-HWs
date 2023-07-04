/* @Author
 * Student Name:  Yusuf Yildiz
 * Student ID : 150210006
 */

#ifndef _UNIVERSITY
#define _UNIVERSITY

#include "../include/student.h"
#include <string>

class University
{
public:
    University(std::string = "", float = rand(), float = rand(), float = rand(), float = rand(), std::string = ""); // Constructor
    void evaluate_student(const Student &);

private:
    std::string uni_name;
    float wGPA;
    float wGRE;
    float wTOEFL;
    float bias;
    std::string country;
};

#endif