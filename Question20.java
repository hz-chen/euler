import java.util.Arrays;

/***
 * 
 * 
 * n! means n × (n − 1) × ... × 3 × 2 × 1
 * 
 * For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800, and the sum of the
 * digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.
 * 
 * Find the sum of the digits in the number 100!
 * 
 * @author chz
 * 
 */
public class Question20 {

	static int res[];
	static int curPos;

	public static void mul(int val) {
		String valStr = String.valueOf(val);
		char valArr[] = valStr.toCharArray();
		// System.out.println("val: " + Arrays.toString(valArr));
		int len = valArr.length;
		int tmpArr[][] = new int[len][curPos + 1];
		// System.out.println(Arrays.deepToString(tmpArr));
		int i = 0, j = 0;
		int carryOver;
		for (i = 0; i < len; i++) {
			carryOver = 0;
			for (j = 0; j < curPos; j++) {
				int tmp = res[j] * (valArr[len - i - 1] - '0') + carryOver;
				tmpArr[i][j] = tmp % 10;
				carryOver = tmp / 10;
			}
			if (carryOver != 0) {
				tmpArr[i][curPos] = carryOver;
				carryOver = 0;
			}
		}
		Arrays.fill(res, 0);
		for (i = 0; i < len; i++) {
//			res[i] = 0;
			carryOver = 0;
			for (j = 0; j < curPos; j++) {
				int tmp = res[i + j] + tmpArr[i][j] + carryOver;
				res[i + j] = tmp % 10;
				carryOver = tmp / 10;
			}
			if (carryOver != 0) {
				res[i + j] = carryOver;
				carryOver = 0;
			}
		}
		curPos = i + j;

	}

	private static void init(int num) {

		res = new int[num * 10];
		res[0] = 1;
		curPos = 1;
	}

	public static void main(String[] args) {

		int number = 1000;
		init(number);
		int i = 0;

		for (i = 1; i <= number; i++) {
			mul(i);
		}

		int sum = 0;
		for (i = 0; i < curPos; i++) {
			sum += res[i];
		}
		System.out.println("sum of each digit of " + number + "! is :" + sum);

	}

}
