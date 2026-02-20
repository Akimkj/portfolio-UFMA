public class HashMap<E> {
    
    private static class Node<E> {
        private final E data;
        private final int key;
        private Node<E> next;

        Node(int key, E data) {
            this.key = key;
            this.data = data;
            this.next = null;
        }
    }

    private Object[] tabHash;
    private int qtd;

    public HashMap(int tam) {
        this.qtd = 0;
        this.tabHash = new Object[tam];
    }

    private int hash(int key) {
        if (key < 0) {
            key *= -1;
        }

        return key % tabHash.length;
    }

    public boolean add(int key, E data) {
        int h = hash(key);
        Node<E> newNode = new Node<>(key, data);

        if (tabHash[h] == null) {
            tabHash[h] = newNode;
        } else {
            Node<E> head = (Node<E>) tabHash[h];
            newNode.next = head;
            tabHash[h] = newNode;
        }
        this.qtd++;
        return true;
    }

    public E query(int key) {
        int h = hash(key);

        Node<E> head = (Node<E>) tabHash[h];

        while (head != null) {
            if (head.key == key) {
                return head.data;
            }
            head = head.next;
        }
        return null;
    }

    public E delete(int key) {
        int h = hash(key);

        Node<E> current = (Node<E>) tabHash[h];
        Node<E> prev = null;

        while (current != null) {
            if (current.key == key) {
                if (prev == null) {
                    tabHash[h] = current.next;
                } else {
                    prev.next = current.next;
                }
                current.next = null;
                this.qtd--;
                return current.data;
            }
            prev = current;
            current = current.next;
        }
        return null;
    }

    public void imprimeTab() {
        for (int i = 0; i < tabHash.length; i++) {
            System.out.print("[" + i + "]: ");
            @SuppressWarnings("unchecked")
            Node<E> atual = (Node<E>) tabHash[i];
            
            if (atual == null) {
                System.out.println("vago");
            } else {
                while (atual != null) {
                    System.out.print(" -> (Chave: " + atual.key + " | " + atual.data + ")");
                    atual = atual.next;
                }
                System.out.println();
            }
        }
    }
}