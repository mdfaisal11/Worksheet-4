#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class PersonRecords
{
private:
    vector<string> names;
    map<string, int> nameAgeMap;

public:
    void addPerson()
    {
        string name;
        int age;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;

        names.push_back(name);
        nameAgeMap[name] = age;
    }
    void findAboveAge(int ageLimit)
    {
        cout << "\nPeople above age " << ageLimit << ":\n";
        for (const auto& entry : nameAgeMap) {
            if (entry.second > ageLimit) {
                cout << entry.first << " - Age: " << entry.second << endl;
            }
        }
    }
    void displayNames()
    {
        sort(names.begin(), names.end());
        cout << "\nNames sorted alphabetically:\n";
        for (const string& name : names) {
            cout << name << endl;
        }
    }
};

int main() {
    PersonRecords pr;
    int choice, ageLimit;

    do
    {
        cout << "\n1. Add new name-age pair" << endl;
        cout << "2. Find people above a certain age" << endl;
        cout << "3. Sort and display names alphabetically" << endl;
        cout << "4. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                pr.addPerson();
                break;
            case 2:
                cout << "Enter age limit: ";
                cin >> ageLimit;
                pr.findAboveAge(ageLimit);
                break;
            case 3:
                pr.displayNames();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
    while (choice != 4);

    return 0;
}
