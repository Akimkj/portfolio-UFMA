
public class BinaryTree<E> {
    private static class Node<E> {
        private final int id;
        private E data;
        private Node<E> left;
        private Node<E> right;

        Node(int id, E data) {
            this.id = id;
            this.data = data;
            this.left = null;
            this.right = null;
        }
    }

    private Node<E> root;

    public BinaryTree() {
        this.root = null;
    }

    private Node<E> searchNode(Node<E> root, int id) {
        if (root != null) {
            if (root.id == id) {
                return root;
            } else if (id < root.id) {
                return searchNode(root.left, id);
            }
            return searchNode(root.right, id);
        }
        return null;
    }

    public E search(int id) {
        /*Node<E> node = searchNode(this.root, id);
        if (node == null) {
            return null;
        }
        return node.data;*/

        Node<E> current = this.root;

        while(current != null) {
            if (current.id == id) {
                return current.data;
            }
            else if (current.id > id) {
                current = current.left;
            } else {
                current = current.right;
            }
        }
        return null;
    }

    /*public boolean add(int id, E data) {
        Node<E> newNode = new Node<>(id, data);

        if (this.root == null) {
            this.root = newNode;
            return true;
        }

        Node<E> current = this.root;
        while (current != null) {
            if (current.id == id) {
                return false; //ja existe um id na arvore
            }
            else if (current.id > id) {
                if (current.left == null) {
                    current.left = newNode;
                    return true;
                }
                current = current.left;
            } else {
                if (current.right == null) {
                    current.right = newNode;
                    return true;
                }
                current = current.right;
            }
        }
        return false;
    }*/

    public boolean add(int id, E data) {
        this.root = addRecursive(this.root, id, data);
        return true;
    }

    private Node<E> addRecursive(Node<E> root, int id, E data) {
        if (root == null) {
            return new Node<>(id, data);
        }

        if (id < root.id) {
            root.left = addRecursive(root.left, id, data);
        } else if (id > root.id) {
            root.right = addRecursive(root.right, id, data);
        } else {
            root.data = data;
        }

        return root;
    }

    public E delete(int id) {
        Node<E> target = searchNode(this.root, id);

        if (target == null) {
            return null;
        }
        E data = target.data;

        this.root = deleteRecursive(this.root, id);
        return data;

    }

    private Node<E> deleteRecursive(Node<E> root, int id) {
        if (root == null) {
            return null;
        }

        if (id < root.id) {
            root.left = deleteRecursive(root.left, id);
        } else if (id > root.id) {
            root.right = deleteRecursive(root.right, id);
        } else {
            if (root.left == null) {
                return root.right;
            } else if (root.right == null) {
                return root.left;
            }

            Node<E> sucessor = findMin(root.right);

            root.right = deleteRecursive(root.right, sucessor.id);

            sucessor.right = root.right;
            sucessor.left = root.left;

            return sucessor;
        }

        return root;
    }

    private Node<E> findMin(Node<E> current) {
        while (current.left != null) {
            current = current.left;
        }
        return current;
    }
}
