#include "MyString.h"
int main() {
    String input;
    cout << "Enter a string: ";
    cin >> input;

    while (true) {
        int choice;
        cout << "Choose an operation:" << endl;
        cout << "1. Display" << endl;
        cout << "2. Search (String)" << endl;
        cout << "3. Search (C-string)" << endl;
        cout << "4. Replace (String)" << endl;
        cout << "5. Replace (C-string)" << endl;
        cout << "6. Merge (String)" << endl;
        cout << "7. Merge (C-string)" << endl;
        cout << "8. Sort" << endl;
        cout << "9. Replace With (String)" << endl;
        cout << "10. Replace With (C-string)" << endl;
        cout << "11. Exit" << endl;
        cin >> choice;

        if (choice == 1) {
            cout << input << endl;
        }
        else if (choice == 2) {
            String searchStr;
            cout << "Enter substring to search for: ";
            cin >> searchStr;
            input.search(searchStr);
        }
        else if (choice == 3) {
            const int bufferSize = 256;
            char searchCStr[bufferSize];
            cout << "Enter substring to search for (C-string): ";
            cin >> searchCStr;
            input.search(searchCStr);
        }
        else if (choice == 4) {
            String oldStr, newStr;
            cout << "Enter substring to replace: ";
            cin >> oldStr;
            cout << "Enter replacement string: ";
            cin >> newStr;
            input.replace(oldStr, newStr);
        }
        else if (choice == 5) {
            const int bufferSize = 256;
            char oldCStr[bufferSize], newCStr[bufferSize];
            cout << "Enter substring to replace (C-string): ";
            cin >> oldCStr;
            cout << "Enter replacement string (C-string): ";
            cin >> newCStr;
            input.replace(oldCStr, newCStr);
        }
        else if (choice == 6) {
            String mergeStr;
            cout << "Enter string to merge: ";
            cin >> mergeStr;
            input.merge(mergeStr);
        }
        else if (choice == 7) {
            const int bufferSize = 256;
            char mergeCStr[bufferSize];
            cout << "Enter string to merge (C-string): ";
            cin >> mergeCStr;
            input.merge(mergeCStr);
        }
        else if (choice == 8) {
            input.sort();
        }
        else if (choice == 9) {
            String newStr;
            cout << "Enter new string: ";
            cin >> newStr;
            input.replaceWith(newStr);
        }
        else if (choice == 10) {
            const int bufferSize = 256;
            char newCStr[bufferSize];
            cout << "Enter new string (C-string): ";
            cin >> newCStr;
            input.replaceWith(newCStr);
        }
        else if (choice == 11) {
            break;
        }
        else {
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}
