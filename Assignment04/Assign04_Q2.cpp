#include <iostream>
using namespace std;
class Stack
{
    int top;
    int *ptr;
    int stack_size;

public:
    Stack()
    {
        stack_size = 5;
        top = -1;
        this->ptr = new int[5];
    }
    Stack(int size)
    {
        this->stack_size = size;
    }
    bool pushElement(int element)
    {
        if (isFull())
        {
            cout << "\nStack is Full ";
            return false;
        }
        else
        {
            this->ptr[++top] = element;
            return true;
        }
    }
    bool popElement(int &ref)
    {
        if (isEmpty())
        {
            cout << "\nStack is Empty...!";
            return false;
        }
        else
        {
            ref = ptr[top--];
            return true;
        }
    }
    void printStack()
    {
        if (isEmpty())
        {
            cout << "\nStack is Empty..! ";
            return;
        }
        else
        {
            cout << "\nElement is :";
            for (int i = 0; i <= top; i++)
            {
                cout << "\t" << ptr[i];
            }
        }
    }
    bool peekElement(int &ref)
    {
        if (isEmpty())
        {
            cout << "\nStack is Empty...!";
            return false;
        }
        else
        {
            ref = ptr[top];
            return true;
        }
    }
    bool isEmpty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }
    bool isFull()
    {
        if (top == 4)
            return true;
        else
            return false;
    }
    ~Stack()
    {
        if (ptr != NULL)
        {
            delete[] ptr;
            ptr = NULL;
        }
    }
};
int menu()
{
    int choice;

    cout << "\n-----------------------------" << endl;
    cout << "0.Exit" << endl;
    cout << "1.Push Element on stack :" << endl;
    cout << "2.Pop Element from stack" << endl;
    cout << "3.Peek Element from stack" << endl;
    cout << "4.Display Element from stack" << endl;
    cout << "-----------------------------" << endl;

    cout << "\nEnter Your Choice : " << endl;
    cin >> choice;

    return choice;
}

int main()
{
    Stack s1;
    int choice;

    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1:
        {
            int element;
            cout << "Enter the Element ";
            cin >> element;
            if (s1.pushElement(element))
            {
                cout << "\nAdded into Stack...";
            }
            else
            {
                cout << "\nFailed to add....!!";
            }
            break;
        }
        case 2:
            int element;
            if (s1.popElement(element))
            {
                cout << element << " is poped ";
            }
            break;
        case 3:
        {
            int element;
            if (s1.peekElement(element))
            {
                cout << element << " is on top of the stack";
            }
            break;
        }
        case 4:
        {
            s1.printStack();
        }
        break;

        default:
            cout << "\nInvalid Choice....!";
            break;
        }
    }

    return 0;
}