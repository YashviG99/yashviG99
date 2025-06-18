#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cout << "Enter number of members: ";
    cin >> n;

    float paid[100], toeach [100], total = 0, average;

    // Input paid amounts
    for (int i = 0; i < n; i++) {
        cout << "Enter amount paid by Member " << i + 1 << ":";
        cin >> paid[i];
        total += paid[i];
    }

    average = total / n;

    // Calculate ammount that has to be paid by each
    for (int i = 0; i < n; i++) {
        toeach [i] = paid[i] - average;
    }

    cout << fixed << setprecision(2);
    cout << "whos pays to whom"<<endl;

    for (int i = 0; i < n; i++) {
        if (toeach [i] < 0) { 
            for (int j = 0; j < n; j++) {
                if (toeach [j] > 0) { 
                    float give = min(-toeach[i], toeach [j]);
                    cout << "Member " << i + 1 << " has to pay" << give
                         << " to Member " << j + 1 << endl;
                    toeach [i] += give;
                    toeach [j] -= give;
                    if (toeach [i] >= -0.01) break;
                }
            }
        }
    }

    return 0;
}