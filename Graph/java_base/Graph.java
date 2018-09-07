import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Graph {
	int v_num, e_num;
	Vertex[] head;
	
	public Graph(int type) {	// type = 1: 有向图，type = 0: 无向图
		Scanner scanner = new Scanner(System.in);
		v_num = scanner.nextInt();
		e_num = scanner.nextInt();
		head = new Vertex[v_num];
		
		for (int i = 0; i < v_num; i++) {
			head[i] = new Vertex(i);
		}
		
		for (int i = 0; i < e_num; i++) {
			int from = scanner.nextInt();
			int to = scanner.nextInt();
			int cost = scanner.nextInt();
			Edge edge = new Edge(to, cost);
			Edge h_edge = head[from].adjcent;
			edge.link = h_edge;
			head[from].adjcent = edge;
			
			if (type == 0) {
				int k = from;
				from = to;
				to = k;
				edge = new Edge(to, cost);
				h_edge = head[from].adjcent;
				edge.link = h_edge;
				head[from].adjcent = edge;
			}
		}
	}
	
	public void showGraph() {
		for (int i = 0; i < v_num; i++) {
			System.out.print("[" + i + "]");
			Edge p = head[i].adjcent;
			while (p != null) {
				System.out.print("->" + "[" + p.verAdj + "]");
				p = p.link;
			}
			System.out.println();
		}
	}
	
	public void DFS(int start) {
		int[] visited = new int[v_num];
		for (int i = 0; i < v_num; i++) {
			visited[i] = 0;
		}
		d(start, visited);
		System.out.println();
	}
	
	private void d(int start, int[] visited) {
		System.out.print(String.valueOf(start) + ' ');
		visited[start] = 1;
		Edge p = head[start].adjcent;
		while (p != null) {
			if (visited[p.verAdj] == 0) {
				d(p.verAdj, visited);
			}
			p = p.link;
		}
	}
	
	public void BFS(int start) {
		int[] visited = new int[v_num];
		for (int i = 0; i < v_num; i++) {
			visited[i] = 0;
		}
		Queue<Integer> q = new LinkedList<Integer>();
		visited[start] = 1;
		System.out.print(String.valueOf(start) + " ");
		q.add(start);
		
		while (!q.isEmpty()) {
			int qp = q.poll();
			Edge p = head[qp].adjcent;
			while (p != null) {
				if (visited[p.verAdj] == 0) {
					System.out.print(p.verAdj + " ");
					q.add(p.verAdj);
					visited[p.verAdj] = 1;
				}
				p = p.link;
			}
		}
		
		System.out.println();
	}
	
	public void dijkstra(int start) {
		int[] visited = new int[v_num];
		int[] dis = new int[v_num];
		int[] path = new int[v_num];
		
		for (int i = 0; i < v_num; i++) {
			visited[i] = 0;
			dis[i] = Integer.MAX_VALUE;
			path[i] = -1;
		}
		
		visited[start] = 1;
		dis[start] = 0;
		
		int u = start;
		
		for (int i = 0; i < v_num - 1; i++) {
			Edge p = head[u].adjcent;
			while (p != null) {
				int k = p.verAdj;
				if (visited[k] == 0 &&
					dis[k] > dis[u] + p.cost) {
					dis[k] = dis[u] + p.cost;
					path[k] = u;
				}
				p = p.link;
			}
			
			int min_dis = Integer.MAX_VALUE;
			
			for (int j = 0; j < v_num; j++) {
				if (visited[j] == 0 &&
					dis[j] < min_dis) {
					u = j;
					min_dis = dis[j];
				}
			}
			visited[u] = 1;
		}
		
		for (int i = 0; i < v_num; i++) {
			System.out.println("path[" + i + "]: " + path[i] + '\t'
								+ "dis[" + i + "]: " + dis[i]);
		}
	}
	
	public static void main(String[] args) {
		Graph graph = new Graph(1);
		graph.showGraph();
		graph.DFS(0);
		graph.BFS(0);
		graph.dijkstra(0);
	}
}
