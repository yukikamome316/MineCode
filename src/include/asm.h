#pragma once
#ifndef ASM_H
#define ASM_H

#include <sstream>
#include <vector>

class Assembly {
public:
    enum condType{
        EQU, // ==
        NEQ, // !=
        LT,  // < 
        GT,  // > 
        GE,  // <=
        LE   // >=
    };

    int stack_size = 0x20;
    std::wstringstream& ss;

    Assembly(std::wstringstream& ss);
    void startOfFunction();
    void endOfFunction();

    void writeRegister(int value, int dest);
    void moveResister(int src, int dest);

    int stack_offset = 8;
    int push(int src = 13);
    void pop(int offset, int dest = 13);

    void callFunction(int address);

    void peek(int offset, int dest = 13, int src = 13);
    void peek_i(int address, int offset = 0, int dest = 13);
    void poke(int offset = 0, int dest = 12, int src = 13);
    void poke_i(int address, int value, int offset = 0);

    void add(int value, int src = 13, int dest = 13);
    void mul(int value, int src = 13, int dest = 13);
    void div(int value, int src = 13, int dest = 13);

    void addReg(int valueReg, int src = 13, int dest = 13);
    void subReg(int valueReg, int src = 13, int dest = 13);
    void mulReg(int valueReg, int src = 13, int dest = 13);
    void divReg(int valueReg, int src = 13, int dest = 13);
    void modReg(int valueReg, int src = 13, int dest = 13);
    void shtrReg(int valueReg, int src = 13, int dest = 13);
    void shtlReg(int valueReg, int src = 13, int dest = 13);

    void OR(int src_1, int dest = 13, int src_2 = 13);
    void XOR(int src_1, int dest = 13, int src_2 = 13);
    void AND(int src_1, int dest = 13, int src_2 = 13);
    void rightShift(int bit, int src = 13, int dest = 13);
    void leftShift(int bit, int src = 13, int dest = 13);

    int make_loop_ctr = 0;
    int loop_flag = 0;
    int loop_count = 0;
    std::vector<int> loop_offset;
    void startOfLoop(int count, int init = 0);
    void endOfLoop();

    int make_if_ctr = 0;
    void startOfIf(int src_1, std::string mode, int src_2 = 13);
    void startOfIf(condType mode = EQU, int condReg = 0);
    void endOfIf();

    void startOfIf_footer();

    void compare(int reg1, int reg2);
    void compareImm(int reg1, int imm);
    void condJump(condType mode, int condReg,uint32_t addr);
    void condJump(condType mode, int condReg,std::wstring label);
    void Jump(std::wstring label);

    std::wstring makeLabel(std::wstring name);
    std::wstring makeLabel();

    std::wstring getLabel();

    int whileBegin();
    std::wstring getEnd_While(int id);
    void whileEnd(int id);

    int string_offset = 0;
    void setString(std::wstring str, int dest = 13);
};

#endif