### Лабораторная работа №3 по дисциплине: «Алгоритмы и структуры данных»
Изучение и исследование методов балансировки двоичных деревьев поиска на примере АТД «Сбалансированное дерево поиска». Освоение методики модификации коллекций с помощью механизма наследования классов.
#### Вариант
АВЛ-дерево как модификация BST-дерева. Алгоритмы операций вставки, удаления и поиска реализуются в рекурсивной форме.
#### Задание
Спроектировать, реализовать и провести тестовые испытания АТД «Сбалансированное дерево поиска» для коллекции, содержащей данные произвольного типа. Тип данных задаётся клиентской программой.
АТД «Сбалансированное дерево поиска» представляет собой модифицированную версию АТД «BST-дерево» с трудоёмкостью операций O(log2n).
Интерфейс АТД «Сбалансированное дерево поиска» включает следующие операции:
- конструктор,
- конструктор копирования,
- деструктор,
- опрос размера дерева,
- очистка дерева,
- проверка дерева на пустоту,
- доступ по чтению/записи к данным по ключу,
- включение данных с заданным ключом,
- удаление данных с заданным ключом,
- запрос прямого итератора, установленного на узел дерева с минимальным ключом begin(),
- запрос обратного итератора, установленного на узел дерева с максимальным ключом rbegin(),
- запрос «неустановленного» прямого итератора end(),
- запрос «неустановленного» обратного итератора rend(),
Операции прямого и обратного итераторов:
- операция доступа по чтению и записи к данным текущего узла * ,
- операция перехода к следующему (для обратного – к предыдущему) по ключу узлу в дереве ++ ,
- операция перехода к предыдущему (для обратного – к следующему) по ключу узлу в дереве -- ,
- проверка равенства однотипных итераторов == ,
- проверка неравенства однотипных итераторов != .