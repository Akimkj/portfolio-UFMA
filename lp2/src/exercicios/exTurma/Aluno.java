package exercicios.exTurma;

public class Aluno {
	private String nome;
	private int matricula;
	public static final String curso = "Ciência da Computação";
	
	public Aluno() {}
	public Aluno(String nome, int matricula) {
		this.nome = nome;
		this.matricula = matricula;
	}
	
	public String getNome() {
		return nome;
	}
	
	public void setNome(String nome) {
		this.nome = nome;
	}
	
	public int getMatricula() {
		return matricula;
	}
	
	public void setMatricula(int matricula) {
		this.matricula = matricula;
	}
	
}
