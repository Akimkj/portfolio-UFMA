package exercicios.lista1;
import java.util.Scanner;
public class Ex001 {

	public static void main(String[] args) {
		Scanner leia = new Scanner(System.in);
		System.out.printf("Digite um inteiro: ");
		int n = leia.nextInt();
		System.out.printf("N\tN*10\tN*100\tN*1000");
		for (int i = 1; i <= n; i++) {
			System.out.printf("\n%d\t%d\t%d\t%d", i, i * 10, i * 100, i * 1000);
		}
		
		
		leia.close();
	}

}
