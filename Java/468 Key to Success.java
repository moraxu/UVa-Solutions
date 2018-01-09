import java.util.Scanner;
import java.util.Arrays;

class Main
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		
		int noOfCases = sc.nextInt();
		
		while(noOfCases-- != 0)
		{
			String text = sc.next(),
				   encText = sc.next();
			
			System.out.println(Decoder.decode(text, encText));
			
			if(noOfCases != 0)
				System.out.println();
		}
		
		sc.close();
	}
}

class Decoder
{
	static class LetterFrequency implements Comparable<LetterFrequency>
	{
		public char letter;
		public int frequency;
		
		public int compareTo(LetterFrequency other)
		{
			return other.frequency - frequency;
		}
		
		public LetterFrequency(char aLetter, int aFrequency)
		{
			letter = aLetter;
			frequency = aFrequency;
		}
	}
	
	public static String decode(String text, String encText)
	{
		final int LETTER_FREQUENCY_SIZE = 26*2;
		LetterFrequency[] textFreq = new LetterFrequency[LETTER_FREQUENCY_SIZE],
						  encTextFreq = new LetterFrequency[LETTER_FREQUENCY_SIZE];
		
		for(int i = 0 ; i < 26 ; ++i)
		{
			textFreq[i] = new LetterFrequency((char)('A'+i), 0);
			encTextFreq[i] = new LetterFrequency((char)('A'+i), 0);
			
			textFreq[i+26] = new LetterFrequency((char)('a'+i), 0);
			encTextFreq[i+26] = new LetterFrequency((char)('a'+i), 0);
		}
		
		for(char letter : text.toCharArray())
		{
			if(Character.isUpperCase(letter))
			{
				++textFreq[letter-'A'].frequency;
			}
			else
			{
				++textFreq[letter-'a'+26].frequency;
			}
		}
		
		for(char letter : encText.toCharArray())
		{
			if(Character.isUpperCase(letter))
			{
				++encTextFreq[letter-'A'].frequency;
			}
			else
			{
				++encTextFreq[letter-'a'+26].frequency;
			}
		}
		
		Arrays.sort(textFreq);
		Arrays.sort(encTextFreq);
		
		char[] mappedLetter = new char[122+1];
		
		for(int i = 0 ; i < LETTER_FREQUENCY_SIZE && textFreq[i].frequency != 0 ; ++i)
		{
			mappedLetter[encTextFreq[i].letter] = textFreq[i].letter;
		}
		
		StringBuilder sB = new StringBuilder();
		
		for(char letter : encText.toCharArray())
		{
			sB.append(mappedLetter[letter]);
		}
		
		return sB.toString();
	}
}