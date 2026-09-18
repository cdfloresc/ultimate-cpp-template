param (
    [string]$Config = "Release"
)

$ErrorActionPreference = "Stop"

Write-Host "==> Configurando con CMake ($Config)..." -ForegroundColor Cyan
cmake -B build -S . -A x64

Write-Host "==> Compilando en modo $Config..." -ForegroundColor Cyan
cmake --build build --config $Config

Write-Host "==> Ejecutando simulación..." -ForegroundColor Green
& ".\build\$Config\simulacion_benchmark.exe"
