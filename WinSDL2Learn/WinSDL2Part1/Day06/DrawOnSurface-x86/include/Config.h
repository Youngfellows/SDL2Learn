#ifndef _DUNGEON_CONFIG_H_
#define _DUNGEON_CONFIG_H_

namespace Dungeon
{
#define WINDOW_WIDTH 900 //Window窗口宽
#define WINDOW_HEIGHT 600 //Window窗口高
#define FRAMERATE 60 //每1秒帧数
#define WINDOW_TITLE "Dungeon" //Window窗口title

#define BACKGROUND_COLOR 0xffffffff //背景颜色-白

#define COMPONENT_SIZE 1 //需要创建的组件个数
#define START_X 50
#define START_Y 80
#define MARGIN_LEFT 10

#define RECT_START_X START_X //矩形开始绘制的X位置
#define RECT_START_Y START_Y //矩形开始绘制的X位置
#define RECT_WIDTH 50 //矩形宽
#define RECT_HEIGHT 50 //矩形高
#define RECT_COLOR 0xFFFFB900 //矩形颜色
#define RECT_BORDER_COLOR 0xFFE33D30 //矩形边框颜色
#define PT_SIZE_10 10 //10榜
#define PT_SIZE_15 15 //15榜
#define PT_SIZE_20 20 //20榜
#define PT_SIZE_25 25 //25榜
#define PT_SIZE_30 30 //30榜

#define CAT_PHOTO_FILE "./resources/cat.jpg" //图片资源
#define GIRL_PHOTO_FILE "./resources/girl.jpg" //图片资源
#define PHOTO_CAT_START_X START_X+RECT_WIDTH+MARGIN_LEFT //图片开始绘制的X位置
#define PHOTO_CAT_START_Y START_Y //图片开始绘制的X位置
#define PHOTO_CAT_WIDTH 80 //图片宽
#define PHOTO_CAT_HEIGHT 80 //图片高

#define PHOTO_GIRL_START_X START_X+RECT_WIDTH+PHOTO_CAT_WIDTH+MARGIN_LEFT*2 //图片开始绘制的X位置
#define PHOTO_GIRL_START_Y START_Y //图片开始绘制的X位置
#define PHOTO_GIRL_WIDTH 200 //图片宽
#define PHOTO_GIRL_HEIGHT 200 //图片高
}

#endif // !_DUNGEON_CONFIG_H_

