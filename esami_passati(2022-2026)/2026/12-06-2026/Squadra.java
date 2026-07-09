package Mondiali;
import java.util.*;
public class Squadra implements Comparable<Squadra> {
	private final String nome;
	private Set<Persona> p;
	
	public Squadra()
	{
		p = new  HashSet<Persona>();
		this.nome = "      ";
	}
	public void  addPersona(Persona pOther)
	{
		if(p.contains(pOther))
		{
			throw new SquadraException("gia presente");
		}
		p.add(pOther);
	}
	public int valoreTotale()
	{
		int som =0;
		for(Persona pers : p)
		{
			som += pers.getValore();
		}
		return som;
	}
	@Override
	public boolean equals(Object obj)
	{
		if(obj == this)
			return true;
		if(obj == null && !(obj instanceof Squadra))
			return true;
		Squadra s = (Squadra) obj;
		return  p.equals(s.p) && nome.equals(s.nome);
	}
	@Override
	public int compareTo(Squadra s)
	{
		return Integer.compare(s.valoreTotale(), valoreTotale());
	}
}
