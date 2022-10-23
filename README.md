# boost_program_options_cxx20_module

(under construction)  

Коротко:
1. OS Windows, Visual Studio 2022 17.2 (и выше) PREVIEW.
2. Boost 1.80

cd boost_install  
bootstrap.bat  
b2 --with-program_options install  
b2 tools\bcp  
dist\bin\bcp.exe --boost="C:\Boost\include\boost-1_80" program_options "D:\boost_program_options_cxx20_module"   

Перед открытием и сборкой проекта требуется создать переменную окружения системного уровня BmiCacheDir со значанием "X:\BmiCacheDir\".  
X - имя дискового тома. Данная директория нужна для размещения двоичных модулей, требуемых всеми предстоящими проектами.  

