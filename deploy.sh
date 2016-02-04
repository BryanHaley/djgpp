#root check from 
#http://www.cyberciti.biz/tips/shell-root-user-check-script.html
FILE="/tmp/out.$$"
GREP="/bin/grep"
if [[ $EUID -ne 0 ]]; then
   echo "This script must be run as root" 1>&2
   exit 1
fi

echo REMOVING OLD IMAGE...
echo
rm ./program_floppy.img
echo

echo CREATING NEW IMAGE...
mkfs.msdos -C ./program_floppy.img 1440
rm -r /media/floppy_img/
mkdir /media/floppy_img/
mount -o loop ./program_floppy.img/ /media/floppy_img/
echo

echo COPYING FILES...
cp ./CWSDPMI.EXE /media/floppy_img/
cp ./program.exe /media/floppy_img/
echo

echo FINISHING UP...
umount /media/floppy_img/
