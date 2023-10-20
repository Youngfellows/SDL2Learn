#ifndef _DUNGEON_CONFIG_H_
#define _DUNGEON_CONFIG_H_

namespace Dungeon
{
#define WINDOW_WIDTH 600 //Window窗口宽
#define WINDOW_HEIGHT 400 //Window窗口高
#define FRAMERATE 60 //每1秒帧数
#define WINDOW_TITLE "Dungeon" //Window窗口title


#define INNER_RECT_REST_WIDTH 100 //矩形宽
#define INNER_RECT_REST_HEIGHT 100 //矩形高
#define INNER_RECT_BORDER_COLOR 0xffff0000 //矩形边框颜色
#define INNER_RECT_FILL_COLOR 0xff0000ff //矩形填充颜色

#define OUTER_RECT_REST_WIDTH 300 //矩形宽
#define OUTER_RECT_REST_HEIGHT 200 //矩形高
#define OUTER_RECT_BORDER_COLOR 0xffff0000 //矩形边框颜色
#define OUTER_RECT_FILL_COLOR 0xff0000ff //矩形填充颜色

#define PT_SIZE_10 10 //大小10pt
#define PT_SIZE_20 20 //大小20pt
#define SPEED 5 //滚动速度

#define CURSOR_DEST_RECT_WIDTH 20 //光标宽
#define CURSOR_DEST_RECT_HEIGHT 20 //光标高
#define CURSOR_FILE_NAME "./resources/cursor.png" //光标资源

#define BACKGROUND_FILE_NAME "./resources/bg_volcano.png" //背景图

}

#endif // !_DUNGEON_CONFIG_H_

