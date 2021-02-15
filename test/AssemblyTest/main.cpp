#include <iostream>
#include <asm.h>

int main()
{
    std::wstringstream ss;
    Assembly assembly(ss);
    assembly.startOfFunction();

    assembly.setString(L"どうも、サメです！");
    assembly.setString(L"Gawr Gura");
    assembly.setString(L"Shaaaaaark");

    assembly.endOfFunction();
    std::wcout << ss.str() << std::endl;
}