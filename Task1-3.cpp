#include <iostream>
#include<queue>
using namespace std;

class Queue {
private:
    int queueArray[10];
    int front, rear;
    const int maxSize = 10;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool IsFull() {
        return (rear + 1) % maxSize == front;
    }

    bool IsEmpty() {
        return front == -1;
    }

    void Enqueue(int value) {
        if (IsFull()) {
            cout << "Queue is full!" << endl;
            return;
        }
        if (IsEmpty()) {
            front = 0;
        }
        rear = (rear + 1) % maxSize;
        queueArray[rear] = value;
        cout << "Enqueued " << value << " to the queue." << endl;
    }

    void Dequeue() {
        if (IsEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Dequeued " << queueArray[front] << " from the queue." << endl;
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % maxSize;
        }
    }

    void Display() {
        if (IsEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << queueArray[i] << " ";
            if (i == rear) break;
            i = (i + 1) % maxSize;
        }
        cout << endl;
    }

    void ReverseFirstK(int k) {
        if (IsEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        if (k <= 0 || k > Size()) {
            cout << "Invalid value of K!" << endl;
            return;
        }

        int temp[10], i = 0, j = front;
        while (i < k) {
            temp[i++] = queueArray[j];
            j = (j + 1) % maxSize;
        }

        for (int l = 0, r = k - 1; l < r; l++, r--) {
            swap(temp[l], temp[r]);
        }

        j = front;
        for (int idx = 0; idx < k; idx++) {
            queueArray[j] = temp[idx];
            j = (j + 1) % maxSize;
        }

        cout << "Reversed first " << k << " elements of the queue." << endl;
    }

    void InterleaveQueue() {
        if (IsEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        int n = Size();
        if (n % 2 != 0) {
            cout << "Interleaving requires even number of elements." << endl;
            return;
        }

        int half = n / 2;
        int firstHalf[5], secondHalf[5];
        int idx = 0, i = front;

        for (int j = 0; j < half; j++) {
            firstHalf[j] = queueArray[i];
            i = (i + 1) % maxSize;
        }

        for (int j = 0; j < half; j++) {
            secondHalf[j] = queueArray[i];
            i = (i + 1) % maxSize;
        }

        i = front;
        for (int j = 0; j < half; j++) {
            queueArray[i] = firstHalf[j];
            i = (i + 1) % maxSize;
            queueArray[i] = secondHalf[j];
            i = (i + 1) % maxSize;
        }

        cout << "Queue has been interleaved (first half with second half)." << endl;
    }

    int Size() {
        if (IsEmpty()) return 0;
        if (rear >= front) return rear - front + 1;
        return maxSize - front + rear + 1;
    }
};

int main() {
    Queue queue;
    int choice, value, k;

    do {
        cout << "\n====== QUEUE MENU ======" << endl;
        cout << "1. Enqueue (Add element)" << endl;
        cout << "2. Dequeue (Remove element)" << endl;
        cout << "3. Reverse first K elements" << endl;
        cout << "4. Interleave first and second half" << endl;
        cout << "5. Display Queue" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                queue.Enqueue(value);
                break;
            case 2:
                queue.Dequeue();
                break;
            case 3:
                cout << "Enter value of K: ";
                cin >> k;
                queue.ReverseFirstK(k);
                break;
            case 4:
                queue.InterleaveQueue();
                break;
            case 5:
                queue.Display();
                break;
            case 6:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }

    } while (choice != 6);

    return 0;
}
