public class NariaTree<E> {
    private Node<E> root;
    private int size;

    public NariaTree() {
        this.root = null;
        this.size = 0;
    }

    public boolean add(String keyFather, String key, E data) {
        return add(this.root, key, data, keyFather);
    }

    private boolean add(Node<E> root, String novaChave, E data, String chavePai) {
        if (root == null) {
            this.root = new Node<>(novaChave, data);
            return true;
        }
        
        Node<E> pai = searchNode(root, chavePai);
        if (pai == null) {
            return false;
        }

        Node<E> filho = new Node<>(novaChave, data);
        Node<E> p = pai.son;
        if (p == null) {
            pai.son = filho;
        } else {
            while (p.brother != null) {
                p = p.brother;
            }
            p.brother = filho;
        }
        return true;
    }

    public E search(String key) {
        Node<E> elem = searchNode(this.root, key);
        if (elem == null) {
            return null;
        }
        return elem.data;
    }

    private Node<E> searchNode(Node<E> root, String key) {
        if (root == null) {
            return null;
        }

        if (key.equals(root.key)) {
            return root;
        }

        Node<E> p = root.son;
        while (p != null) {
            Node<E> resp = searchNode(p, key);
            if (resp != null) {
                return resp;
            }
            p = p.brother;
        }
        return null;
    }

    public void display() {
        displayRec(this.root);
    }

    private void displayRec(Node<E> root) {
        if (root != null) {
            System.out.println(root.key + "(");
            Node<E> p = root.son;
            while (p != null) {
                displayRec(p);
                p = p.brother;
            }
            System.out.println(")");
        }
    }


    public int getSize() {
        return this.size;
    }
 

    private static class Node<E> {
        private String key;
        private Node<E> son;
        private Node<E> brother;
        private E data;

        Node(String key, E data) {
            this.key = key;
            this.data = data;
            this.son = null;
            this.brother = null;
        }
    }
}
