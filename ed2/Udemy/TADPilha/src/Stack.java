import java.util.ArrayList;

/*
Nesta implementação, o TAD Stack depende quase totalmente da classe ArrayList para realizar suas operações. No entanto, a complexidade deste algoritmo torna-se ocasionalmente O(n), pois para cada vez que o espaço reservado na memória precisa ser expandido, a classe ArrayList cria um novo vetor/espaço maior e realoca todos esses dados para esse novo espaço.


A outra forma (e mais perfomatica) de implementar o TAD Stack é por meio de uma Lista Encadeada.
*/

public class Stack<E> {
    private final ArrayList<E> pilha;

    public Stack() {
        pilha = new ArrayList<>();
    }

    public E push(E elem) {
        pilha.add(elem);
        
        return elem;
    }

    public E pop() {
        if (this.isEmpty()) {
            throw new RuntimeException("Pilha está vazia. Não há o que desempilhar.");
        }
        E aux = this.peek();
        this.pilha.remove(this.size() - 1);
        return aux;
    }

    public E peek() {
        if (this.isEmpty()) {
            throw new RuntimeException("Pilha está vazia. Não há o que espiar.");
        }
        int top = this.size() - 1;
        return this.pilha.get(top);
    }

    public int size() {
        return this.pilha.size();
        /*
        return this.top + 1;
        */
    }

    public boolean isEmpty() {
        return this.pilha.isEmpty();
        /*
        return this.top == -1; 
        or 
        return this.pilha.size() == 0;
        */
    }
}
