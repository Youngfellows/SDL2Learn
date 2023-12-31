#ifndef _DUNGEON_CONFIG_H_
#define _DUNGEON_CONFIG_H_

namespace Dungeon
{
#define MAKE_THREAD_SIZE 3 //多线程数量
#define USE_THREAD_SIZE 5 //多线程数量
#define MAX_SIZE 20 //保存音频容器的最大容量
#define AUDIO_CAPACITY 2048*1 //每次读取文件的内存大小2024个字节,也就是2kb


#define PCM_1_FILE_NAME "./resources/mu_rong_xue_xue_kai_qi.wav"
#define PCM_2_FILE_NAME "./resources/mu_rong_xue_xue_kai_qi_1.wav"
#define PCM_3_FILE_NAME "./resources/mu_rong_xue_xue_kai_qi.pcm" //其实是一个pcm音频文件
#define MP3_FILE_NAME "./resources/mu_rong_xue_xue_kai_qi.mp3"
#define SAVE_FILE_NAME "../Debug/my_save_4.pcm" //保存读取到的音频文件
}

#endif // !_DUNGEON_CONFIG_H_

