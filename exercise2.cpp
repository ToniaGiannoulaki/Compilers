// exercise2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    string s = "E";
    
    int steps = 0; // Steps that have been taken
    bool done = false;
    int maxr; // In maxr, we store the maximum value r can take for rule A, to ensure the program terminates
    int r; // In r, we store the random value
    while (!done) // We change done to false whenever a non-terminal rule is added
    {
        srand(time(nullptr));
        
        done = true; // We assume it finishes in this iteration
        if (s.find('E') != string::npos) // We check if E exists (find returns -1 if not found)
        {
            s.replace(s.find('E'), 1, "(Y)"); // Replace E with (Y) according to the first rule
            cout << s << endl; // Display the first change
            steps++; // Increment the steps taken
            done = false;
        }
        if (s.find('Y') != string::npos)
        {
            s.replace(s.find('Y'), 1, "AB"); // Replace Y with AB according to the second rule
            cout << s << endl;
            steps++;
            done = false;
        }
        if (s.find('A') != string::npos)
        {
            if (steps <= 20) // If it exceeds 20 steps, we don't allow the second case of the rule that leads to non-termination
            {
                maxr = 2; // It can take two different values
            }
            else
            {
                maxr = 1;
            }
            r = rand() % maxr + 1;
            if (r == 1)
            {
                s.replace(s.find('A'), 1, "n"); // Replace A with n
                cout << s << endl;
                steps++;
            }
            else
            {
                s.replace(s.find('A'), 1, "E"); // Replace A with E
                cout << s << endl;
                steps++;
                done = false;
            }
        }
        if (s.find('B') != string::npos)
        {
            r = rand() % 3 + 1; // Any of the cases is fine since they all eventually lead to termination
            if (r == 1)
            {
                s.replace(s.find('B'), 1, "-Y"); // Replace B with -Y
                cout << s << endl;
                steps++;
                done = false;
            }
            else if (r == 2)
            {
                s.replace(s.find('B'), 1, "+Y"); // Replace B with +Y
                cout << s << endl;
                steps++;
                done = false;
            }
            else
            {
                s.replace(s.find('B'), 1, ""); // Remove B
                cout << s << endl;
                steps++;
            }
        }
    }
}
