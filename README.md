![c2b](icon.png)

**c2b** is an easy to use shell application for quick and easy number base converter

## How to build ?
To build `c2b` it's easy. There is 2 way of doing it.
### Using the build script
```shell
./build.sh
```
It will juste generate the `c2b` executable.
### Using Make
```shell
make install
```
It will install `c2b` in your `/usr/local/bin` folder.

## How to use ?
To use `c2b` it's easy !
```shell
c2b [OPTIONS] NUMBER
```

### Options
There is several options you can have access :
- `-h`, `--help` : Print the help message
- `-b BASE` : Specify the base of the output number (default : 2)
- `-B, --input-base BASE` : Specify the base of the input number (default : 10)

## Example
```shell
c2b 13
1101
```

```shell
c2b -b 16 "154"
9A
```

```shell
c2b -b 10 -B 16 "9A"
154
```
Note that the quotes are not necessary.

### What I want to work on ?
- Being able to convert bigger numbers than `long long int` 

## Foot note
I love working on this project. If you have any suggestion about new fonctionnalities dont hesitate !