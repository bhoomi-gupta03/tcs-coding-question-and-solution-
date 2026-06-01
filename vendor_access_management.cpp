/*
    =========================================================
    VENDOR ACCESS MANAGEMENT SYSTEM
    =========================================================

    Problem Statement:
    ------------------
    A company maintains a list of registered vendors.

    You are given:
    - n registered vendor IDs
    - m operations

    Supported Operations:

    1. ENTRY id
       - If the vendor is registered, allow entry and
         mark them as active.
       - Otherwise, count it as a blocked attempt.

    2. EXIT id
       - Remove the vendor from the active list.

    3. CHECK id
       - A status-check operation.

    At the end, print:
    - Number of active vendors
    - Number of blocked entry attempts

    ---------------------------------------------------------
    Example:
    ---------------------------------------------------------

    Input:
        3
        101 102 103
        5
        ENTRY 101
        ENTRY 200
        ENTRY 102
        EXIT 101
        ENTRY 103

    Output:
        active vendors : 2
        blocked : 1

    ---------------------------------------------------------
    Approach:
    ---------------------------------------------------------

    Use two unordered_sets:

    1. registered
       Stores valid vendor IDs.

    2. active
       Stores vendors currently inside.

    ENTRY:
        Check if vendor exists in registered set.

    EXIT:
        Remove vendor from active set.

    CHECK:
        Count/handle status checks.

    ---------------------------------------------------------
    Time Complexity:
    ---------------------------------------------------------

        Registration : O(n)
        Operations   : O(m)

        Overall:
            O(n + m)

    Space Complexity:
        O(n)

    =========================================================
*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    unordered_set<int> registered;

    for(int i = 0; i < n; i++) {
        int id;
        cin >> id;
        registered.insert(id);
    }

    int m;
    cin >> m;

    unordered_set<int> active;

    int blocked = 0;
    int checked = 0;

    for(int i = 0; i < m; i++) {

        string op;
        int x;

        cin >> op >> x;

        if(op == "ENTRY") {

            if(registered.count(x)) {
                active.insert(x);
            }
            else {
                blocked++;
            }

        }
        else if(op == "CHECK") {

            checked++;

        }
        else if(op == "EXIT") {

            active.erase(x);
        }
    }

    cout << "active vendors : "
         << active.size() << endl;

    cout << "blocked : "
         << blocked << endl;

    return 0;
}
