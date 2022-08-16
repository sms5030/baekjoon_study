#include <iostream>
#define PACKAGE_NUM 6

using namespace std;

int N, M, pricePackage, price, minPricePackage = 100000, minPrice = 100000, totalPrice;
int main () {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> pricePackage >> price;
        if (minPricePackage > pricePackage) {
            minPricePackage = pricePackage;
        }
        if (minPrice > price) {
            minPrice = price;
        }
    }

    if (minPricePackage > minPrice * PACKAGE_NUM) {
        minPricePackage = minPrice * PACKAGE_NUM;
    }

    totalPrice = minPricePackage * (N / PACKAGE_NUM);
    N %= PACKAGE_NUM;
    totalPrice += (minPricePackage < minPrice * N ? minPricePackage : minPrice * N);
    cout << totalPrice << endl;

    return 0;
}