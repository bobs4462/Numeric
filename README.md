# Numeric

Программа Nummeric для нахождения решения СЛАУ.

В ней реализовано 3 метода решения:

	*Метод Гаусса
	*Метод Зейделя
	*Метод Итерации

Для компиляции программы вам необходим Make и GCC (Unix подобная система тоже необходима)
Достаточно запустить make из директории src.
Для компиляции под Windows можно попробывать подключить все файлы в проект и скомпилировать,
нет гарантий что заработает без "танцев с бубном".


Запуск программы возможен с опциями и без.

например:

	./numeric 2x2 -v

./numeric - название программы

2x2 	  - название файла с уравнением

-v        - пока что единственная доступная опция выводит подробные шаги операций

В случае если опции не указаны, программа попросит ввести название файла с уравнением.

Примеры файлов с уравнениями находятся в директории equations
Парсер программы достаточно слабоват, и поэтому уравнения должны
явно содержать все коэффициенты, если коэффициент равен нулю, нуль 
пишется а переменная после не пишется (вообще переменные писать не обязательно).
В названиях переменных не допускается использование цифр.

Программа может решать СЛАУ любой размерности, но обязательным условием является 
отсуствие свободных переменных (все переменные базисные), вычисления определителя
будет произведено перед началом решения.

Метод Гаусса может решать уравнения определитель матрицы которой не равен нулю.
Также программа сама будет переставлять строки для не допущения деления на нуль.

Метод Зейделя может решать уравнения, матрица которых является диагонально 
преобладающей, если же матрица таковой не является, программа сделает жалкую 
попытку привести её к такому виду, и если у неё это не получится, то программа
завершится, если же получится то будьте готовы к тому что переменные будут перепутаны
(в целом ответ будет правильным но значение будут присвоены не тем переменным)

Метод Итерации аналогичен Методу Зейделя, но сходится чуть медленнее.



	
