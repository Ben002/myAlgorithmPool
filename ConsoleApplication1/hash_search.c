// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE 12 //定义散列表长度
#define NULL_KEY    -32768

typedef struct {
    int* elem;//数据元素存储地址，动态分配数组
    int count;//当前元素的个数
}HashTable;

int m = 0;

//返回长度
int InitHash(HashTable* H) {
    int i;
    m = HASH_SIZE;
    H->elem = (int*)malloc(m * sizeof(int));
    H->count = m;

    for (int i = 0; i < m; i++) {
        H->elem[i] = NULL_KEY;
    }
    return H->count;

}


int Hash(int k) {
    return k % m;//除留余数法
}

void Insert(HashTable* H, int k) {
    int addr = Hash(k);
    while (H->elem[addr] != NULL_KEY) {
        addr = (addr + 1) % m;
    }
    H->elem[addr] = k;
}

int Search(HashTable * H, int k) {
    int addr = Hash(k);

    while (H->elem[addr] != k) {
        addr = (addr+1)%m;
        if(H->elem[addr] == NULL_KEY || addr == Hash(k)) {
            return -1;
        }
    }
    return addr;

}






int main()
{	
	int i = 0;
    int arrayValue[12] = {1,3,67,5,55,8,9,23,14,79,99,12};
    HashTable H;
    


    InitHash(&H);

    for (int i = 0; i < (sizeof(arrayValue)/sizeof(int)); i++) {
        Insert(&H, arrayValue[i]);
    }

    for (int i = 0; i < H.count; i++) {
        printf("H的位置 %d -> H.elem= %d \n", i,H.elem[i]);
    }
    
    for (int i = 0; i < (sizeof(arrayValue) / sizeof(int)); i++) {
        int addr = Search(&H, arrayValue[i]);
        printf("k=%d 的位置 addr= %d\n",arrayValue[i],addr);
    }


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
