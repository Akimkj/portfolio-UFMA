

public class Fila {
    private int front;
    private int rear;
    private int tamMax;
    private int numItens;
    private int[] itens;

    public Fila(int tamMax) {
        if (tamMax <= 0) {
            throw new RuntimeException("Erro: O tamanho da fila não pode ser menor ou igual a 0.");
        }
        this.tamMax = tamMax;
        this.front = 0;
        this.rear = 0;
        this.numItens = 0;
        this.itens = new int[this.tamMax];
    }

    public String enqueue(int value) {
        if (this.isFull()) {
            return "Erro: limite da fila já atingido!";
        } 

        this.itens[this.rear] = value;
        this.rear = (this.rear + 1) % this.tamMax;
        this.numItens++;

        return "Elemento enfileirado com Sucesso!";
    }

    public Integer dequeue() {
        if (this.isEmpty()) {
            return null;
        }

        int aux = this.peek();
        this.front  = (this.front + 1) % this.tamMax;
        this.numItens--;
        return aux;
    }

    public Integer peek() {
        if (this.isEmpty()) {
            return null;
        }
        return this.itens[this.front];
    }

    public boolean isFull() {
        return this.numItens == this.tamMax;
    }

    public boolean isEmpty() {
        return this.numItens == 0;
    }

    public String print() {
        String ret = "";
        if (this.isEmpty()) {
            ret = "A fila esta vazia";
        } else if (this.front < this.rear) {
            for (int i = this.front; i < this.rear; i++) {
                ret += this.itens[i] + " ";
            }
        } else if (this.isFull() || this.front > this.rear) {
            for (int i = this.front; i < this.tamMax; i++) {
                ret += this.itens[i] + " ";
            }
            if (this.front > 0) {
                for (int i = 0; i < this.rear; i++) {
                    ret += this.itens[i] + " ";
                }
            }
        }
        return ret;
    }

    public int getFront() {
        return this.front;
    }

    public int getRear() {
        return this.rear;
    }

    public int getTamMax() {
        return this.tamMax;
    }

    public int size() {
        return this.numItens;
    }
}
