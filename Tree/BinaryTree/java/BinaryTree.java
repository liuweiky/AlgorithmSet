import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class BinaryTree {
	Node<Character> root = null;
	
	public BinaryTree() {
		createTree();
	}

	/*先根遍历序列创建二叉树*/
	public void createTree() {
		Scanner scanner = new Scanner(System.in);
		String preOrder = scanner.nextLine();
		root = create(preOrder, 0);
	}
	
	private Node<Character> create(String preOrder, int pos) {
		Character c = preOrder.charAt(pos);
		if (c == '#')
			return null;
		Node<Character> node = new Node<Character>(c);
		node.left = create(preOrder, pos + 1);
		node.right = create(preOrder, pos + 2);
		return node;
	}
	
	public void preOrder(Node<Character> n) {
		System.out.print(n.data + " ");
		if (n.left != null)
			preOrder(n.left);
		if (n.right != null)
			preOrder(n.right);
	}
	
	public void inOrder(Node<Character> n) {
		if (n.left != null)
			inOrder(n.left);
		System.out.print(n.data + " ");
		if (n.right != null)
			inOrder(n.right);
	}
	
	public void postOrder(Node<Character> n) {
		if (n.left != null)
			postOrder(n.left);
		if (n.right != null)
			postOrder(n.right);
		System.out.print(n.data + " ");
	}
	
	public void levelOrder() {
		Queue<Node<Character>> queue = new LinkedList<Node<Character>>();
		queue.add(root);
		while (!queue.isEmpty()) {
			Node<Character> node = queue.poll();
			System.out.print(node.data + " ");
			if (node.left != null)
				queue.add(node.left);
			if (node.right != null)
				queue.add(node.right);
		}
	}
	
	public static void main(String[] args) {
		BinaryTree tree = new BinaryTree();
		System.out.println();
		tree.preOrder(tree.root);
		System.out.println();
		tree.inOrder(tree.root);
		System.out.println();
		tree.postOrder(tree.root);
		System.out.println();
		tree.levelOrder();
	}
}
