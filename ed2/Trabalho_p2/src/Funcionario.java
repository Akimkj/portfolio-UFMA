public class Funcionario {
    String nome;
    int idade;
    float salario;

    public Funcionario(String nome, int idade, float salario) {
        this.nome = nome;
        this.idade = idade;
        this.salario = salario;
    }

    @Override
    public String toString() {
        return String.format("%-25s | Idade: %2d | R$ %.2f",
            nome, idade, salario);
    }
}
