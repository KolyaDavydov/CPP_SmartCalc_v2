CC=g++ #gcc -O0 -g
CFLAGS=-std=c++17 -Wall -Werror -Wextra
PROFILE_FLAGS = -fprofile-arcs -ftest-coverage
LIBSOURCES=controller/controller.cc model/model.cc model/credit_model.cc
LIBOBJECTS=$(LIBSOURCES:.cc=.o)

TETEX=texi2dvi

OS = $(shell uname)

ifeq ($(OS), Linux)
	CHECKFLAGS=-lgtest -lm -lpthread -lrt -lsubunit
else
	CHECKFLAGS=-lgtest -lm -lpthread
endif

all: tests

controller.a: $(LIBOBJECTS)
	ar -crs controller.a $(LIBOBJECTS)
	rm -f *.o

tests: clean test/test.cc controller.a
	$(CC) $(CFLAGS) test/test.cc $(LIBSOURCES) -o run $(CHECKFLAGS) -lgcov --coverage
	./run

gcov_report: tests
	lcov -t "test" -o report.info --no-external -c -d .
	genhtml -o report report.info
	open ./report/index.html

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
	tar -cf ../SmartCalcV1.tar ../build

leaks: test
	valgrind --leak-check=full --quiet ./run

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
					SmartCalcV1 \
					.qmake.stash \
					gcov \
					report/ \
					../app/ \
					report.info \
					controller/*.o \
					model/*.o

