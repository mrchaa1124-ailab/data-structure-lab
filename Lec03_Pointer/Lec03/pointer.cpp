#include <iostream> // printf 사용을 위한 헤더 (또는 <cstdio> 가능)


// 포인터를 이용한 두 변수의 값 교체 
void swap(int* px, int* py) {
    int tmp;
    tmp = *px;
    *px = *py;
    *py = tmp;
}

int main() {


    int a = 1, b = 2;

    printf("SWAP을 호출하기 전: a = %d, b = %d\n", a, b);
    swap(&a, &b);

    // 출력 메시지의 오타를 '호출한 후'로 수정하고 결과를 확인합니다.
    printf("SWAP을 호출한 후: a = %d, b = %d\n", a, b);

    return 0;
}