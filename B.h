//用这种是老版本
//#ifndef BH  先判断是否定义，已经定义就不会再进入下面的代码
//#define BH  没有定义再定义  
//#include "A.h"
//
//void printfB();
//
//#endif


//新版本就是用这种方法
#pragma once
#include "A.h"

void printfB();