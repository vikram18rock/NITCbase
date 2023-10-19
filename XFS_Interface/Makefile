default: xfs-interface

xfs-interface: *.cpp *.h define/*
	g++ *.cpp -o xfs-interface -Wno-write-strings -Wno-return-type -lreadline

debug: *.cpp *.h define/*
	g++ *.cpp -o xfs-interface-debug -Wno-write-strings -Wno-return-type -lreadline -g

clean:
	$(RM) xfs-interface *.o