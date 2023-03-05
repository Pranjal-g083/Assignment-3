## To make lex file
```C
flex flex_spec.l
```

## For generating a.out
```C
cc lex.yy.c main.c -lfl
```

## To generate output
```C
./a.out < test.nc > output.txt
```