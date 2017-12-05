package test;

public class Main {
	public static void main(String[] ar)
	{
		long t_1 = System.currentTimeMillis();
		double result = 0;
		for(int i = 0; i < 100000000; i++) {
			result += i;
		}
		System.out.println(result);
		long t_2 = System.currentTimeMillis();
		System.out.println(t_2 - t_1);
	}
}
