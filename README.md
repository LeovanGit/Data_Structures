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
  
