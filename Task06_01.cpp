#include <iostream>
using namespace std;

class vector
{
    int *arr;
    int size;

public:
    vector()
    {
        this->size = 0;
        this->arr = new int[this->size];
    }

    ~vector()
    { 

    }

    void pushFront(int value) 
    {
        int *temp = new int[++this->size];
        for (int i = 0, j = 1; i < this->size - 1; i++, j++)
        {
            temp[j] = this->arr[i];
        }
        temp[0] = value;
        this->arr = temp;
    }

    void pushBack(int value)
    {
        int *temp = new int[++this->size];
        for (int i = 0; i < this->size; i++) 
        {
            temp[i] = this->arr[i];
        }
        temp[this->size - 1] = value;
        this->arr = temp;
    }

    void pushIndex(int value, int index) 
    {
        if (index < this->size)
        {
            int* temp = new int[++this->size];
            for (int i = 0, j = 0; i < this->size; i++, j++)
            {
                if (i != index)
                {
                    temp[i] = arr[j];
                }
                else
                {
                    temp[i] = value;
                }
            }
            this->arr = temp;
        }
        else
        {
            cout << "Incorrect index.\n";
        }
    }

    void removeFront()
    {
        int *temp = new int[--this->size];
        for (int i = 0, j = 1; i < this->size; i++, j++)
        {
            temp[i] = this->arr[j];
        }
        this->arr = temp;
    }

    void removeBack()
    {
        int *temp = new int[--this->size];
        for (int i = 0; i < this->size; i++)
        {
            temp[i] = this->arr[i];
        }
        this->arr = temp;
    }

    void removeIndex(int index)
    {
        if (index < this->size)
        {
            int *temp = new int[--this->size];
            for (int i = 0, j = 0; j < this->size + 1; j++)
            {
                if (j != index)
                {
                    temp[i] = arr[j];
                    i++;
                }
            }
            this->arr = temp;
        }
        else
        {
            cout << "Incorrect index.\n";
        }
    }

    int getIndex(int index)
    {
        return this->arr[index];
    }

    int getSize()
    {
        return this->size;
    }

    void compare(vector vector)
    {
        if (this->size == vector.getSize())
        {
            for (int i = 0; i < this->size; i++)
            {
                if (this->arr[i] != vector.getIndex(i))
                {
                    cout << "Vectors are not equal.\n";
                    break;
                }
            }
            cout << "Vectors are equal.\n";
        }
        else
        {
            cout << "Vectors are not equal.\n";
        }
    }

    vector operator+(vector vector)
    {
        if (this->size == vector.getSize())
        {
            for (int i = 0; i < this->size; i++)
            {
                this->arr[i] = this->arr[i] + vector.arr[i];
            }
            return *this;
        }
        else
        {
            cout << "Vectors sizes are different.";
        }
    }

    vector operator*(vector vector)
    {
        if (this->size == vector.getSize())
        {
            for (int i = 0; i < this->size; i++)
            {
                this->arr[i] = this->arr[i] * vector.arr[i];
            }
            return *this;
        }
        else
        {
            cout << "Vectors sizes are different.";
        }
    }

    friend void print(vector vector);
};

void print(vector vector) 
{
    cout << "[";
    for (int i = 0; i < vector.size - 1; i++)
    {
        cout << vector.arr[i] << ";";
    }
    cout << vector.arr[vector.size - 1] << "]\n";
}

int main()
{
    vector vector1, vector2, vector3;
    vector1.pushFront(1);
    vector1.pushBack(2);
    vector1.pushBack(3);
    vector1.removeIndex(1);
    vector2.pushFront(1);
    vector2.pushBack(2);
    vector2.removeBack();
    vector2.pushBack(3);
    vector1.compare(vector2);
    vector3 = vector1 + vector2;
    print(vector3);
}