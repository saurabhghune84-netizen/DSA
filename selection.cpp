
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

struct Student
{
    int id;
    char name[50];
    float cgpa;
};

void display(Student s[], int n)
{
    for (int i = 0; i < n; i++)
        cout << s[i].id << " " << s[i].name
             << " " << s[i].cgpa << endl;
}

void selectionSort(Student s[], int n, int ch)
{
    for (int i = 0; i < n - 1; i++)
    {
        int pos = i;

        for (int j = i + 1; j < n; j++)
        {
            if ((ch == 1 && strcmp(s[j].name, s[pos].name) < 0) ||
                (ch == 2 && s[j].cgpa < s[pos].cgpa) ||
                (ch == 3 && s[j].cgpa > s[pos].cgpa))
                pos = j;
        }

        Student t = s[i];
        s[i] = s[pos];
        s[pos] = t;
    }
}

int main()
{
    Student *s = NULL, *temp;
    int n = 0, ch;

    do
    {
        cout << "\n1.Add Student\n2.Sort by Name";
        cout << "\n3.CGPA Ascending\n4.CGPA Descending";
        cout << "\n5.Display\n6.Exit\nChoice: ";
        cin >> ch;

        switch (ch)
        {
            case 1:
                temp = (Student*)realloc(s, (n + 1) * sizeof(Student));

                if (temp == NULL)
                {
                    cout << "Memory Allocation Failed\n";
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
                cout << "Student Added Successfully\n";
                break;

            case 2:
            case 3:
            case 4:
                selectionSort(s, n, ch == 2 ? 1 : ch);
                cout << "Sorted Records:\n";
                display(s, n);
                break;

            case 5:
                display(s, n);
                break;

            case 6:
                cout << "Exit\n";
                break;

            default:
                cout << "Invalid Choice\n";
        }

    } while (ch != 6);

    free(s);
    return 0;
}
