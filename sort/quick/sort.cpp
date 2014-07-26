#include <iostream>

const int LEN = 8;
int A[LEN] = {2,8,7,1,3,5,6,4};

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
 * @param a An array
 */
int partition(int a[], int p, int r) {
    int x = a[r - 1];
    int i = p - 1;
    
    for (int j = p; j < r - 1; ++j) {
        if (x > a[j]) {
            ++i;
            int tmp = a[j];
            a[j] = a[i];
            a[i] = tmp;
        }
    }

    int tmp = a[r - 1];
    a[r - 1] = a[i + 1];
    a[i + 1] = tmp;
    
    return i + 1; 
}

/**
 * @param a An array to sort
 * @param start Start position
 * @param len How many items to sort, length
 */
void sort(int a[], int p, int r) {
    if (p >= r)
        return;
    
    int q = partition(a, p, r);

    sort(a, p, q - 1);
    sort(a, q + 1, r);    
}

int main() {
    print(A, 0, LEN);
    sort(A, 0, LEN);
    print(A, 0, LEN);
}