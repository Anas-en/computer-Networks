#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string encrypt(string text, string key) {
    int cols = key.length();
    int rows = (text.length() + cols - 1) / cols;
    while (text.length() < rows * cols)
        text += 'X';
    vector<vector<char>> matrix(rows, vector<char>(cols));
    int k = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            matrix[i][j] = text[k++];
    string sortedKey = key;
    sort(sortedKey.begin(), sortedKey.end());
    string cipher = "";
    for (char ch : sortedKey) {
        int col = key.find(ch);
        for (int i = 0; i < rows; i++)
            cipher += matrix[i][col];
        cipher += " ";
        key[col] = '#';
    }
    return cipher;
}

string decrypt(string cipher, string key) {
    cipher.erase(remove(cipher.begin(), cipher.end(), ' '), cipher.end());
    int cols = key.length();
    int rows = cipher.length() / cols;
    vector<vector<char>> matrix(rows, vector<char>(cols));
    string sortedKey = key;
    sort(sortedKey.begin(), sortedKey.end());
    int k = 0;
    for (char ch : sortedKey) {
        int col = key.find(ch);
        for (int i = 0; i < rows; i++)
            matrix[i][col] = cipher[k++];
        key[col] = '#';
    }
    string text = "";
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            text += matrix[i][j];
    return text;
}

int main() {
    string text, key, cipher;
    int choice;
    do {
        cout << "\n1. Encryption";
        cout << "\n2. Decryption";
        cout << "\n3. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter plaintext: ";
                cin >> text;
                cout << "Enter key: ";
                cin >> key;
                cipher = encrypt(text, key);
                cout << "Encrypted text: " << cipher << endl;
                break;
            case 2:
                cout << "Enter ciphertext: ";
                cin.ignore();
                getline(cin, cipher);
                cout << "Enter key: ";
                cin >> key;
                text = decrypt(cipher, key);
                cout << "Decrypted text: " << text << endl;
                break;
            case 3:
                cout << "Exiting...";
                break;
            default:
                cout << "Invalid choice!";
        }
    } while (choice != 3);
    return 0;
}