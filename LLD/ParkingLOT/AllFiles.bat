@echo off
type NUL > combined1.txt

for %%f in (*.cpp *.hpp) do (
    type "%%~nf.%%~xf" >> combined1.txt
    echo. >> combined1.txt
)
