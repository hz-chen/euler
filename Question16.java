import java.util.Arrays;

/**
 * 
 * 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
 * 
 * What is the sum of the digits of the number 2^1000?
 * 
 */

public class Question16 {

	static int LEN = 1000000;
	static int res[] = new int[LEN];
	static int curr_pos = 0; // current highest bit

	public static void init() {
		Arrays.fill(res, 0);
		res[0] = 1;
		curr_pos = 1;
	}

	// res *= 2
	public static void time_two() {
		int tmp_bit = 0; // puls one to next digit?
		int i = 0, result = 0;
		for (i = 0; i < curr_pos + 1; i++) {
			result = res[i] * 2 + tmp_bit;
			tmp_bit = result / 10;
			res[i] = result % 10;
			if (tmp_bit != 0)
				curr_pos++;

		}
	}

	public static void calculate(int power) {

		int i = 0;
		for (i = 0; i < power; i++)
			time_two();
	}

	public static double get_result() {
		double result = 0;
		int i = 0;
		for (i = 0; i < LEN; i++) {
			result += res[i];
		}

		return result;
	}

	public static void main(String[] args) {
		init();
		calculate(1000);
		System.out.println("The result is " + get_result());
	}

}
