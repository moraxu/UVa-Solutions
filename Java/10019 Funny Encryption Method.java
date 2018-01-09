import java.util.Scanner;

class Main
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		
		int testCases = sc.nextInt();
		
		while(testCases-- != 0)
		{
			int number = sc.nextInt();
			
			int[] ans = Encoder.encryptNumber(number);
			
			System.out.print(ans[0] + " " + ans[1] + "\n");
		}
		
		sc.close();
	}
}

class Encoder
{
	public static int[] encryptNumber(int number)
	{
		return new int[]{ Integer.bitCount(number), Integer.bitCount(Integer.parseInt(Integer.toString(number), 16)) };
	}
}