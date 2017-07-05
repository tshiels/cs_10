//  =============== BEGIN ASSESSMENT HEADER ================
/// @file pig.cpp 
/// @brief assn5/pig
///
/// @author Thomas Shiels [tshie001@ucr.edu]
/// @date May 10, 2015
///
/// @par Plagiarism Section
/// I hereby certify that I have not received assistance on this assignment, 
/// or used code, from ANY outside source other than the instruction team.
//  ================== END ASSESSMENT HEADER ===============
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <ios>
#include <iomanip>

using namespace std;

int genRandInt(int minNumber, int maxNumber) 
{
    
    int randomNumber = 0;
    
    randomNumber = (rand() % (maxNumber - minNumber + 1)) + minNumber;
    
    return randomNumber;
}

int singleTurn(int nValue) //simulates one turn of pig
{
    int score = 0;
    int roll = 0;
    
    while (score < nValue) {
        roll = genRandInt(1,6);  
        if (roll == 1)
        {
            score = 0;
            return score;
        }
        score = score + roll;
    }
    
    return score;
}


int main() 
{
    int nValue = 0;
    int nTurns = 0;
    srand(time(0));
    int i = 0;
    int scoreTotal = 0;
    
    cout << "What value should we hold at? ";
    cin >> nValue;
    cout << endl;
    
    cout << "Hold-at-N turn simulations? ";
    cin >> nTurns;
    cout << endl;
    
    double counter1 = 0;
    double counter2 = 0;
    double counter3 = 0;
    double counter4 = 0;
    double counter5 = 0;
    double counter6 = 0;
    double counter7 = 0;
    
    for (i = 0; i < nTurns; ++i)
    {
        scoreTotal = singleTurn(nValue);
        
        if (scoreTotal == 0) {
            ++counter1;
        }
        else if (scoreTotal == nValue) {
            ++counter2;
        }
        else if (scoreTotal == nValue + 1) {
            ++counter3;
        }
        else if (scoreTotal == nValue + 2) {
            ++counter4;
        }
        else if (scoreTotal == nValue + 3) {
            ++counter5;
        }
        else if (scoreTotal == nValue + 4) {
            ++counter6;
        }
        else {
            ++counter7;
        }
    }
    
    
    
    cout << "Score" << '\t' << "Estimated Probability" << endl;
    cout << 0 << '\t' << fixed << setprecision(6) << counter1 / nTurns << endl;
    cout << nValue << '\t' << fixed << setprecision(6) << counter2 / nTurns <<
        endl;
    cout << nValue + 1 << '\t' << fixed << setprecision(6) <<
        counter3 / nTurns << endl;
    cout << nValue + 2 << '\t' << fixed << setprecision(6) <<
        counter4 / nTurns << endl;
    cout << nValue + 3 << '\t' << fixed << setprecision(6) <<
        counter5 / nTurns << endl;
    cout << nValue + 4 << '\t' << fixed << setprecision(6) <<
        counter6 / nTurns << endl;
    cout << nValue + 5 << '\t' << fixed << setprecision(6) <<
        counter7 / nTurns << endl;
    
    
    return 0;
}