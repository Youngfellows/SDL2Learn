#ifndef _DUNGEON_CONFIG_H_
#define _DUNGEON_CONFIG_H_

namespace Dungeon
{
#define WINDOW_WIDTH 700 //Window窗口宽
#define WINDOW_HEIGHT 400 //Window窗口高
#define FRAMERATE 60 //每1秒帧数
#define WINDOW_TITLE "Dungeon" //Window窗口title

#define START_X_POSITION 50 //绘制开始X位置
#define START_Y_POSITION 25 //绘制开始Y位置

#define INNER_RECT_DEST_WIDTH 50 //玩家宽
#define INNER_RECT_DEST_HEIGHT INNER_RECT_DEST_WIDTH //玩家高
#define INNER_RECT_BORDER_COLOR 0xffff0000 //矩形边框颜色
#define INNER_RECT_FILL_COLOR 0xff0000ff //矩形填充颜色

#define BACKGROUND_RECT_DEST_WIDTH 500 //矩形宽
#define BACKGROUND_RECT_DEST_HEIGHT 350 //矩形高
#define BACKGROUND_RECT_BORDER_COLOR 0xff239344 //矩形边框颜色
#define BACKGROUND_RECT_FILL_COLOR 0xFFFFB900 //矩形填充颜色

#define PT_SIZE_5 5 //大小5pt
#define PT_SIZE_10 10 //大小10pt
#define PT_SIZE_20 20 //大小20pt
#define PT_SIZE_25 25 //大小25pt
#define PT_SIZE_30 30 //大小30pt
#define SPEED 5 //滚动速度

#define CURSOR_DEST_RECT_WIDTH 20 //光标宽
#define CURSOR_DEST_RECT_HEIGHT CURSOR_DEST_RECT_WIDTH //光标高
#define CURSOR_FILE_NAME "./resources/cursor.png" //光标资源

#define BACKGROUND_FILE_NAME "./resources/bg_volcano.png" //背景图
#define PLAYER_FILE_NAME "./resources/player.png"

#define MINE_SIZE 20 //地雷数量
#define MINE_FIELD_WIDTH BACKGROUND_RECT_DEST_WIDTH //雷场宽
#define MINE_FIELD_HEIGHT BACKGROUND_RECT_DEST_HEIGHT //雷场高
#define MINE_DEST_RECT_WIDTH 20 //雷宽
#define MINE_DEST_RECT_HEIGHT MINE_DEST_RECT_WIDTH //雷高
#define MINE_FILE_NAME "./resources/mine.bmp" //雷图片资源

#define FONT_FINE_NAME "./resources/padmaa.ttf" //字体
#define START_TEXT "Start" //开始游戏
#define COLOR_START_TEXT 0xff239344 //字体颜色
#define COLOR_MSG_TEXT 0xFFCB95F7 //字体颜色
}

#endif // !_DUNGEON_CONFIG_H_

