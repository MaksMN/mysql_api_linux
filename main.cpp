#include <iostream>
#include </usr/include/mysql/mysql.h>
int main(int argc, const char *argv[])
{
	MYSQL mysql;
	MYSQL_RES *res;
	MYSQL_ROW row;

	int i = 0;

	// Получаем дескриптор соединения
	mysql_init(&mysql);
	if (&mysql == nullptr)
	{
		// Если дескриптор не получен — выводим сообщение об ошибке
		std::cout << "Error: can't create MySQL-descriptor" << std::endl;
	}

	// Подключаемся к серверу
	if (!mysql_real_connect(&mysql, "localhost", "dbuser", "dbpass", "dbname", 3306, NULL, 0))
	{
		// Если нет возможности установить соединение с БД выводим сообщение об ошибке
		std::cout << "Error: can't connect to database " << mysql_error(&mysql) << std::endl;
	}
	else
	{
		// Если соединение успешно установлено выводим фразу — "Success!"
		std::cout << "Success!" << std::endl;
	}

	mysql_set_character_set(&mysql, "utf8mb4");
	// Смотрим изменилась ли кодировка на нужную, по умолчанию идёт latin1
	std::cout << "connection characterset: " << mysql_character_set_name(&mysql) << std::endl;

	mysql_query(&mysql, "SELECT * FROM test"); // Делаем запрос к таблице

	// Выводим все что есть в базе через цикл
	if (res = mysql_store_result(&mysql))
	{
		while (row = mysql_fetch_row(res))
		{
			for (i = 0; i < mysql_num_fields(res); i++)
			{
				std::cout << row[i] << "  ";
			}
			std::cout << std::endl;
		}
	}
	else
		std::cout << "Ошибка MySql номер " << mysql_error(&mysql);

	// Закрываем соединение с сервером базы данных
	mysql_close(&mysql);
}
