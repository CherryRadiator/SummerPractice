# Makefile для сборки программы сортировки

CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -O2
TARGET = sorting_program
SOURCES = main.cpp menu.cpp file_io.cpp sorting.cpp
OBJECTS = $(SOURCES:.cpp=.o)
HEADERS = menu.h file_io.h sorting.h

# Основная цель
all: $(TARGET)

# Сборка исполняемого файла
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)
	@echo "Программа успешно собрана: $(TARGET)"

# Компиляция объектных файлов
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Очистка
clean:
	rm -f $(OBJECTS) $(TARGET)
	@echo "Очистка завершена"

# Запуск программы
run: $(TARGET)
	./$(TARGET)

# Создание тестового файла с числами
test_file:
	echo "64 34 25 12 22 11 90 5 77 30 44 55 66 33 99 88 2 8 1" > input.txt
	@echo "Создан тестовый файл input.txt"

# Помощь
help:
	@echo "Доступные команды:"
	@echo "  make        - собрать программу"
	@echo "  make run    - собрать и запустить программу"
	@echo "  make clean  - удалить объектные файлы и исполняемый файл"
	@echo "  make test_file - создать тестовый файл с числами"
	@echo "  make help   - показать эту справку"

.PHONY: all clean run test_file help