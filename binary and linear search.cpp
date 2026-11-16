
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

struct Student
{
    int id;
    char name[50];
    float cgpa;
};

int linearSearch(Student s[], int n, int id)
{
    for (int i = 0; i < n; i++)
        if (s[i].id == id)
            return i;
    return -1;
}

int binarySearch(Student s[], int n, int id)
{
    sort(s, s + n, [](Student a, Student b) {
        return a.id < b.id;
    });

    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (s[mid].id == id) return mid;
        if (s[mid].id < id) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main()
{
    Student *s = NULL, *temp;
    int n = 0, ch, id;

    do
    {
        cout << "\n1.Add Student";
        cout << "\n2.Linear Search";
        cout << "\n3.Binary Search";
        cout << "\n4.Display";
        cout << "\n5.Exit";
        cout << "\nEnter choice: ";
        cin >> ch;

        switch (ch)
        {
            case 1:
                temp = (Student*)realloc(s, (n + 1) * sizeof(Student));

                if (temp == NULL)
                {
                    cout << "Memory Allocation Failed!";
                    break;
                }

                s = temp;

                cout << "Enter ID: ";
                cin >> s[n].id;

                cout << "Enter Name: ";
                cin >> ws;
                cin.getline(s[n].name, 50);

                cout << "Enter CGPA: ";
                cin >> s[n].cgpa;

                n++;
                cout << "Student Added Successfully!\n";
                break;

            case 2:
                cout << "Enter ID: ";
                cin >> id;
                id = linearSearch(s, n, id);

                if (id != -1)
                    cout << "Found: " << s[id].name
                         << " CGPA: " << s[id].cgpa << endl;
                else
                    cout << "Student Not Found\n";
                break;

            case 3:
                cout << "Enter ID: ";
                cin >> id;
                id = binarySearch(s, n, id);

                if (id != -1)
                    cout << "Found: " << s[id].name
                         << " CGPA: " << s[id].cgpa << endl;
                else
                    cout << "Student Not Found\n";
                break;

            case 4:
                for (int i = 0; i < n; i++)
                    cout << s[i].id << " "
                         << s[i].name << " "
                         << s[i].cgpa << endl;
                break;

            case 5:
                cout << "Exit\n";
                break;

            default:
                cout << "Invalid Choice\n";
        }

    } while (ch != 5);

    free(s);
    return 0;
}
