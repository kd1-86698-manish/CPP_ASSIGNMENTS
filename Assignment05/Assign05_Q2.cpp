#include <iostream>
using namespace std;
class Student
{
    string name;
    const int rollno;
    char gender;
    string address;
    int marks[3];
    static int genrate_roll;

public:
    Student() : rollno(++genrate_roll)
    {
        this->name = " ";
        this->gender = ' ';
        this->address = "";
    }
    void setRollNo(int rn)
    {
        this->rollno;
    }

    int getRollNo()
    {
        return this->rollno;
    }

    void acceptData()
    {
        getchar();
        cout << "\nEnter Name   : ";
        getline(cin, name);

        cout << "Enter Gender  : ";
        cin >> gender;

        getchar();
        cout << "Enter Address : ";
        getline(cin, address);

        cout << "Enter Marks Of 3 Subjects : " << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << "Marks of subject " << i + 1 << " : ";
            cin >> marks[i];
        }
    }
    void percentage()
    {
        double total = 0.0, per;
        for (int i = 0; i < 3; i++)
        {
            total = total + marks[i];
        }
        per = total / 3;
        cout << "Percentage : " << per << " %" << endl;
        cout << "***************************" << endl;
    }

    void displayStudent()
    {
        cout << "\n***************************" << endl;
        cout << "Name    : " << name << endl;
        cout << "Roll No : " << rollno << endl;
        cout << "Gender  : " << gender << endl;
        cout << "Address : " << address << endl;
    }
};
int search(Student **s)
{
    int rollno;
    cout << "\nEnter the roll number you want to search: ";
    cin >> rollno;

    for (int i = 0; i < 3; i++)
    {
        if (rollno == s[i]->getRollNo())
        {
            return i;
        }
    }
    return -1;
}
int Student ::genrate_roll = 0;
int menu()
{
    int choice;

    cout << "\n------------------------" << endl;
    cout << "0.Exit" << endl;
    cout << "1.Accept Student " << endl;
    cout << "2.Display Student " << endl;
    cout << "3.Search Student " << endl;
    cout << "4.Percentage Student " << endl;
    cout << "------------------------" << endl;

    cout << "Enter Your Choice :" << endl;
    cin >> choice;

    return choice;
}
int main()
{
    Student *s[5];
    int choice;

    for (int i = 0; i < 3; i++)
    {
        s[i] = new Student();
    }
    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 0:
            cout << "Thank You.... :) " << endl;
            break;
        case 1:
        {
            for (int i = 0; i < 3; i++)
            {
                s[i]->acceptData();
            }
        }
        break;
        case 2:
        {
            for (int i = 0; i < 3; i++)
            {
                s[i]->displayStudent();
            }
        }
        break;
        case 3:
        {
            int index;
            index = search(s);
            if (index == -1)
                cout << "\nRoll number is not found.";
            else
                cout << "\n"
                     << s[index]->getRollNo() << " found at index-" << index;
        }
        break;
        case 4:
        {
            for (int i = 0; i < 3; i++)
            {
                s[i]->displayStudent();
                s[i]->percentage();
            }
        }
        break;

        default:
            cout << "Invalid choice..... :(" << endl;
            break;
        }
    }

    return 0;
}