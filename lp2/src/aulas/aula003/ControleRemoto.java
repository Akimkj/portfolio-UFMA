package aulas.aula003;

public class ControleRemoto implements Controlador {
	private int volume;
	private boolean tocando;
	private boolean ligado;
	
	public ControleRemoto() {
		this.volume = 50;
		this.tocando = false;
		this.ligado = false;
	}

	public int getVolume() {
		return volume;
	}

	public void setVolume(int volume) {
		this.volume = volume;
	}

	public boolean isTocando() {
		return tocando;
	}

	public void setTocando(boolean tocando) {
		this.tocando = tocando;
	}

	public boolean isLigado() {
		return ligado;
	}

	public void setLigado(boolean ligado) {
		this.ligado = ligado;
	}

	
	@Override
	public void ligar() {
		this.setLigado(true);
	}

	@Override
	public void desligar() {
		this.setLigado(false);
		
	}

	@Override
	public void aumentarVolume() {
		if (this.isLigado() && this.getVolume() < 100) {
			this.setVolume(this.getVolume() + 5);
		}
	}

	@Override
	public void diminuirVolume() {
		if (this.isLigado() && this.getVolume() > 0) {
			this.setVolume(this.getVolume() - 5);
		}
		
	}

	@Override
	public void abrirMenu() {
		System.out.printf("Está ligado? %b\n", this.isLigado());
		System.out.printf("Está tocando? %b\n", this.isTocando());
		System.out.printf("Volume: %d\t", this.getVolume());
		for (int i = 0; i <= this.getVolume(); i++) {
			System.out.printf("|");
		}
		System.out.println();
		
	}

	@Override
	public void fecharMenu() {
		System.out.println("Menu fechando...");
		
	}

	@Override
	public void ligarMudo() {
		if (this.isLigado() && this.getVolume() > 0) {
			this.setVolume(0);
		}
		
	}

	@Override
	public void desligarMudo() {
		if (this.isLigado() && this.getVolume() == 0) {
			this.setVolume(50);
		}
		
	}

	@Override
	public void play() {
		if (this.isLigado() && (!this.isTocando()) ) {
			this.setTocando(true);
		}
	}

	@Override
	public void pause() {
		if (this.isLigado() && (this.isTocando()) ) {
			this.setTocando(false);
		}
	}
	
	
	
}
