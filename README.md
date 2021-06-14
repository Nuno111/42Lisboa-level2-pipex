# Pipex

The goal of this project is to simulate in a basic way how shell piping and redirection works.

The main things to understand here is to understand what the following functions do, and how they work together to create a redirection system.

* dup2
* wait
* waitpid
* pipe
* execve

All code is written in accordance to the norminette version running at the time of project completion.

## How to use
In order to run this project you will need to compile it using the make command and pass the parameters to the executable as shown in the example below.

```
make
```

Example of usage:

```
$> ./pipex infile ``ls -l'' ``wc -l'' outfile
```

Should give the same output as running the below command on your terminal

```
$> < infile ls -l | wc -l > outfile
```

## Things to consider when doing this project

```
< file | cmd1
```

The above means that the file is open for reading on stdin, which is then piped to cmd1

What you shouldn't do and its wrong, is passing file as an argument to cmd1.

If you do that, then your grep command will work but ls won't.

Ls doesn't take files as input but grep does.

## Usefull resources

[How fork works](https://stackoverflow.com/questions/15102328/how-does-fork-work)

[How dup2 works](https://www.youtube.com/watch?v=PIb2aShU_H4&ab_channel=KrisJordan)

## Contact

For any questions regarding my project email me at: Nuno_c11@hotmail.com

Or if you are a 42student my slack username is: ngregori
