//如果没有定义AH，定义AH
//#ifndef AH
//#define AH
//#include "B.h"  导入b.h
//
//void printfA();
//
//#endif


//该头文件只被包含一次，让编译器自定处理好循环包含问题
#pragma once
#include "B.h"

void printfA();