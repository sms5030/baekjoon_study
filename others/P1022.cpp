#include <iostream>
#include <vector>
#include <string>

using namespace std;

int GetABS(int n);
int GetValue();

int main() {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    // for (int i = r1; i < r2; i++) {
    //     for (int j = c1; j < c2; j++) {
    //         int len = GetLen(map[i][j]);
    //         int diff = maxLen - len;
    //         string str = "";
    //         for (int k = 0; k < diff; k++) {
    //             str += " ";
    //         }
    //         str += (to_string(map[i][j]) + " ");
    //         cout << str;
    //     }
    //     cout << "\n";
    // }

    return 0;
}

int GetABS(int n) {
    return n > 0 ? n : -n;
}

int GetValue(int r, int c) {
    if (GetABS(r - c) < GetABS(2 * r)) {
        int pivot = r;
        int value = 0;
        if (pivot > 0) {
            if (GetABS(r - c) == 0) {
                value = GetABS(2 * pivot + 1);
                value = value * value;
            } else {
                value = GetABS(2 * (pivot - 1) + 1);
                value = value * value;
            }
            

        } else if (pivot < 0) {

        }
    } else if (GetABS(r - c) < GetABS(2 * c)) {

    } else {
        return -1;
    }

    

    return 0;
}

// #include <iostream>
// #include <vector>
// #include <string>

// using namespace std;

// int map[10001][10001] = { 0 };
// int direction = 0;  // D R U L
// int moveCount = 1;
// int value = 1;
// int maxValue = 10001 * 10001;
// int posR = 4999, posC = 5000;

// void SetMap();
// void MovePosition();
// int GetLen(int val);

// int main() {
//     SetMap();

//     int r1, c1, r2, c2;
//     cin >> r1 >> c1 >> r2 >> c2;
//     r1 += 5000;
//     c1 += 5000;
//     r2 += 5001;
//     c2 += 5001;

//     int maxVal = 0;
//     for (int i = r1; i < r2; i++) {
//         for (int j = c1; j < c2; j++) {
//             if (map[i][j] > maxVal) {
//                 maxVal = map[i][j];
//             }
//         }
//     }

//     int maxLen = GetLen(maxVal);
//     for (int i = r1; i < r2; i++) {
//         for (int j = c1; j < c2; j++) {
//             int len = GetLen(map[i][j]);
//             int diff = maxLen - len;
//             string str = "";
//             for (int k = 0; k < diff; k++) {
//                 str += " ";
//             }
//             str += (to_string(map[i][j]) + " ");
//             cout << str;
//         }
//         cout << "\n";
//     }

//     return 0;
// }

// void SetMap() {
//     while(true) {
//         for (int i = 0; i < 2; i++) {
//             MovePosition();
//             map[posR][posC] = value++;
//             if (value == maxValue) {
//                 return;
//             }
//             direction = (direction + 1) % 4;
//             for(int j = 0; j < moveCount - 1; j++) {
//                 MovePosition();
//                 map[posR][posC] = value++;
//                 if (value == maxValue) {
//                     return;
//                 }
//             }
//         }
//         moveCount++;
//     }
// }

// void MovePosition() {
//     switch(direction) {
//         case 0:
//             posR++;
//             break;
//         case 1:
//             posC++;
//             break;
//         case 2:
//             posR--;
//             break;
//         case 3:
//             posC--;
//             break;
//     }
// }

// int GetLen(int val) {
//     int len = 0;
//     while(val > 0) {
//         val /= 10;
//         len++;
//     }
//     return len;
// }