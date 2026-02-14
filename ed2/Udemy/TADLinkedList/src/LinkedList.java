public class LinkedList<E> {
    private static class Node<E> {
        E data;
        Node<E> next;

        Node(E data, Node<E> next) {
            this.data = data;
            this.next = next;
        }
    }

    Node<E> head;

    public LinkedList() {
        this.head = null;
    }

    public boolean addFirst(E elem) {
        try {
            Node<E> newNode = new Node<>(elem, head);
            this.head = newNode;
            return true;    
        } catch (Exception e) {
            return false;
        }
        
    }

    public boolean addLast(E elem) {
        try {
            Node<E> newNode = new Node<>(elem, null);
            if (this.isEmpty()) {
                this.head = newNode;
            } else {
                Node<E> last = getLastNode();
                last.next = newNode;
            }
            return true;
        } catch (Exception e) {
            return false;
        }
    }

    public E removeFirst() {
        if (isEmpty()) {
            return null;
        }
        Node<E> aux = this.head; //salva o topo (inicio da lista)
        this.head = aux.next; //o topo agora é o proximo elemento da lista
        aux.next = null; // tornamos null o proximo do nó que sera retirado
        return aux.data; // retornamos data
    }

    public E getFirst() {
        return this.head.data;
    }

    public E getLast() {
        if (isEmpty()) {
            return null;
        }
        return this.getLastNode().data;
    }

    Node<E> getLastNode() {
        if (isEmpty()) {
            return null;
        }
        Node<E> spec = this.head;
        while (spec.next != null) {
            spec = spec.next;
        }
        return spec;
    }

    public boolean isEmpty() {
        return this.head == null;
    }
}
