#include <iostream>
#include<list>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void InsertAtStart(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        cout << "Inserted " << value << " at the start." << endl;
    }


    void InsertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            cout << "Inserted " << value << " at the end." << endl;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
        cout << "Inserted " << value << " at the end." << endl;
    }


    void InsertAtPosition(int value, int position) {
        if (position <= 0) {
            cout << "Invalid position!" << endl;
            return;
        }
        Node* newNode = new Node(value);
        if (position == 1) {
            newNode->next = head;
            head = newNode;
            cout << "Inserted " << value << " at position " << position << "." << endl;
            return;
        }
        Node* temp = head;
        for (int i = 1; temp != nullptr && i < position - 1; ++i) temp = temp->next;
        if (!temp) {
            cout << "Position out of bounds!" << endl;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Inserted " << value << " at position " << position << "." << endl;
    }


    void Display() {
        if (!head) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        cout << "List: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }


    void DetectAndRemoveLoop() {
        if (!head) return;
        Node *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                cout << "Loop detected! Removing loop..." << endl;
                slow = head;
                while (slow->next != fast->next) {
                    slow = slow->next;
                    fast = fast->next;
                }
                fast->next = nullptr;  // Remove the loop
                return;
            }
        }
        cout << "No loop detected." << endl;
    }
    void FindNthNodeFromEnd(int n) {
        if (!head || n <= 0) {
            cout << "Invalid value of N or empty list!" << endl;
            return;
        }
        Node *main_ptr = head, *ref_ptr = head;
        int count = 0;
        while (count < n) {
            if (!ref_ptr) {
                cout << "N is greater than the length of the list!" << endl;
                return;
            }
            ref_ptr = ref_ptr->next;
            count++;
        }
        while (ref_ptr) {
            main_ptr = main_ptr->next;
            ref_ptr = ref_ptr->next;
        }
        cout << "The " << n << "th node from the end is: " << main_ptr->data << endl;
    }

    void ReverseInGroupsOfK(int k) {
        if (!head || k <= 0) {
            cout << "Invalid value of K or empty list!" << endl;
            return;
        }
        Node *current = head, *prevTail = nullptr;
        bool firstGroup = true;
        while (current) {
            Node *groupHead = nullptr, *groupTail = current;
            int count = 0;
            while (current && count < k) {
                Node* next = current->next;
                current->next = groupHead;
                groupHead = current;
                current = next;
                count++;
            }
            if (firstGroup) {
                head = groupHead;
                firstGroup = false;
            } else {
                prevTail->next = groupHead;
            }
            groupTail->next = current;
            prevTail = groupTail;
        }
        cout << "List reversed in groups of " << k << " nodes." << endl;
    }
};

int main() {
    LinkedList list;
    int choice, value, position, n, k;

    do {
        cout << "\n===== LINKED LIST MENU =====" << endl;
        cout << "1. Insert at start" << endl;
        cout << "2. Insert at end" << endl;
        cout << "3. Insert at position" << endl;
        cout << "4. Detect and remove loop" << endl;
        cout << "5. Find nth node from the end" << endl;
        cout << "6. Reverse in groups of K nodes" << endl;
        cout << "7. Display list" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at start: ";
                cin >> value;
                list.InsertAtStart(value);
                break;
            case 2:
                cout << "Enter value to insert at end: ";
                cin >> value;
                list.InsertAtEnd(value);
                break;
            case 3:
                cout << "Enter value and position: ";
                cin >> value >> position;
                list.InsertAtPosition(value, position);
                break;
            case 4:
                list.DetectAndRemoveLoop();
                break;
            case 5:
                cout << "Enter value of N: ";
                cin >> n;
                list.FindNthNodeFromEnd(n);
                break;
            case 6:
                cout << "Enter value of K: ";
                cin >> k;
                list.ReverseInGroupsOfK(k);
                break;
            case 7:
                list.Display();
                break;
            case 8:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }

    } while (choice != 8);

    return 0;
}
