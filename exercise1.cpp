// exercise1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	cout << "ENTER STRING: "; // Prompt the user to enter a string
	string symbseira; 
	cin >> symbseira; // The user inputs the string into this variable
	int something = symbseira.size(); // We store the size of the string in the variable something
	stack <char> s; // Define stack s
	bool check = true; // Boolean that will help us determine if the string starts with 'x' or not
	int counterx = 0; // Counts the 'x'
	int countery = 0; // Counts the 'y'
	if (symbseira[0] == 'x') // If the string starts with 'x'
	{
		cout << "the first character is x, so we continue \n ";
		for (int i = 0; i < something; i++) // Start iteration and take the elements of the string one by one using i
		{
			if (symbseira[i] == 'x' || symbseira[i] == 'y') // Check if the elements of the string are 'x' or 'y'
			{
				cout << "the symbol is x or y, we continue \n ";
				if (symbseira[i] == 'x') // If it is 'x'
				{
					s.push(symbseira[i]); // Insert element 'x' into the stack
					counterx++; // Counter for 'x' increases by 1
					cout << "the symbol is x so added to the stack\n ";
				}
				else // If it is 'y' 
				{
					cout << "the symbol is y,";
					countery++; // Counter for 'y' increases by 1
					if (!s.empty()) // If the stack is not empty
					{
						s.pop(); // Remove element from the stack
						cout << "removed the x \n";
					}
					else // If the stack is empty
					{
						cout << "there is no x, and since there is no x it is not valid \n";
						break; /* It is not possible to remove an element if the stack is empty, therefore there are fewer 'x's than 'y's,
							      so we exit the loop, the string is not valid */
					}
				}
			
			}
			else
			{
				cout << "Invalid input, the string is not valid \n";
				break; /* The current element in the string is neither 'x' nor 'y', so we exit the loop,
					     the string is not valid */
			}
		}
	}
	else
	{
		cout << "the first symbol is not x, so not accepted \n ";
		check = false; // The string does not start with 'x', so check becomes false, the string is not valid
	}

	if (s.empty() && (counterx == countery) && check) /* If the stack is empty, the 'x's are equal to the 'y's, and check is true
													    (meaning the string starts with 'x'), then the string is accepted */
	{
		cout << "It was accepted";
	}
	else // If the above conditions are not met, the string is not accepted
	{
		cout << "not accepted";
	}
}

/* xyxyxyxyxyxyyxyxyxyxyxyxxxxyyy 
 * we put them in order in the stack and do the following 
 * {x    if x counterx++
 * y    if y countery++
 * countery>counterx break cout error}
 * .....
 * counterx == countery {
 * cout correct
 * }
 * else {cout error}
 *
 */
