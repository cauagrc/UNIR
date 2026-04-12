package main;

public class Main {
    public static void main(String[] args) {

        Estudio estudio = new Estudio("Programadores");
        
        Projeto projeto1 = new Projeto("Jogo");
        Projeto projeto2 = new Projeto("Sistema");

        Desenvolvedor desenvolvedor1 = new Desenvolvedor("Pablo", "Programador Senior", 4);
        Desenvolvedor desenvolvedor2 = new Desenvolvedor("Henrique", "Programador Junior", 1);

        projeto1.addDesenvolvedor(desenvolvedor1);
        projeto2.addDesenvolvedor("João", "Scrum Master", 2);

        projeto2.addDesenvolvedor(desenvolvedor1, desenvolvedor2);

        estudio.addProjeto(projeto1);
        estudio.addProjeto(projeto2);

        System.out.println("Nome Estudio: " + estudio.getNome());
        System.out.printf("\n");
        
        int indice;

        for (Projeto projeto : estudio.getProjetos()) {
            System.out.println("Projeto: " + projeto.getNome());
            indice = 0;

            for (Desenvolvedor developer : projeto.getDesenvolvedores()) {
            	indice++;
            	System.out.println(indice + ". " + developer.getNome());
            	System.out.println("Cargo: " + developer.getCargo());
                System.out.println("Anos de Experiencia " + developer.getAnosExperiencia() + " anos");
                System.out.printf("\n");
            }
        }

        System.out.println("Total de desenvolvedores: " + Desenvolvedor.getTotalDesenvolvedores());
        
    }
}