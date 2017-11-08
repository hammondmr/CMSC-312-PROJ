# src and obj are folder destinations for these files, to keep them organized
#
src = src
obj = object_files
std = -std=c++11

awesome_os.exe: $(obj)/main.o $(obj)/basic_shell.o $(obj)/kernel.o $(obj)/ps_controlblock.o
	g++ $(std) -Wall $(obj)/main.o $(obj)/basic_shell.o $(obj)/kernel.o $(obj)/ps_controlblock.o -o awesome_os.exe

$(obj)/main.o: $(src)/main.cpp
	g++ $(std) -Wall -c $(src)/main.cpp -o $(obj)/main.o

$(obj)/basic_shell.o: $(src)/basic_shell.cpp $(src)/basic_shell.h
	g++ $(std) -Wall -c $(src)/basic_shell.cpp -o $(obj)/basic_shell.o

$(obj)/kernel.o: $(src)/kernel.cpp $(src)/kernel.h
	g++ $(std) -Wall -c $(src)/kernel.cpp -o $(obj)/kernel.o

$(obj)/ps_controlblock.o: $(src)/ps_controlblock.cpp $(src)/ps_controlblock.h
	g++ $(std) -Wall -c $(src)/ps_controlblock.cpp -o $(obj)/ps_controlblock.o


clean:
	\rm *.o awesome_os.exe


