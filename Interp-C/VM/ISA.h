//
// Created by DELL on 2018/10/30.
//

#ifndef INTERP_C_ISA_H
#define INTERP_C_ISA_H
// Y86_64 字节码
enum ISA_OPCode {
	STOP = 0x00,
	NOP = 0x10,
	// 1 + 1（寄存器）
	RRMOV = 0x20,
	// 把立即数放进寄存器中，按照字节大小
	// 1 + 1（寄存器）+ 8（立即数）
	IRMOVQ = 0x30,
	IRMOVD = 0x31,
	IRMOVW = 0x32,
	IRMOVB = 0x33,
	// 寄存器中的值放进内存中，按照字节大小
	// 1 + 1（寄存器）+ 8（内存地址）
	RMMOVQ = 0x40,
	RMMOVD = 0x41,
	RMMOVW = 0x42,
	RMMOVB = 0x43,
	MRMOVQ = 0x50,
	MRMOVD = 0x51,
	MRMOVW = 0x52,
	MRMOVB = 0x53,
	// OP 类指令，CPU运算
	// 1 + 1（寄存器）
	OP_ADD = 0x60,
	OP_SUB = 0x61,
	OP_MUL = 0x62,
	OP_DIV = 0x63,
	OP_AND = 0x64,
	OP_OR = 0x65,
	OP_NOT = 0x66,
	OP_XOR = 0x67,
	OP_SHR = 0x68,
	OP_SHL = 0x69,
	OP_INC = 0x6A,
	OP_DEC = 0x6B,
	OP_NEG = 0x6C,
	OP_CMP = 0x6D,
	OP_TEST = 0x6E,
	// JMP类指令，跳转到当前地址结束+偏移地址
	// 1 + 8（目的地址）
	JMP = 0x70,
	JLE = 0x71,
	JL = 0x72,
	JE = 0x73,
	JNE = 0x74,
	JGE = 0x75,
	JG = 0x76,
	// 跳转到指定地址，并且执行函数
	// 1 + 8（目的地址）
	CALL = 0x80,
	// 函数返回，跳转回执行前地址
	// 1
	RET = 0x90,
	// 将寄存器中的值入栈，8字节
	// 1 + 1（寄存器）
	PUSH = 0xA0,
	// 将立即数入栈，8字节
	// 1 + 8（立即数）
	PUSHI = 0xA1,
	// 将一定字节的数据入栈，仅开辟栈空间
	// 1 + 8（立即数）
	PUSHN = 0xA2,
	// 将栈上的8字节数据弹入寄存器
	// 1 + 1（寄存器）
	POP = 0xB0,
	// 从栈中空弹一定字节的数据
	// 1 + 8（立即数）
	POPN = 0xB1,
	// 执行系统调用
	// 1 + 1（功能）
	SYSCALL = 0xC0,

	ERR = 0xFF,
};
#endif //INTERP_C_ISA_H
