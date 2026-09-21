#include <iostream>

const int MAX_SIZE = 10;

void sub(int x, int arr[]) {
    x = 10;
    arr[0] = 10;
}

int main() {
    int var = 0;
    int list[MAX_SIZE];

    list[0] = 0;
    sub(var, list);

    std::cout << "var = " << var << std::endl;       // 출력: 0 (값에 의한 호출, Pass by Value)
    std::cout << "list[0] = " << list[0] << std::endl; // 출력: 10 (주소에 의한 호출, Pass by Reference)

    return 0;
}