#include <iostream>
#include <string>
using namespace std;

int main() {
    const string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const string key =      "$@#!&^_123465-9.8+7=&)('[']*zyx/vut;rqpo'm~kj:h`f|?\\><";
    string original_message; // As reference to see if we encrypted/decrypted correctly

    cout << "Please enter your message: ";
    getline(cin, original_message);

    string encrypted_message { original_message };

    // "encrypt" our message using the provided key.
    for (int i = 0; i < encrypted_message.length(); i++) {
        const char ch = encrypted_message[i];

        if (const size_t position = alphabet.find(ch); position != string::npos) {
            encrypted_message.replace(i, 1,  string(1, key[position]));
        }
    }

    cout << endl << "Your message encoded: " << encrypted_message << endl;

    string decrypted { encrypted_message };

    // "dencrypt" our message using the provided key.
    for (int i = 0; i < decrypted.length(); i++) {
        const char ch = decrypted[i];

        if (const size_t position = key.find(ch); position != string::npos)
            decrypted.replace(i, 1, string(1, alphabet[position]));
    }

    cout << endl << "Your message decoded: " << decrypted << endl;
    cout << ::boolalpha;
    cout << "Matches your original message: " << (original_message == decrypted) << endl;
}
