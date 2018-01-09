import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Main
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int howManyTeams = 0;
		int teamCount = 1;
		int scenarioNo = 1;
		
		Map<Integer, Integer> elementsToTeams = new HashMap<>();
		
		while((howManyTeams = sc.nextInt()) != 0)
		{
			for(int i = howManyTeams ; i != 0 ; --i, ++teamCount)
			{
				for(int j = sc.nextInt() ; j != 0 ; --j)
				{
					int element = sc.nextInt();
					elementsToTeams.put(element, teamCount);
				}
			}
			
			//-----------------------------------------------------------------------
			System.out.println("Scenario #" + scenarioNo);
			
			Map<Integer, LinkedList<Integer>> teamsToContent = new HashMap<>();
			
			List<LinkedList<Integer>> queue = new LinkedList<>();
			
			String word;
			
			while(!(word = sc.next()).equals("STOP"))
			{
				if(word.equals("DEQUEUE"))
				{
					List<Integer> listAtTheBeggining = queue.get(0);
					
					int firstRemoved = listAtTheBeggining.remove(0);
					System.out.println(firstRemoved);
					
					if(listAtTheBeggining.isEmpty())
					{
						teamsToContent.remove(elementsToTeams.get(firstRemoved));
						queue.remove(0);
					}
				}
				else
				{
					int elementToAdd = sc.nextInt();
					LinkedList<Integer> listOfTeam = teamsToContent.get(elementsToTeams.get(elementToAdd));
					
					if(listOfTeam == null)
					{
						listOfTeam = new LinkedList<Integer>();
						teamsToContent.put(elementsToTeams.get(elementToAdd), listOfTeam);
						queue.add(listOfTeam);
					}
					
					listOfTeam.add(elementToAdd);
				}
			}
			
			++scenarioNo;
			System.out.println();
		}
		sc.close();
	}
}
