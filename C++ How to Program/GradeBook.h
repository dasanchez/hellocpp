// Fig 7.15: GradeBook.h
// Definition of class GradeBook that uses an array to store test grades.
// Member functions are defined in sandbox.cpp
#include <string>
using namespace std;

// GradeBook class definition
class GradeBook
{
  public:
    // constant -- number of students who took the test
    static const int students = 10; // note public data

    // constructor initalizes course name anad array of grades
    GradeBook(string, const int[]);

    void setCourseName(string);
    string getCourseName();
    void displayMessage(); // display a welcome message
    void processGrades();
    int getMinimum();
    int getMaximum();
    double getAverage(); // determine the average grade for the test
    void outputBarChart();
    void outputGrades();

private:
    string courseName;
    int grades[students];
}; // end class GradeBook
