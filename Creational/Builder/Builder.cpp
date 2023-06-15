#include "Student.h"

int main()
{
    auto s = Student::getStudentBuilder()->setAge(20)->setName("Santosh")->setPhoneNumber(23423)->getStudent();
    s->print();
}