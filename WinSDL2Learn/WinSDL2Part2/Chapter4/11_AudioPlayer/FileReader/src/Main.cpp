#define _CRT_SECURE_NO_WARNINGS
#include "FileReader.h"

using namespace std;

#define	SRC_FILE_NAME "./resources/mu_rong_xue_xue_kai_qi_1.wav"
#define SAVE_FILE_NAME "../x64/Debug/save_test_x1.pcm"
//#define	SRC_FILE_NAME "./resources/readme.txt" //读取文本文件没有问题
//#define SAVE_FILE_NAME "../x64/Debug/save_readme.txt"

#define CACHE_SIZE 1024 //临时缓存大小

int main(int argc, char *argv[])
{
	FILE *srcFile = fopen(SRC_FILE_NAME, "rb");
	if (!srcFile)
	{
		printf("open file error:%s\n", SRC_FILE_NAME);
		return 0;
	}
	long size = getFileSize(srcFile);
	printf("size:%ld\n", size);

	//保存整个文件的缓存空间
	char *buffer = (char *)malloc(sizeof(char) * size);
	if (!buffer)
	{
		printf("malloc buffer error\n");
		return 0;
	}
	//每一次读取到的缓存空间
	char *cache = (char *)malloc(sizeof(char) * CACHE_SIZE);
	if (!cache)
	{
		printf("malloc cache error\n");
		return 0;
	}
	size_t len = 0;
	size_t index = 0;
	while ((len = fread(cache, 1, CACHE_SIZE, srcFile)) > 0)
	{
		printf("index:%ld,len:%ld\n", index, len);
		//strcpy(buffer + index, cache);//把读取到的数据拷贝到缓存
		//strncpy(buffer + index, cache, len);
		memcpy(buffer + index, cache, len);//一定要用memcpy才可以复制二进制文件
		index += len;
		memset(cache, 0, CACHE_SIZE);//清空缓存
	}
	fclose(srcFile);
	printf("read file success");

	FILE *saveFile = fopen(SAVE_FILE_NAME, "wb");
	if (!saveFile)
	{
		printf("open file error:%s", SAVE_FILE_NAME);
		return 0;
	}
	fwrite(buffer, 1, size, saveFile);//把数据写入文件
	fclose(saveFile);
	return 1;
}