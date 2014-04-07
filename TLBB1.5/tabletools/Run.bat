echo off

del /Q Public\*.*
del /S /Q /F CodeTable
 
set courcedir=".\Datas"
set pathonPath="python.exe"
mkdir Public
copy /Y %courcedir%\client\*.xlsx .\Public\
copy /Y %courcedir%\public\*.xlsx .\Public\
copy /Y %courcedir%\server\*.xlsx .\Public\

%pathonPath% DataConverter.py

PlistTableCode.exe -charp


cd ..

echo ����C#����
copy /Y  .\tabletools\CodeTable\CSharp\*.cs .\Client\Assets\Client\Scripts\Table\

echo ����Tabletxt����
copy /Y .\tabletools\Public\*.txt .\Client\Assets\Client\Resources\


cd tabletools

del /Q Public\*.*
del /S /Q /F CodeTable

copy /Y %courcedir%\public\*.xlsx .\Public\
copy /Y %courcedir%\server\*.xlsx .\Public\

%pathonPath% DataConverter.py
PlistTableCode.exe -charp -java

cd ..


echo ����java����
copy /Y  .\tabletools\CodeTable\Java\xjgame\table\*.java .\server\src\xjgame\table\

echo ����GameData����
copy /Y .\tabletools\Public\*.txt .\GameData\

cd tabletools
pause




