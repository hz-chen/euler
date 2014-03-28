import java.math.*;
import java.util.*;

/**
 * The Fibonacci sequence is defined by the recurrence relation:
 * 
 * Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.
 * 
 * Hence the first 12 terms will be:
 * 
 * F1 = 1 F2 = 1 F3 = 2 F4 = 3 F5 = 5 F6 = 8 F7 = 13 F8 = 21 F9 = 34 F10 = 55
 * F11 = 89 F12 = 144
 * 
 * The 12th term, F12, is the first term to contain three digits.
 * 
 * What is the first term in the Fibonacci sequence to contain 1000 digits?
 * 
 * @author chz
 * 
 */
public class Question25 {

	static int curr[] = new int[1024];
	static int prev[] = new int[1024];
	static int pos = 0;
	static int term = 0;

	private static void init() {
		curr[0] = 1;
		prev[0] = 1;
		pos = 1;
		term = 2;
	}

	private static void getNextFeb() {
		// swap(curr, prev)
		int[] tmp = curr;
		curr = prev;
		prev = tmp;

		// curr += prev --pos change
		int i = 0, sum = 0, takeover = 0;
		for (i = 0; i < pos; i++) {
			sum = prev[i] + curr[i] + takeover;
			curr[i] = sum % 10;
			takeover = sum / 10;
		}
		if (takeover > 0) {
			if (takeover > 10)
				System.err.println("takeover too big");
			curr[pos++] = takeover;
		}
		term++;
	}

	private static void print() {
		int i = 0;
		System.out.print("term " + term + " with pos " + pos + ": ");
		for (i = pos - 1; i >= 0; i--) {
			System.out.print(curr[i]);
		}
		System.out.println();
	}

	private static void sln2() {
		boolean found = false;
		BigInteger last = BigInteger.ONE;
		BigInteger secLast = BigInteger.ONE;
		BigInteger testNum;
		long a = 3;
		while (!found) {
			testNum = last.add(secLast);
			secLast = last;
			last = testNum;
			long digs = numDigits(testNum);
			if (digs == 1000) {
				// System.out.println(testNum + " has 1000 digits.");
				System.out.println("This is f_" + a);
				found = true;
			} else {
				// System.out.println(testNum);
				a++;
			}
		}
	}

	private static long numDigits(BigInteger testNum) {
		long digits = testNum.toString().length();

		return digits;
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		init();
		long start = System.nanoTime();
		while (pos < 1000) {
			getNextFeb();
			// print();
		}
		long end = System.nanoTime();
		System.out.println("my time elapse: " + (end - start) + " nano secs");
		print();
		start = System.nanoTime();
		sln2();
		end = System.nanoTime();
		System.out.println("Big Integer time elapse: " + (end - start)
				+ " nano secs");
	}

}
