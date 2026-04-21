# CalculatorQt

CalculatorQt is a desktop calculator app built with Qt Widgets and C++17.
It uses the `MathEngine` library to parse and evaluate expressions such as:

- `2+2*2`
- `sqrt(16)+sin(0)`
- `2^3^2`
- `2(3+4)` (implicit multiplication)

The project builds:

- `CalculatorQt` (Qt GUI executable)
- `MathCore` (static library from `libs/MathEngine`)

Note: `MathEngine` tests are not built from the top-level project by default.

---

## Features

- Calculator UI based on Qt Widgets (`QMainWindow` + `.ui` form)
- Supports basic operators: `+`, `-`, `*`, `/`, `^`
- Built-in functions: `sqrt`, `sin`, `cos`, `tan`
- Parentheses and decimal numbers
- Cursor navigation, backspace, clear, and Enter-to-calculate
- Safe evaluation with structured error messages (`calculateSafe`)

---

## Requirements

- CMake `>= 3.19`
- Qt `>= 6.5` with components:
  - `Core`
  - `Widgets`
- A C++17 compiler:
  - Windows: MSVC (Visual Studio 2022 recommended)
  - Linux/macOS: GCC or Clang

---

## Build

### Configure

```bash
cmake -S . -B build
```

### Compile

Windows:

```powershell
cmake --build build --config Debug
```

Linux/macOS:

```bash
cmake --build build
```

Note: the command above is for single-config generators (typical on Linux/macOS). On Windows with Visual Studio, use `--config Debug` or `--config Release`.

Alternative (if you are already in the `build` directory):

```bash
cmake ..
cmake --build .
```

---

## Run

### Run application

Windows (Visual Studio generator):

```powershell
.\build\Debug\CalculatorQt.exe
```

Linux/macOS:

```bash
./build/CalculatorQt
```

---

## Deployment (optional)

### Windows deployment (optional)

`windeployqt` is **not required** to configure or build the project.

If you want to run the app outside your build machine (for example by copying the `.exe` to another folder), deploy Qt runtime files with `windeployqt`.

Recommended workflow before sending the app to someone:

1. Create a new empty folder for distribution (for example `Calculator`).
2. Copy `CalculatorQt.exe` from your build output (for example `build/Debug`) into that folder.
3. Run `windeployqt.exe` and point it to the copied executable.

Example command:

```powershell
C:\Qt\6.11.0\msvc2022_64\bin\windeployqt.exe C:\Users\YourUser\Desktop\Calculator\CalculatorQt.exe
```

`windeployqt` will add required Qt runtime files (DLLs, platform plugins, image format plugins, and related folders) next to the executable.

Note: this project already contains Qt CMake deploy/install integration (`qt_generate_deploy_app_script`), so manual `windeployqt` is mainly useful for quick local packaging.

### Linux/macOS deployment

macOS:

- Use `macdeployqt` for app bundle deployment.
- Example:

```bash
/path/to/Qt/6.11.0/macos/bin/macdeployqt ./build/CalculatorQt.app
```

Linux:

- Qt does not provide a direct equivalent of `windeployqt` for all Linux distributions.
- Common options are:
  - package your app with your distro tooling (`.deb`, `.rpm`, etc.),
  - use tools such as `linuxdeployqt`/AppImage,
  - install and run with required Qt runtime available on target system.

For CMake-based installation you can also use:

```bash
cmake --install build
```

On Windows multi-config generators (for example Visual Studio), use:

```powershell
cmake --install build --config Release
```

If Windows installation fails because of permissions in `Program Files`, install to a local absolute path:

```powershell
cmake --install build --config Debug --prefix "C:/Users/USER/source/repos/CalculatorQt/dist"
```

---

## Usage

1. Launch the app.
2. Enter an expression using keyboard or on-screen buttons.
3. Press `=` (or Enter) to calculate.
4. If parsing or evaluation fails, an `Error: ...` message is shown in the result field.

---

## Project Structure

```text
CalculatorQt/
├── CMakeLists.txt
├── README.md
├── main.cpp
├── mainwindow.cpp
├── mainwindow.h
├── mainwindow.ui
└── libs/
    └── MathEngine/
        ├── CMakeLists.txt
        ├── lib/
        │   ├── include/
        │   └── src/
        └── tests/
```

---

## License

MIT
