param (
    [string]$Config = "Release"
)

$ErrorActionPreference = "Stop"

Write-Host "======================================================================" -ForegroundColor Cyan
Write-Host "   Compilando y Ejecutando Proyecto C++ ($Config)" -ForegroundColor Cyan
Write-Host "======================================================================" -ForegroundColor Cyan

if (-not (Get-Command cmake -ErrorAction SilentlyContinue)) {
    Write-Host "[ERROR] CMake no se encontro en el sistema." -ForegroundColor Red
    Write-Host "Por favor instala CMake: winget install Kitware.CMake" -ForegroundColor Yellow
    exit 1
}

if (-not (Test-Path "build")) {
    Write-Host "[1/2] Primera ejecucion detectada. Configurando CMake..." -ForegroundColor Yellow
    cmake -B build -S . -A x64
    if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }
}

Write-Host "[1/2] Compilando codigo C++ en modo $Config..." -ForegroundColor Yellow
cmake --build build --config $Config
if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }

Write-Host "[2/2] Iniciando ejecucion..." -ForegroundColor Green
Write-Host ""
if (Test-Path ".\build\$Config\simulacion_benchmark.exe") {
    & ".\build\$Config\simulacion_benchmark.exe"
} elseif (Test-Path ".\build\simulacion_benchmark.exe") {
    & ".\build\simulacion_benchmark.exe"
} else {
    Write-Host "[ERROR] No se encontro el ejecutable generado en build." -ForegroundColor Red
    exit 1
}
