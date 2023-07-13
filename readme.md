## Работа с MySQL API в Linux Ubuntu

Найдено здесь https://www.programmersought.com/article/78966223321/#数据库连接c-api

Установить библиотеку для разработчиков. Она есть в репозиториях.

``` 
$ sudo apt install libmysqlclient-dev
```
Команда:
```
$ mysql_config --cflags --libs
```
покажет какие библиотеки надо указать в параметрах компилятора:
```
-I/usr/include/mysql - include path
-L/usr/lib/x86_64-linux-gnu -lmysqlclient -lpthread -lz -lm -lrt -ldl - включение библиотек
```

Примеры запуска компилятора:
```
gcc -c `mysql_config --cflags` progname.c
gcc -o progname progname.o `mysql_config --libs`
g++ test.cpp `mysql_config --cflags --libs` -o test
```
примеры запуска компилятора в .vscode/tasks.json и Makefile
