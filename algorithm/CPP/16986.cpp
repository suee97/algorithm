#include<bits/stdc++.h>
using namespace std;

int main() {
    int isWin = 0;

    int n, k;
    cin >> n >> k;

    vector<int> gameCase;
    int arr[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++) gameCase.push_back(i);

    int gh[20];
    int mh[20];

    for (int i = 0; i < 20; i++) {
        cin >> gh[i];
    }
    for (int i = 0; i < 20; i++) {
        cin >> mh[i];
    }

    do {
        for (int i = 0; i < n; i++) {
            cout << gameCase[i] << ' ';
        }
        cout << '\n';

        int jCount = 0;
        int gCount = 0;
        int mCount = 0;

        char gamer1 = 'J';
        char gamer2 = 'G';

        for (int i = 0; i < 20; i++) {
            if (gamer1 == 'J' && gamer2 == 'G') {
                int result = arr[gameCase[i]][gh[i]-1];
                if (result == 0) {
                    
                } else if (result == 1) {

                } else if (result == 2) {

                }
            }
        }

    } while (next_permutation(gameCase.begin(), gameCase.end()));
}