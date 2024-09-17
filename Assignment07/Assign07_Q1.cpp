#include <iostream>
using namespace std;
class Product
{
    int id;
    string title;
    double price;

public:
    Product()
    {
        this->id = 0;
        this->title = "";
        this->price = 0;
    }
    Product(int id, string title, double price)
    {
        this->id = id;
        this->title = title;
        this->price = price;
    }
    double getPrice()
    {
        return price;
    }
    virtual void accept()
    {
        cout << "Enter Id :";
        cin >> id;

        cout << "Enter Title :";
        getchar();
        getline(cin, title);

        cout << "Enter Price :";
        cin >> price;
    }
    virtual void display()
    {
        cout << "Id    : " << id << endl;
        cout << "Title : " << title << endl;
        cout << "Price : " << price << endl;
    }
};
class Book : public Product
{
    string author;

public:
    Book()
    {
        this->author = "";
    }
    Book(int id, string title, double price, string author) : Product(id, title, price)
    {
        this->author = author;
    }
    void accept()
    {
        Product::accept();

        cout << "Enter Author : ";
        getchar();
        getline(cin, author);
    }

    void display()
    {
        Product::display();
        cout << "Author : " << author << endl;
    }
};
class Tape : public Product
{
    string artist;

public:
    Tape()
    {
        this->artist = "";
    }

    Tape(int id, string title, double price, string artist) : Product(id, title, price)
    {
        this->artist = artist;
    }
    void accept()
    {
        Product::accept();
        cout << "Enter Artist : ";
        getchar();
        getline(cin, artist);
    }
    void display()
    {
        Product::display();
        cout << "Artist : " << artist << endl;
    }
};
void finalPrice(Product **arr)
{
    double dprice = 0;
    double totalPrice = 0;

    for (int i = 0; i < 3; i++)
    {
        if (typeid(*arr[i]) == typeid(Book))
        {
            dprice = arr[i]->getPrice() - (arr[i]->getPrice() * .10);
        }
        else
        {
            dprice = arr[i]->getPrice() - (arr[i]->getPrice() * .05);
        }

        totalPrice += dprice;
    }
    cout << "Total Bill : " << totalPrice << endl;
}
int menu()
{
    int choice;
    cout << "-----------------" << endl;
    cout << "0.Exit" << endl;
    cout << "1.Add Book" << endl;
    cout << "2.Add Tape" << endl;
    cout << "3.Total Bill" << endl;
    cout << "-----------------" << endl;
    cout << "Enter Your Choice :";
    cin >> choice;

    return choice;
}
int main()
{
    int choice;
    Product *arr[3];
    int index = 0;
    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1:
        {
            if (index < 3)
            {
                arr[index] = new Book;
                arr[index]->accept();
                index++;
            }
            else
            {
                cout << "Cart is Full" << endl;
            }
        }
        break;
        case 2:
        {
            if (index < 3)
            {
                arr[index] = new Tape;
                arr[index]->accept();
                index++;
            }
            else
            {
                cout << "Cart is Full" << endl;
            }
        }
        break;
        case 3:
        {
            finalPrice(arr);
        }
        break;

        default:
            cout << "Invalid Choice...:(" << endl;
            break;
        }
    }

    return 0;
}