import java.util.*;

class Main
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		
		while(sc.hasNext())
		{
			String word = sc.next();
			
			ArrayList<String> uniquePalindromes = new ArrayList<>();
			
			for(int i = 0 ; i < word.length() ; ++i)
			{
				for(int j = i ; j < word.length() ; ++j)
				{
					String substring = word.substring(i, j+1);
					
					if(substring.equals(new StringBuilder(substring).reverse().toString())
							&&
						!uniquePalindromes.contains(substring))
					{
						uniquePalindromes.add(substring);
					}
				}
			}
			
			System.out.println("The string '" + word + "' contains " + uniquePalindromes.size() + " palindromes.");
		}
		
		sc.close();
	}
}
