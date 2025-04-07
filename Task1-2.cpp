#include <iostream>
#include<stack>
using namespace std;

class Stack {
private:
    int stackArray[10];
    int top;
    const int maxSize = 10;

public:
    Stack() {
        top = -1;
    }
     bool IsFull() {
        return top == maxSize - 1;
    }

    bool IsEmpty() {
        return top == -1;
    }
    void Push(int value) {
        if (IsFull()) {
            cout << "Stack is full!" << endl;
            return;
        }
        stackArray[++top] = value;
        cout << "Pushed " << value << " to the stack." << endl;
    }

    void Pop() {
        if (IsEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Popped " << stackArray[top--] << " from the stack." << endl;
    }

    void FindMiddle() {
        if (IsEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        int midIndex = top / 2;
        cout << "Middle element is: " << stackArray[midIndex] << endl;
    }

    void ReverseBottomHalf() {
        if (IsEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        int half = (top + 1) / 2;
        for (int i = 0; i < half / 2; ++i) {
            int temp = stackArray[i];
            stackArray[i] = stackArray[half - 1 - i];
            stackArray[half - 1 - i] = temp;
        }
        cout << "Bottom half of the stack has been reversed." << endl;
    }

    void Display() {
        if (IsEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack elements (bottom to top): ";
        for (int i = 0; i <= top; ++i) {
            cout << stackArray[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack stack;
    int choice, value;

    do {
        cout << "\n===== STACK MENU =====" << endl;
        cout << "1. Push (Add element)" << endl;
        cout << "2. Pop (Remove element)" << endl;
        cout << "6. Find Middle Element" << endl;
        cout << "7. Reverse Bottom Half" << endl;
        cout << "8. Display Stack" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                stack.Push(value);
                break;
            case 2:
                stack.Pop();
                break;
            case 3:
                stack.FindMiddle();
                break;
            case 4:
                stack.ReverseBottomHalf();
                break;
            case 5:
                stack.Display();
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
