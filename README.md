# Linux-Shell

INTERNAL COMMANDS

history:
	
BUGS HANDLED
• Handled any number of arguments.
• Handled extra spaces at the start and in the middle of arguments.
• Maintained history even after session ends.
       
OPTIONS HANDLED
• Handled -w
• Handled -c

TEST CASES
anshks@ansh-msi:/home/anshks/Desktop$ echo ansh 
ansh 
anshks@ansh-msi:/home/anshks/Desktop$ cd ..
anshks@ansh-msi:/home/anshks$ history -w
anshks@ansh-msi:/home/anshks$ echo ansh cd .. history -w
anshks@ansh-msi:/home/anshks/Desktop$ echo -c
-c 
anshks@ansh-msi:/home/anshks/Desktop$ history -c
anshks@ansh-msi:/home/anshks/Desktop$ echo ansh cd .. history -w

echo:

BUGS HANDLED
• Handled any number of arguments.
• Handled quotation marks.
• Handled extra spaces at the start and in the middle of arguments.
       
OPTIONS HANDLED
• Handled -n
• Handled -E

TEST CASES
anshks@ansh-msi:/home/anshks/Desktop$ echo -n ansh is good
ansh is good anshks@ansh-msi:/home/anshks/Desktop$ echo -E fuesnknlfse
fuesnknlfse
      
cd:
	BUGS HANDLED
    • Handled too may arguments.
    • Handled too less arguments.
    • Handled invalid directory.
    • Handled extra spaces at the start and in the middle of arguments.
       
       OPTIONS HANDLED
    • Handled -L
    • Handled -P

	TEST CASES
anshks@ansh-msi:/home/anshks/Desktop$ cd ..
anshks@ansh-msi:/home/anshks$ cd andld
bash: cd: andld: No such file or directory

pwd:
	BUGS HANDLED
    • Works fine with garbage arguments like in actual shell.
    • Handled extra spaces at the start.
       
       OPTIONS HANDLED
    • Handled -L
    • Handled -P

	TEST CASES
anshks@ansh-msi:/home/anshks$ pwd
/home/anshks

exit:
	BUGS HANDLED
    • Handled extra spaces at the start.
    • Handled garbage arguments.
    • Handled numbers along with garbage arguments. 

	TEST CASES
anshks@ansh-msi:/home/anshks$ exit 0 fsc
exit
bash: exit: too many arguments
anshks@ansh-msi:/home/anshks$ exit
Bye
       
       OPTIONS HANDLED
    • No option to handle.

EXTERNAL COMMANDS

ls:
       Complete Functionality

	TEST CASES
anshks@ansh-msi:/home/anshks$ exit 0 fsc
exit
bash: exit: too many arguments
anshks@ansh-msi:/home/anshks$ exit
Bye
       
cat:
	Complete Functionality

	TEST CASES
anshks@ansh-msi:/home/anshks/Desktop/rmd$ ls -l
total 4
drwxr-xr-x 5 anshks anshks 4096 Jul 23 22:36 flairdetection
anshks@ansh-msi:/home/anshks/Desktop/rmd$ ls -a
.  ..  flairdetection
anshks@ansh-msi:/home/anshks/Desktop/rmd$ ls
flairdetection

date:
	Complete Functionality

	TEST CASES
anshks@ansh-msi:/home/anshks/Desktop/rmd$ date
Tue Sep  3 23:37:00 IST 2019

rm:
	Complete Functionality

	TEST CASES
anshks@ansh-msi:/home/anshks/Desktop$ rm -r a
anshks@ansh-msi:/home/anshks/Desktop$ rm -r b
anshks@ansh-msi:/home/anshks/Desktop$ rm -r c
anshks@ansh-msi:/home/anshks/Desktop$ rm -r d

mkdir:
	Complete Functionality

	TEST CASES
anshks@ansh-msi:/home/anshks/Desktop$ mkdir a b c d
anshks@ansh-msi:/home/anshks/Desktop$ mkdir d/e
