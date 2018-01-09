import java.util.Scanner;

class Main
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		
		while(sc.hasNextLine())
		{
			String line = sc.nextLine();
			
			if(line.length() > 0)
			{
				if(Character.isDigit(line.charAt(0)))
				{
					System.out.println(Decoder.decodeMessage(line));
				}
				else
				{
					System.out.println(Encoder.encodeMessage(line));
				}
			}
			else
			{
				System.out.println();
			}
		}
		
		sc.close();
	}
}

class Encoder
{
	public static String encodeMessage(String message)
	{
		StringBuilder encMess = new StringBuilder();
		
		for(int i = message.length()-1 ; i >= 0 ; --i)
		{
			encMess.append(new StringBuilder(String.valueOf((int)message.charAt(i))).reverse().toString());
		}
		
		return encMess.toString();
	}
}

class Decoder
{
	public static String decodeMessage(String message)
	{
		StringBuilder decMess = new StringBuilder();
		String punctuationMarks = " !,.:;?";
		
		for(int i = message.length()-1 ; i >= 0 ; --i)
		{
			StringBuilder codePoint = new StringBuilder();
			codePoint.append(message.charAt(i));
			codePoint.append(message.charAt(--i));
			
			char currChar = (char)Integer.parseInt(codePoint.toString());
			
			if((currChar >= 65 && currChar <= 90) || (currChar >= 97 && currChar <= 99) || punctuationMarks.contains(String.valueOf(currChar)))
			{
				decMess.append(currChar);
			}
			else
			{
				codePoint.append(message.charAt(--i));
				decMess.append((char)Integer.parseInt(codePoint.toString()));
			}
		}
		
		return decMess.toString();
	}
}