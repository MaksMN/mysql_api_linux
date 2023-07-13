SRC = *.cpp
TARGET = mysql_api_linux
PREFIX = /usr/local/bin
MYSQL = `mysql_config --cflags --libs`

mysql_api_linux:
	mkdir -p bin
	g++ -std=c++20 $(SRC) $(MYSQL) -o bin/$(TARGET)

install:
	install bin/$(TARGET) $(PREFIX)	
	
uninstall:
	rm -rf $(PREFIX)/$(TARGET)
