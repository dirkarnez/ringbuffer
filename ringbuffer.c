#include <stdio.h> // 引入標準輸入輸出標頭檔
#include <stddef.h> // 引入標準輸入輸出標頭檔

void fill(char* dst, size_t dst_length, const char* src, size_t src_length) {
    dst[0] = src[0];
}

int main() {
    char buffer[5] = {0};
    char* a = "aa";
    fill(buffer, 5, a, 2);
    
    printf("->%s<-", buffer); 
    return 0; // 程式正常結束
}
