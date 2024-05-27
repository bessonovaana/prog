cmake_minimum_required(VERSION 3.10)	 # Проверка версии CMake.
										# Если версия установленой программы
										# старее указаной, произойдёт аварийный выход.

project(main)			# Название проекта

set(SOURCE_EXE la13.c)		# Установка переменной со списком исходников для исполняемого файла, чтобы разыменовать и
                            # вытащить значение переменной используется ${имя_переменной}
set(SOURCE_LIB Viviod.c Fill.c Fill_r.c Simple.c puzir.c Shake.c Bin1.c Bin2.c Hell.c)			# Тоже самое, но для библиотеки

add_library(MY_LIB STATIC ${SOURCE_LIB})	# Создание статической библиотеки с именем MY_LIB

add_executable(main ${SOURCE_EXE})	# Создает исполняемый файл с именем main

target_link_libraries(main MY_LIB)		# Линковка программы с библиотекой