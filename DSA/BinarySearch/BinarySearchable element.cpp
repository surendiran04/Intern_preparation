public int howMany(int[] input) {
 
    int n = input.length;
    int maxi[] = new int[n];
    int min[] = new int[n];
    
    int max = Integer.MIN_VALUE;
    int mi = Integer.MAX_VALUE;
    
    for (int i = 0 ; i < n; i++){
        maxi[i] = Math.max(max, input[i]);
        max = maxi[i];
    }
    for (int i = n-1 ; i >= 0; i--){
        min[i] = Math.min(mi, input[i]);
        mi = min[i];
    }
    int count = 0;
    for( int i = 0; i< n ; i++){
        if(maxi[i] == min[i]) count++;
    }
    return count;
    
}

public static void main(String[] args) {
    BinarySearchable solution = new BinarySearchable();
    System.out.println(solution.howMany(new int[] {1, 3, 2}));
    System.out.println(solution.howMany(new int[] {2, 1, 3, 5, 4, 6}));
    System.out.println(solution.howMany(new int[] {1, 5, 7, 11, 12, 18}));
    System.out.println(solution.howMany(new int[] {5, 4, 3, 2, 1, 0}));
    System.out.println(solution.howMany(new int[] {1, 3, 2, 4, 5, 7, 6, 8}));
}
