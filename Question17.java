
/*******
 * 
 * If the numbers 1 to 5 are written out in words: one, two, three, four, five,
 * then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
 * 
 * If all the numbers from 1 to 1000 (one thousand) inclusive were written out
 * in words, how many letters would be used?
 * 
 * NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and
 * forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20
 * letters. The use of "and" when writing out numbers is in compliance with
 * British usage.
 * 
 * @author chz
 * 
 */
public class Question17 {

	static int cnt[] = new int[1001];
	static int hundred = 7;
	static int thousand = 8;
	static int and = 3;

	public static void init() {
		cnt[0] = 0;
		cnt[1] = 3; // one
		cnt[2] = 3; // two
		cnt[3] = 5; // three
		cnt[4] = 4; // four
		cnt[5] = 4; // five
		cnt[6] = 3; // six
		cnt[7] = 5; // seven
		cnt[8] = 5; // eight
		cnt[9] = 4; // nine
		cnt[10] = 3; // ten
		cnt[11] = 6; // eleven
		cnt[12] = 6; // twelve
		cnt[13] = 8; // thirteen
		cnt[14] = 8; // fourteen
		cnt[15] = 7; // fifteen
		cnt[16] = 7; // sixteen
		cnt[17] = 9; // seventeen
		cnt[18] = 8; // eighteen
		cnt[19] = 8; // nineteen
		cnt[20] = 6; // twenty
		cnt[30] = 6; // thirty
		cnt[40] = 5; // forty
		cnt[50] = 5; // fifty
		cnt[60] = 5; // sixty
		cnt[70] = 7; // seventy
		cnt[80] = 6; // eighty
		cnt[90] = 6; // ninety

		int i = 0;
		for (i = 21; i < 100; i++) {
			cnt[i] = cnt[(i / 10) * 10] + cnt[i % 10];
		}
		for (i = 100; i < 1000; i++) {
			cnt[i] = cnt[i / 100] + hundred + and + cnt[i % 100];
		}

		for (i = 100; i < 1000; i += 100) {
			cnt[i] = cnt[i / 100] + hundred;
		}

		cnt[1000] = 3 + thousand;

	}

	public static int calculate() {
		int res = 0, i = 0;
		for (i = 0; i < 1001; i++) {
			res += cnt[i];
		}
		return res;
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		init();
		System.out.println(calculate());
	}

}
