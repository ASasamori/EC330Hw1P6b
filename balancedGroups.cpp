// Using tutorialspoint

#include "balancedGroups.h"
#include <map>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// your includes here

Assignment balancedGroups(vector<int> const &birthdays)
{
    // Initializes new vector for bithday's that's not constant
    vector<int> newBirth;

    // Makes sure that the birthday vector size matches the original vector
    newBirth.resize(birthdays.size());
    for (int i = 0; i < birthdays.size(); i++)
    {
        newBirth[i] = birthdays[i];
    }

    // Initizlies each vector
    vector<int> group1;
    vector<int> group2;

    // Sorts the vector in descending order
    sort(newBirth.begin(), newBirth.end(), greater<int>());

    // Initializes the summation of each of the group vectors
    int sum1 = 0;
    int sum2 = 0;

    // Iterates through each element of the birthday list
    for (int i = 0; i < newBirth.size(); i++)
    {
        // Checks if the summation of the two groups are the same
        // adds the element to the first group (arbitrary)
        if (sum1 == sum2)
        {
            group1.push_back(newBirth[i]);
            sum1 += newBirth[i];
        }

        else if (sum1 > sum2)
        {
            group2.push_back(newBirth[i]);
            sum2 += newBirth[i];
        }
        else if (sum1 < sum2)
        {
            group1.push_back(newBirth[i]);
            sum1 += newBirth[i];
        }
    }
    return Assignment(0, group1, group2);
}

// Main function to test accuracy
int main()
{
    vector<int> birthDates = {5, 15, 30, 16};
    Assignment result = balancedGroups(birthDates);
    result.printAssignment();
    return 0;
}
/* your helper function here if you have any */
