#include <iostream>

using namespace std;

class MyClass
{
private:
    int size;
    int *Array;
public:
    MyClass(int size)
    {
        cout << "\nConstructor " << this << " is called" << endl;
        this->size = size;
        this->Array = new int[size];

        cout << "\nArray: " ;

        for (int i = 0; i < size; i++)
        {
            if (i % 2 == 0)
            {
                Array[i] = i + 5;
            }
            else
            {
                Array[i] = i - 2;
            }
        }
        for (int i = 0; i < size; i++)
        {
            cout << Array[i] << "; ";
        }

    }

    MyClass(const MyClass &other)
    {
        int coutner = 0;
        this->size = other.size;
        this->Array = new int[other.size];//покажчик на масив

        for (int i = 0; i < other.size; i++)
        {
            this->Array[i] = other.Array[i];

            if (this->Array[i] % 2 != 0)
            {
                coutner++;
            }
        }


        cout << "\nOdd elements = " << coutner << endl;
        cout << "\nConstructor of copy " << this << " is called" << endl;
    }

    ~MyClass()
    {
        cout << "Destructor " << this << " is called" << endl;
        delete[] Array;
    }
};

void Foo(const MyClass &first)
{
    MyClass second(first);
}

int main()
{
    MyClass first(8);
    Foo(first);
    return 0;
}