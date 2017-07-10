#Simple_shell#


##Description##

>This project implements some functionalities of a C shell (simple UIX command interpreter).
The program can run in interactive and non-interactive mode.

>The shell uses only the following commands.

>- access (man 2 access)
- chdir (man 2 chdir)
- close (man 2 close)
- closedir (man 3 closedir)
- execve (man 2 execve)
- exit (man 3 exit)
- fork (man 2 fork)
- free (man 3 free)
- fstat (man 2 fstat)
- getcwd (man 3 getcwd)
- getline (man 3 getline)
- kill (man 2 kill)
- lstat (man 2 lstat)
- malloc (man 3 malloc)
- open (man 2 open)
- opendir (man 3 opendir)
- perror (man 3 perror)
- read (man 2 read)
- readdir (man 3 readdir)
- signal (man 2 signal)
- stat (man 2 stat)
- strtok (man 3 strtok)
- wait (man 2 wait)
- waitpid (man 2 waitpid)
- wait3 (man 2 wait3)
- wait4 (man 2 wait4)
- write (man 2 write)
- _exit (man 2 _exit)

>The README file, man man_1_simple_shell, and the AUTHORS page are also available.


##Table of Contents##

1. Betty styling

2. Simple shell 0.1
   simple_shell
Display a prompt and wait for the user to type a command. A command line always ends with a new line.
The prompt is displayed again each time a command has been executed.
The command lines are simple, no semi-columns, no pipes, no redirections or any other advanced features.
The command lines are made only of one word. No arguments will be passed to programs.
If an executable cannot be found, print an error message and display the prompt again.
Handle errors.
You have to handle the "end of file" condition (Ctrl+D). Exit with code 0.

3. Simple shell 0.1.1 - Alternative getline function
Write your own getline function
Use a buffer to read many chars at once and call the least possible the read system call
It uses static variables

4. Simple shell 0.2 - Handle command lines with arguments

5. Simple shell 0.2.1 - Implement strtok()

6. Simple shell 0.3 - Handle the PATH environment variable

7. Simple shell 0.4 - exit()
Implement the exit buit-in, that exits the shell
Usage: exit
You don't have to handle any argument to the built-in exit

8. Simple shell 0.4.1 - exit
Handle arguments for the built-in exit
       exit status
where status is an integer used to exit the shell

9. Simple shell 0.4.2 - Handle Ctrl+c
   Ctrl+C
Your shell should not quit when the user inputs ^C.

10. Simple shell 1.0 - Implement the env built-in, that prints the current environment.
    env

11. setenv, unsetenv - Implement the setenv and unsetenv built-in commands:

        setenv VARIABLE_VALUE

where VARIABLE_VALUE is a new environment variable or modify an existing one.

        unsetenv VARIABLE

where VARIABLE is an environment variable.

12. cd
Implement the builtin command cd:

>Changes the current directory of the process.
Command syntax: cd [DIRECTORY]
If no argument is given to cd the command must be interpreted like cd $HOME
You have to handle the command cd -
You have to update the environment variable PWD when you change directory

        cd PATHNAME

13. separator" - handle the commands separator

        COMMAND ; COMMAND

where COMMAND is a bash or Linux command

14. && and || - handle && and || shell logical operators

        COMMAND && COMMAND

        COMMAND || COMMAND

15. alias - handle aliases

16. Variables
Handle variables replacement
Handle the $? variable
Handle the $$ variable

17. Comments - handle comments on the command line

         COMMAND # ignore this

18. help
    Implement the help buit-in

        help [BUILTIN]

19. history
Implement the history built-in, without any argument
The history built-in displays the history list, one command by line, preceded with line numbers (starting at 0)
On exit, write the entire history, without line numbers, to a file named .simple_shell_history in the directory $HOME
When the shell starts, read the file .simple_shell_history in the directory $HOME if it exists, and set the first line number to the total number of lines in the file modulo 4096

        history

20. File as input
Your shell can take a file as a command line argument
The file contains all the commands that your shell should run before exiting
The file should contain one command per line
In this mode, the shell should not print a prompt and should not read from stdin

        simple_shell [filename]

##Blog##
What happens when you type ls -l in the shell
        [Link to Blogs]

##Test suite##

>The test suite should cover every task from above, and contributors are listed in the AUTHORS file

>Also see https://github.com/srinitude/shellgame

##Installation##
>Git clone the repository at https://github.com/xxxxxx.git

##Usage##
>Files were compiled on Ubuntu 14.04 LTS, using gcc 4.8.4. This code was compiled in a shell script with the following flags:

        gcc -Wall -Werror -Wextra -pedantic *. -o hsh

The files follow the Betty style coding convention.

##Contributors##

Authors are listed in the "AUTHORS" file. Please contact the authors for getting collaboration access to the GIthub repository.

##Credits##

Felicia Hsieh and Kiren Srinivasan. The project is titled, "0x15. C - Simple Shell" and was created between July 6, 2017 to July 14, 2017. You may contact felicia@tixwriteoff.com and srinitude@gmail.com.

##License##
GNU public license

--------

  [contributor]: http://x.net/
  [1]: http://markdowntutoriallink
  [source code]: githublink
