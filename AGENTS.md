# AI Agent Instructions for hoc_dsa_cung_bi_beo

## Repository purpose
- This is a personal C++ learning repository for Data Structures and Algorithms (DSA).
- The code is organized as standalone example programs, lecture exercises, and LeetCode solutions.
- Treat it as a study notebook, not a production application.

## Key directories
- `Cau_truc_du_lieu/` — data structure examples by chapter (linked lists, stacks/queues, hash tables, trees, graphs).
- `Giai_thuat/` — algorithm implementations organized by topic (search, sort, etc.).
- `LeetCode_Solutions/` — individual algorithmic problem solutions.

## Build and run
- There is no centralized build system or test suite.
- Use the VS Code task `C/C++: g++.exe build active file` from `.vscode/tasks.json`.
- Equivalent command for a source file is:
  - `C:\msys64\ucrt64\bin\g++.exe -fdiagnostics-color=always -g <file> -o <fileDirname>\<fileBasenameNoExtension>.exe`

## Agent guidance
- Prefer minimal, example-level changes. Most files are isolated demos.
- Avoid broad project-wide refactors unless the user explicitly requests them.
- Keep filenames and folder placement consistent with the existing Vietnamese naming and chapter-based structure.
- Preserve the pedagogical nature of the repository: clear examples, simple logic, and working compilation are more important than advanced C++ idioms.

## When modifying code
- If adding new examples, place them in the appropriate chapter folder with a descriptive filename.
- If improving existing code, ensure the file still compiles with the current `g++` command.
- Avoid introducing external dependencies or libraries.

## Documentation
- The root `README.md` contains the project overview and directory structure.
- Use it as the primary source of repo purpose and organization.
