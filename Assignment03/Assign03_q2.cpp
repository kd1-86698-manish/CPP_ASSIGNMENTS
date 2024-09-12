#include <iostream>
using namespace std;

int tollPaidByCar = 0;
int notTollPaidByCar = 0;

class TollBooth
{
    unsigned int totalNoOfCars;
    double amount;

public:
    TollBooth()
    {
        this->totalNoOfCars = 0;
        this->amount = 0;
    }

    TollBooth(unsigned int tnoc, double amt)
    {
        this->totalNoOfCars = tnoc;
        this->amount = amt;
    }

    void payingCar()
    {
        tollPaidByCar++;
        totalNoOfCars++;
        amount = amount + 50;
    }

    void notPayingCar()
    {
        notTollPaidByCar++;
        totalNoOfCars++;
    }

    void display()
    {
        cout << "\n\nTotal number of cars: " << totalNoOfCars;
        cout << "\nTotal collection amount: " << amount << "Rs.";
        cout << "\nPaying cars: " << tollPaidByCar;
        cout << "\nNot Paying cars: " << notTollPaidByCar;
    }
};

int menu()
{
    int Choice;
    cout << "\n............................";
    cout << "\n0. Exit";
    cout << "\n1. Paying Cars: ";
    cout << "\n2. Not Pating Cars: ";
    cout << "\n3. Total collection amount: ";
    cout << "\n............................";

    cout << "\nEnter your choice: ";
    cin >> Choice;
    return Choice;
}

int main()
{
    TollBooth t1;
    int choice;

    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1:
        {
            t1.payingCar();
        }
        break;

        case 2:
        {
            t1.notPayingCar();
        }
        break;

        case 3:
        {
            t1.display();
        }
        break;

        default:
            cout << "\nInvalid choice....!";
        } // switch
    } // while
    return 0;
}