#include <iostream>
#include "sqlite3.h"

//#pragma comment(lib,"sqlite3.lib")

int main()
{
	// 打开或创建数据库文件
	sqlite3 *db;
	const char *path = "./resources/mydatabase.db";
	int rc = sqlite3_open(path, &db);
	if (rc != SQLITE_OK)
	{
		std::cerr << "open sqlite3 database failed.: " << sqlite3_errmsg(db) << std::endl;
		return rc;
	}
	else
	{
		std::cout << "open sqlite3 database sucess." << std::endl;
	}

	// 在这里执行与数据库的交互操作，例如执行SQL查询
	sqlite3_close(db);
	return 0;
}