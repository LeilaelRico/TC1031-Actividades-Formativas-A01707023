# Análisis de Complejidad

## loadGraphList

Al tratarse de la carga de un archivo (*O(n)*) para después hacer que esta información se añada en una lista (*O(1)*), su complejidad para el peor de los casos será de ***O(n)***.   

## DFS

Al tener que viajar por nodos los cuales están almacenados en una lista de adyacencia como si de una matriz se tratase, su complejidad para el peor de los casos es de ***O(n + m)***; viaja siempre eligiendo el nodo con el valor más pequeño.

## BFS

Similar a la estructura anterior, analiza los nodos de la lista de adyacencia para encontrar el camino más óptimo entre el origen y destino, su complejidad para el peor de los casos es de ***O(n + m)***.