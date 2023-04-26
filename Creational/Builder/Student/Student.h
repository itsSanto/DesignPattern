#include <string>

class Student
{
private:
    class StudentBuilder
    {
    public:
        Student *getStudent()
        {
            return new Student(this);
        }

        StudentBuilder *setName(const std::string &name)
        {
            mName = name;
            return this;
        }

        std::string getName()
        {
            return mName;
        }

        StudentBuilder *setPsp(const int &psp)
        {
            mPsp = psp;
            return this;
        }
        int getPsp()
        {
            return mPsp;
        }

        StudentBuilder *setAge(const int &age)
        {
            mAge = age;
            return this;
        }

        int getAge()
        {
            return mAge;
        }

        StudentBuilder *setPhoneNumber(const int &phoneNumber)
        {
            mPhoneNumber = phoneNumber;
            return this;
        }

        int getPhoneNumber()
        {
            return mPhoneNumber;
        }

    private:
        std::string mName;

        int mAge;

        int mPsp;

        int mPhoneNumber;
    };

    Student(StudentBuilder *studentBuilder)
        : mName(studentBuilder->getName()), mAge(studentBuilder->getAge()), mPsp(studentBuilder->getPsp()), mPhoneNumber(studentBuilder->getPhoneNumber())
    {
    }

    std::string mName;

    int mAge;

    int mPsp;

    int mPhoneNumber;

public:
    static StudentBuilder *getStudentBuilder()
    {
        return new StudentBuilder();
    }
};

int main()
{
    auto student = Student::getStudentBuilder()->setAge(20)->setName("")->getStudent();
}