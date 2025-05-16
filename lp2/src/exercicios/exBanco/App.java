package exercicios.exBanco;

public class App {

	public static void main(String[] args) {
		Banco conta1 = new Banco();
		
		conta1.abrirConta("corrente");
		conta1.depositar(45f);
		
		System.out.printf("%.2f\n", conta1.getSaldo());
		
		conta1.pagarMensal();
		
		System.out.printf("%.2f\n", conta1.getSaldo());
		
		conta1.sacar(80f);
		System.out.printf("%.2f\n", conta1.getSaldo());
		conta1.pagarMensal();
		System.out.printf("%.2f\n", conta1.getSaldo());
	}

}
