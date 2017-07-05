//  =============== BEGIN ASSESSMENT HEADER ================
/// @file cipher.cpp 
/// @brief assn4/cipher
///
/// @author Thomas Shiels [tshie001@ucr.edu]
/// @date April 26, 2015
///
/// @par Plagiarism Section
/// I hereby certify that I have not received assistance on this assignment, 
/// or used code, from ANY outside source other than the instruction team.
//  ================== END ASSESSMENT HEADER ===============
#include <iostream>

using namespace std;

int main ()
{
    string userWord;
    string userMethod;
    string userMap;
    string alphaMap;
    int i;
    
    string test = "abcdefghijklmnopqrstuvwxyz";
   
    
    cout << "What is the method (encryption or decryption)? "; //asks method
    cin >> userMethod;
    cout << endl;
    if (!((userMethod == "encryption") || (userMethod == "decryption"))) {
        cout << "Error: invalid method choice." << endl;
        return 0;
    }
        
    
    cout << "What is the translation map (type 'default' to use default): ";
    cin >> userMap;
    cout << endl;
    if (userMap == "default") {
        userMap = "zyxwvutsrqponmlkjihgfedcba";
    }
    else if (userMap.size() != 26) {
        cout << "Error: invalid translation map size." << endl;
        return 0;
    }
    for (i = 0; i < userMap.size(); ++i) {
        if (!((userMap.at(i) >= 'a') && (userMap.at(i) <= 'z'))) {
            if (userMethod == "encryption") {
                cout << "Error: encryption cannot be performed." << endl;
            }
            return 0;
        }
    }
    
    cout << endl << endl;
    cout << "What is the single word to translate: ";
    cin >> userWord;
    cout << endl;
    
    for (i = 0; i < userWord.size(); ++i) {
        if (!((userWord.at(i) >= 'a') && (userWord.at(i) <= 'z'))) {
            if (userMethod == "encryption") {
                cout << "Error: encryption cannot be performed." << endl;
            }
            else if (userMethod == "decryption") {
                cout << "Error: decryption cannot be performed." << endl;
            }
            return 0;
        }
    }
    
    alphaMap = "abcdefghijklmnopqrstuvwxyz";
    
    if (userMethod == "encryption") {
        for (i = 0; i < userWord.size(); ++i) {
            userWord.at(i) = userMap.at(25 - ('z' - userWord.at(i)));
        }
        cout << "Encrypted word: " << userWord << endl;
    }
    else if (userMethod == "decryption") {
        if (userMap == "default") {
            userMap = "abcdefghijklmnopqrstuvwxyz";
        }
        for (i = 0; i < userWord.size(); ++i) {
            // userWord.at(i) = userMap.at(25 - ('z' - userWord.at(i)));
            if(userMap.find(userWord.at(i)) == string::npos){
                cout << "Error: decryption cannot be performed." <<endl;
                return 0;                
            }
            userWord.at(i) = test.at(userMap.find(userWord.at(i)));
        }
        cout << "Decrypted word: " << userWord << endl;
    }
    
    return 0;
}