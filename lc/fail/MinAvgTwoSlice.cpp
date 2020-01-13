A non-empty array A consisting of N integers is given. A pair of integers (P, Q), such that 0 ≤ P < Q < N, is called a slice of array A (notice that the slice contains at least two elements). The average of a slice (P, Q) is the sum of A[P] + A[P + 1] + ... + A[Q] divided by the length of the slice. To be precise, the average equals (A[P] + A[P + 1] + ... + A[Q]) / (Q − P + 1).

For example, array A such that:

    A[0] = 4
    A[1] = 2
    A[2] = 2
    A[3] = 5
    A[4] = 1
    A[5] = 5
    A[6] = 8
    
public int solution(int[] A) {
    if (A.length == 2) return 0;

    int minSliceTwo = A[0] + A[1];
    int minTwoIndex = 0;

    int minSliceThree = Integer.MAX_VALUE;
    int minThreeIndex = 0;

    for (int i = 2; i < A.length; i++) {
        int sliceTwo = A[i - 1] + A[i];
        if (sliceTwo < minSliceTwo) {
            minSliceTwo = sliceTwo;
            minTwoIndex = i - 1;
        }

        int sliceThree = sliceTwo + A[i - 2];
        if (sliceThree < minSliceThree) {
            minSliceThree = sliceThree;
            minThreeIndex = i - 2;
        }
    }
    int averageMinTwo = minSliceTwo*3;
    int averageMinThree = minSliceThree*2;

    if (averageMinTwo == averageMinThree) return Math.min(minTwoIndex, minThreeIndex);
    else return averageMinTwo < averageMinThree ? minTwoIndex : minThreeIndex;
}