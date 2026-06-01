/*
    STUDENT GRADE DISTRIBUTION ANALYZER

    Additional Rule:
    ----------------
    If all marks are invalid (not in range 0-100),
    print 'X'.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    unordered_map<char, int> gradeCount;
    bool hasValidMark = false;

    for(int i = 0; i < n; i++) {

        int score;
        cin >> score;

        // Invalid mark
        if(score < 0 || score > 100)
            continue;

        hasValidMark = true;

        if(score >= 90)
            gradeCount['A']++;
        else if(score >= 80)
            gradeCount['B']++;
        else if(score >= 70)
            gradeCount['C']++;
        else if(score >= 60)
            gradeCount['D']++;
        else if(score >= 50)
            gradeCount['E']++;
        else
            gradeCount['F']++;
    }

    // All inputs invalid
    if(!hasValidMark) {
        cout << 'X' << endl;
        return 0;
    }

    char ans = 'A';
    int mx = gradeCount['A'];

    string priority = "ABCDEF";

    for(char grade : priority) {
        if(gradeCount[grade] > mx) {
            mx = gradeCount[grade];
            ans = grade;
        }
    }

    cout << ans << endl;

    return 0;
}
