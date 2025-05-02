#include <iostream>
#include <cstring> // For C-style strings

using namespace std;
class String {
private:
    string data;

public:
    String() : data("") {}

    String(const string& str) : data(str) {}

    String(const char* cstr) : data(cstr) {}

    void display() {
        cout << "String: " << data << endl;
    }

    bool search(const String& substr) {
        size_t found = data.find(substr.data);
        if (found != string::npos) {
            cout << "Substring found at position " << found << endl;
            return true;
        }
        else {
            cout << "Substring not found" << endl;
            return false;
        }
    }

    bool search(const char* cstr) {
        String temp(cstr);
        return search(temp);
    }

    void replace(const String& oldStr, const String& newStr) {
        size_t found = data.find(oldStr.data);
        while (found != string::npos) {
            data.replace(found, oldStr.data.length(), newStr.data);
            found = data.find(oldStr.data, found + newStr.data.length());
        }
        cout << "String after replacement: " << data << endl;
    }

    void replace(const char* oldCstr, const char* newCstr) {
        String oldStr(oldCstr);
        String newStr(newCstr);
        replace(oldStr, newStr);
    }

    void merge(const String& other) {
        data += other.data;
        cout << "Merged string: " << data << endl;
    }

    void merge(const char* cstr) {
        String temp(cstr);
        merge(temp);
    }

    void sort() {
        int n = data.length();
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (data[j] > data[j + 1]) {
                    char temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                }
            }
        }
        cout << "Sorted string: " << data << endl;
    }

    friend istream& operator>>(istream& input, String& myString) {
        input >> myString.data;
        return input;
    }

    friend ostream& operator<<(ostream& output, const String& myString) {
        output << myString.data;
        return output;
    }

    void replaceWith(const String& newStr) {
        data = newStr.data;
        cout << "String after replacement: " << data << endl;
    }

    void replaceWith(const char* cstr) {
        String temp(cstr);
        replaceWith(temp);
    }
};

String operator+(const String& str1, const String& str2) {
    String result = str1;
    result.merge(str2);
    return result;
}
#pragma once
