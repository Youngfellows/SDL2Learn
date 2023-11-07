#ifndef _DUNGEON_CONFIG_H_
#define _DUNGEON_CONFIG_H_

namespace Dungeon
{
#define WINDOW_WIDTH 900 //Window窗口宽
#define WINDOW_HEIGHT 600 //Window窗口高
#define FRAMERATE 60 //每1秒帧数
#define WINDOW_TITLE "Dungeon" //Window窗口title

#define BACKGROUND_COLOR 0xffffffff //背景颜色-白

#define COMPONENT_SIZE 6 //需要创建的组件个数
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

#define CAT_PHOTO_BMP_FILE "./resources/cat.bmp" //图片资源
#define CAT_PHOTO_FILE "./resources/cat.jpg" //图片资源
#define GIRL_PHOTO_FILE "./resources/girl.jpg" //图片资源
#define GIRL_SASA_PHOTO_FILE "./resources/sasa.jpg" //图片资源
#define GIRL_YAYA_PHOTO_FILE "./resources/yaya.png" //图片资源
#define PHOTO_CAT_START_X START_X+RECT_WIDTH+MARGIN_LEFT //图片开始绘制的X位置
#define PHOTO_CAT_START_Y START_Y //图片开始绘制的X位置
#define PHOTO_CAT_WIDTH 80 //图片宽
#define PHOTO_CAT_HEIGHT 80 //图片高

#define PHOTO_GIRL_START_X START_X+RECT_WIDTH+PHOTO_CAT_WIDTH+MARGIN_LEFT*2  //图片开始绘制的X位置
#define PHOTO_GIRL_START_Y START_Y //图片开始绘制的X位置
#define PHOTO_GIRL_WIDTH 200 //图片宽
#define PHOTO_GIRL_HEIGHT 200 //图片高

#define PHOTO_GIRL_SASA_START_X 2*START_X //图片开始绘制的X位置
#define PHOTO_GIRL_SASA_START_Y 2*START_Y //图片开始绘制的X位置
#define PHOTO_GIRL_SASA_WIDTH 200 //图片宽
#define PHOTO_GIRL_SASA_HEIGHT 200 //图片高

#define PHOTO_GIRL_YAYA_START_X 3*START_X //图片开始绘制的X位置
#define PHOTO_GIRL_YAYA_START_Y 3*START_Y //图片开始绘制的X位置
#define PHOTO_GIRL_YAYA_WIDTH 200 //图片宽
#define PHOTO_GIRL_YAYA_HEIGHT 200 //图片高

#define ARIAL_FONT_FILE "./resources/Arial.ttf" //字体
#define PADMAA_FONT_FILE "./resources/padmaa.ttf" //字体
#define TEXT_1 "Cute Cat"
#define TEXT_2 "Mona Lisa"

#define TEXT_COLOR 0xff000000 //字体颜色
#define TEXT_BACKGROUND_COLOR 0xFFFFB6C1 //字体背景颜色
#define TEXT_1_X_POSITION 10 //开始绘制文本1的X位置
#define TEXT_1_Y_POSITION 10 //开始绘制文本1的Y位置
#define TEXT_2_X_POSITION TEXT_1_X_POSITION //开始绘制文本2的X位置
#define TEXT_2_Y_POSITION START_Y + PHOTO_CAT_HEIGHT + PT_SIZE_10  //开始绘制文本2的Y位置
#define PADDING_LEFT PT_SIZE_10 //左边距
#define PADDING_TOP PT_SIZE_10 //上边距
#define PADDING_RIGHT PT_SIZE_10 //右边距
#define PADDING_BOTTOM PT_SIZE_10 //下边距
}

#endif // !_DUNGEON_CONFIG_H_

