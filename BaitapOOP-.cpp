#include <iostream>

using namespace std;

class chiphi {
private:
    string x;

public:
    chiphi(const string& s) : x(s) {}

    int tinhcp() const {
        int cost = 0;
        size_t i = 0, j = x.length() - 1;

        while (i < j) {
            if (x[i] != x[j]) {
                cost++;
            }
            i++;
            j--;
        }

        return cost;
    }

    bool operator==(const chiphi& k) const {
        return x == k.x;
    }
};

int main() {
    string xau;
    cout << "Nhap xau: ";
    cin >> xau;
    
    chiphi tinh(xau);
    int kq = tinh.tinhcp();

    cout << "Chi phi nho nhat de bien doi mot xau tro thanh xau doi xung: " << kq+1;

    return 0;
}
