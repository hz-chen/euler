/***
 * 
 * 
 * The following iterative sequence is defined for the set of positive
 * longest:
 * 
 * n → n/2 (n is even) n → 3n + 1 (n is odd)
 * 
 * Using the rule above and starting with 13, we generate the following
 * sequence: 13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
 * 
 * It can be seen that this sequence (starting at 13 and finishing at 1)
 * contains 10 terms. Although it has not been proved yet (Collatz Problem), it
 * is thought that all starting numbers finish at 1.
 * 
 * Which starting number, under one million, produces the longest chain?
 * 
 * NOTE: Once the chain starts the terms are allowed to go above one million.
 * 
 * @author chz
 * 
 */
public class Question14 {

	static int RANGE = 1000000;

	static long[] arr = new long[RANGE];

	/*
	 * return the number of term of num
	 */
	public static long get_term(int num) {
		long term = 1;
		long val = num;
		while (val != 1) {
			if ((val > 0) && (val < RANGE) && (arr[(int) val] != 0)) {
				// System.out.println("referencing " + num);
				term += arr[(int) val] - 1;
				break;
			}

			if (val % 2 == 0)
				val /= 2;
			else
				val = 3 * val + 1;

			// System.out.println("-->" + num);
			term++;
		}
		arr[num] = term;
		return term;
	}

	public static void main(String[] args) {

		long max_term = 0;
		long max_num = 0;
		int num = 1;

		while (num < RANGE) {
			long tmp = get_term(num);
			if (tmp > max_term) {
				max_term = tmp;
				max_num = num;
			}
			// System.out.println("term of " + num + " is " + tmp);
			num++;
		}
		System.out.println("the number with max term is " + max_num
				+ ", it's term is " + max_term + ".");
	}
}
