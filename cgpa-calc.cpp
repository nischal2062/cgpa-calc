#include <iostream>
#include <vector>
#include <string>

using namespace std;

class courseBase{
    public:
        virtual void inputCourseDetails() = 0;
        virtual void displayCourseGrade() const = 0;
        virtual float getGradePoint() const = 0;
        virtual int getCreditHours() const = 0;
        virtual ~courseBase() {}
};

class Course: public courseBase{

    private:
        string courseName;
        char grade;
        int creditHours;
        float gradePoint;

    void calculateGradePoint() {
        switch (grade) {
            case 'A': gradePoint = 4.0; break;
            case 'B': gradePoint = 3.0; break;
            case 'C': gradePoint = 2.0; break;
            case 'D': gradePoint = 1.0; break;
            case 'F': gradePoint = 0.0; break;
            default: gradePoint = 0.0; break;
        }
    }

    public:
        Course() {
            courseName = "";
            grade = 'F';
            creditHours = 0;
            gradePoint = 0.0;
        }

        void inputCourseDetails() override {
            cout << "\nEnter course name: ";
            getline(cin >> ws, courseName);

            cout << "Enter course grade (A/B/C/D/F):  ";
            cin >> grade;
            grade = toupper(grade);

            cout<< "Enter credit hours: ";
            cin >> creditHours;

            calculateGradePoint();
        }

        void displayCourseGrade() const override {
            cout << courseName << " | Grade: " << grade
            << " | Credit Hours: " << creditHours << " | Grade Point: "<<gradePoint << endl;
        }
        float getGradePoint() const override{ return gradePoint; }
        int getCreditHours() const override { return creditHours; }
};
class CGPACalculator {
    private:
        vector<Course> courses;
        float totalGradePoints;
        int totalCredits;

    public:
    CGPACalculator() {
        totalGradePoints = 0.0;
        totalCredits = 0;
    }

    void inputCourses (){
        int n;
        cout << "How many courses? ";
        cin >> n;

        for (int i = 0; i < n; i++) {
            cout << "\n-- Course " << i + 1 << "---";
            Course c;
            c.inputCourseDetails();
            courses.push_back(c);
        }
    }

    void calculateGPA() {
        totalGradePoints = 0.0;
        totalCredits = 0;

        for (const Course& c : courses) {
            totalGradePoints += c.getGradePoint() * c.getCreditHours();
            totalCredits += c.getCreditHours();
        }
    }
    void displayReport(){
        cout << "\n\n--- Grade Report ---" << endl;
        for (const Course&c : courses) {
            c.displayCourseGrade();
        }
        float cgpa = (totalCredits==0) ? 0.0 : totalGradePoints / totalCredits;
         cout << "\nTotal Credit Hours: " << totalCredits << endl;
         cout << "Total Grade Points: " << totalGradePoints << endl;
         cout << "CGPA: " << cgpa << endl;

    }
};
int main()
{
    CGPACalculator calc;
    calc.inputCourses();
    calc.calculateGPA();
    calc.displayReport();

    return 0;

}