#include <iostream>
using namespace std;
template <typename T>
class DynamicArray
{
    T *Array;
    int Length;

public:
    DynamicArray()
    {
        Array = nullptr;
        Length = 0;
    }
    DynamicArray(T *array, int len)
    {

        Array = array;
        Length = len;
    }
    DynamicArray(DynamicArray &arr) = delete;
    void Display()
    {
        for (int i = 0; i < Length; i++)
        {
            cout << Array[i] << "  ";
        }
        cout << endl;
    }
    int getLength() const
    {
        return Length;
    }
    T &operator[](int index)
    {
        return Array[index];
    }

    DynamicArray &operator=(const DynamicArray &other) = delete;
    DynamicArray(const DynamicArray &&other) noexcept
    {
        Array = other.Array;
        Length = other.Length;
        other.Array = nullptr;
    }

    DynamicArray &operator=( DynamicArray &&other)
    {
        if (&other == this)
            return *this;

        Array = other.Array;
        Length = other.Length;
        other.Array = nullptr;
        other.Length = 0;
        return *this;
    }
    ~DynamicArray()
    {
        delete[] Array;
    }
};
int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int arr2[5] = {11, 22, 33, 44, 55};
    DynamicArray<int> myArrInt(arr, 5);
    DynamicArray<int> myArr2(arr2, 5);
    myArrInt.Display();
    myArr2.Display();
    myArr2 = std::move(myArrInt);
    cout << "myArr2 length =" << myArr2.getLength() << endl;
    myArr2.Display();

    myArr2[2] = 99;
    cout << endl;
    myArr2.Display();
}