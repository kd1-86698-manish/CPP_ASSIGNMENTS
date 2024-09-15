#include <iostream>
using namespace std;
class Date
{
    int day, month, year;

public:
    Date()
    {
        this->day = 0;
        this->month = 0;
        this->year = 0;
    }
    Date(int day, int month, int year)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }
    void setDay(int day)
    {
        this->day = day;
    }
    void setMonth(int month)
    {
        this->month = month;
    }
    void setYear(int year)
    {
        this->year = year;
    }
    void acceptDate()
    {
        cout << "Enter day : ";
        cin >> day;
        cout << "Enter Month : ";
        cin >> month;
        cout << "Enter Year : ";
        cin >> year;
    }
    void displayDate()
    {
        cout << day << "/" << month << "/" << year << endl;
    }
};
class Person
{
    string name;
    string address;
    Date dob;

public:
    Person()
    {
        this->name = "";
        this->address = "";
    }
    Person(string name, string address, int day, int month, int year)
    {
        this->name = name;
        this->address = address;
        dob.setDay(day);
        dob.setMonth(month);
        dob.setYear(year);
    }
    void acceptPerson()
    {
        cout << "Enter Name    : ";
        getchar();
        getline(cin, name);

        cout << "Enter Address : ";
        getline(cin, address);

        cout << "Enter DOB     : " << endl;
        dob.acceptDate();
    }
    void displayPerson()
    {
        cout << "...................................." << endl;
        cout << "Name         : " << name << endl;
        cout << "Address      : " << address << endl;
        cout << "DOB          : ";
        dob.displayDate();
    }
};
class Employee : public Person
{
    int id, sal;
    string dept;
    Date doj;

public:
    Employee()
    {
        this->id = 0;
        this->dept = "";
        this->sal = 0;
    }
    Employee(int id, string dept, int sal, int day, int month, int year)
    {
        this->id = id;
        this->dept = dept;
        this->sal = sal;
        doj.setDay(day);
        doj.setMonth(month);
        doj.setYear(year);
    }
    void aceeptEmployee()
    {
        this->acceptPerson();

        cout << "Enter ID         : ";
        cin >> id;

        cout << "Enter Department : ";
        cin >> dept;

        cout << "Enter Salary     : ";
        cin >> sal;

        cout << "Enter Date Of Joining : " << endl;
        doj.acceptDate();
    }

    void displayEmployee()
    {
        
        this->displayPerson();
        cout << "ID           : " << id << endl;
        cout << "Department   : " << dept << endl;
        cout << "Salary       : " << sal << endl;
        cout << "Joining Date : ";
        doj.displayDate();
        cout << "...................................." << endl;
    }
};
int menu()
{
    int choice;

    cout << "-----------------------------" << endl;
    cout << "0.Exit " << endl;
    cout << "1.Accept Employee Details  " << endl;
    cout << "2.Display Employee Details  " << endl;
    cout << "-----------------------------" << endl;

    cout << "Enter Your Choice :";
    cin >> choice;

    return choice;
}
int main()
{
    Employee e1;

    int choice;

    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1:
        {
            e1.aceeptEmployee();
        }
        break;
        case 2:
        {
            e1.displayEmployee();
        }
        break;
        default:
            cout << "Invalid Choice .... :(" << endl;
            break;
        }
    }

    return 0;
}