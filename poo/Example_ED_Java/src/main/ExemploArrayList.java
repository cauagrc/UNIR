package main;

import java.util.ArrayList;

public class ExemploArrayList {
    public static void main(String[] args) {
        // Criando um ArrayList de Strings
        ArrayList<String> lista = new ArrayList<>();
       
        // Adicionando elementos à lista
        lista.add("Maçã");
        lista.add("Banana");
        lista.add("Laranja");
        System.out.println("Lista original: " + lista);

        // Adicionando um elemento em uma posição específica
        lista.add(1, "Uva");
        System.out.println("Após adicionar 'Uva' na posição 1: " + lista);

        // Removendo um elemento pelo índice
        lista.remove(2);
        System.out.println("Após remover o elemento na posição 2: " + lista);

        // Removendo um elemento pelo valor
        lista.remove("Maçã");
        System.out.println("Após remover 'Maçã': " + lista);

        // Acessando um elemento pelo índice
        String fruta = lista.get(0);
        System.out.println("Primeiro elemento da lista: " + fruta);

        // Substituindo um elemento pelo índice
        lista.set(0, "Pera");
        System.out.println("Após substituir 'Maçã' por 'Pera': " + lista);

        // Verificando o tamanho da lista
        int tamanho = lista.size();
        System.out.println("Tamanho da lista: " + tamanho);

        // Verificando se a lista está vazia
        boolean vazia = lista.isEmpty();
        System.out.println("A lista está vazia? " + vazia);
        String a = "";
       
        // Limpando a lista
        lista.clear();
        System.out.println("Lista após limpar: " + lista);
        

        // Verificando se um elemento está na lista
        boolean contemLaranja = lista.contains("Laranja");
        System.out.println("A lista contém 'Laranja'? " + contemLaranja);
    }
}

