package exercicios.lista1;
import java.util.Scanner;
public class Ex002b {

	public static void main(String[] args) {
		Scanner leia = new Scanner(System.in);
		int linhas = leia.nextInt();
		
		for (int i = linhas; i >= 1; i--) {
			for (int j = 1; j <= i; j++) {
				System.out.printf("*");
			}
			System.out.println();
		}
		leia.close();
	}

}
