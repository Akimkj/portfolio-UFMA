package exercicios.lista1;
import java.util.Scanner;
public class Ex002a {
	public static void main(String[] args) {
		Scanner leia = new Scanner(System.in);
		
		int linhas = leia.nextInt();
		
		while (true) {
			if (linhas > 1) {
				break;
			}
			linhas = leia.nextInt();
		}
		
		for (int i = 1; i <= linhas; i++) {
			for (int j = 1; j <= i; j++) {
				System.out.printf("*");
			}
			System.out.println();
		}
		leia.close();
	}

}
