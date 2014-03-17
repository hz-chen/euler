import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Arrays;


public class Question22 {
	public static void main(String[] args) throws IOException {
		long total = 0;
		BufferedReader br = new BufferedReader(new FileReader("res/names.txt"));
		String s = br.readLine();
		String names[] = s.replaceAll("\"", "").split(",");
		Arrays.sort(names);
		for (int i = 0; i < names.length; i++) {
			char[] c_arr = names[i].toCharArray();
			int sum = 0;
			for (char c : c_arr) {
				sum += c - 'A' + 1;
			}
			total += (i + 1) * sum;
		}
		System.out.println(total);
	}
}
