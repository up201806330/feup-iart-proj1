<!--
Copyright (C) 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira
Distributed under the terms of the GNU General Public License, version 3
-->

# IART project 1

[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)
[![License: CC BY-NC-ND 4.0](https://img.shields.io/badge/License-CC%20BY--NC--ND%204.0-lightgrey.svg)](https://creativecommons.org/licenses/by-nc-nd/4.0/)

[![build](https://github.com/dmfrodrigues/feup-iart-proj1/actions/workflows/build.yml/badge.svg)](https://github.com/dmfrodrigues/feup-iart-proj1/actions/workflows/build.yml)
[![report1](https://github.com/dmfrodrigues/feup-iart-proj1/actions/workflows/report1.yml/badge.svg)](https://github.com/dmfrodrigues/feup-iart-proj1/actions/workflows/report1.yml)

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


# License

© 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira

All files are licensed under [GNU General Public License v3](https://github.com/dmfrodrigues/feup-iart-proj1/blob/master/LICENSE) by **© 2021 Diogo Rodrigues, Rafael Ribeiro, Bernardo Ferreira**, to the exception of:
- all files inside directory `doc/report` and all artifacts deriving from them, which are licensed under the [Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International](doc/report/LICENSE) public license.

<!-- The files not authored by us are presented as a fundamental complement to the presented solutions, and are made available under *fair use for education*. -->
