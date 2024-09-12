#include <iostream>
using namespace std;

class Address
{
    string buliding;
    string street;
    string city;
    int pin;

public:
    Address()
    {
        buliding = "";
        street = "";
        city = "";
        pin = 0;
    }

    Address(string buliding, string street, string city, int pin)
    {
        this->buliding = buliding;
        this->street = street;
        this->city = city;
        this->pin = pin;
    }
    void setBuliding(string buliding)
    {
        this->buliding = buliding;
    }
    void setStreet(string street)
    {
        this->street = street;
    }
    void setCity(string city)
    {
        this->city = city;
    }
    void setPin(int pin)
    {
        this->pin = pin;
    }
    string getBuilding()
    {
        return buliding;
    }
    string getStreet()
    {
        return street;
    }
    string getCity()
    {
        return city;
    }
    int getPin()
    {
        return pin;
    }
    void acceptAddress()
    {
        cout << "Enter Buliding Name :" << endl;
        getchar();
        getline(cin, this->buliding);

        cout << "Enter Street Name :" << endl;
        getchar();
        getline(cin, this->street);

        cout << "Enter City :" << endl;
        getchar();
        getline(cin, this->city);

        cout << "Enter Pin :" << endl;
        cin >> this->pin;
    }

    void displayAddress()
    {
        cout << "------------------" << endl;
        cout << "Address : " << this->buliding << " , " << this->street << " , " << this->city << " , " << this->pin << endl;
        cout << "------------------" << endl;
    }
};
int menu()
{
    int choice;
    cout << "----------------" << endl;
    cout << "0.Exit " << endl;
    cout << "1.Accept Address " << endl;
    cout << "2.Display Address " << endl;
    cout << "3.Display Address(Getters & Setters) " << endl;
    cout << "----------------" << endl;

    cout << "Enter Your Choice : " << endl;
    cin >> choice;
    return choice;
}
int main()
{
    int choice;
    Address a1;
    Address a2;

    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1:
        {
            a1.acceptAddress();
        }
        break;

        case 2:
        {
            a1.displayAddress();
            break;
        }
        case 3:
        {
            a2.setBuliding("Krushn Kunj");
            a2.setStreet("Meera Road");
            a2.setCity("Mumbai");
            a2.setPin(411030);

            cout << "Address : " << a2.getBuilding() << " , " << a2.getStreet() << " , " << a2.getCity() << " , " << a2.getPin() << "." << endl;
        }
        break;

        default:
            cout << "Invalid  Choice....!" << endl;
            break;
        }
    }

    return 0;
}