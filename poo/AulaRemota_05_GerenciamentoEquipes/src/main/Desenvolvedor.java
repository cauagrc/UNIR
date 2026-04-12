package main;

public class Desenvolvedor {
	private String nome;
	private String cargo;
	private int anosExperiencia;
	private static int totalDesenvolvedores = 0;
	
	public Desenvolvedor(String nome, String cargo, int anosExperiencia) {
		this.nome = nome;
        this.cargo = cargo;
        this.anosExperiencia = anosExperiencia;
        totalDesenvolvedores++;
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public String getCargo() {
		return cargo;
	}

	public void setCargo(String cargo) {
		this.cargo = cargo;
	}

	public int getAnosExperiencia() {
		return anosExperiencia;
	}

	public void setAnosExperiencia(int anosExperiencia) {
		this.anosExperiencia = anosExperiencia;
	}

	public static int getTotalDesenvolvedores() {
		return totalDesenvolvedores;
	}

	public static void setTotalDesenvolvedores(int totalDesenvolvedores) {
		Desenvolvedor.totalDesenvolvedores = totalDesenvolvedores;
	}
	
	
}
