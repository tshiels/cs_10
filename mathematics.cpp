//  =============== BEGIN ASSESSMENT HEADER ================
/// @file math.cpp 
/// @brief assn6/math
///
/// @author Thomas Shiels [tshie001@ucr.edu]
/// @date May 17, 2015
///
/// @par Plagiarism Section
/// I hereby certify that I have not received assistance on this assignment, 
/// or used code, from ANY outside source other than the instruction team.
//  ================== END ASSESSMENT HEADER ===============
#include <iostream>
#include <cmath>
#include <cctype>
using namespace std;

const int OK = 0;
const int DIV_ZERO = 1;
const int SQRT_ERR = 2;

int acquireOperands(const string &op, double &x, double &y, double &z)
{
    cout << "Enter your first number: ";
    cin >> x;
    cout << endl;
    
    cout << "Enter your second number: ";
    cin >> y;
    cout << endl;
    
    if (op == "quadratic")
    {
        cout << "Enter your third number: ";
        cin >> z;
        cout << endl;
    }
    
    
    if (op == "division" || op == "pythagorean")
    {
        return 2;
    }
    else if (op == "quadratic")
    {
        return 3;
    }
    return 0;
}

int division(double x, double y, double &result)
{
    if (y > 0 || y < 0)
    {
        result = (x / y);
        result = (x / y) + (x - result * y);
        return OK;
    }
    else return DIV_ZERO;
}

int quadratic(double a, double b, double c, double &root1, double &root2)
{
    
    
    if (a > 0 || a < 0)
    {
        if ((b * b - 4 * a * c) >= 0)
        {
            root1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
            root2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
            
            return OK;
        }
        else 
        {
            return SQRT_ERR;
        }
        
    }
    else 
    {
        return DIV_ZERO;
    }
}

int pythagorean(double a, double b, double &c)
{
    c = sqrt(pow(a, 2.0) + pow(b, 2.0));
    
    return OK;
}


int main()
{
    string op;
    double x = 0.0;
    double y = 0.0;
    double z = 0.0;
    
    do
    {
        cout << "Please choose an operation: ";
        cin >> op;
        cout << endl;
    
    
        // get operation
        if (!(op == "division" || op == "pythagorean" || op == "quadratic"))
        {
            cout << "Error: Operation not supported.";
            cout << endl;
        }
    } while (!(op == "division" || op == "pythagorean" || op == "quadratic"));
    
    if (acquireOperands(op, x, y, z) == 2) 
    {
        if (op == "division")
        {
            if (division(x, y, z) == OK)
            {
                cout << "Equation: " << x << " / " << y << endl;
                cout << "Result: " << z << endl;
            }
            else
            {
                cout << "Equation: " << x << " / " << y << endl;
                cout << "Error: Cannot divide by zero." << endl;
                
                return 0;
            }
        }
        else if (op == "pythagorean")
        {
            if (pythagorean(x, y, z) == OK)
            {
                cout << "Equation: sqrt(" << x << "^2 + " << y << "^2)";
                cout << endl;
                cout << "Result: " << z << endl;
            }
        }
    }
    else
    {
        double root1 = 0.0;
        double root2 = 0.0;
        
        if (quadratic(x, y, z, root1, root2) == OK)
        {
                
            cout << "Equation: " << x << "x^2 + " << y << "x + " << z <<
                " = 0";
            cout << endl;
            if (root1 == root2)
            {
                cout << "Result: " << root1 << endl;
            }
            else
            {
                cout << "Result: " << root2 << ", " << root1 << endl;
            }
                
        }
        else if (quadratic(x, y, z, root1, root2) == DIV_ZERO)
        {
            cout << "Equation: " << x << "x^2 + " << y << "x + " << z <<
                " = 0";
            cout << endl;
            cout << "Error: Cannot divide by zero." << endl;
                
            return 0;
        }
        else if (quadratic(x, y , z, root1, root2) == SQRT_ERR)
        {
            cout << "Equation: " << x << "x^2 + " << y << "x + " << z <<
                " = 0";
            cout << endl;
            cout << "Error: Cannot take square root of a negative " <<
                "number.";
            cout << endl;
                
            return 0;
        }
    }
      
    return 0;
}