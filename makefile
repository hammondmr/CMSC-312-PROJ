# src and obj are folder destinations for these files, to keep them organized
#
src = src
obj = object_files
std = -std=c++11

awesome_os.exe: $(obj)/main.o $(obj)/basic_shell.o
	g++ $(std) -Wall $(obj)/main.o $(obj)/basic_shell.o -o awesome_os.exe

$(obj)/main.o: $(src)/main.cpp
	g++ $(std) -Wall -c $(src)/main.cpp -o $(obj)/main.o

$(obj)/basic_shell.o: $(src)/basic_shell.cpp $(src)/basic_shell.h
	g++ $(std) -Wall -c $(src)/basic_shell.cpp -o $(obj)/basic_shell.o

clean:
	\rm *.o awesome_os.exe


