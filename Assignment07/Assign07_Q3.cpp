#include <iostream>
using namespace std;
class InsufficientFundsException
{
    string message;

public:
    InsufficientFundsException(string message)
    {
        this->message = message;
    }
    void display()
    {
        cout << "Exception : InsufficientFundsException" << endl;
        cout << "Message   :   " << message << endl;
    }
};
enum EaccountType
{
    SAVING = 1,
    CURRENT,
    DMAT
};
class Account
{
    int accno;
    EaccountType e;
    double balance;

public:
    Account()
    {
        balance = 0;
    }
    Account(int accno, EaccountType e, double balance)
    {
        this->accno = accno;
        this->e = e;
        this->balance = balance;
    }
    void accept()
    {
        int choice;

        cout << "Enter Account Type :" << endl;
        cout << "1.SAVING Account :" << endl;
        cout << "2.CURRENT Account :" << endl;
        cout << "3.DMAT Account :" << endl;

        cout << "Enter Choice :";
        cin >> choice;
        e = EaccountType(choice);

        cout << "Enter Account No : ";
        cin >> accno;

        cout << "Enter Balance : ";
        cin >> balance;
    }
    void display()
    {
        cout << "Account No : " << accno << endl;
        switch (e)
        {
        case SAVING:
            cout << "Savings Account";
            break;
        case CURRENT:
            cout << "Current Account";
            break;
        case DMAT:
            cout << "Dmat Account";
            break;

        default:
            cout << "Invalid Choice..." << endl;
            break;
        }
        cout << "\nBalance    : " << balance << endl;
    }
    void deposit()
    {

        double deposit;

        cout << "Enter Amount to Deposit : ";
        cin >> deposit;

        if (deposit < 0)
            throw InsufficientFundsException("Can't Deposite amount less than  or equal to 0");
        else
        {
            balance = balance + deposit;
            cout << "\nNew Balance = " << balance << endl;
        }
    }
    void withdraw()
    {
        double withdraw;

        cout << "Enter Amount to withdraw : ";
        cin >> withdraw;
        if (withdraw > balance)
            throw InsufficientFundsException("Insufficient Balance");
        else
        {
            balance = balance - withdraw;
            cout << "\nNew Balance = " << balance << endl;
        }
    }
};
int menu()
{
    int choice;

    cout << "\n---------------------" << endl;
    cout << "0.Exit" << endl;
    cout << "1.Create Account" << endl;
    cout << "2.Show Account" << endl;
    cout << "3.Deposite Amount" << endl;
    cout << "4.Withdraw Amount" << endl;
    cout << "---------------------" << endl;

    cout << "Enter Your Choice : ";
    cin >> choice;

    return choice;
}
int main()
{
    Account *arr[5];
    int choice;
    int index;

    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1:
        {
            if (index < 5)
            {
                arr[index] = new Account;
                arr[index]->accept();
            }
        }
        break;
        case 2:
        {
            arr[index]->display();
        }
        break;
        case 3:
        {
            try
            {
                arr[index]->deposit();
            }
            catch (InsufficientFundsException e)
            {
                e.display();
            }
        }
        break;
        case 4:
        {
            try
            {
                arr[index]->withdraw();
            }
            catch (InsufficientFundsException e)
            {
                e.display();
            }
        }
        break;

        default:
            cout << "Invalid Choice... :(";
            break;
        }
    }

    return 0;
}