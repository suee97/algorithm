#include <bits/stdc++.h>
using namespace std;

int gear1[8];
int gear2[8];
int gear3[8];
int gear4[8];
int relation[3]; // 1이면 N-S 조합

void rotateGear(int gear[], int dir) {
    if (dir == 1) {
        int tmp = gear[7];
        int tmpArr[8];
        for (int i = 0; i < 7; i++) tmpArr[i+1] = gear[i];
        tmpArr[0] = tmp;
        copy_n(tmpArr, 8, gear);
    }
    if (dir == -1) {
        int tmp = gear[0];
        int tmpArr[8];
        for (int i = 0; i < 7; i++) tmpArr[i] = gear[i+1];
        tmpArr[7] = tmp;
        copy_n(tmpArr, 8, gear);
    }
}

void updateRelation() {
    for (int i = 0; i < 3; i++) relation[i] = 0;
    if (gear1[2] != gear2[6]) relation[0] = 1;
    if (gear2[2] != gear3[6]) relation[1] = 1;
    if (gear3[2] != gear4[6]) relation[2] = 1;
}

int main() {
    string s1; cin >> s1;
    for (int j = 0; j < 8; j++) gear1[j] = s1[j] - '0';
    string s2; cin >> s2;
    for (int j = 0; j < 8; j++) gear2[j] = s2[j] - '0';    
    string s3; cin >> s3;
    for (int j = 0; j < 8; j++) gear3[j] = s3[j] - '0';    
    string s4; cin >> s4;
    for (int j = 0; j < 8; j++) gear4[j] = s4[j] - '0';    

    int k;
    cin >> k;
    
    for (int i = 0; i < k; i++) {
        int gearNum, dir;
        cin >> gearNum >> dir;
        updateRelation();
        if (gearNum == 1) {
            rotateGear(gear1, dir);
            if (relation[0] == 1) {
                rotateGear(gear2, -dir);
                if (relation[1] == 1) {
                    rotateGear(gear3, dir);
                    if (relation[2] == 1) {
                        rotateGear(gear4, -dir);
                    }
                }
            }
        }
        if (gearNum == 2) {
            rotateGear(gear2, dir);
            if (relation[0] == 1) {
                rotateGear(gear1, -dir);
            }
            if (relation[1] == 1) {
                rotateGear(gear3, -dir);
                if (relation[2] == 1) {
                    rotateGear(gear4, dir);
                }
            }
        }
        if (gearNum == 3) {
            rotateGear(gear3, dir);
            if (relation[1] == 1) {
                rotateGear(gear2, -dir);
                if (relation[0] == 1) {
                    rotateGear(gear1, dir);
                }
            }
            if (relation[2] == 1) {
                rotateGear(gear4, -dir);
            }
        }
        if (gearNum == 4) {
            rotateGear(gear4, dir);
            if (relation[2] == 1) {
                rotateGear(gear3, -dir);
                if (relation[1] == 1) {
                    rotateGear(gear2, dir);
                    if (relation[0] == 1) {
                        rotateGear(gear1, -dir);
                    }
                }
            }
        }
    }

    int sum = 0;
    if (gear1[0] == 1) sum += 1;
    if (gear2[0] == 1) sum += 2;
    if (gear3[0] == 1) sum += 4;
    if (gear4[0] == 1) sum += 8;
    cout << sum;

}