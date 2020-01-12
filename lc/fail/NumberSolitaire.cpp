public int solution(int[] A) {
    int lens = A.length;
    int dp[] = new int[6];
    for (int i = 0; i < 6; i++) {
        dp[i] = A[0];
    }
    for (int i = 1; i < lens; i++) {
        dp[i%6] = getMax6(dp) + A[i];
    }
    return dp[(lens-1)%6];
}

private int getMax6(int dp[]){
    int max = dp[0];
    for (int i = 1; i < dp.length; i++) {
        max = Math.max(max, dp[i]);
    }
    return max;
}
