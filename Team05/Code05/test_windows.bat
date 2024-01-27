@echo off

rem Run the auto tester and generate the xml in ./test/out.xml

set EXECUTABLE_PATH=".\out\build\x64-Debug\src\autotester\autotester.exe"
set SOURCE_PATH="..\Tests05\Sample_source.txt"
set QUERY_PATH="..\Tests05\Sample_queries.txt"
set OUTPUT_XML_PATH="./tests/out.xml"

echo [+] - Running AutoTester...
>NUL (
	"%EXECUTABLE_PATH%" "%SOURCE_PATH%" "%QUERY_PATH%" "%OUTPUT_XML_PATH%"
)
echo [+] - AutoTester Done!

echo [+] - Starting HTTP Server...
rem Start a python3 http server to serve the folder at localhost:8000
start "server" python3 -m http.server 8000

rem Waiting for 2s to let HTTP server spin up
timeout /t 2

rem Open link with default browser
echo [+] - Opening link to results...
powershell -Command "Start-Process -NoNewWindow -FilePath explorer -ArgumentList 'http://localhost:8000/tests/out.xml'"