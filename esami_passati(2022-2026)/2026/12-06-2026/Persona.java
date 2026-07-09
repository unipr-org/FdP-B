package Mondiali;

public abstract class Persona {
	private final String nome;
	private final String cognome;
	
	public Persona(String nome,String cognome)
	{
		this.nome = nome;
		this.cognome = cognome;
	}
	
	public String getNome()
	{
		return nome;
	}
	public String getCognome()
	{
		return cognome;
	}
	@Override
	public boolean equals(Object obj)
	{
		if(obj == this)
			return true;
		if(obj == null && !(obj instanceof Persona))
			return true;
		Persona p = (Persona) obj;
		return nome.equals(p.nome) && cognome.equals(p.cognome);
	}
	
	public  abstract int getValore();
}
