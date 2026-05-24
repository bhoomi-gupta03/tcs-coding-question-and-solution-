/*
    =========================================================
    VALID SOLDIER ARRANGEMENT
    =========================================================

    Problem Statement:
    ------------------
    You are given:

    - n       -> Total number of soldiers
    - values  -> Array of allowed soldier numbers
    - end     -> Required number of the last soldier

    Arrange the soldiers in a straight line such that:

    1. Each soldier number is chosen from values[]
    2. First soldier number must be 1
    3. Last soldier number must be end
    4. No two adjacent soldiers can have the same number

    Print all valid arrangements and return the total count.

    ---------------------------------------------------------
    Example:
    ---------------------------------------------------------

    Input:
        n = 4
        values = {1,2,3,4}
        end = 3

    Output:
        1 2 1 3
        1 2 4 3
        1 3 1 3
        1 3 2 3
        1 3 4 3
        1 4 1 3
        1 4 2 3

        Total Valid Arrangements = 7

    ---------------------------------------------------------
    Recursion Tree:
    ---------------------------------------------------------

                           [1 _ _ 3]
                        /      |      \
                       2       3       4
                     / | \   / | \   / | \
                    1  3 4  1 2 4  1 2 3
                    |  | |  | | |  | | |
                  V  X V  V V V  V V X

    V = Valid Arrangement
    X = Invalid Arrangement

    Example:
        1 2 1 3  -> Valid
        1 2 3 3  -> Invalid (adjacent same)

    ---------------------------------------------------------
    Approach:
    ---------------------------------------------------------

    We use Backtracking:

    - Fix first soldier = 1
    - Fix last soldier = end
    - Recursively fill middle positions
    - Skip invalid choices where adjacent soldiers become same

    ---------------------------------------------------------
    Time Complexity:
    ---------------------------------------------------------

        O(k^(n-2))

        where:
        k = values.size()

    =========================================================
*/

#include <bits/stdc++.h>
using namespace std;

/*
    Recursive function to generate valid arrangements
*/
void solve(int index,
           vector<int>& arr,
           vector<int>& values,
           int& count,
           int n)
{
    // Base Case:
    // All middle positions filled
    if(index == n - 1)
    {
        // Check last soldier with previous soldier
        if(arr[n - 1] != arr[n - 2])
        {
            count++;

            // Print valid arrangement
            for(int i = 0; i < n; i++)
            {
                cout << arr[i] << " ";
            }

            cout << endl;
        }

        return;
    }

    // Try every allowed value
    for(int i = 0; i < values.size(); i++)
    {
        int val = values[i];

        // Adjacent soldiers should not be same
        if(val != arr[index - 1])
        {
            arr[index] = val;

            // Recursive call
            solve(index + 1,
                  arr,
                  values,
                  count,
                  n);
        }
    }
}

/*
    Function to count arrangements
*/
int countArrangement(int n,
                     vector<int>& values,
                     int end)
{
    vector<int> arr(n);

    // First soldier fixed
    arr[0] = 1;

    // Last soldier fixed
    arr[n - 1] = end;

    int count = 0;

    // Start filling from index 1
    solve(1,
          arr,
          values,
          count,
          n);

    return count;
}

/*
    Driver Code
*/
int main()
{
    int n = 4;

    vector<int> values = {1, 2, 3, 4};

    int end = 3;

    int ans = countArrangement(n,
                               values,
                               end);

    cout << "\nTotal Valid Arrangements = "
         << ans;

    return 0;
}
