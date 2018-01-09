import java.util.Scanner;

class Main 
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		
		int key;
		
		while((key = sc.nextInt()) != 0)
		{
			System.out.println(Decoder.decodeMessage(sc.next(), key));
		}
		
		sc.close();
	}
}

class Decoder
{
	public static String decodeMessage(String message, int key)
	{
		final int MESSAGE_LENGTH = message.length();
		
		StringBuilder decMess = new StringBuilder();
		int[] plainCode = new int[MESSAGE_LENGTH];
		
		for(int i = 0 ; i < MESSAGE_LENGTH ; ++i)
		{
			int cipherCode;
			char character = message.charAt(i);
			
			if(Character.isLetter(character))
				cipherCode = character-'a'+1;
			else if(character == '_')
				cipherCode = 0;
			else	//character == '.'
				cipherCode = 27;
			
			plainCode[(key*i) % MESSAGE_LENGTH] = (cipherCode+i) % 28;
		}
		
		for(int i = 0 ; i < MESSAGE_LENGTH ; ++i)
		{
			if(plainCode[i] == 0)
				System.out.print('_');
			else if(plainCode[i] == 27)
				System.out.print('.');
			else
				System.out.print((char)(plainCode[i]-1+'a'));
		}
		
		return decMess.toString();
	}
}