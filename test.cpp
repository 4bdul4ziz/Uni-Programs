#include <algorithm>
#include <chrono>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using namespace std::chrono;
class Student
{
private:
public:
    void input();
    void output();
    string name;
    char regno[9];
    int marks;
};

void Student::input()
{
}

void Student::output()
{
}

void selection_sort(int arr[], int n)
{
    int i, j, min_ind;
    int temp;
    for (i = 0; i < n - 1; i++)
    {
        min_ind = i; //minimum element in unsorted array
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_ind])
                min_ind = j;

        //swap(&arr[min_idx], &arr[i]);` // Swap the found minimum element with the first element
        temp = arr[min_ind];
        arr[min_ind] = arr[i];
        arr[i] = temp;
    }
}

int main()
{
    Student arr[5];
    int arr_to_be_sorted[5];
    cout << "Taking input for 5 students" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter Student name: ";
        cin >> arr[i].name;
        cout << "Enter Student registration number: ";
        cin >> arr[i].regno;
        cout << "Enter Student marks: ";
        cin >> arr[i].marks;
        arr_to_be_sorted[i] = arr[i].marks;
    }

    selection_sort(arr_to_be_sorted, 5);

    cout << "\nThe details of the students are as follows: " << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << "\nStudent name: " << arr[i].name;
        cout << "\nStudent registration number: " << arr[i].regno;
        arr[i].marks = arr_to_be_sorted[i];
        cout << "\n Student marks: " << arr[i].marks;
    }

    return 0;
}
