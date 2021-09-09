# Análisis de Complejidad Temporal en Algoritos de Ordenamiento

## ordenaSeleccion

Usa ciclos anidados para encontrar el elemento menor y cambiar su posición, da vueltas hasta ordenar el vector. Para el peor de los casos, su complejidad es ***O(n^2)***.

## ordenaBurbuja

Igual que la anterior, hace uso de ciclos anidados para cambiar de posición si el elemento es mayor que el continuo, lo recorre haciendo cambios hasta ordenar el vector. Su complejidad es, también, similar al de Ordenamiento para el peor de los casos: ***O(n^2)***.

## busqSecuencial

Recorre el arreglo buscando que el valor de búsqueda sea similar con alguno del arreglo, es lineal, su complejidad es ***O(n)*** para el peor de los casos.

## busqBinaria

A partir de un arreglo ordenado, divide y busca iniciando en el centro del arreglo, su complejidad es ***O(log n)*** para el peor de los casos.

## ordenaMerge

Divide a la mitad el arreglo hasta obtener solo un valor, después combina y junta las mitades que hace, su complejidad es ***O(nlog(n))*** para el peor de los casos.
