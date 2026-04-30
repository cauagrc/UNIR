package main;

import java.util.LinkedList;

public class ExemploLinkedList {
    public static void main(String[] args) {
        // Criando uma LinkedList de Strings
        LinkedList<String> lista = new LinkedList<>();

        // Adicionando elementos à lista
        lista.add("Maçã");
        lista.add("Banana");
        lista.add("Laranja");
        System.out.println("Lista original: " + lista);

        // Adicionando um elemento na posição específica
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

        // Limpando a lista
        lista.clear();
        System.out.println("Lista após limpar: " + lista);

        // Verificando se um elemento está na lista
        boolean contemLaranja = lista.contains("Laranja");
        System.out.println("A lista contém 'Laranja'? " + contemLaranja);

        // Adicionando elementos novamente
        lista.add("Maçã");
        lista.add("Banana");
        lista.add("Maçã");

        // Encontrando o índice da primeira ocorrência de "Maçã"
        int indiceMaçã = lista.indexOf("Maçã");
        System.out.println("Índice da primeira ocorrência de 'Maçã': " + indiceMaçã);

        // Encontrando o índice da última ocorrência de "Maçã"
        int ultimoIndiceMaçã = lista.lastIndexOf("Maçã");
        System.out.println("Índice da última ocorrência de 'Maçã': " + ultimoIndiceMaçã);
    }
}
