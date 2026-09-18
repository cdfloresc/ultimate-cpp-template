@echo off
setlocal
set CONFIG=%1
if "%CONFIG%"=="" set CONFIG=Release

echo ======================================================================
echo    Compilando y Ejecutando Proyecto C++ (%CONFIG%)
echo ======================================================================

where cmake >nul 2>nul
if %ERRORLEVEL% neq 0 (
    echo [ERROR] CMake no se encontro en el sistema.
    echo Por favor instala CMake: winget install Kitware.CMake
    exit /b 1
)

if not exist "build" (
    echo [1/2] Primera ejecucion detectada. Configurando CMake...
    cmake -B build -S . -A x64
    if %ERRORLEVEL% neq 0 (
        echo [ERROR] No se pudo configurar el proyecto con CMake.
        exit /b %ERRORLEVEL%
    )
)

echo [1/2] Compilando codigo C++ en modo %CONFIG%...
cmake --build build --config %CONFIG%
if %ERRORLEVEL% neq 0 (
    echo [ERROR] Fallo la compilacion.
    exit /b %ERRORLEVEL%
)

echo [2/2] Iniciando ejecucion...
echo.
if exist ".\build\%CONFIG%\simulacion_benchmark.exe" (
    .\build\%CONFIG%\simulacion_benchmark.exe
) else if exist ".\build\simulacion_benchmark.exe" (
    .\build\simulacion_benchmark.exe
) else (
    echo [ERROR] No se encontro el ejecutable generado en build.
    exit /b 1
)
