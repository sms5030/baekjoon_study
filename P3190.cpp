#include <iostream>
#include <queue>

#define STATE_BLANK 0
#define STATE_SNAKE 1
#define STATE_APPLE 2
#define STATE_FAIL 3

#define DIR_UP 0
#define DIR_LEFT 1
#define DIR_DOWN 2
#define DIR_RIGHT 3

using namespace std;

int DummyGame();

int mapInfo[101][101] = { 0 };
int N, K, L;
queue<int> snakeInfo;
queue<pair<int, char> > moveInfo;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    
    cin >> K;
    for (int i = 0; i < K; i++) {
        int tempI, tempJ;
        cin >> tempI >> tempJ;
        mapInfo[tempI - 1][tempJ - 1] = STATE_APPLE;
    }

    cin >> L;
    for (int i = 0; i < L; i++) {
        int count;
        char direction;
        cin >> count >> direction;
        moveInfo.push(make_pair(count, direction));
    }
    cout << DummyGame() << endl;
}

int DummyGame() {
    int turnCount = 0;
    int directionInfo = DIR_RIGHT;
    int snakeHeadPos = 0;
    snakeInfo.push(0);
    mapInfo[0][0] = STATE_SNAKE;

    int prevCount = 0;
    while (moveInfo.size() > 0) {
        pair<int, char> movePair = moveInfo.front();
        moveInfo.pop();
        int curCount = movePair.first;
        char direction = movePair.second;
        int count = curCount - prevCount;
        prevCount = curCount;

        for (int turn = 0; turn < count; turn++) {
            int moveState = STATE_FAIL;
            int posI = snakeHeadPos / N;
            int posJ = snakeHeadPos % N;
            if (directionInfo == DIR_UP) {
                if (posI - 1 >= 0 && mapInfo[posI - 1][posJ] != STATE_SNAKE) {
                    moveState = mapInfo[posI - 1][posJ];
                    mapInfo[posI - 1][posJ] = STATE_SNAKE;
                    snakeInfo.push((posI - 1) * N + posJ);
                    snakeHeadPos = (posI - 1) * N + posJ;
                }
            } else if (directionInfo == DIR_DOWN) {
                if (posI + 1 < N && mapInfo[posI + 1][posJ] != STATE_SNAKE) {
                    moveState = mapInfo[posI + 1][posJ];
                    mapInfo[posI + 1][posJ] = STATE_SNAKE;
                    snakeInfo.push((posI + 1) * N + posJ);
                    snakeHeadPos = (posI + 1) * N + posJ;
                }
            } else if (directionInfo == DIR_LEFT) {
                if (posJ - 1 >= 0 && mapInfo[posI][posJ - 1] != STATE_SNAKE) {
                    moveState = mapInfo[posI][posJ - 1];
                    mapInfo[posI][posJ - 1] = STATE_SNAKE;
                    snakeInfo.push(posI * N + posJ - 1);
                    snakeHeadPos = posI * N + posJ - 1;
                }
            } else if (directionInfo == DIR_RIGHT) {
                if (posJ + 1 < N && mapInfo[posI][posJ + 1] != STATE_SNAKE) {
                    moveState = mapInfo[posI][posJ + 1];
                    mapInfo[posI][posJ + 1] = STATE_SNAKE;
                    snakeInfo.push(posI * N + posJ + 1);
                    snakeHeadPos = posI * N + posJ + 1;
                }
            }
            
            turnCount++;
            if (moveState == STATE_FAIL) {
                return turnCount;  // STATE_FAIL
            } else if (moveState == STATE_BLANK) {
                int snakeTailPos = snakeInfo.front();
                int tailPosI = snakeTailPos / N;
                int tailPosJ = snakeTailPos % N;
                mapInfo[tailPosI][tailPosJ] = STATE_BLANK;
                snakeInfo.pop();
            }
        }
        directionInfo = direction == 'L' ? (directionInfo + 1) % 4 : (4 + directionInfo - 1) % 4;
    }

    int moveState = STATE_SNAKE;
    while (moveState != STATE_FAIL) {
        int moveState = STATE_FAIL;
        int posI = snakeHeadPos / N;
        int posJ = snakeHeadPos % N;
        if (directionInfo == DIR_UP) {
            if (posI - 1 >= 0 && mapInfo[posI - 1][posJ] != STATE_SNAKE) {
                moveState = mapInfo[posI - 1][posJ];
                mapInfo[posI - 1][posJ] = STATE_SNAKE;
                snakeInfo.push((posI - 1) * N + posJ);
                snakeHeadPos = (posI - 1) * N + posJ;
            }
        } else if (directionInfo == DIR_DOWN) {
            if (posI + 1 < N && mapInfo[posI + 1][posJ] != STATE_SNAKE) {
                moveState = mapInfo[posI + 1][posJ];
                mapInfo[posI + 1][posJ] = STATE_SNAKE;
                snakeInfo.push((posI + 1) * N + posJ);
                snakeHeadPos = (posI + 1) * N + posJ;
            }
        } else if (directionInfo == DIR_LEFT) {
            if (posJ - 1 >= 0 && mapInfo[posI][posJ - 1] != STATE_SNAKE) {
                moveState = mapInfo[posI][posJ - 1];
                mapInfo[posI][posJ - 1] = STATE_SNAKE;
                snakeInfo.push(posI * N + posJ - 1);
                snakeHeadPos = posI * N + posJ - 1;
            }
        } else if (directionInfo == DIR_RIGHT) {
            if (posJ + 1 < N && mapInfo[posI][posJ + 1] != STATE_SNAKE) {
                moveState = mapInfo[posI][posJ + 1];
                mapInfo[posI][posJ + 1] = STATE_SNAKE;
                snakeInfo.push(posI * N + posJ + 1);
                snakeHeadPos = posI * N + posJ + 1;
            }
        }

        turnCount++;
        if (moveState == STATE_FAIL) {
            return turnCount;  // STATE_FAIL
        } else if (moveState == STATE_BLANK) {
            int snakeTailPos = snakeInfo.front();
            int tailPosI = snakeTailPos / N;
            int tailPosJ = snakeTailPos % N;
            mapInfo[tailPosI][tailPosJ] = STATE_BLANK;
            snakeInfo.pop();
        }
    }

    return turnCount;
}