# Snake CLI
The classic Snake game from Nokia for Windows command line (either PowerShell or CMD). This project is the final assignment of my university class _Algorithms & Programming_.

## How to Build & Test
### Prerequisites:
- [Microsoft Windows 10](https://www.microsoft.com/windows)
- [Visual Studio Code](https://code.visualstudio.com)
- [MinGW-w64](https://sourceforge.net/projects/mingw-w64)
- [PowerShell 7](https://github.com/PowerShell/powershell/releases)

Add `{mingw-w64 directory}\bin` and `{powershell directory}\{version}` to your system's _path_ environment variable.

### On Visual Studio Code:
This project has custom-built tasks for Visual Studio Code. To run tasks either

1. Go to `Terminal\Run Task...`, or
2. Press `Ctrl + P` and enter `task [task-name]`.

<br>

| Task          | Description                              |
|--------------:|------------------------------------------|
| _build_       | Build application executable             |
| _rebuild_     | Clean and rebuild application executable |
| _test_        | Build unit test executables              |
| _clean_       | Clean build directories                  |

### On other editors:

To build the application, run
```powershell
mingw32-make
```

To build the unit tests, run
```powershell
mingw32-make check
```

## University Info

| University                   | Location                | Course           | Class                    |
|------------------------------|-------------------------|------------------|--------------------------|
| [UFRGS](http://www.ufrgs.br) | Porto Alegre RS, Brazil | Computer Science | Algorithms & Programming |
