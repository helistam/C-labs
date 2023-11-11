# <center> Лабораторные работы 3 семестр С++ </center> 
***
### Navigation 
* [Лр1](https://github.com/helistam/C-labs/tree/master/lab1)
* [Лр2](https://github.com/helistam/C-labs/tree/master/lab2)
* [Лр3](https://github.com/helistam/C-labs/tree/master/lab3)
* [Лр4](https://github.com/helistam/C-labs/tree/master/lab4)
* [Лр5](https://github.com/helistam/C-labs/tree/master/lab5)
* [Лр6](https://github.com/helistam/C-labs/tree/master/lab6)
* [Лр6](https://github.com/helistam/C-labs/tree/master/lab7)

# Условия лабораторных
# <center>Лабораторная работа 1 <center> 
Создать класс, в котором реализовать функции для работы с 
одномерными массивами: 
а) получить пересечение элементов массивов; 
б) получить объединение элементов массивов. 
Память под массивы отводить динамически. Использовать конструктор с 
параметрами, конструктор копирования. Деструктор должен освобождать 
память, выделенную под массивы.
# <center>Лабораторная работа 2 <center> 
 Написать класс для работы с символьными строками. Память под строку 
отводить динамически. Перегрузить операторы =, +, +=, ==, !=, [], ()(int, int). 
Продемонстрировать работу с этими операторами. 
# <center>Лабораторная работа 3 <center> 
Реализовать наследование согласно диаграмме классов

![Image alt](https://github.com/helistam/C-labs/blob/master/taskScreen/task3.png)

# <center>Лабораторная работа 4 <center> 
Реализовать свой класс "список"(List)
# <center>Лабораторная работа 5 <center>
Написать программу на основе лабораторных №3-4:
Реализовать базовый класс ошибок, от него унаследовать несколько 
других классов (для проверки ввода числа, ввода строк и т.д.)

![Image alt](https://github.com/helistam/C-labs/blob/master/taskScreen/task5.png)

Написать функции для проверки ввода различных полей (имя, дата, 
номер карты…) и добавить их вызов при заполнении полей класса. В них 
генерировать исключения, например при неправильном вводе

**if(str[i]<’A’||str[i]>’Z’)
throw ExpVvod(123, “Вводите только прописными латинскими буквами.”);**

При необходимости добавить генерацию ошибок на неправильное 
выделение памяти, выход за границы контейнера и т.п.

# <center>Лабораторная работа 6 <center>
 Задание выполнить на основе предыдущих лабораторных работ.
Расшить функционал предыдущих работ. Написать функции для 
чтения/записи в файл в двух видах: текстовом и бинарном. В контейнер 
(разработанный в лабораторной работе №4) поместить несколько объектов из 
лабораторной работы №3, записать содержимое контейнера в файл и 
прочитать записанные данные обратно в контейнер. Для записи в бинарный 
файл следует использовать промежуточную структуру с фиксированным 
размером полей, если в исходном классе содержатся динамические поля.
Продемонстрировать работу с текстовыми и бинарными файлами.

# <center>Лабораторная работа 8 <center>
Продемонстрировать работу с vector и библиотекой algorithm