#ifndef _DUNGEON_CONFIG_H_
#define _DUNGEON_CONFIG_H_

namespace Dungeon
{
#define WINDOW_WIDTH 800 //Window窗口宽
#define WINDOW_HEIGHT 400 //Window窗口高
#define FRAMERATE 60 //每1秒帧数
#define WINDOW_TITLE "Dungeon" //Window窗口title

#define PT_SIZE_5 5 //大小5pt
#define PT_SIZE_10 10 //大小10pt
#define PT_SIZE_20 20 //大小20pt
#define PT_SIZE_25 25 //大小25pt
#define PT_SIZE_30 30 //大小30pt
#define SPEED 5 //滚动速度

#define FONT_FINE_NAME "./resources/padmaa.ttf" //字体
#define START_TEXT "Start" //开始
#define PAUSE_TEXT "Pause" //暂停
#define RE_START_TEXT "ReStart" //从新开始
#define STOP_TEXT "Stop" //停止
#define STATE_TEXT "State" //状态

#define COLOR_TEXT 0xffff0000 //字体颜色
#define BG_COLOR_TEXT 0xFF62E872 //字体背景颜色
#define PADDING_LEFT 10 //左边距
#define PADDING_RIGHT 10 //右边距
#define PADDING_TOP 10 //上边距
#define PADDING_BOTTOM 10 //下边距

#define START_TEXT_X_POSITION 10
#define START_TEXT_Y_POSITION 10
#define PAUSE_TEXT_X_POSITION START_TEXT_X_POSITION
#define PAUSE_TEXT_Y_POSITION START_TEXT_Y_POSITION + 80 
#define RE_START_TEXT_X_POSITION START_TEXT_X_POSITION 
#define RE_START_TEXT_Y_POSITION PAUSE_TEXT_Y_POSITION+80
#define STOP_TEXT_X_POSITION START_TEXT_X_POSITION
#define STOP_TEXT_Y_POSITION RE_START_TEXT_Y_POSITION + 80

#define STATE_COLOR_TEXT 0xff000000 //字体颜色
#define STATE_BG_COLOR_TEXT 0xFFFFB6C1 //字体背景颜色
#define STATE_TEXT_X_POSITION 300
#define STATE_TEXT_Y_POSITION 150

#define COMPONENT_SIZE 6 //需要创建的组件个数

#define WAV_SOUND_SIZE 2 //音频数量
#define WAV_SOUND_FILE_NAME "./resources/sound.wav"
#define WAV_SOUND_SIREN_FILE_NAME "./resources/siren_signal_wail_yelp_multitone_phaser_hilo.wav"
#define FLAG_CREATE_AUDIO_PLAYER "CreateAudioPlayer"
#define FLAG_START_AUDIO_PLAYER "StartAudioPlayer"
#define FLAG_STOP_AUDIO_PLAYER "StopAudioPlayer"
#define FLAG_PAUSE_AUDIO_PLAYER "PauseAudioPlayer"
#define FLAG_RELEASE_AUDIO_PLAYER "ReleaseAudioPlayer"
}

namespace Dungeon
{
#define MAKE_THREAD_SIZE 1 //多线程数量
#define USE_THREAD_SIZE 1 //多线程数量
#define MAX_SIZE 20 //保存音频容器的最大容量
//#define AUDIO_CAPACITY 2048*1 //每次读取文件的内存大小2024个字节,也就是2kb
#define AUDIO_CAPACITY 16384 //每次读取文件的内存大小2024个字节,也就是2kb


#define PCM_1_FILE_NAME "./resources/mu_rong_xue_xue_kai_qi.wav"
#define PCM_2_FILE_NAME "./resources/mu_rong_xue_xue_kai_qi_1.wav"
#define PCM_3_FILE_NAME "./resources/mu_rong_xue_xue_kai_qi.pcm" //其实是一个pcm音频文件
#define MP3_FILE_NAME "./resources/mu_rong_xue_xue_kai_qi.mp3"
#define SAVE_FILE_NAME "../x64/Debug/my_save_1.pcm" //保存读取到的音频文件
//#define USE_AUDIO_IN_CALLBACK //是否使用多线程写音频文件的标志
}

#endif // !_DUNGEON_CONFIG_H_

