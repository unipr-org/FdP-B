package Mondiali;

public class Giocatore extends Persona {
	private final int golSegnati;
	
	public Giocatore(String nome,String cognome,int gol)
	{
		super(nome,cognome);
		golSegnati = gol;
	}
	@Override
	public boolean equals(Object obj)
	{
		if(obj == this)
			return true;
		if(obj == null && !(obj instanceof Giocatore))
			return true;
		Giocatore g = (Giocatore) obj;
		return super.equals(g) && golSegnati == g.golSegnati;
	}
	@Override 
	public int getValore()
	{
		return golSegnati;
	}
}
