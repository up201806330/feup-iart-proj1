# IART project 1

Based on game [*Ball Sort Puzzle*](https://play.google.com/store/apps/details?id=com.spicags.ballsort&hl=pt_PT&gl=US) by [Spica Game Studio](https://play.google.com/store/apps/developer?id=Spica+Game+Studio).

## Get this project

### Setup

On Microsoft Windows, (as always) things don't just work out-of-the-box.

This project uses ASCII color codes, which are not enabled on some versions of Windows by default.

#### cmd/PowerShell

If colors don't properly render, try running the following command in cmd as administrator so that cmd can correctly interpret ASCII colors ([source](https://www.codeproject.com/Tips/5255355/How-to-Put-Color-on-Windows-Console)):
```cmd
reg add HKEY_CURRENT_USER\Console /v VirtualTerminalLevel /t REG_DWORD /d 0x00000001 /f
```
and open a new cmd (not required to be administrator) to run with correct color rendering. Worked for me on Windows 10.

#### Visual Studio Code integrated terminal (cmd/PowerShell)

Add the following line to `.vscode/settings.json`:
```json
"terminal.integrated.windowsEnableConpty": false
```
and open a new integrated terminal to run with correct color rendering and avoid garbage being printed.

### Compile
