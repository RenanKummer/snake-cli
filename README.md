# Description
The classic Snake game from Nokia for Windows command line (either PowerShell or CMD). This project is the final assignment of my university class _Algorithms & Programming_.

# How to Build & Test
### **Prerequisites:**
- [Microsoft Windows 10](https://www.microsoft.com/windows)
- [Visual Studio Code](https://code.visualstudio.com)
- [MinGW-w64](https://sourceforge.net/projects/mingw-w64)
  - Add `{mingw-w64 directory}\bin` to your system's _path_ environment variable.
- [PowerShell 7](https://github.com/PowerShell/powershell/releases)
  - Add `{powershell directory}\{version}` to your system's _path_ environment variable.

### **On Visual Studio Code:**
This project has custom-built tasks for Visual Studio Code. To run tasks either

1. Go to `Terminal\Run Task...`, or
2. Press `Ctrl + P` and enter `task [task-name]`.

<br>

| Task      | Description                              |
|----------:|------------------------------------------|
| _build_   | Build application executable             |
| _rebuild_ | Clean and rebuild application executable |
| _test_    | Run unit tests                           |
| _clean_   | Clean build directories                  |

### **On other editors:**

To build the application, run
```powershell
mingw32-make
```

To unit test the application, run
```powershell
mingw32-make check
```

# Continuous Integration
This project performs [Continuous Integration using GitHub Actions](https://github.com/RenanKummer/snake-cli/actions?query=workflow%3A%22Continuous+Integration%22) on push and pull request events to `master` branch.

# University Info
<dl>
  <dt><strong>What is the name of your university?</strong></dt>
  <dd>Universidade Federal do Rio Grande do Sul (aka UFRGS). <a href="http://www.ufrgs.br">Here is the official website</a>.</dd>
  <dt><strong>Where is your university located?</strong></dt>
  <dd>Porto Alegre RS, Brazil.</dd>
  <dt><strong>What course do you study?</strong></dt>
  <dd>Bachelor in Computer Science.</dd>
  <dt><strong>Which class is this project for?</strong></dt>
  <dd>Algorithms & Programming - in this class we learn the basics of programming using C.</dd>
</dl>
