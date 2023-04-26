#include "Student.h"
#include "StudentBuilder.h"

int main()
{

    auto studentBuilder = StudentBuilder::getStudentBuilder();
    studentBuilder->setName("Santosh");
    studentBuilder->setAge(20);

    return 0;
}