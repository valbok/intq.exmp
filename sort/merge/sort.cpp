#include <iostream>

const int LEN = 9;
int A[LEN] = {2,4,5,7,1,2,3,6,1};

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
 * @param left Items count of left array
 * @param right Items count of right array
 */
void merge(int a[], int start, int left, int right) {
    int i = 0, j = 0;
    int mid = start + left;
    int end = mid + right;
    
    int iii = 0;
    int l[left];
    // Copy left items
    for (int ii = start; ii < mid; ++ii) {
        l[iii] = a[ii];
        ++iii;
    }

    int r[right];
    iii = 0;
    // Copy right items
    for (int ii = mid; ii < end; ++ii) {
        r[iii] = a[ii];
        ++iii;
    }

    for (int step = start; step < end; ++step) {
        if (j >= right && i < left) {
            a[step] = l[i];
            break;
        }

        if (i >= left && j < right) {
            a[step] = r[j];
            break;
        }
        
        if (r[j] < l[i]) {            
            a[step] = r[j];
            j++;
        } else {
            a[step] = l[i];
            i++;
        }
    }
}

/**
 * @param a An array to sort
 * @param start Start position
 * @param len How many items to sort, length
 */
void merge_sort(int a[], int start, int len) {
    if (len <= 1)
        return;

    int left = len / 2;
    int right = len - left;
    merge_sort(a, start, left);
    merge_sort(a, start + left, right);
    merge(a, start, left, right);
}

int main() {
    print(A, 0, LEN);
    merge_sort(A, 0, LEN);
    print(A, 0, LEN);
}