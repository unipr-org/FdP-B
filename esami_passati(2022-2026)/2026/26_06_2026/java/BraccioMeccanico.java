public class BraccioMeccanico extends Robot {
	private final int pesoMaxSollevabile;
	
	public BraccioMeccanico(int pesoMax,String id, int energia) {
		super(id,energia);
		pesoMaxSollevabile = pesoMax;
	}
	@Override
	public int autonomia()
	{
		return getEnergia() * pesoMaxSollevabile;
	}
	@Override
	public boolean equals(Object obj) {
	
		if(obj == this)
			return true;
		if(obj == null && !(obj instanceof BraccioMeccanico))
			return false;
		BraccioMeccanico b = (BraccioMeccanico) obj;
		return super.equals(b) && pesoMaxSollevabile == b.pesoMaxSollevabile;
	}
}
