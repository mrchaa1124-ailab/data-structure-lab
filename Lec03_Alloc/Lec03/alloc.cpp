#include <iostream>

int main() {
    char* str = new char[1000];

    // C++에서는 NULL 대신 현대적인 nullptr 사용을 권장합니다.
    if (str == nullptr) {
        printf("Insufficient memory available\n");
    }
    else {
        printf("Allocated 1000 bytes\n");
        delete[] str;
        printf("Memory freed\n");
    }

    return 0;
}