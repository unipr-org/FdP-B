public class Drone extends Robot {
	private final int quotaMassima;
	
	public Drone(int quotaMax,String id, int energia) {
		super(id,energia);
		quotaMassima = quotaMax;
	}
	@Override
	public int autonomia()
	{
		return getEnergia() * quotaMassima;
	}
	@Override
	public boolean equals(Object obj) {
	
		if(obj == this)
			return true;
		if(obj == null && !(obj instanceof Drone))
			return false;
		Drone r = (Drone) obj;
		return super.equals(r) && quotaMassima == r.quotaMassima;
	}
}
