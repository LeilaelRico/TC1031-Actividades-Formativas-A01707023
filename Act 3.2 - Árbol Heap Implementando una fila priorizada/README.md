# Análisis de Complejidad.

## push

Con una complejidad de ***O(log n)*** para el peor de los casos, esta función se encarga de insertar un dato nuevo en el árbol; 

## pop

Saca el dato con mayor prioridad del árbol y vuelve a acomodar la estrucura haciendo uso de la función *heapify*, para el peor de los casos, su complejidad es de ***O(log n)***.

## top

Al devolver el dato que se encuentra al inicio y ser similar a un *getter*, su complejidad será de ***O(1)*** para el peor de los casos.

## empty

Al regresar un valor booleano para indicar si el árbol se encuentra vacío, para el peor de sus casos tiene una complejidad de ***O(1)***.

## size

Similar a un *getter*, regresa el dato registrado por el *int cuentaEspacios* para regresar la cantidad de datos dentro del árbol; cuenta con una complejidad de ***O(1)*** para el peor de los casos.
