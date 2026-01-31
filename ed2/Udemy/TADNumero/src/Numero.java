public class Numero {
    private float valor;

    public Numero() {
        this.valor = 0;
    }

    public float getValor() {
        return this.valor;
    }

    public void setValor(float number) {
        this.valor = number;
        if (number > 100) {
            this.valor = 100.0f;
        } else if (number < 0) {
            this.valor = 0.0f;
        } else if (number > 40 && number < 60) {
            if (number < 50) {
                this.valor = 40;
            } else {
                this.valor = 60;
            }
        }
    }
    
}
