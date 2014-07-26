#include <iostream>

const int LEN = 11;
int A[LEN] = {5,2,4,6,1,3,1,8,2,4,10};

/**
 * @param array
 * @param start Position
 * @param len Length
 */
void print(const int a[], int start, int len) {
    for (int i = start; i < len; ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}

/**
 * @param a An array to sort
 * @param start Start position
 * @param len How many items to sort, length
 */
void sort(int a[], int start, int len) {
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (a[j] < a[i]) {
                int tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}

/**
 * @param a An array to sort
 * @param start Start position
 * @param len How many items to sort, length
 */
void insertion_sort(int a[], int start, int len) {
    for (int j = 1; j < len; ++j) {
        int k = a[j];
        int i = j - 1;
        while (i >= 0 && a[i] > k) {
            a[i + 1] = a[i];
            --i;
        }
        a[i + 1] = k;
    }
}

int main() {
    print(A, 0, LEN);
    //insertion_sort(A, 0, LEN);
    sort(A, 0, LEN);
    print(A, 0, LEN);
}