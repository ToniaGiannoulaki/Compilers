// PikrakisExercise2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <stack>
#include <queue>
using namespace std;

int main()
{
    queue<string> prodtree;
    prodtree.push("S");
    string treetemp;
    stack<string> analysisStack; // Stack for the analysis
    analysisStack.push("$S"); // Adding the first element
    map <string, string> table = { // Using map for the grammar rule table
        {"S(","(X)"},         
        {"X(","YZ"},
        {"Xa","YZ"},
        {"Xb","YZ"},
        {"Y(","S"},
        {"Ya","a"},
        {"Yb","b"},
        {"Z)","e"},
        {"Z*","*X"},
        {"Z+","+X"},
        {"Z-","-X"}
    };
    string inp;
    cin >> inp; // User input 
    inp.append("$"); // Adding $ at the end of the input 
    char x; // x character during analysis
    char a; // a character during analysis
    int pos = 0; // Used so we don't need to delete something from the original input 
    string prod; // For the productions
    string tempS = ""; // A temporary string used for various scenarios
    string tempS2 = "";
	while (inp.length() - 1 != pos) // This runs as long as we haven't reached the end of the string 
	{
        x = analysisStack.top()[analysisStack.top().length() - 1]; // Setting x as the rightmost character in the top of the stack
        a = inp[pos]; // Setting a as the "leftmost" character in the input
		if (x == '(' || x == ')' || x == 'a' || x == 'b' || x == '*' || x == '+' || x == '-' || x == '$') // Check if the stack character is a terminal
		{
            if (x != '$' && x == a) // 1st rule
            {
                pos++;
                tempS = analysisStack.top(); // Save the top of the analysis stack
                tempS.pop_back(); // Remove the last symbol 
                analysisStack.push(tempS); // Re-add it to the analysis stack
                tempS = ""; // Reset the temporary string 
            }
            else if (x == a && a == '$') // 2nd rule. Using break because it's over and is accepted
            {
                cout << "Accepted!";
                break;
            }
		}
        else if (x == 'S' || x == 'X' || x == 'Y' || x == 'Z') // If it's not a terminal
        {
	        tempS += analysisStack.top()[analysisStack.top().length() - 1]; // Essentially, we save x 
            tempS += inp[pos]; // And a
        	try // 3rd rule   
        	{
                prod.append(table.at(tempS)); // Check the table, if found and no exception occurs, the third rule is valid and saved as production
                
                reverse(prod.begin(), prod.end()); // Reverse it to add backwards, as needed
                tempS2 = analysisStack.top(); // Get the top of the analysis stack
                tempS2.pop_back(); // Remove the last character
                if (prod != "e") { // Check if it's "e" (empty)
                    tempS2.append(prod); // Append prod to tempS2 
                    reverse(prod.begin(), prod.end()); // Reverse it back to normal
					treetemp = prodtree.back(); // Store in a variable
                    prodtree.push(treetemp.replace(prodtree.back().find(analysisStack.top()[analysisStack.top().length() - 1]), 1, table.at(tempS))); // Replace in the tree according to the production 
                }
                else // If it's "e"
                {
                    treetemp = prodtree.back(); // Same process
                    prodtree.push(treetemp.erase(prodtree.back().find(analysisStack.top()[analysisStack.top().length() - 1]), 1)); // Here, we simply remove what had "e" as its production 
                }
                analysisStack.push(tempS2); // Push the modified stack back
                treetemp = ""; // Reset all modified strings
                prod = "";
                tempS = "";
                tempS2 = "";
        	}
        	catch (exception e) // 4th rule (if an exception is found, the production doesn't exist, and the string is not accepted)
        	{
                cout << "Not accepted ";
                break;
        	}
		}
		cout << analysisStack.top() << "\n"; // Print the step
	}
	while (!prodtree.empty()) // While the tree is not empty 
	{
        if (prodtree.size() > 1) { // As long as it's not the last element, print and add an arrow 
            cout << prodtree.front() << "=>";
        }
        else // Otherwise, for the last element, don't add an arrow
        {
            cout << prodtree.front();
        }
        prodtree.pop(); // Remove the printed item
	}
}
