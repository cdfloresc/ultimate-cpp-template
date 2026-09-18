@echo off
setlocal
set CONFIG=%1
if "%CONFIG%"=="" set CONFIG=Release

echo [1/2] Compilando (%CONFIG%)...
cmake --build build --config %CONFIG%
if %ERRORLEVEL% neq 0 (
    echo [!] Build no configurado o fallo. Configurando con CMake...
    cmake -B build -S . -A x64
    cmake --build build --config %CONFIG%
    if %ERRORLEVEL% neq 0 exit /b %ERRORLEVEL%
)

echo [2/2] Ejecutando...
.\build\%CONFIG%\simulacion_benchmark.exe
