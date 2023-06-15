#include "Student.h"

Student *Student::StudentBuilder::getStudent()
{
    return new Student(this);
}

Student::StudentBuilder *Student::StudentBuilder::setName(const std::string &name)
{
    mName = name;
    return this;
}
Student::StudentBuilder *Student::StudentBuilder::setPhoneNumber(int phoneNumber)
{
    mPhoneNumber = phoneNumber;
    return this;
}
Student::StudentBuilder *Student::StudentBuilder::setAge(int age)
{
    mAge = age;
    return this;
}

std::string Student::StudentBuilder::getName()
{
    return mName;
}

int Student::StudentBuilder::getAge()
{
    return mAge;
}

int Student::StudentBuilder::getPhoneNumber()
{
    return mPhoneNumber;
}

Student::Student(StudentBuilder *studentBuilder) : mName(studentBuilder->getName()), mAge(studentBuilder->getAge()), mPhoneNumber(studentBuilder->getPhoneNumber()) {}

Student::StudentBuilder *Student::getStudentBuilder()
{
    return new StudentBuilder();
}

void Student::print()
{
    std::cout << mName << " " << mAge << " " << mPhoneNumber << std::endl;
}
