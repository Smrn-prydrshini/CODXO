/* Motive:- This program is used to calculate CGPA from a 10 scale grade */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// creating a stuct of course containing grades and credit hours
struct course
{
    string grade; // grade acheived in the course
    int credit_Hrs; // credit hours of the course
};

//function to get grade points on a scale of 10
double getGradePoints(const string& grade)
{
    // using if comand instead of switch case due to multi characters of grade
    
    if (grade == "A+") return 10.0;
    if (grade == "A") return 9.0;
    if (grade == "B+") return 8.0;
    if (grade == "B") return 7.0;
    if (grade == "C+") return 6.0;
    if (grade == "C") return 5.0;
    if (grade == "D") return 4.0;
    if (grade == "F") return 0.0;
    return 0.0; // it handels invaid grades provided by user

}

// fuction to calculate CGPA
double CGPA(const vector<course>&courses)
{
    double total_GPoint = 0; // total grade points
    int total_CHours = 0; // total credit hours

    for (const auto& course : courses)
        { 
            total_CHours += course.credit_Hrs; // calculating total credit hours
            total_GPoint += getGradePoints(course.grade)* course.credit_Hrs; // calculating total grade point
        }
    if (total_CHours == 0)
    {
        return 0.0; // this will prevent division to bappen by 0
    }
return total_GPoint/total_CHours ; // returns caclulated cgpa
}

int main()
{
    int totalCourses ; // creating a variable for total number of courses
    cout <<" Enter the total number of courses: " ;
    cin >> totalCourses ; //taking input for courses

    vector<course> courses(totalCourses);

        //taking input for the grades and credit hours
        for (int i =0; i<totalCourses; i++)
        {
            cout << "Enter the Grade for course "<< i+1 << ":" ;
            cin >> courses[i].grade;
            cout << "Enter credit hours for course "<< i+1 << ":" ;
            cin >> courses[i].credit_Hrs;
        }

// calling the CGPA function to calculate CGPA
double cgpa = CGPA(courses);
cout << "You have scroed a total CGPA of : " << cgpa << endl;

return 0;

}