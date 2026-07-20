package Mondiali;

public class Allenatore extends Persona{
	private final int anni;
	public Allenatore(String nome,String cognome,int anni)
	{
		super(nome,cognome);
		this.anni = anni;
	}
	@Override 
	public int getValore()
	{
		return anni;
	}
	@Override
	public boolean equals(Object obj)
	{
		if(obj == this)
			return true;
		if(obj == null && !(obj instanceof Allenatore))
			return true;
		Allenatore p = (Allenatore) obj;
		return  super.equals(p) && anni == p.anni;
	}
}
