public abstract class Robot implements Comparable<Robot> {
	
	private final String id;
	private final int energia;
	
	public Robot(String id, int energia) {                 
		this.id = id;
		this.energia = energia;
	}
	public String getId() {
		return id;
	}
	public int getEnergia() {
		return energia;
	}
	public abstract int autonomia();
	@Override
	public boolean equals(Object obj) {
	
		if(obj == this)
			return true;
		if(obj == null && !(obj instanceof Robot))
			return false;
		Robot r = (Robot) obj;
		return r.id.equals(this.id);
	}
	@Override
	public int compareTo(Robot o) {
		return Integer.compare(autonomia(), o.autonomia());
	}
	
}
