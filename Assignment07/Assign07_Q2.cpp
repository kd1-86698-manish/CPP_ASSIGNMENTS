#include <iostream>
using namespace std;
class Employee
{
    int id;
    double salary;

public:
    Employee()
    {
        this->id = 0;
        this->salary = 0;
    }
    Employee(int id, double salary)
    {

        this->id = id;
        this->salary = salary;
    }
    virtual void accept()
    {
        cout << "Enter Id         : ";
        cin >> id;
        cout << "Enter Salary     : ";
        cin >> salary;
    }
    virtual void display()
    {
        cout << "\nId          : " << id << endl;
        cout << "Salary      : " << salary << endl;
    }
};
class Manager : virtual public Employee
{
    double bonus;

protected:
    void acceptManager()
    {
        cout << "Enter Bonus      : ";
        cin >> bonus;
    }
    void displayManger()
    {
        cout << "Bonus       : " << bonus << endl;
    }

public:
    Manager()
    {
        this->bonus = 0;
    }
    Manager(int id, double salary, double bonus) : Employee(id, salary)
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
        displayManger();
    }
};
class Salesman : virtual public Employee
{
    double comm;

protected:
    void acceptSalesman()
    {
        cout << "Enter Commission : ";
        cin >> comm;
    }
    void displaySalesman()
    {
        cout << "Commision   : " << comm << endl;
    }

public:
    Salesman()
    {
        this->comm = 0;
    }
    Salesman(double comm)
    {
        this->comm = comm;
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
    void accept()
    {
        Employee::accept();
        acceptManager();
        acceptSalesman();
    }
    void display()
    {
        Employee::display();
        displayManger();
        displaySalesman();
    }
};
void countEmployee(Employee **arr, int index)
{
    int mcount = 0, scount = 0, smcount = 0;
    for (int i = 0; i < index; i++)
    {
        if (typeid(*arr[i]) == typeid(Manager))
        {
            mcount++;
        }
        else if (typeid(*arr[i]) == typeid(Salesman))
        {
            scount++;
        }
        else
        {
            smcount++;
        }
    }
    cout << "Enployes Count" << endl;
    cout << "\nManager Count      : " << mcount << endl;
    cout << "Salesman Count     : " << scount << endl;
    cout << "SalesManager Count : " << smcount << endl;
}
int menu()
{
    int choice;
    cout << "\n---------------------------------------------------" << endl;
    cout << "0.Exit" << endl;
    cout << "1.Accept Employee" << endl;
    cout << "2.Display Count of all Employee w.r.to Designation" << endl;
    cout << "3.Display All Managers" << endl;
    cout << "4.Display All Salesman" << endl;
    cout << "5.Display All SalesManager" << endl;
    cout << "---------------------------------------------------" << endl;

    cout << "Enter Your Choice : ";
    cin >> choice;

    return choice;
}
int addEmployee()
{
    int ch;
    cout << "\n--------------------------" << endl;
    cout << "0.Exit" << endl;
    cout << "1.Accept Manager " << endl;
    cout << "2.Accept Salesman " << endl;
    cout << "3.Accept SalesManager " << endl;
    cout << "--------------------------";

    cout << "\nEnter Your Choice : ";
    cin >> ch;

    return ch;
}
int main()
{
    Employee *arr[5];
    int index = 0;
    int choice;

    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1:
        {
            int ch;
            while ((ch = addEmployee()) != 0)
            {
                switch (ch)
                {
                case 1:
                {
                    if (index < 5)
                    {
                        arr[index] = new Manager;
                        arr[index]->accept();
                        index++;
                    }
                    else
                    {
                        cout << "Array is Full...!" << endl;
                    }
                }
                break;
                case 2:
                {
                    if (index < 5)
                    {
                        arr[index] = new Salesman;
                        arr[index]->accept();
                        index++;
                    }
                    else
                    {
                        cout << "Array is Full...!" << endl;
                    }
                }
                break;
                case 3:
                {
                    if (index < 5)
                    {
                        arr[index] = new SalesManager;
                        arr[index]->accept();
                        index++;
                    }
                    else
                    {
                        cout << "Array is Full...!" << endl;
                    }
                }
                break;
                default:
                    cout << "Wrong Choice ... :(";
                    break;
                }
            }
        }
        case 2:
        {
            countEmployee(arr, index);
        }
        break;
        case 3:
        {
            for (int i = 0; i < index; i++)
            {
                if (typeid(*arr[i]) == typeid(Manager))
                {
                    arr[i]->display();
                }
            }
        }
        break;
        case 4:
        {
            for (int i = 0; i < index; i++)
            {
                if (typeid(*arr[i]) == typeid(Salesman))
                {
                    arr[i]->display();
                }
            }
        }
        break;
        case 5:
        {
            for (int i = 0; i < index; i++)
            {
                if (typeid(*arr[i]) == typeid(SalesManager))
                {
                    arr[i]->display();
                }
            }
        }
        break;

        default:
            break;
        }
    }

    return 0;
}