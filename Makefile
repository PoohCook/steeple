CC = g++
CPPFLAGS = -g -Wall -std=c++11 -pthread -iquote inc -I boostlib/inc
LFLAGS = -Wall -DBOOST_ALL_NO_LIB -DBOOST_ALL_DYN_LINK -DBOOST_LOG_DYN_LINK
BOOST = -Lboostlib/lib -lboost_unit_test_framework -lboost_system -lboost_serialization -lboost_wserialization \
        -lboost_program_options -lboost_filesystem -Wl,-rpath,'boostlib/lib'

DEPS = inc/People.h inc/PeopleList.h inc/Logger.h
OBJ = obj/People.o obj/PeopleList.o
TEST = obj/TestPeople.o obj/TestPeopleList.o
MUTED = -DDIAG_MESSAGES

obj/%.o: src/%.cpp $(DEPS)
	mkdir -p obj
	$(CC) -c -o $@ $< $(CPPFLAGS)

obj/%.o: test/%.cpp $(DEPS)
	mkdir -p obj
	$(CC) -c -o $@ $< $(CPPFLAGS)

main: $(OBJ) src/main.cpp
	$(CC) -o $@  $^ $(CPPFLAGS) $(LFLAGS)

test: testRunner
	./testRunner

testRunner: $(OBJ) $(TEST) test/TestMain.cpp
	$(CC) -o $@  $^ $(CPPFLAGS) $(BOOST) $(LFLAGS)


clean:
	rm -f *.o *.so *.a main testRunner
	rm -rf obj
	rm -f testRunner
	rm -f main
	rm -f eeyore
