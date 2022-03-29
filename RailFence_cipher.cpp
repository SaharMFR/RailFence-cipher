// Program Name: RailFence_cipher.cpp
// Last Modification Date: 27/3/2022
// Author : Sahar Mohamed
// Purpose: cipher and decipher by RailFence cipher

#include <iostream>
using namespace std;

char plaintext[1000] , no_spaces[1000] , key1_1[1000] , key1_2[1000] , key1_3[1000] , finaltxt_1[1000] , finaltxt_2[1000];
int j = 0 , choice;
string ciphertxt;

//Function to get letters from an array and leave dots .
void final_text(char arr[1000]){
    int k = 0;
    for (int i = 0; i < strlen(arr); i++) {
        if (arr[i] == '.')
            continue;
        else {
            finaltxt_1[k] = arr[i];
            k++;
        }
    }
    for (int i = k; i < strlen(finaltxt_1); i++) {
        finaltxt_1[i] = NULL;
    }
}
//Function to cipher
void cipher(){
    //Entering the text to cipher (with spaces) without being affected by "cin" operand
    cout << "Please enter the message to cipher : " << endl;
    cin.ignore();
    cin.getline(plaintext , 1000 , '\n');
    //Removing spaces
    for (int i = 0; i < strlen(plaintext); i++) {
        if (!isspace(plaintext[i])) {
            no_spaces[j] = plaintext[i];
            j++;
        }
    }
    no_spaces[j] = NULL;
    cout << no_spaces << endl;
    //Turning all the text to lower letters
    for (int i = 0; i < strlen(no_spaces); i++) {
        no_spaces[i] = tolower(no_spaces[i]);
    }
    cout << no_spaces << endl;
    //Creating the first row
    int l = 0;
    for (int i = 0; i < strlen(no_spaces); i++) {
        if (i % 4 != 0) {
            key1_1[l] = '.';
            l++;
        } else {
            key1_1[l] = no_spaces[i];
            l++;
        }
    }
    key1_1[l] = NULL;
    cout << key1_1 << endl;
    //Creating the second row
    int m = 0;
    for (int i = 0; i < strlen(no_spaces); i++) {
        if (i % 2 == 0) {
            key1_2[m] = '.';
            m++;
        } else {
            key1_2[m] = no_spaces[i];
            m++;
        }
    }
    key1_2[m] = NULL;
    cout << key1_2 << endl;
    //Creating the third row
    int n = 0;
    for (int i = 0; i < strlen(no_spaces); i++) {
        if ((i % 2 == 0) && (i % 4 != 0)) {
            key1_3[n] = no_spaces[i];
            n++;
        } else {
            key1_3[n] = '.';
            n++;
        }
    }
    key1_3[n] = NULL;
    cout << key1_3 << endl;
    //Taking just letters in each row and printing it adjacent
    cout << "\nThe ciphertext : " << endl;
    final_text(key1_1);
    cout << " \" " << finaltxt_1;
    final_text(key1_2);
    cout << finaltxt_1;
    final_text(key1_3);
    cout << finaltxt_1 << " \" " << endl;
}
//Function to decipher
void decipher() {
    //Entering the cipherd text without spaces
    cout << "Please enter a ciphertext to decipher : " << endl;
    cin >> ciphertxt;
    //Separate counter for the cipher text
    int l = 0;
    char key2_1[ciphertxt.length()], key2_2[ciphertxt.length()], key2_3[ciphertxt.length()];
    //Creating the first row with appending the dots
    for (int i = 0; i < ciphertxt.length(); i++) {
        if (i % 4 == 0) {
            key2_1[i] = ciphertxt[l];
            l++;
        } else {
            key2_1[i] = '.';
        }
    }
    cout << key2_1 << endl;
    //Creating the second row with appending the dots
    for (int i = 0; i < ciphertxt.length(); i++) {
        if (i % 2 == 0) {
            key2_2[i] = '.';
        } else {
            key2_2[i] = ciphertxt[l];
            l++;
        }
    }
    cout << key2_2 << endl;
    //Creating the third row with appending the dots
    for (int i = 0; i < ciphertxt.length(); i++) {
        if ((i % 2 == 0) && (i % 4 != 0)) {
            key2_3[i] = ciphertxt[l];
            l++;
        } else {
            key2_3[i] = '.';
        }
    }
    cout << key2_3 << endl;
    //Separate counter for the final text
    int k = 0;
    //Creating the final text and printing it
    for (int i = 0; i < ciphertxt.length();) {
        finaltxt_2[k] = key2_1[i];
        i++, k++;
        finaltxt_2[k] = key2_2[i];
        i++, k++;
        finaltxt_2[k] = key2_3[i];
        i++, k++;
        finaltxt_2[k] = key2_2[i];
        i++, k++;
        }
        cout << "The deciphered text : " << finaltxt_2 << endl;
    }
int main() {
    //Condition to repeat asking about the process that the user want to do
    int end = 0;
    cout << "\nAhlan ya user ya habibi ." << endl;
    cout << "What do you like to do today ? " << endl;
    while (end == 0) {
        cout << "\n ( Enter the number of the process that you want to do ) " << endl;
        cout << " 1 - Cipher a message . " << endl;
        cout << " 2 - Decipher a message . " << endl;
        cout << " 3 - End . " << endl;
        cin >> choice;
            if (choice == 1) {
                cipher();
            } else if (choice == 2) {
                decipher();
            } else if (choice == 3) {
                cout << "Thank you for using the program " << endl;
                end = 1;
            } else {
                cout << "Sorry! Invalid choice . Try again .. " << endl;
            }
    }
        return 0;
}