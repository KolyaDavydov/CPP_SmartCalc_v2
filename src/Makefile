CC=g++
CFLAGS=-std=c++17 -Wall -Werror -Wextra
PROFILE_FLAGS = -fprofile-arcs -ftest-coverage
LIBSOURCES=controller/controller.cc model/model.cc model/credit_model.cc
LIBOBJECTS=$(LIBSOURCES:.cc=.o)
VALGRIND_FLAGS = --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all --verbose

OS = $(shell uname)

ifeq ($(OS), Linux)
	CHECKFLAGS=-lgtest -lm -lpthread -lrt
else
	CHECKFLAGS=-lgtest -lm -lpthread
endif

all: install

controller.a: $(LIBOBJECTS)
	ar -crs controller.a $(LIBOBJECTS)
	rm -f *.o

tests: clean test/test.cc controller.a
	$(CC) $(CFLAGS) test/test.cc $(LIBSOURCES) -o run $(CHECKFLAGS) -lgcov --coverage
	./run

gcov_report: tests
	lcov -t "test" -o report.info --no-external -c -d .
	genhtml -o report report.info
ifeq ($(OS), Linux)
	xdg-open ./report/index.html
else
	open ./report/index.html
endif

install: clean
	mkdir ../build
	cmake -S . -B ../build/
	make -C ../build

open:
	./../build/Calc

uninstall: clean
	rm -rf ../build
	rm -rf build

cppcheck:
	cp ../materials/linters/.clang-format .clang-format
	clang-format -n controller/*.cc controller/*.h \
					model/*.cc model/*.h \
					view/*.cpp view/*.h \
					test/test.cc
	rm .clang-format

dvi:
	open info/info.html

dist: install
	tar -cf ../SmartCalcV2.tar ../build

leaks: tests
	CK_FORK=no valgrind $(VALGRIND_FLAGS) --log-file=RESULT_VALGRIND.txt ./run

clean:
	rm -rf *.o \
					*.a \
					*.aux \
					*.dvi \
					*.fdb_latexmk \
					*.fls \
					*.log \
					*.pdf \
					*.gz \
					*.so \
					*.gcno \
					*gcda \
					*.gcov \
					gcov_report.* \
					*.dSYM \
					*.out \
					unit-test \
					vtests_run \
					*.dvi \
					run \
					SmartCalcV2 \
					.qmake.stash \
					gcov \
					report/ \
					../app/ \
					report.info \
					controller/*.o \
					model/*.o \
					RESULT_VALGRIND.txt

