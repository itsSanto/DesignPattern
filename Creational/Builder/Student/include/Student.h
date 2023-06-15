#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>

class Student
{
private:
    class StudentBuilder
    {
    public:
        Student *getStudent();

        StudentBuilder *setName(const std::string &name);
        StudentBuilder *setPhoneNumber(int phoneNumber);
        StudentBuilder *setAge(int age);
        std::string getName();
        int getPhoneNumber();
        int getAge();

    private:
        std::string mName;
        int mAge;
        int mPhoneNumber;
    };

    Student(StudentBuilder *studentBuilder);

    std::string mName;
    int mAge;
    int mPhoneNumber;

public:
    static StudentBuilder *getStudentBuilder();

    void print();
};

#endif // STUDENT_H