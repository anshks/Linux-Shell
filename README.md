# Linux-Shell

INTERNAL COMMANDS

history:<br />
	<br />
BUGS HANDLED<br />
• Handled any number of arguments.<br />
• Handled extra spaces at the start and in the middle of arguments.<br />
• Maintained history even after session ends.<br />
       <br />
OPTIONS HANDLED<br />
• Handled -w<br />
• Handled -c<br />
<br />
TEST CASES<br />
anshks@ansh-msi:/home/anshks/Desktop$ echo ansh <br />
ansh <br />
anshks@ansh-msi:/home/anshks/Desktop$ cd ..<br />
anshks@ansh-msi:/home/anshks$ history -w<br />
anshks@ansh-msi:/home/anshks$ echo ansh cd .. history -w<br />
anshks@ansh-msi:/home/anshks/Desktop$ echo -c<br />
-c <br />
anshks@ansh-msi:/home/anshks/Desktop$ history -c<br />
anshks@ansh-msi:/home/anshks/Desktop$ echo ansh cd .. history -w<br />
<br />
echo:<br />
<br />
BUGS HANDLED<br />
• Handled any number of arguments.<br />
• Handled quotation marks.<br />
• Handled extra spaces at the start and in the middle of arguments<br />
       <br />
OPTIONS HANDLED<br />
• Handled -n<br />
• Handled -E<br />
<br />
TEST CASES<br />
anshks@ansh-msi:/home/anshks/Desktop$ echo -n ansh is good<br />
ansh is good anshks@ansh-msi:/home/anshks/Desktop$ echo -E fuesnknlfse<br />
fuesnknlfse<br />
      <br />
      <br />
cd:<br />
BUGS HANDLED<br />
• Handled too may arguments.<br />
• Handled too less arguments.<br />
• Handled invalid directory.<br />
• Handled extra spaces at the start and in the middle of arguments.<br />
       <br />
OPTIONS HANDLED<br />
• Handled -L<br />
• Handled -P<br />

TEST CASES<br />
	anshks@ansh-msi:/home/anshks/Desktop$ cd ..<br />
	anshks@ansh-msi:/home/anshks$ cd andld<br />
	bash: cd: andld: No such file or directory<br />


pwd:<br />
BUGS HANDLED<br />
• Works fine with garbage arguments like in actual shell.<br />
• Handled extra spaces at the start.<br />
       <br />
OPTIONS HANDLED<br />
• Handled -L<br />
• Handled -P<br />
<br />
TEST CASES<br />
	anshks@ansh-msi:/home/anshks$ pwd<br />
	/home/anshks<br />
<br />
<br />
exit:<br />
BUGS HANDLED<br />
• Handled extra spaces at the start.<br />
• Handled garbage arguments.<br />
• Handled numbers along with garbage arguments. <br />
<br />
TEST CASES<br />
	anshks@ansh-msi:/home/anshks$ exit 0 fsc<br />
	exit<br />
	bash: exit: too many arguments<br />
	anshks@ansh-msi:/home/anshks$ exit<br />
	Bye<br />
       <br />
OPTIONS HANDLED<br />
• No option to handle.<br />
<br />
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
