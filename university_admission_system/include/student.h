/* @Author
 * Student Name:  Yusuf Yildiz
 * Student ID : 150210006
 */

#ifndef _STUDENT
#define _STUDENT

#include "../include/student.h"
#include <string>

class Student
{
public:
    Student(std::string = "", float = 0, int = 0, int = 0); // Constructor
    Student(const Student &);                               // Copy constructor
    ~Student();                                             // Destructor
    // Getter and setter methods of the class
    std::string get_name() const;
    void set_name(std::string);
    float get_gpa() const; // Written as const methods so,
    int get_gre() const;   // constant Student objects can call them
    int get_toefl() const;
    void increment_num_of_app() const; // Only used methods implemented

private:
    std::string name;
    float GPA;
    int GRE;
    int TOEFL;
    mutable int num_of_app; // Written as mutable so, it can be change even object is const.
};

#endif