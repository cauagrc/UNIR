package main;

import java.util.HashMap;
import java.util.Map;
import java.util.Set;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;

public class ExemploHashMap {
    public static void main(String[] args) {
        // Criando um HashMap de String para String
        HashMap<String, String> mapa = new HashMap<>();
        
        // Adicionando elementos ao mapa
        mapa.put("chave1", "valor1");
        mapa.put("chave2", "valor2");
        mapa.put("chave3", "valor3");
        System.out.println("Mapa original: " + mapa);

        // Recuperando um valor pela chave
        String valor = mapa.get("chave2");
        System.out.println("Valor associado à chave 'chave2': " + valor);

        // Verificando se o mapa contém uma chave específica
        boolean contemChave = mapa.containsKey("chave3");
        System.out.println("O mapa contém a chave 'chave3'? " + contemChave);

        // Verificando se o mapa contém um valor específico
        boolean contemValor = mapa.containsValue("valor2");
        System.out.println("O mapa contém o valor 'valor2'? " + contemValor);

        // Removendo um par chave-valor do mapa
        mapa.remove("chave1");
        System.out.println("Mapa após remover o par chave-valor associado à chave 'chave1': " + mapa);

        // Obtendo o tamanho do mapa
        int tamanho = mapa.size();
        System.out.println("Tamanho do mapa: " + tamanho);

        // Verificando se o mapa está vazio
        boolean vazio = mapa.isEmpty();
        System.out.println("O mapa está vazio? " + vazio);

        // Limpando o mapa
        mapa.clear();
        System.out.println("Mapa após limpar: " + mapa);

        // Criando um novo mapa
        mapa.put("chaveA", "valorA");
        mapa.put("chaveB", "valorB");
        mapa.put("chaveC", "valorC");

        // Obtendo um conjunto de chaves do mapa
        Set<String> chaves = mapa.keySet();
        System.out.println("Conjunto de chaves: " + chaves);
        ArrayList<String> indices = new ArrayList<String>(chaves);
        Collections.sort(indices);
        
        for (String key : indices) {
        	System.out.println("Chave: " + key + " Valor: " + mapa.get(key));
        }
        
        
        // Obtendo uma coleção de valores do mapa
        Collection<String> valores = mapa.values();
        System.out.println("Coleção de valores: " + valores);

        // Obtendo um conjunto de pares chave-valor do mapa
        Set<Map.Entry<String, String>> pares = mapa.entrySet();
        System.out.println("Conjunto de pares chave-valor: " + pares);
    }
}
