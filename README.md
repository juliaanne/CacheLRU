# Cache LRU

---

Repositório para o  trabalho da disciplina **Tópicos Especiais em Programação** do curso de *Ciência da Computação - UFRJ*

Simulação de uma memória cache LRU - Least Recently Used - utilizando a *linguagem*.

---

#### Usage

O Cache LRU pode:

1. Verificar se contém uma chave, e atualizá-la para a ultima da lista pois foi recentemente visitada.

2. Inserir na lista na primeira posição - convenção de mais recente.
  1. Inserir caso não ultrapasse loadFactor
  2. Inserir e remover última posição caso ultrapasse loadFactor
  3. Inserir caso a lista esteja vazia MESMO QUE ultrapasse loadFactor

3. Remover da lista a última posição - convenção de mais antiga.
