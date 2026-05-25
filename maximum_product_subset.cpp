/*
    =========================================================
    MAXIMUM PRODUCT SUBSET
    =========================================================

    Problem Statement:
    ------------------
    You are given an array containing:
        - Positive numbers
        - Negative numbers
        - Zeros

    Your task is to find the maximum product possible
    by multiplying any subset of elements.

    A subset may contain:
        - One element
        - Multiple elements
        - All elements

    ---------------------------------------------------------
    Example 1:
    ---------------------------------------------------------

    Input:
        arr = {-1, 2, 3, 4}

    Output:
        24

    ---------------------------------------------------------
    Example 2:
    ---------------------------------------------------------

    Input:
        arr = {1,-2,-3,-4}

    Output:
        12

    ---------------------------------------------------------
    Important Observations:
    ---------------------------------------------------------

    1. Positive numbers always increase product

    2. Negative numbers should be taken in pairs

    3. If count of negatives is odd:
       remove the negative closest to zero

    4. Ignore zeros whenever possible

    ---------------------------------------------------------
    Time Complexity:
    ---------------------------------------------------------

        O(n)

    =========================================================
*/

#include <bits/stdc++.h>
using namespace std;

/*
    Function to find maximum product subset
*/
long long maximumProductSubset(vector<int>& arr)
{
    int n = arr.size();

    // Single element case
    if(n == 1)
    {
        return arr[0];
    }

    long long product = 1;

    int negative_count = 0;
    int zero_count = 0;

    // Largest negative means:
    // closest to zero
    int largest_negative = INT_MIN;

    for(int i = 0; i < n; i++)
    {
        // Ignore zeros
        if(arr[i] == 0)
        {
            zero_count++;
            continue;
        }

        // Count negatives
        if(arr[i] < 0)
        {
            negative_count++;

            largest_negative =
                max(largest_negative, arr[i]);
        }

        // Multiply non-zero elements
        product *= arr[i];
    }

    // All zeros
    if(zero_count == n)
    {
        return 0;
    }

    /*
        Special Case:
        Only one negative and rest zeros
    */
    if(negative_count == 1 &&
       zero_count + negative_count == n)
    {
        return 0;
    }

    // If negatives are odd
    if(negative_count % 2 == 1)
    {
        // Remove largest negative
        product /= largest_negative;
    }

    return product;
}

/*
    Driver Code
*/
int main()
{
    vector<int> arr = {1,-2,-3,-4};

    cout << "Maximum Product Subset = "
         << maximumProductSubset(arr);

    return 0;
}
