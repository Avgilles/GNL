*This project has been created as part of the 42 curriculum by gavraam*

## Description

[Subject Link](https://cdn.intra.42.fr/pdf/pdf/188916/en.subject.pdf)

**Get Next Line** is a function that reads and returns a line from a file descriptor. This project helps understand the concepts of:
- Static variables
- Dynamic memory management
- Buffer manipulation
- Reading by chunks with `read()`

The function returns a line ending with `\n` (if present) at each call, until the end of file.

## Instructions

How to compile :

1. Uncomment the `main` function in `get_next_line.c`

2. Launch this command in a terminal in the current directory. 
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o a.out
```

Debugging (Optinal) 
```bash
cc -g -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o a.out
```

Bonus :
```bash
cc -g -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c -o a.out
```
3. Create a texte file, named test.txt and put random texte inside. Here is an example :
```txt
Welcome to the file!
This is the first line.
This is the second line.
This is the third line.
```

A more complexe example, to copy and paste in the file :
[Bible pdf](https://archives.ecole-alsacienne.org/CDI/pdf/1400/14003_ANON.pdf)

## Resources

[Static variables](https://openclassrooms.com/forum/sujet/comment-ca-fonctionne-12569)

[Test main](https://github.com/xicodomingues/francinette)

[Awesome 42 ressource](https://medium.com/@lannur-s/gnl-c3cff1ee552b)
