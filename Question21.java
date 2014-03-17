/***
 * 
 * 
 * Let d(n) be defined as the sum of proper divisors of n (numbers less than n
 * which divide evenly into n). If d(a) = b and d(b) = a, where a ≠ b, then a
 * and b are an amicable pair and each of a and b are called amicable numbers.
 * 
 * For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44,
 * 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4,
 * 71 and 142; so d(284) = 220.
 * 
 * Evaluate the sum of all the amicable numbers under 10000.
 * 
 * 
 */
public class Question21 {

	private static int d(int num) {
		int end = (int) Math.sqrt(num);
		int sum = 1;
		for (int i = 2; i <= end; i++) {
			if (num % i == 0) {
				sum += num / i;
				sum += i;
			}
		}

		if (end * end == num)
			sum -= end;
		return sum;
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {

		int range = 10000;
		int sum = 0;
		for (int i = 2; i < range; i++) {
			int tmp = d(i);
			if (tmp == i)
				continue;
			if (i == d(tmp)) {
				sum += i;
				System.out.println("amicable found: " + i + " with d(i) = "
						+ tmp + ", sum up to " + sum);
			}
		}
		System.out.println("sum is " + sum);
	}
}
