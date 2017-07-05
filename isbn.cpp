//  =============== BEGIN ASSESSMENT HEADER ================
/// @file isbn.cpp 
/// @brief assn2/isbn
///
/// @author Thomas Shiels [tshie001@ucr.edu]
/// @date April 12, 2015
///
/// @par Plagiarism Section
/// I hereby certify that I have not received assistance on this assignment, 
/// or used code, from ANY outside source other than the instruction team.
//  ================== END ASSESSMENT HEADER ===============

#include <iostream>

using namespace std; 

int main ()
{
    int isbnInput = 0;
    int weightSum = 0;
    int checkSum = 0;
    
    
    cout << 
    "Please enter the first 9 digits of the ISBN: ";   
    /* prompts for isbn */
    cin >> isbnInput; // user inputs isbn
    cout << endl; 
    
    weightSum = ((isbnInput / 100000000) * 1)
     + (((isbnInput % 100000000) / 10000000) * 2) + 
     (((isbnInput % 10000000) / 1000000) * 3) + 
     (((isbnInput % 1000000) / 100000) * 4) + 
     (((isbnInput % 100000) / 10000) * 5) +
     (((isbnInput % 10000) / 1000) * 6) + 
     (((isbnInput % 1000) / 100) * 7) + 
     (((isbnInput % 100) / 10) * 8) +
     (((isbnInput % 10) / 1) * 9);
    
    checkSum = weightSum % 11;
    
    cout << "Checksum: " << checkSum << endl;
    
    
    
    
    
    
    
    
    
    
}