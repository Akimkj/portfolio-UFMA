import java.util.ArrayList;

public class Stack {
    private int tamMax;
    private int top;
    private int[] list;
    private int repetir;

    public Stack(int tamanho, int podeRepetir) {
        this.tamMax = tamanho;
        if (tamanho <= 0) {
            this.tamMax = 1;
        }
        this.top = -1;
        this.list = new int[this.tamMax];
        this.repetir = podeRepetir;
    }

    public boolean push(int elem) {
        if (this.isFull() || !this.getPosSpec(elem).isEmpty() && this.repetir == 0) {
            return false;  
        }
        this.top++;
        this.list[this.top] = elem;
        return true;
    }

    public Integer pop() {
        if (this.isEmpty()) {
            return null;
        }
        int aux = this.list[this.top];
        this.top--;
        return aux;
    }

    public int getQuant() {
        return this.top + 1;
    }

    public int getTop() {
        return this.top;
    }

    public ArrayList<Integer> getPosSpec(int item) {
        ArrayList<Integer> poss = new ArrayList<>();
        for (int i = 0; i <= this.top; i++) {
            if (this.list[i] == item) {
                poss.add(i);
            }
        }
        return poss;
    }


    public void print() {
        for (int i = this.top; i >= 0; i--) {
            System.out.println(this.list[i]);
        }
    }

    public boolean isFull() {
        return this.top == this.tamMax - 1;
    }

    public boolean isEmpty() {
        return this.top == -1;
    }
}
