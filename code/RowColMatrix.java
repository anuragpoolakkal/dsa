// Binary Search in a matrix (2D array). // video: https://youtu.be/enI_KyGLYPo?si=lLAI4pyyIX2K9xsW

import java.util.Arrays;

public class RowColMatrix {
    public static void main(String[] args) {
        int[][] arr = {
            {10, 20, 30, 40},
            {12,22, 32, 42},
            {15, 25, 35, 37},
            {18, 28, 38, 48},
        };

        int target = 38;

        System.out.println(Arrays.toString(search(arr, target)));
    }

    static int[] search(int[][] matrix, int target) {
        int row = 0;
        int col = matrix[0].length - 1;

        while (row < matrix.length && col >= 0) {
            if(matrix[row][col] == target)
                return new int[]{row, col};

            if (matrix[row][col] < target) {
                row++;
            } else {
                col--;
            }
        }
        return new int[]{-1, -1};
    }
}