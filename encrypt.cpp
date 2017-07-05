//  =============== BEGIN ASSESSMENT HEADER ================
/// @file encrypt.cpp 
/// @brief assn3/encrypt
///
/// @author Thomas Shiels [tshie001@ucr.edu]
/// @date April 19, 2015
///
/// @par Plagiarism Section
/// I hereby certify that I have not received assistance on this assignment, 
/// or used code, from ANY outside source other than the instruction team.
//  ================== END ASSESSMENT HEADER ===============
#include <iostream>

using namespace std;

int main ()
{
    
    string userMap; //user inputs own translation map
    string userWord; //word to encrypt
    
    cout << "What is the translation map (type 'default' to use default): ";
    cin >> userMap;
    if (userMap == "default") {
        userMap = "zyxwvutsrqponmlkjihgfedcba";
       
        
    }
    
    cout << endl;
   
    if (userMap.size() != 26) {
        cout << "Error: invalid translation map size." << endl;
        return 0;
      
    }
    if (!((userMap.at(0) >= 'a') && (userMap.at(0) <= 'z'))) {
        cout << "Error: encryption cannot be performed." << endl;
        return 0;
    }
   
    
    cout << endl << endl;
    cout << "What is the single word to translate: ";
    cin >> userWord;
    cout << endl;
    
    if (!((userWord.at(0) >= 'a') && (userWord.at(0) <= 'z'))) {
        cout << "Error: encryption cannot be performed." << endl;
        return 0;
    }
    
    
    userWord.at(0) = userMap.at(25 - ('z' - userWord.at(0)));
    
    
    
    cout << "Encrypted word: " << userWord << endl;
    
    
    
    
    
    
    return 0;    
}