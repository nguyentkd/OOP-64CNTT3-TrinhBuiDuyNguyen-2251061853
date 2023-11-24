#include <iostream>
using namespace std;
class SoNguyen{
	private:
    	int soA;
    	int soB;

public:
    SoNguyen(int a, int b) : soA(a), soB(b) {}

    int TinhTong() const {
        return soA + soB;
    }
};

int main() {
    int a, b;
    cin >> a >> b; 
    SoNguyen tongHaiSo(a, b);
    int ketQua = tongHaiSo.TinhTong();
    cout<< ketQua <<endl;
    return 0;
}
