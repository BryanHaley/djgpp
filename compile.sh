./bin/i586-pc-msdosdjgpp-g++ -o program.exe -L./lib -I./include ./src/*.cpp -lpdcurses
dosbox -c "MOUNT c $PWD" -c "C:" -c "CWSDPMI.EXE" -c "PROGRAM.EXE"
