#include <iostream>
using namespace std;
class Box
{
    double length;
    double width;
    double height;

public:
    Box()
    {
        length = 2;
        width = 2;
        height = 2;
    }
    Box(double value)
    {
        length = value;
        width = value;
        height = value;
    }
    Box(double length, double width, double height)
    {
        this->length = length;
        this->width = width;
        this->height = height;
    }
    void calc_Volume()
    {
        double volume = length * width * height;
        cout << "Volume : " << volume << endl;
    }
};
int menu()
{
    int choice;

    cout << "-------------------------------------------------------------" << endl;
    cout << "0.Exit " << endl;
    cout << "1.Calculate Volume with default values" << endl;
    cout << "2.Calculate Volume with length,breadth and height with same value " << endl;
    cout << "3.Calculate Volume with different length,breadth and height values" << endl;
    cout << "-------------------------------------------------------------" << endl;

    cout << "Enter Your Choice : " << endl;
    cin >> choice;

    return choice;
}
int main()
{
{

    int choice;

    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1:
        {
            Box b1;
            b1.calc_Volume();
        }
        break;
        case 2:
        {
            Box b1(3);
            b1.calc_Volume();
        }
        break;
        case 3:
        {
            Box b1(4, 5, 3);
            b1.calc_Volume();
        }
        break;

        default:
            cout << "Invalid Choice...!" << endl;
            break;
        }
    }

    return 0;
}