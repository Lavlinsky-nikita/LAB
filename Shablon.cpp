#include <iostream>
#include <string>
#include <ctime>

using namespace std;


struct Person
{
    string lastName;
    int age;

    Person()
    {
        lastName = "";
        age = 0;
    }
    Person(string _lastName, int _age)
    {
        lastName = _lastName;
        age = _age;
    }


    bool operator > (Person p)
    {
        return age > p.age;
    }
    bool operator < (Person p)
    {
        return age < p.age;
    }

    friend ostream& operator << (ostream& os, Person& p);
};

ostream& operator << (ostream& os, Person& p)
{
    cout << p.lastName << ":" << p.age;

    return cout;
}


template <typename T>
void quickSort(T* arr, int left, int right)
{
    int i = left;
    int j = right;
    T pivot = arr[(i + j) / 2];
    T temp;

    while (i <= j)
    {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;

        if (i <= j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    if (j > left) quickSort(arr, left, j);
    if (i < right) quickSort(arr, i, right);
}

template <typename T>
void printArray(T* array, int n)
{
    for (int i = 0; i < n; i++) cout << array[i] << "  ";
    cout << endl;
}


int main()
{
    srand(time(0));

    int n;

    cout << "Enter n: ";
    cin >> n;



    bool* arr = new bool[n];

    for (int i = 0; i < n; i++) arr[i] = rand() % 2;

    cout << "Before Quick Sort [bool]:" << endl;
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    cout << "After Quick Sort [bool]:" << endl;
    printArray(arr, n);
    cout << "\n\n";



    int* arr1 = new int[n];

    for (int i = 0; i < n; i++) arr1[i] = -50 + rand() % 100;

    cout << "Before Quick Sort [int]:" << endl;
    printArray(arr1, n);

    quickSort(arr1, 0, n - 1);

    cout << "After Quick Sort [int]:" << endl;
    printArray(arr1, n);
    cout << "\n\n";



    double* arr2 = new double[n];

    for (int i = 0; i < n; i++) arr2[i] = -1 + (double)rand() / 10000;

    cout << "Before Quick Sort [double]:" << endl;
    printArray(arr2, n);

    quickSort(arr2, 0, n - 1);

    cout << "After Quick Sort [double]:" << endl;
    printArray(arr2, n);
    cout << "\n\n";



    Person* p = new Person[n];

    for (int i = 0; i < n; i++)
    {
        p[i].lastName = "Name(" + to_string(i) + ")";
        p[i].age = 15 + rand() % 21;
    }

    cout << "Before Quick Sort [Person]:" << endl;
    printArray(p, n);

    quickSort(p, 0, n - 1);

    cout << "After Quick Sort [Person]:" << endl;
    printArray(p, n);
}