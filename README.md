Project name: simple_shell

Description: This project replicates some of the functionalities of a C shell (simple UIX command interpreter). The program will run in interactive and non-interactive mode.
We will use only the following commands.

access (man 2 access)
chdir (man 2 chdir)
close (man 2 close)
closedir (man 3 closedir)
execve (man 2 execve)
exit (man 3 exit)
fork (man 2 fork)
free (man 3 free)
fstat (man 2 fstat)
getcwd (man 3 getcwd)
getline (man 3 getline)
kill (man 2 kill)
lstat (man 2 lstat)
malloc (man 3 malloc)
open (man 2 open)
opendir (man 3 opendir)
perror (man 3 perror)
read (man 2 read)
readdir (man 3 readdir)
signal (man 2 signal)
stat (man 2 stat)
strtok (man 3 strtok)
wait (man 2 wait)
waitpid (man 2 waitpid)
wait3 (man 2 wait3)
wait4 (man 2 wait4)
write (man 2 write)
_exit (man 2 _exit)

Table of Contents:
0. Introduction - Read the README file, man man_1_simple_shell, and the AUTHORS page.
1. Betty
2. Simple shell 0.1
3. Simple shell 0.1.1
4. Simple shell 0.2
5. Simple shell 0.2.1
6. Simple shell 0.3
7. Simple shell 0.4
8. Simple shell 0.4.1
9. Simple shell 0.4.2 
10. Simple shell 1.0
11. setenv, unsetenv
12. cd
13. ;
14. && and ||
15. alias
16. Variables
17. Comments
18. help
19. history
20. File as input
21. ls -l
22. Test suite (See https://github.com/srinitude/shellgame)

Installation: Git clone the repository at https://github.com/xxxxxx.git

Usage: Files were compiled on Ubuntu 14.04 LTS, using gcc 4.8.4. This code was compiled in a shell script with the following flags:

     gcc -Wall -Werror -Wextra -pedantic *.c -o hsh

Contributing: Please contact the authors for getting collaboration access to the GIthub repository.

Credits: Felicia Hsieh and Kiren Srinivasan. The project is titled, "0x15. C - Simple Shell" and was created between July 6, 2017 to \
July 14, 2017. You may contact felicia@tixwriteoff.com and srinitude@gmail.com.

License: GNU public license