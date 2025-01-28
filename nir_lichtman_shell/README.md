https://www.youtube.com/watch?v=u2Juz5sQyYQ


```
./build.sh
```


```
gcc -c -fno-stack-protector hmm.c
as hmm.S
ld -o hmm hmm.o a.out --entry main -z noexecstack
```

```
zig cc -Os -target x86_64-linux-musl -static sys.S shell.c
```

