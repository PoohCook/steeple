CC = g++
CPPFLAGS = -g -Wall -std=c++11 -pthread -iquote inc 
LFLAGS = -Wall 

DEPS = inc/People.h inc/PeopleList.h inc/Logger.h
OBJ = obj/People.o obj/PeopleList.o
# TEST = obj/TestWorker.o 
MUTED = -DDIAG_MESSAGES

obj/%.o: src/%.cpp $(DEPS)
	mkdir -p obj
	$(CC) -c -o $@ $< $(CPPFLAGS)

obj/%.o: test/%.cpp $(DEPS)
	mkdir -p obj
	$(CC) -c -o $@ $< $(CPPFLAGS)

main: $(OBJ) src/main.cpp
	$(CC) -o $@  $^ $(CPPFLAGS) $(LFLAGS)

test: eeyore testRunner
	./testRunner

testRunner: $(OBJ) $(TEST) test/TestMain.cpp
	$(CC) -o $@  $^ $(CPPFLAGS) $(LFLAGS)

eeyore: $(DEPS) test/EeyoreClient.cpp
	$(CC) -o $@  test/EeyoreClient.cpp  $(BOOST)  $(CPPFLAGS) $(LFLAGS)

clean:
	rm -f *.o *.so *.a main testRunner
	rm -rf obj
	rm -f testRunner
	rm -f main
	rm -f eeyore
