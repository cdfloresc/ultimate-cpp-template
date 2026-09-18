# ⚡ Ultimate C++20 High-Performance Template

[![C++20](https://img.shields.io/badge/C%2B%2B-20-blue.svg?style=flat-square&logo=c%2B%2B)](https://en.wikipedia.org/wiki/C%2B%2B20)
[![CMake](https://img.shields.io/badge/CMake-3.25%2B-064F8C.svg?style=flat-square&logo=cmake)](https://cmake.org)
[![OpenMP](https://img.shields.io/badge/OpenMP-Multi--Threading-red.svg?style=flat-square)](https://www.openmp.org/)
[![SIMD](https://img.shields.io/badge/SIMD-AVX2%20Optimized-brightgreen.svg?style=flat-square)](#)
[![CI](https://img.shields.io/badge/CI-GitHub%20Actions-2088FF.svg?style=flat-square&logo=github-actions)](https://github.com)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg?style=flat-square)](LICENSE)

Una plantilla (Starter Kit / Template) profesional y lista para producción en **C++20** con **CMake**. Diseñada tanto para principiantes que buscan una forma rápida de programar en C++ sin dolores de cabeza, como para profesionales que desarrollan **simulaciones científicas pesadas, motores de cálculo, física de partículas, renderizado y algoritmos de alto rendimiento (HPC)**.

---

## 📋 Información para Publicar en GitHub

Si vas a subir este template a tu cuenta de GitHub, aquí tienes la información recomendada para copiar y pegar:

* **Repository Name (Nombre sugerido):**
  * `ultimate-cpp-template` *(Recomendado)*
  * `cpp-simulation-starter`
  * `modern-cpp20-template`
* **Description (Descripción para el repo):**
  > 🚀 Professional C++20 template for high-performance computing, heavy simulations & algorithms. Multi-platform (Windows/Linux), OpenMP multi-threading, AVX2 SIMD, CMake presets and CI ready.
* **Topics (Tags para GitHub):**  
  `cpp`, `cpp20`, `cmake`, `openmp`, `simulations`, `high-performance-computing`, `template`, `starter-kit`, `scientific-computing`, `multithreading`

---

## ⚡ Inicio Rápido (En 1 Solo Comando)

No necesitas recordar comandos largos ni rutas complejas:

### 🪟 En Windows (CMD o PowerShell)
```powershell
.\run
```
*(Para compilar con símbolos de depuración: `.\run Debug`)*

### 🐧 En Linux / 🍎 macOS
```bash
chmod +x run.sh
./run.sh
```

### 💻 En tu Editor (VS Code / Antigravity IDE)
- Presiona **`F5`** ➡️ Compila y arranca con el depurador integrado automáticamente.
- Presiona **`Ctrl + Shift + B`** ➡️ Compila la versión optimizada Release.

---

## 🛠️ Requisitos Previos (Instalación en 1 Minuto)

Solo necesitas tener instaladas dos cosas en tu máquina:

### En Windows
Abre una terminal como Administrador y ejecuta:
```powershell
# 1. Instalar CMake
winget install Kitware.CMake

# 2. Instalar Visual Studio Build Tools (con C++)
winget install Microsoft.VisualStudio.2022.BuildTools --override "--passive --add Microsoft.VisualStudio.Workload.VCTools --includeRecommended"
```
*(O simplemente instala [Visual Studio](https://visualstudio.microsoft.com/) marcando la casilla "Desarrollo para el escritorio con C++")*.

### En Linux (Ubuntu / Debian)
```bash
sudo apt update && sudo apt install -y cmake build-essential g++
```

### En macOS
```bash
brew install cmake
```

---

## 📁 Estructura del Proyecto

La plantilla sigue las mejores prácticas de la industria y estándares de Clean Architecture en C++:

```text
├── .github/
│   └── workflows/
│       └── ci.yml              # Integración continua automática en Windows y Linux (GitHub Actions)
├── .vscode/
│   ├── launch.json             # Depuración directa con tecla F5
│   └── tasks.json              # Atajos de compilación rápida (Ctrl + Shift + B)
├── CMakeLists.txt              # Configuración de CMake (C++20, OpenMP, AVX2, flags /O2)
├── CMakePresets.json           # Presets estándar reconocidos por VS Code, Visual Studio y CLion
├── .gitignore                  # Excluye binarios, carpetas build/ y archivos temporales
├── include/
│   └── sim/
│       ├── simulation.hpp      # Estructuras alineadas a 32 bytes para Caché L1/L2/L3 y SIMD
│       └── timer.hpp           # Cronómetro de microsegundos de alta resolución (std::chrono)
├── src/
│   ├── simulation.cpp          # Lógica computacional con bucles multinúcleo en OpenMP
│   └── main.cpp                # Punto de entrada con diagnóstico de hardware y benchmark
├── run.cmd                     # Script Windows: compila y corre escribiendo '.\run'
├── run.sh                      # Script Linux/macOS: compila y corre escribiendo './run.sh'
└── README.md
```

---

## 🔬 Benchmark de Demostración Incluido

Al ejecutar el proyecto, se ejecuta una prueba de estrés de cálculo masivo (Simulación Gravitacional N-Body):
- **12,000 partículas físicas** calculando **144 millones de interacciones gravitatorias por paso** ($O(N^2)$).
- **Paralelismo masivo:** Utiliza todos los núcleos de tu CPU mediante **OpenMP**.
- **Instrucciones SIMD:** Optimizado con vectorización **AVX2** y optimización matemática `/fp:fast`.
- **Rendimiento:** Supera los **~2.0 Giga-Interacciones / segundo** en un procesador convencional de 8 hilos.

---

## 🚀 Cómo Usar este Template para Tus Propios Proyectos

### Paso 1: Crear tu nuevo repo desde la plantilla
1. En GitHub, haz clic en el botón verde **"Use this template"** ➡️ **"Create a new repository"**.
2. Ponle el nombre de tu nuevo proyecto y clónalo en tu computadora.

### Paso 2: Personalizar el nombre
Abre [CMakeLists.txt](CMakeLists.txt) y cambia el nombre de la línea 2:
```cmake
project(MiNuevaSimulacion LANGUAGES CXX)
```

### Paso 3: Programar
- Agrega tus clases y cabeceras en `include/`.
- Agrega tus archivos `.cpp` en `src/`.
- Ejecuta `.\run` y disfruta de la máxima velocidad que C++ puede ofrecer.

---

## 📄 Licencia
Este proyecto está bajo la Licencia MIT. Eres libre de usarlo, modificarlo y distribuirlo para proyectos personales, académicos o comerciales.
