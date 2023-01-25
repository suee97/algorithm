#include <bits/stdc++.h>
using namespace std;

int n, w, L;
int bridge[100];

void moveWithoutAddTruck() {
    int tmp[100];
    for (int i = 0; i < w-1; i++) {
        tmp[i+1] = bridge[i];
    }
    tmp[0] = 0;
    copy(&tmp[0], &tmp[0]+w, &bridge[0]);
}

int getBridgeWeight() {
    int sum = 0;
    for (int i = 0; i < w; i++) sum += bridge[i];
    return sum;
}

int main() {
    cin >> n >> w >> L;
    queue<int> truck;
    int min = 0;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        truck.push(tmp);
    }
    while (1) {
        int curWeight = getBridgeWeight();

        if (truck.empty()) {
            moveWithoutAddTruck();
            min++;
        } else if (curWeight + truck.front() > L) {
            moveWithoutAddTruck();
            if (getBridgeWeight() + truck.front() <= L) {
                bridge[0] = truck.front();
                truck.pop();
            }
            min++;
        } else {
            moveWithoutAddTruck();
            bridge[0] = truck.front();
            truck.pop();
            min++;
        }
        if (truck.empty() && getBridgeWeight() == 0) break;
    }
    cout << min;
}