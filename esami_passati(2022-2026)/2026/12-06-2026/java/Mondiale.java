package Mondiali;
import java.util.*;
public class Mondiale {
	private Set<Squadra> squadre;
	
	public Mondiale()
	{
		squadre = new HashSet<Squadra>();
	}
	public void addSquadra(Squadra s)
	{
		if(	!squadre.add(s))
			throw new SquadraException(" gia presente");
	
	}
	public Squadra getMigliore()
	{
		Squadra s_max = null;
		int max = -1;
		for(Squadra s: squadre)
		{
			if(s.valoreTotale() > max)
			{
				max = s.valoreTotale();
				s_max = s;
			}
		}
		return s_max;
	}
}
