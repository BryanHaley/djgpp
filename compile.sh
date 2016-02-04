echo COMPILING...
echo
./bin/i586-pc-msdosdjgpp-g++ -o program.exe -L./lib -I./include ./src/*.cpp -lpdcurses
echo
echo

echo RUNNING...
echo
dosbox -c "MOUNT c $PWD" -c "C:" -c "CWSDPMI.EXE" -c "PROGRAM.EXE"
