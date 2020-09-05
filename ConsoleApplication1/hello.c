// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include <stdlib.h>
#include "seqlist.h"

int baseArray[4] = { 1,2,5,10 };

void printfArray(int* array) {
    for (int ii = 1; ii < array[0]; ii++) {
        if (array[ii] < 1)break;
        printf("%d ,", array[ii]);
    }
    printf("\n");
}


void arrayAdd(int* array, int size,int addValue) {
    for (int ii = array[0]+1; ii < size; ii++) {
        if (array[ii] == 0) {
            array[ii] = addValue;
            array[0] += 1;
            break;
        }
    }
}


void arrayCopy(int* arrayDisc,int* arraySrc, int size) {
    for (int ii = 0; ii < size; ii++) {
        arrayDisc[ii] = arraySrc[ii];
    }
}

void reward_get(int value ,int* returnArray)
{
    if (value == 0) {

        printfArray(returnArray);
        return;
    }
    if (value < 0)return;
    for (int i = 0; i < (sizeof(baseArray) / sizeof(int)); i++) {
        int arrayBuffer[11] = {0,0,0,0,0,0,0,0,0,0,0};
        if (returnArray[0] > 0) {
            arrayCopy(arrayBuffer, returnArray, (returnArray[0]+1));
        }
        arrayAdd(arrayBuffer,sizeof(arrayBuffer)/sizeof(int),baseArray[i]);
        reward_get(value - baseArray[i], arrayBuffer);
    }


}


void reward_compose( int rewardValue,int* rewardElement)
{

}

int main()
{	
	int i = 0;
    int arrayValue[11] = {0,0,0,0,0,0,0,0,0,0,0};
    reward_get(10, arrayValue);


    printf("hello old man!");
    return 0;




}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
