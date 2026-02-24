
public class BinaryTree<E> {
    private static class Node<E> {
        private final int id;
        private E data;
        private Node<E> left;
        private Node<E> right;
        private int height;

        Node(int id, E data) {
            this.id = id;
            this.data = data;
            this.left = null;
            this.right = null;
            this.height = 0;
        }
    }

    private Node<E> root;
    private int qtd;

    public BinaryTree() {
        this.root = null;
        this.qtd = 0;
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

    public boolean add(int id, E data) {
        Node<E> newNode = new Node<>(id, data);

        if (this.root == null) {
            this.root = newNode;
            this.qtd++;
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
                    this.qtd++;
                    return true;
                }
                current = current.left;
            } else {
                if (current.right == null) {
                    current.right = newNode;
                    this.qtd++;
                    return true;
                }
                current = current.right;
            }
        }
        return false;
    }

    public boolean addRecursive(int id, E data) {
        this.root = addRecursive(this.root, id, data);
        this.qtd++;
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

        return rebalance(root);
    }

    public E deleteRecursive(int id) {
        Node<E> target = searchNode(this.root, id);

        if (target == null) {
            return null;
        }
        E data = target.data;

        this.root = deleteRecursive(this.root, id);
        this.qtd--;
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
                root = root.right;
            } else if (root.right == null) {
                root = root.left;
            } else {
                Node<E> sucessor = findMin(root.right);

                root.right = deleteRecursive(root.right, sucessor.id);

                sucessor.right = root.right;
                sucessor.left = root.left;

                root = sucessor;
            }
        }
        
        if (root == null) {
            return null;
        }
        
        return rebalance(root);
    }

    private Node<E> findMin(Node<E> current) {
        while (current.left != null) {
            current = current.left;
        }
        return current;
    }

    private void imprimirPreOrdem(Node<E> root) {
        if (root != null) {
            Elemento e = (Elemento) root.data;
            System.out.println("ID: " + e.getNumero() + " | NOME: " + e.getNome());
            imprimirPreOrdem(root.left);
            imprimirPreOrdem(root.right);
        }
    }

    public void preOrdem() {
        imprimirPreOrdem(this.root);
    }

    private void imprimirPosOrdem(Node<E> root) {
        if (root != null) {
            imprimirPosOrdem(root.left);
            imprimirPosOrdem(root.right);
            Elemento e = (Elemento) root.data;
            System.out.println("ID: " + e.getNumero() + " | NOME: " + e.getNome());
        }
    }

    public void posOrdem() {
        imprimirPosOrdem(this.root);
    }

    private void imprimirSimetrico(Node<E> root) {
        if (root != null) {
            imprimirSimetrico(root.left);
            Elemento e = (Elemento) root.data;
            System.out.println("ID: " + e.getNumero() + " | NOME: " + e.getNome());
            imprimirSimetrico(root.right);
        }
    }

    public void simetrico() {
        imprimirSimetrico(this.root);
    }

    public int getQtd() {
        return this.qtd;
    }

    public E getRaiz() {
        if (this.root == null) {
            return null;
        }
        return this.root.data;
    }


    private int height(Node<E> node) {
        if (node == null) {
            return -1;
        }
        return node.height;
    }

    private int getBalanceFactor(Node<E> node) {
        if (node == null) {
            return 0;
        }
        return height(node.right) - height(node.left);
    }

    private void updateHeight(Node<E> node) {
        int hLeft = height(node.left);
        int hRight = height(node.right);
        
        if (hLeft > hRight) {
            node.height = hLeft + 1;
        } else {
            node.height = hRight + 1;
        }
    }


    private Node<E> rotateLeft(Node<E> x) {
        Node<E> y = x.right;
        Node<E> T2 = y.left;

        y.left = x;
        x.right = T2;

        updateHeight(x);
        updateHeight(y);

        return y;
    }

    private Node<E> rotateRight(Node<E> x) {
        Node<E> y = x.left;
        Node<E> T2 = y.right;

        y.right = x;
        x.left = T2;

        updateHeight(x);
        updateHeight(y);

        return y;
    }

    private Node<E> rotateDoubleLeft(Node<E> x) {
        x.right = rotateRight(x.right);
        return rotateLeft(x);
    }

    private Node<E> rotateDoubleRight(Node<E> x) {
        x.left = rotateLeft(x.left);
        return rotateRight(x);
    }

    private Node<E> rebalance(Node<E> node) {
        updateHeight(node);
        int balance = getBalanceFactor(node);

        if (balance  < -1) {
            if (getBalanceFactor(node.right) > 0) {
                return rotateDoubleRight(node);
            }
            return rotateRight(node);
        }

        if (balance > 1) {
            if (getBalanceFactor(node.left) < 0) {
                return rotateDoubleLeft(node);
            }
            return rotateLeft(node);
        }

        return node;
    }
}
