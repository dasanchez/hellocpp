// Fig 7.22: GradeBook.h
// Definition of class GradeBook that uses a
// two-dimensional array to store test grades.
// Member functions are defined in sandbox.cpp
#include <string>
using namespace std;

// GradeBook class definition
class GradeBook
{
  public:
    // constants
    static const int students = 10; // number of students
    static const int tests = 3; // number of tests

    // constructor initalizes course name anad array of grades
    GradeBook(string, const int[][tests]);

    void setCourseName(string);
    string getCourseName();
    void displayMessage(); // display a welcome message
    void processGrades();
    int getMinimum();
    int getMaximum();
    double getAverage(const int [], const int); // get student's average
    void outputBarChart();
    void outputGrades();

private:
    string courseName;
    int grades[students][tests]; // two-dimensional array of grades
}; // end class GradeBook
