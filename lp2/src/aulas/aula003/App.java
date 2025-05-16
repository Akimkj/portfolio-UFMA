package aulas.aula003;

public class App {

	public static void main(String[] args) {
		ControleRemoto c1 = new ControleRemoto();
		
		c1.ligar();
		c1.play();
		for (int i = 0; i < 10; i++) {
			c1.diminuirVolume();
		}
		c1.abrirMenu();

	}

}
