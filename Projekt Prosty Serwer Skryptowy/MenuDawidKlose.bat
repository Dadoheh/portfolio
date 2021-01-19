@echo off
setlocal enabledelayedexpansion
@chcp 1250

:menu
cls

echo MENU
echo 1 - Uruchom program
echo 2 - Pokaz wynik uruchomionego programu 
echo 3 - Pokaz backup uruchomionego programu 
echo 4 - Pokaz instrukcje
echo q - zamknij program

set /p ch=""
if %ch%==1 (
goto program
)
if %ch%==2 (
goto wynik 
)
if %ch%==3 (
goto backup
)
if %ch%==4 (
goto instrukcja
)
if %ch%==q (
exit
)

:program
cls

echo 1 - Domyslna sciezka
echo 2 - Niestandardowa sciezka

set /p pr=""
if %pr%==1 (
call LiczbyZaprzyjaznione.py "files\in.txt" 
pause
goto menu
)
if %pr%==2 (
set /p sc=Podaj sciezke plikow wejsciowych:
call LiczbyZaprzyjaznione.py sc 
pasue
goto menu
)

:wynik
start "" "files\out.html"
goto menu

:backup
start "" "logs.txt"
pause
goto menu

:instrukcja
start "" "files\instrukcja.txt"
pause
goto menu