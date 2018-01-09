import java.util.LinkedHashMap;
import java.util.Map;
import java.util.Scanner;

public class Main
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		Map<Integer, Integer> frequencies = new LinkedHashMap<>();
		
		while(sc.hasNextInt())
		{
			int number = sc.nextInt();
			
			if(frequencies.containsKey(number))
			{
				frequencies.put(number, frequencies.get(number)+1);
			}
			else
			{
				frequencies.put(number, 1);
			}
		}
		
		for(Map.Entry<Integer, Integer> entry : frequencies.entrySet())
		{
			System.out.println(entry.getKey() + " " + entry.getValue());
		}
		
		sc.close();
	}
}
