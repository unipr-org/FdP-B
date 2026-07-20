public class Laboratorio {
	private final String nome;
	private Set<Robot> robots;
	
	public Laboratorio(String nome)
	{
		robots = new HashSet<Robot>();
		this.nome = nome;
	}
	public void aggiungiRobot(Robot r) throws RobotException
	{
		if(robots.contains(r))
			throw new RobotException("robot gia presente");
		robots.add(r);
	}
	public int autonomiaTotale() {
		int sum = 0;
		for(Robot r: robots)
		{
			sum += r.autonomia();
		}
		return sum;
	}
	public Robot robotMigliore()
	{
		Robot robot_max = null;
		int max = -1;
		for(Robot r : robots)
		{
			if(r.autonomia() > max)
			{
				max = r.autonomia();
				robot_max = r;
			}
		}
		return robot_max;
	}
}
