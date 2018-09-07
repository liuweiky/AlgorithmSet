
public class Edge {
	int verAdj;
	int cost = 0;
	Edge link = null;
	
	public Edge(int verAdj, int cost) {
		super();
		this.verAdj = verAdj;
		this.cost = cost;
	}
}
