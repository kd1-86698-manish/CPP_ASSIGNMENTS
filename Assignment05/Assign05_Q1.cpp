#include <iostream>
using namespace std;
class Date
{
    int day;
    int month;
    int year;

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
        cout << "\nEnter Day : ";
        cin >> day;

        cout << "Enter Month : ";
        cin >> month;

        cout << "Enter Year : ";
        cin >> year;
    }
    void displayDate()
    {
        cout << day << "/" << month << "/" << year;
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
    }
    void acceptPerson()
    {
        getchar();
        cout << "Enter Name : " << name;
        getline(cin, name);

        cout << "Enter Address : " << address;
        getline(cin, address);

        cout << "Enter Date of Birth : ";
        dob.acceptDate();
    }
    void displayPerson()
    {
        cout << "\n--------------------------------------" << endl;
        cout << "Name    : " << name << endl;
        cout << "Address : " << address << endl;
        cout << "DOB     : ";
        dob.displayDate();
        cout << "\n--------------------------------------" << endl;
    }
};
int menu()
{
    int choice;
    cout << "\n-------------------------" << endl;
    cout << "0.Exit" << endl;
    cout << "1.Accept Person Details" << endl;
    cout << "2.Display Person Details" << endl;
    cout << "-------------------------" << endl;

    cout << "Enter Your Choice :";
    cin >> choice;

    return choice;
}
int main()
{
    Person p1;
    int choice;
    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1:
        {
            p1.acceptPerson();
        }
        break;
        case 2:
        {
            p1.displayPerson();
        }
        break;

        default:
            break;
        }
    }

    return 0;
}