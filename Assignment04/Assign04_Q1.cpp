#include <iostream>
using namespace std;

class Time
{
    int hrs;
    int min;
    int sec;

public:
    Time()
    {
        hrs = 00;
        min = 00;
        sec = 00;
    }
    Time(int hrs, int min, int sec)
    {
        this->hrs = hrs;
        this->min = min;
        this->sec = sec;
    }
    void setHrs(int hrs)
    {
        this->hrs = hrs;
    }
    void setMin(int min)
    {
        this->min = min;
    }
    void setSec(int sec)
    {
        this->sec = sec;
    }
    int getHrs(int hrs)
    {
        return hrs;
    }
    int getMin(int min)
    {
        return min;
    }
    int getSec(int sec)
    {
        return sec;
    }
    void acceptTime()
    {
        cout << "Enter Hrs : ";
        cin >> hrs;
        cout << "Enter Min : ";
        cin >> min;
        cout << "Enter Sec : ";
        cin >> sec;
        cout << "................" << endl;
    }
    void printTime()
    {
        cout << "\n--------------------------" << endl;
        cout << "Time : " << hrs << " : " << min << " : " << sec << endl;
        cout << "--------------------------" << endl;
    }
};
int main()
{
    int i;
    Time *arr[5];
    for (i = 0; i < 5; i++)
    {
        arr[i] = new Time;
        arr[i]->acceptTime();
    }
    for (i = 0; i < 5; i++)
    {
        arr[i]->printTime();
    }
    for (i = 0; i < 5; i++)
    {
        delete arr[i];
        arr[i] = NULL;
    }
    return 0;
}