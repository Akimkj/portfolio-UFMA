public class LinkedList<E> {
    private static class Node<E> {
        E data;
        Node <E> prev;
        Node<E> next;

        Node(E data, Node<E> prev, Node<E> next) {
            this.data = data;
            this.prev = prev;
            this.next = next;
        }
    }

    private Node<E> head;
    private Node<E> tail;
    private int size;

    public LinkedList() {
        this.head = null;
        this.tail = null;
        this.size = 0;
    }

    private Node<E> node(int index) {
        if (index < 0 || index >= this.size) {
            throw new IndexOutOfBoundsException();
        }

        Node<E> current;
        if (index > (this.size - 1) / 2) {
            current = this.tail;
            for (int i = this.size - 1; i > index; i--) {
                current = current.prev;
            }
        } else {
            current = this.head;
            for (int i = 0; i < index; i++) {
                current = current.next;
            } 
        }
        
        return current;
    }

    public boolean add(E elem, int index) {
        if (index < 0 || index > this.size) {
            throw new IndexOutOfBoundsException();
        }

        
        if (index == 0) {
            Node<E> newNode = new Node<>(elem,null, this.head);
            if (this.head != null) {
                this.head.prev = newNode;
            }
            this.head = newNode;
            if (this.size == 0) {
                this.tail = newNode;
            }
        } else if (index == this.size) {
            Node<E> newNode = new Node<>(elem,this.tail, null);
            this.tail.next = newNode;
            this.tail = newNode;
        } else {
            Node<E> current = node(index);
            Node<E> prev = current.prev;

            Node<E> newNode = new Node<>(elem,prev, current);

            current.prev = newNode;
            prev.next = newNode;
        }
        this.size++;
        return true;
    }

    // MUDAR PARA DOUBLE LIST
    public E remove(int index) {
        if (index < 0 || index >= this.size) {
            throw new IndexOutOfBoundsException();
        }

        Node<E> aux;
        if (index == 0) {
            aux = this.head;
            this.head = aux.next;

            if (this.head != null) {
                this.head.prev = null;
            }
            if (this.tail == aux) {
                this.tail = this.head;
            }
        } else {
            aux = node(index);
            Node<E> prev = aux.prev;
            Node<E> next = aux.next;

            prev.next = next;
            if (next != null) {
                next.prev = prev;
            } else {
                this.tail = prev;
            }
        }

        aux.prev = null;
        aux.next = null; 
        this.size--;
        return aux.data;
    }

    public boolean addFirst(E elem) {
        try {
            Node<E> newNode = new Node<>(elem, null, this.head);
            this.head = newNode;
            this.size++;
            if (this.tail == null) {
                this.tail = newNode;
            }
            return true;    
        } catch (Exception e) {
            return false;
        }
        
    }

    public boolean addLast(E elem) {
        try {
            Node<E> newNode = new Node<>(elem,this.tail,null);
            if (this.isEmpty()) {
                this.head = newNode;
            }

            this.tail.next = newNode;
            this.tail = newNode;
            this.size++;
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
        if (this.head != null) {
            this.head.prev = null;
        }
        aux.next = null; // tornamos null o proximo do nó que sera retirado
        if (this.tail == aux) {
            this.tail = this.head;
        }
        this.size--;
        return aux.data; // retornamos data
    }

    public E removeLast() {
        if (isEmpty()) {
            return null;
        }
        Node<E> aux = this.tail;
        Node<E> prev = aux.prev;

        aux.prev = null; 
        this.tail = prev;
        if (prev != null) {
            prev.next = null;
        }

        return aux.data;
    }

    public E get(int index) {
        if (isEmpty()) {
            return null;
        }
        try {
            Node<E> node = node(index);
            return node.data;
        } catch (Exception e) {
            return null;
        }
    }

    public E getFirst() {
        if (isEmpty()) {
            return null;
        }
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
        return this.tail;
    }

    public boolean isEmpty() {
        return this.head == null || this.tail == null;
    }

    public int size() {
        return this.size;
    }

    public void clear() {
        this.head = null;
        this.tail = null;
        this.size = 0;
    }
} 
