To clone this repository, run these commands in the terminal:

>mkdir djgpp

>cd djgpp

>git clone https://github.com/BryanHaley/djgpp.git

Once cloning is finished, put your code in the djgpp/src directory. You will need DosBox installed. If you're on Ubuntu, simply run the command:

>sudo apt-get install dosbox

To compile and run your code, open a terminal and navigate to the djgpp directory, then run compile.sh:

>cd djgpp

>bash ./compile.sh

Once finished, close the dosbox window (type "exit" in dosbox or just close the window).

When your code is ready, upload it back to this repository. To do this, run these commands in a terminal:

>cd djgpp

>git add -A

>git push -u origin testing

To automatically generate a floppy image for use with a virtual machine, run:

>cd djgpp

>sudo bash ./deploy.sh
