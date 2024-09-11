#include <iostream>
using namespace std;
class Date
{
    int day;
    int month;
    int year;

public:
    void initDate()
    {
        cout << "Date : 01/01/1990" << endl;
    }
    void printDateOnConsol()
    {
        cout << "Date ::" << day << "/" << month << "/" << year << endl;
    }
    void acceptDateFromConsol()
    {
        cout << "----- Date -----" << endl;
        cout << "Enter Day :" << endl;
        cin >> day;
        cout << "Enter Month :" << endl;
        cin >> month;
        cout << "Enter Year :" << endl;
        cin >> year;
    }
    bool isLeapYear()
    {
            if((year%4==0) && ((year%400==0) || (year%100!=0)))  

            return true;
        else
            return false;
    }
};
int menu()
{
    int choice;
    cout << "---- Menu ----" << endl;
    cout << "0.Exit" << endl;
    cout << "1.Init Date" << endl;
    cout << "2.Accept Date" << endl;
    cout << "3.Display Date " << endl;
    cout << "4.Leap year " << endl;
    cout << "--------------" << endl;

    cout << "Enter Choice :" << endl;
    cin >> choice;

    return choice;
}
int main()
{
    bool d;
    Date d1;
    int choice;
    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1:
            d1.initDate();
            break;
        case 2:
            d1.acceptDateFromConsol();
            break;
        case 3:
            d1.printDateOnConsol();
            break;
        case 4:
        {
            d = d1.isLeapYear();
            if (d)
            {
                cout << "Leap Year" << endl;
            }
            else
            {
                cout << "Not Leap Year" << endl;
            }
        }

        break;

        default:
            cout << "Invalid Choice..." << endl;
            break;
        }
    }

    return 0;
}
