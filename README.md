# 🚀 C++ High-Performance Simulation & Scientific Computing Template

Template profesional y listo para producción en **C++20** con **CMake**, soporte para **OpenMP (multiprocesamiento en paralelo)**, optimizaciones vectoriales SIMD (**AVX2**) y configuración multiplataforma (**Windows MSVC / Linux GCC**).

Diseñado específicamente para ser usado como **Plantilla de GitHub** para crear simulaciones pesadas, motores de cálculo, física de partículas o algoritmos de alto rendimiento sin perder tiempo configurando entornos de compilación.

---

## ⚡ Inicio Rápido (En 1 Comando)

### En Windows (PowerShell o CMD)
```powershell
.\run
```
*(También puedes usar: `.\run Debug` para compilar en modo depuración)*

### En Linux / macOS
```bash
chmod +x run.sh
./run.sh
```

### En tu Editor / IDE (VS Code, Antigravity IDE)
- Presiona **`F5`** para compilar y ejecutar con depurador integrado automáticamente.
- Presiona **`Ctrl + Shift + B`** para compilar la versión optimizada Release.

---

## 📁 Estructura de la Plantilla

```text
├── .github/
│   └── workflows/
│       └── ci.yml              # CI en GitHub Actions (compila en Windows y Linux en cada commit)
├── .vscode/
│   ├── launch.json             # Depuración directa con tecla F5
│   └── tasks.json              # Tarea de compilación rápida (Ctrl + Shift + B)
├── CMakeLists.txt              # Configuración moderna de CMake con soporte OpenMP y AVX2
├── CMakePresets.json           # Presets estándar reconocidos por VS Code, Visual Studio y CLion
├── .gitignore                  # Exclusión limpia de binarios y temporales
├── include/
│   └── sim/
│       ├── simulation.hpp      # Modelos de datos alineados en memoria para Caché y SIMD
│       └── timer.hpp           # Cronómetro de microsegundos de alta precisión (std::chrono)
├── src/
│   ├── simulation.cpp          # Lógica computacional paralelizada con OpenMP
│   └── main.cpp                # Punto de entrada y benchmark científico
├── run.cmd                     # Script Windows: compila y corre escribiendo '.\run'
├── run.sh                      # Script Linux/macOS: compila y corre escribiendo './run.sh'
└── README.md
```

---

## 🔬 Benchmark de Demostración Incluido

El template incluye de fábrica una simulación física **N-Body gravitacional $O(N^2)$**:
- **12,000 partículas** calculando **144 millones de interacciones por paso**.
- **Cálculo masivo:** ~2.88 mil millones de interacciones gravitatorias procesadas en ~1.8 segundos aprovechando todos los núcleos de la CPU.
- Sirve como test de estrés instantáneo para comprobar que el entorno C++ está optimizado al 100%.

---

## 🛠️ Cómo Usar este Template para Tus Propios Proyectos

1. En GitHub, haz clic en el botón verde **"Use this template"** -> **"Create a new repository"**.
2. Clona tu nuevo repositorio.
3. Para cambiar el nombre del ejecutable o del proyecto, solo modifica la línea 2 de [CMakeLists.txt](file:///d:/Dev/prueba%20c++/CMakeLists.txt):
   ```cmake
   project(MiProyecto LANGUAGES CXX)
   ```
4. Escribe tu código en `src/` e `include/` y ejecuta con `.\run`.
