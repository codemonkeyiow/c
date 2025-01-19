```
gcc -c hmm.c
as hmm.S
ld -o hmm hmm.o a.out --entry main -z noexecstack
```

```
zig cc -Os -target x86_64-linux-musl -static sys.S shell.c
```

