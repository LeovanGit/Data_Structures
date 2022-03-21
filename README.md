# Динамический массив
---

<table border="0" align="center" width="50%" cellspacing="0">
  <tr>
		<th>2</th>
		<th>-1</th>
    <th>0</th>
		<th>5</th>
    <th>3</th>
		<th>20</th>
    <th>8</th>
		<th>1</th>
    <th>10</th>
		<th>31</th>
	</tr>

<table border="1" align="center" width="50%" cellspacing="0">
  <tr>
		<th>ПЛЮСЫ</th>
		<th>МИНУСЫ</th>
	</tr>
  <tr>
		<td>Все элементы находяться в непрерывной области памяти (идут друг за другом), что позволяет зная адрес первого элемента максимально быстро обратиться ко всем другим используя адресную арифметику</td>
		<td> Медленное добавление\удаление элементов:
      <ul>
          <li>Создать новый массив с бОльшим размером</li>
          <li>Перенести все данные из старого массива в новый</li>
          <li>Удалить старый массив</li>
      </ul>
    </td>
	</tr>
</table>

Соответственно если приходиться часто вносить изменения, то использовать динамический массив не лучшая идея.
  
# Односвязный список
---

__Односвязный список__ - динамическая структура данных, состоящая из узлов, каждый из которых содержит данные и указатель на следующий узел.

![singly_linked](https://upload.wikimedia.org/wikipedia/commons/thumb/9/9c/Single_linked_list.png/400px-Single_linked_list.png)

<table border="1" align="center" width="50%" cellspacing="0">
  <tr>
		<th>ПЛЮСЫ</th>
		<th>МИНУСЫ</th>
	</tr>
  <tr>
		<td>Чтобы добавить\удалить элемент достаточно поменять значения нескольких указателей</td>
		<td>Элементы списка могут находиться в совершенно разных областях памяти, что значительно замедляет доступ к ним по индексу: приходиться проходиться по всем элементам списка до нужного нам</td>
	</tr>
    <tr>
		<td></td>
		<td>Каждому узлу необходимо небольшое дополнительное место, как минимум под указатель</td>
	</tr>
</table>

# Двусвязный список
---
  
Каждый узел списка помимо указателя на следующий элемент, теперь содержит указатель на предыдущий, что частично решает проблему с медленным доступом к элементам.
  
![doubly_linked](https://upload.wikimedia.org/wikipedia/commons/thumb/c/ca/Doubly_linked_list.png/800px-Doubly_linked_list.png?20050612101643)
  
<table border="1" align="center" width="50%" cellspacing="0">
  <tr>
		<th>ПЛЮСЫ</th>
		<th>МИНУСЫ</th>
	</tr>
  <tr>
		<td>Все плюсы односвязного списка</td>
		<td>Все минусы односвязного спика</td>
	</tr>
    <tr>
		<td>В некоторых ситуациях поиск с конца списка будет быстрее чем с начала, что частично решает проблему с медленным доступом к элементам. Например мы знаем что длина списка 10, а нам нужен элемент под индексом 8, логичнее было бы искать с конца</td>
		<td>Не для всех задач нужен указатель на предыдущий элемент. В итоге он просто будет занимать лишнее место</td>
	</tr>
</table>
  
Неправильно считать что __двусвязный список__ лучше __односвязного__ и соответственно последний вовсе никогда не использовать. Под каждую задачу приходиться выбирать между структурами данных. Допустим если чаще всего работа идёт с началом списка, то односвязный будет хорошим выбором, если с концом списка - двусвязный.
  
# Кольцевой связный список
---
  
Одной из разновидностей связных списков является кольцевой список. Его отличие лишь в том что последний элемент содержит адрес не на __nullptr__, а на первый элемент, и соответственно первый элемент содержит адрес на последний, в случае двусвязного списка.
  
![circular_linked](https://upload.wikimedia.org/wikipedia/commons/thumb/9/98/Circurlar_linked_list.png/400px-Circurlar_linked_list.png)
  
__Многие другие динамические структуры данных построенны на динамическом массиве и связных списках, так что это основа.__

# Стек
---

__Стек__ - структура данных, организованная по принципу __LIFO__ (Last In First Out).

![stack](https://cafedev.vn/wp-content/uploads/2020/07/cafedev-of-stack.png)
	
Стек часто реализуется как динамический массив, однако для стека не важна скорость доступа к элементам, поскольку мы не собираемся итерироваться по его элементам, а работать будем только с его вершиной. Куда важнее уметь быстро добавлять\удалять последний элемент. Соответственно __односвязный список__ будет отличной основой для стека.


# Очередь
---
	
__Очередь__ - структура данных, организованная по принципу __FIFO__ (First In First Out).
	
![queue](https://lh6.googleusercontent.com/_wsL1YMOLzVyg3q4T3VohbjTtiiQiWuvFf8aLZkun1W12vDtrnR9764nMUS181xLEVb26MvugjxqJ14AMlLBfPMbPy5gYX_V9SGbmsLDbzN3VUpq0RHx1T8uugY6s6FMWTZRPvDd)

В очереди, нам тоже не нужно итерироваться по элементам, однако кроме указателя на вершину нам пригодиться указатель на последний элемент очереди. Соответственно __односвязный список__ с дополнительным указателем на последний элемент (ну или двусвязный с ограниченным функционалом, что тоже самое) наш выбор.

# Кольцевая очередь
---
	
Это та же самая очередь, только при извлечении элемента мы его не удаляем из очереди, а снова добавляем в конец очереди.
	
# Очередь с приоритетом
---
	
Есть несколько вариантов организации такой очереди:
* При добавлении нового элемента в очередь мы его сразу же сортируем по приоритету - __очередь с приоритетным включением__
* В момент извлечения элемента из очереди мы выбираем самый приоритетный - __очередь с приоритетным исключением__

# Дек
---

__Deque__ (double ended queue) - двухсторонняя очередь, элементы можно добавлять и удалять как в начало, так и в конец очереди. Указатели на начало и конец очереди теперь называются левая и правая стороны. Реализовывать дек опять же можно на __динамическом масиве__ либо на __двусвязном списке__.

![deque](https://cdn.programiz.com/sites/tutorial2program/files/deque.png)

 Реализация деки в библиотеке __STL__ несколько особенная: она позволяет нам так же итерироваться по её элементам (по сути тот же двусвязный список), но отличия с двусвязным списком есть. Узлы в деке __STL__ это маленькие динамические массивы, т.е. новый элемент добавляется в динамический массив, а когда массив заполнится вместо того что бы изменить его размер создаётся еще один массив:

![deque_STL](https://i.ibb.co/4TCQpxC/2.png)

Такой гибрид значительно влияет на его скоростные характеристики.

Разновидности __дек__:
* Дек с ограниченным входом - можно добавлять новый элемент только с одной стороны, а извлекать с двух
* Дек с ограниченным выходом - можно добавлять элемент с двух сторон, а извлекать только с одной

# Бинарное дерево
---

__Бинарное дерево__ - динамическая структура данных, состоящая из узлов; каждый узел является родителем (имеет указатели на) двух других узлов - левого и правого (Бинарное - каждый узел может максимум иметь двух потомков).

__Корень__ - узел у которого нет родителя (самый первый).

__Листья__ - узлы у которых нет потомков.

Бинарное дерево __упорядоченная структура данных__ - всегда отсортирована. Благодаря этому бинарное дерево частично решает проблемы связных списков. В связном списке что бы найти элемент пришлось бы пройтись по всему списку пока не наткнемся на него, в дереве мы каждый раз отбрасываем ветку которая нам не подходит.

![binary_tree](https://upload.wikimedia.org/wikipedia/commons/thumb/d/da/Binary_search_tree.svg/274px-Binary_search_tree.svg.png)

Новый узел добавляют:
* __Влево__, если его значение меньше чем у родителя
* __Вправо__, если его значение больше чем у родителя

При этом что делать если узел имеет значение, которое уже есть в дереве зависит от реализаций:
* Не вставляют его в дерево, соответственно дерево хранит уникальные значения как множество (set)
* Вставляют влево, как в multiset

Вырвав из контекста дерева любой его элемент, его можно считать корнем меньшего дерева. Соответственно при работе с деревом удобно использовать __рекурсию.__

Удаление элементов из дерева:
* __Лист__ - просто удаляем и заменяем указатель родителя на nullptr
* __Корень с одним потомком__ - подменяем на потомка
* __Корень с двумя потомками__ - заменяем его на самый левый элемент в правой ветке (самый маленький в правой ветке): нам нужно поставить элемент, который больше чем любой в левой ветке и меньше чем любой в правой.

Деревьев нет в стандартных библиотеках, поскольку есть более хорошие контейнеры, однако деревья применяются как основа для некоторых других структур.
