@echo off
type NUL > combined.txt

for %%f in (*.cpp *.hpp) do (
    type "%%f" >> combined.txt
    echo. >> combined.txt
)
