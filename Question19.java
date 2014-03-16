/********
 * 
 * You are given the following information, but you may prefer to do some
 * research for yourself.
 * 
 * 1 Jan 1900 was a Monday. Thirty days has September, April, June and November.
 * All the rest have thirty-one, Saving February alone, Which has twenty-eight,
 * rain or shine. And on leap years, twenty-nine. A leap year occurs on any year
 * evenly divisible by 4, but not on a century unless it is divisible by 400.
 * 
 * How many Sundays fell on the first of the month during the twentieth century
 * (1 Jan 1901 to 31 Dec 2000)?
 * 
 * @author chz
 * 
 */
public class Question19 {

	static int months[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	public static void main(String[] args) {
		int lastWeekDayOfAMonth = 0;
		int counter = 0;
		int y, m;
		for (y = 1900; y < 2001; y++) {
			for (m = 0; m < 12; m++) {
				if ((m == 1)
						&& ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0)))
					lastWeekDayOfAMonth += 29;
				else
					lastWeekDayOfAMonth += months[m];

				lastWeekDayOfAMonth %= 7;
				if (lastWeekDayOfAMonth == 6 && y != 1900)
					counter++;
			}
		}

		System.out.println(counter);
	}

}
