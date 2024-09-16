#include <iostream>
using namespace std;
class Employee
{
    int empid;
    double salary;

public:
    Employee()
    {
        this->empid = 0;
        this->salary = 0;
    }
    Employee(int empid, double salary)
    {
        this->empid = empid;
        this->salary = salary;
    }
    virtual void accept()
    {
        cout << "Enter Empid : ";
        cin >> empid;

        cout << "Enter Salary : ";
        cin >> salary;
    }
    virtual void display()
    {
        cout << "ID     : " << empid << endl;
        cout << "Salary : " << salary << endl;
    }
};
class Manager : virtual public Employee
{
    double bonus;

protected:
    void acceptManager()
    {
        cout << "Enter Bonus : ";
        cin >> bonus;
    }
    void displayManager()
    {
        cout << "Bonus : " << bonus << endl;
    }

public:
    Manager()
    {
        this->bonus = 0;
    }
    Manager(int empid, double salary, double bonus) : Employee(empid, salary)
    {
        this->bonus = bonus;
    }
    void setBonus(double bonus)
    {
        this->bonus = bonus;
    }
    void accept()
    {
        Employee::accept();
        acceptManager();
    }
    void display()
    {
        Employee::display();
        displayManager();
    }
};
class Salesman : virtual public Employee
{
    double commission;

protected:
    void acceptSalesman()
    {
        cout << "Enter Commission : ";
        cin >> commission;
    }
    void displaySalesman()
    {
        cout << "Commission : " << commission << endl;
    }

public:
    Salesman()
    {
        this->commission = 0;
    }
    Salesman(int empid, double salary, double commission) : Employee(empid, salary)
    {
        this->commission = commission;
    }
    void setCommission(double commission)
    {
        this->commission = commission;
    }
    void accept()
    {
        Employee::accept();
        acceptSalesman();
    }
    void display()
    {
        Employee::display();
        displaySalesman();
    }
};
class SalesManager : public Manager, public Salesman
{
public:
    SalesManager()
    {
    }
    SalesManager(int empid, double salary, double bonus, double commission) : Employee(empid, salary)
    {
        this->setBonus(0);
        this->setCommission(0);
    }
    void accept()
    {
        Employee::accept();
        acceptManager();
        acceptSalesman();
    }
    void display()
    {
        Employee::display();
        displayManager();
        displaySalesman();
    }
};
int main()
{
    SalesManager s;

    return 0;
}