#include <cstdio>

#define MAX_LIST_SIZE 100

class ArrayList {
private:
    int data[MAX_LIST_SIZE];
    int length;

public:
    ArrayList(void) {
        length = 0;
    }

    // 삽입 연산 
    void insert(int pos, int e) {
        if (!isFull() && pos >= 0 && pos <= length) {
            for (int i = length; i > pos; i--) {
                data[i] = data[i - 1];
            }
            data[pos] = e;
            length++;
        }
        else {
            printf("포화상태 오류 또는 삽입 위치 오류\n");
        }
    }

    // 삭제 연산 
    void remove(int pos) {
        if (!isEmpty() && pos >= 0 && pos < length) {
            for (int i = pos + 1; i < length; i++) {
                data[i - 1] = data[i];
            }
            length--;
        }
        else {
            printf("공백상태 오류 또는 삭제 위치 오류\n");
        }
    }

    int getEntry(int pos) {
        return data[pos];
    }

    bool isEmpty() {
        return length == 0;
    }

    bool isFull() {
        return length == MAX_LIST_SIZE;
    }

    bool find(int item) {
        for (int i = 0; i < length; i++) {
            if (data[i] == item) return true; // data[a] -> data[i]로 수정
        }
        return false;
    }

    void replace(int pos, int e) {
        data[pos] = e;
    }

    int size() {
        return length;
    }

    void clear() {
        length = 0; // 비교 연산(==)을 대입 연산(=)으로 수정
    }

    void display() {
        printf("[배열로 구현한 리스트 항목 수 = %2d] : ", size());
        for (int i = 0; i < size(); i++) { // if < size() -> i < size()로 수정
            printf(" [%2d] ", data[i]);
        }
        printf("\n");
    }
};

// 테스트를 위한 main 함수 추가
int main() {
    ArrayList list;

    list.insert(0, 10);
    list.insert(0, 20);
    list.insert(1, 30);
    list.insert(list.size(), 40);
    list.insert(2, 50);
    list.display();

    list.remove(2);
    list.remove(list.size() - 1);
    list.remove(0);
    list.replace(1, 90);
    list.display();

    list.clear();
    list.display();

    return 0;
}