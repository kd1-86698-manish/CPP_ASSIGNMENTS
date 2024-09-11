#include <iostream>
using namespace std;

namespace Nstudent
{
    class Student
    {
        int roll;
        string name;
        int marks;

    public:
        void initStud()
        {
            roll = 0;
            name = "Please enter your Name ";
            marks = 0;
            cout << "Roll No :" << roll << endl
                 << "Name : " << name << endl
                 << "Marks :" << marks << endl;
        }
        void acceptStud()
        {
            cout << "Enter Roll NO :" << endl;
            cin >> roll;
            cout << "Enter Your Name :" << endl;
            cin >> name;
            cout << "Enter Your Marks :" << endl;
            cin >> marks;
        }
        void displayStud()
        {
            cout << "Roll No :" << roll << endl
                 << "Name : " << name << endl
                 << "Marks :" << marks << endl;
        }
    };
}
using namespace Nstudent;
int menu()
{
    int choice;

    cout << "------ Menu ------" << endl;
    cout << "0.Exit" << endl;
    cout << "1.Init Data" << endl;
    cout << "2.Accept Stud Data" << endl;
    cout << "3.Display Stud Data" << endl;
    cout << "-----------------------" << endl;

    cout << "Enter Your Choice : " << endl;
    cin >> choice;

    return choice;
}
int main()
{
    int ch;
    Student s1;
    while ((ch = menu()) != 0)
    {
        switch (ch)
        {
        case 1:
            s1.initStud();
            break;

        case 2:
            s1.acceptStud();
            break;

        case 3:
            s1.displayStud();
            break;

        default:
            cout << "Invalid Choice...!" << endl;
            break;
        }
    }

    return 0;
}