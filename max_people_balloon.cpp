/*
    =========================================================
    MAXIMUM PEOPLE IN A BALLOON
    =========================================================

    Problem Statement:
    ------------------
    You are given:

    - n       -> Total number of people
    - arr[]   -> Array containing weight of each person
    - y       -> Maximum weight capacity of the balloon

    Find the maximum number of people that can fly in the
    balloon such that the total weight does not exceed y.

    ---------------------------------------------------------
    Example:
    ---------------------------------------------------------

    Input:
        arr = {40,20,30,10,50}
        y = 100

    Output:
        4

    Explanation:
        We can choose:
            10 + 20 + 30 + 40 = 100

        Total people = 4

    ---------------------------------------------------------
    Greedy Visualization:
    ---------------------------------------------------------

    Original Array:
        [40,20,30,10,50]

    After Sorting:
        [10,20,30,40,50]

    Step-by-Step:

        sum = 0

        Take 10 -> sum = 10
        Take 20 -> sum = 30
        Take 30 -> sum = 60
        Take 40 -> sum = 100
        Take 50 -> exceeds capacity

    Maximum People = 4

    ---------------------------------------------------------
    Approach:
    ---------------------------------------------------------

    We use Greedy Algorithm:

    1. Sort the array
    2. Choose lighter people first
    3. Keep adding until capacity exceeds y

    This works because choosing smaller weights allows
    maximum number of people.

    ---------------------------------------------------------
    Time Complexity:
    ---------------------------------------------------------

        Sorting  -> O(n log n)
        Traversal -> O(n)

        Total -> O(n log n)

    =========================================================
*/

#include <bits/stdc++.h>
using namespace std;

/*
    Function to find maximum people
*/
int max_people(vector<int> arr, int n, int y)
{
    // Sort weights in ascending order
    sort(arr.begin(), arr.end());

    int sum = 0;
    int count = 0;

    // Choose smallest weights first
    for(int i = 0; i < n; i++)
    {
        // Check if adding current person
        // exceeds balloon capacity
        if(sum + arr[i] <= y)
        {
            sum += arr[i];
            count++;
        }
        else
        {
            break;
        }
    }

    return count;
}

/*
    Driver Code
*/
int main()
{
    vector<int> arr = {40,20,30,10,50};

    int n = arr.size();

    int y = 100;

    cout << "Maximum People = "
         << max_people(arr, n, y);

    return 0;
}
