import java.util.Arrays;

/***
 * 
 * Starting in the top left corner of a 2×2 grid, and only being able to move to
 * the right and down, there are exactly 6 routes to the bottom right corner.
 * 
 * How many such routes are there through a 20×20 grid?
 * 
 * @author chz
 * 
 */
public class Question15 {

	static int SZ_I, SZ_J;
	static long cnt_grid[][];

	public static void init(int i, int j) {
		SZ_I = i + 1;
		SZ_J = j + 1;
		cnt_grid = new long[SZ_I][SZ_J];

		int cnt = 0;
		for (cnt = 0; cnt < SZ_J; cnt++)
			cnt_grid[0][cnt] = 1;

		for (cnt = 0; cnt < SZ_I; cnt++)
			cnt_grid[cnt][0] = 1;
	}

	public static long count() {

		int i = 0, j = 0;
		for (i = 1; i < SZ_I; i++) {
			for (j = 1; j < SZ_J; j++) {
				cnt_grid[i][j] = cnt_grid[i][j - 1] + cnt_grid[i - 1][j];
			}
		}

		return cnt_grid[SZ_I - 1][SZ_J - 1];
	}

	public static void main(String[] args) {
		init(4, 6);
		System.out.println("possible ways of " + (SZ_I - 1) + "*" + (SZ_J - 1)
				+ " is " + count());
		for (int i = 0; i < SZ_I; i++)
			System.out.println(Arrays.toString(cnt_grid[i]));
	}
}
