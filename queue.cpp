
#include <iostream>
using namespace std;

#define SIZE 5

int q[SIZE], front = -1, rear = -1;

void enqueue(int x)
{
    if ((rear + 1) % SIZE == front)
        cout << "Queue is Full\n";
    else
    {
        if (front == -1)
            front = 0;
        rear = (rear + 1) % SIZE;
        q[rear] = x;
        cout << x << " Inserted\n";
    }
}

void dequeue()
{
    if (front == -1)
        cout << "Queue is Empty\n";
    else
    {
        cout << q[front] << " Deleted\n";
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % SIZE;
    }
}

void display()
{
    if (front == -1)
        cout << "Queue is Empty\n";
    else
    {
        int i = front;
        cout << "Queue: ";
        while (true)
        {
            cout << q[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
}

int main()
{
    int ch, x;

    do
    {
        cout << "\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n";
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch)
        {
            case 1:
                cout << "Enter value: ";
                cin >> x;
                enqueue(x);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                cout << "Exit";
                break;

            default:
                cout << "Invalid Choice\n";
        }
    } while (ch != 4);

    return 0;
}
