如何获取一个在内存中的4字节整数的值
如何把一共4字节整数存入内存中,也就是一个整数在内存中是如何存储的

案例:
	一个4字节整数在内存中是如何存储的？
	将一个内存中的ascii字符IHDR转化为4字节的整数？

首先获取每个字节的数据，然后交换字节，即高低字节交换顺序
	I		   H		  D			 R
	49 		   48         44         52
	0100 1001  0100 1000  0100 0100  0101 0010
1.& 0000 0000  0000 0000  0000 0000  1111 1111
————————————————————————————————————————————————
	0000 0000  0000 0000  0000 0000  0101 0010
<<24
————————————————————————————————————————————————
	0101 0010  0000 0000  0000 0000  0000 0000
	

	I		   H		  D			 R
	49 		   48         44         52
	0100 1001  0100 1000  0100 0100  0101 0010
2.& 0000 0000  0000 0000  1111 1111  0000 0000
————————————————————————————————————————————————  
	0000 0000  0000 0000  0100 0100  0000 0000
<<8
————————————————————————————————————————————————
	0000 0000  0100 0100  0000 0000  0000 0000
	

	I		   H		  D			 R
	49 		   48         44         52
	0100 1001  0100 1000  0100 0100  0101 0010
3.& 0000 0000  1111 1111  0000 0000  0000 0000
————————————————————————————————————————————————  
	0000 0000  0100 1000  0000 0000  0000 0000
>>8
————————————————————————————————————————————————
	0000 0000  0000 0000  0100 1000  0000 0000
	

	49 		   48         44         52
	0100 1001  0100 1000  0100 0100  0101 0010
4.& 1111 1111  0000 0000  0000 0000  0000 0000
————————————————————————————————————————————————  
	0100 1001  0000 0000  0000 0000  0000 0000
>>24
————————————————————————————————————————————————
	0000 0000  0000 0000  0000 0000  0100 1001
	

再把交换字节后的4个字节，按位或，就得到了存储在内存中的整数值
5.  0101 0010  0000 0000  0000 0000  0000 0000
  | 0000 0000  0100 0100  0000 0000  0000 0000
  | 0000 0000  0000 0000  0100 1000  0000 0000
  | 0000 0000  0000 0000  0000 0000  0100 1001
————————————————————————————————————————————————
    0101 0010  0100 0100  0100 1000  0100 1001  (大小端字节交换后的数即是存储在内存中的4字节整数)
		

取第1个字节
	711

	0000 0000 0000 0000 0000 0010 1100 0111
&   1111 1111 0000 0000 0000 0000 0000 0000

	


