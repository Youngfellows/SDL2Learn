#include "FileReader.h"

/*
* 获取文件大小
*/
long getFileSize(FILE *file)
{
	long fileSize = -1;
	if (file != NULL) {
		if (fseek(file, 0L, SEEK_END) == 0) {
			fileSize = ftell(file);
		}
		rewind(file);
	}
	return fileSize;
}