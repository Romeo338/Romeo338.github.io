@echo off
set SOURCE_FILES=main.cpp
set OUTPUT=index.html
set OPTIMIZATION=-O2
set EM_FLAGS=-s WASM=1 -s USE_SDL=3
emcc %SOURCE_FILES% %OPTIMIZATION% %EM_FLAGS% -o %OUTPUT%

if %ERRORLEVEL% EQU 0 (
    echo Build successful! Output: %OUTPUT%
    echo Run with: emrun %OUTPUT%
) else (
    echo Build failed with error code %ERRORLEVEL%
    exit /b %ERRORLEVEL%
)

pause