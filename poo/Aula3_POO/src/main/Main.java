package main;

public class Main {
	
	public static void main(String[] args) {
		Aluno veterano = new Aluno();
		
		veterano.setMatricula("12345678");
		veterano.setCurso("Computacao");
		veterano.setName("Aluno");
		
		veterano.visualizarDados();
	}

}
