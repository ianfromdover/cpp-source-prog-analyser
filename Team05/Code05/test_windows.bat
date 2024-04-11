@echo off

rem Run the auto tester and generate the xml in ./test/out.xml

set EXECUTABLE_PATH=".\autotester.exe"
set SOURCE_PATH="..\Tests05\testcases\system_test_1_source.txt"
set QUERY_PATH="..\Tests05\testcases\system_test_1_queries.txt"
set OUTPUT_XML_PATH="./out.xml"



echo [+] - Starting HTTP Server...
rem Start a python3 http server to serve the folder at localhost:8000
start "server" python3 -m http.server 8000

rem Waiting for 2s to let HTTP server spin up
timeout /t 2

rem Open link with default browser
echo [+] - Opening link to results...
powershell -Command "Start-Process -NoNewWindow -FilePath explorer -ArgumentList 'http://localhost:8000/out.xml'"