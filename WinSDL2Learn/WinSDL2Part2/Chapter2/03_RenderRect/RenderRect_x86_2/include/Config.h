#ifndef _DUNGEON_CONFIG_H_
#define _DUNGEON_CONFIG_H_

namespace Dungeon
{
#define WINDOW_WIDTH 900 //Window窗口宽
#define WINDOW_HEIGHT 600 //Window窗口高
#define FRAMERATE 60 //每1秒帧数
#define WINDOW_TITLE "Dungeon" //Window窗口title

#define COMPONENT_SIZE 8 //需要创建的组件个数
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
#define LANDSCAPE_PHOTO_FILE "./resources/landscape.png" //图片资源
#define PHOTO_CAT_START_X START_X+RECT_WIDTH+MARGIN_LEFT //图片开始绘制的X位置
#define PHOTO_CAT_START_Y START_Y //图片开始绘制的X位置
#define PHOTO_CAT_WIDTH 80 //图片宽
#define PHOTO_CAT_HEIGHT 80 //图片高

#define PHOTO_GIRL_START_X START_X+RECT_WIDTH+PHOTO_CAT_WIDTH+MARGIN_LEFT*2 //图片开始绘制的X位置
#define PHOTO_GIRL_START_Y START_Y //图片开始绘制的X位置
#define PHOTO_GIRL_WIDTH 200 //图片宽
#define PHOTO_GIRL_HEIGHT 200 //图片高

#define FONT_FILE "./resources/Arial.ttf" //字体
#define TEXT_1 "Cat"
#define TEXT_2 "Lisa"

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

#define BUBBLE_COUNT 50 //星空绘制点数量
#define BUBBLE_WIDTH 30 //泡泡宽
#define BUBBLE_HEIGHT BUBBLE_WIDTH //泡泡高
#define STARLITSKY_COLOR 0xFFE95420 //星空点的颜色
#define STARLITSKY_BACKGROUND_COLOR 0xFF2885CD //星空背景
#define STARLITSKY_START_X WINDOW_WIDTH - STARLITSKY_WIDTH - MARGIN_LEFT*2 //绘制星空的X起始位置
#define STARLITSKY_START_Y START_Y //绘制星空的Y起始位置
#define STARLITSKY_WIDTH 300 //星空宽
#define STARLITSKY_HEIGHT STARLITSKY_WIDTH//星空高

#define LINE_1_COLOR 0xffff0000 //直线颜色1
#define LINE_2_COLOR 0xff00ff00 //直线颜色2
#define LINE_3_COLOR 0xff0000ff //直线颜色3
#define LINE_4_COLOR 0xFF22A5F1 //直线颜色4
#define POINT_1_X 100 //第1个点X位置
#define POINT_1_Y 100 //第1个点Y位置	
#define POINT_2_X 200 //第2个点X位置
#define POINT_2_Y 150 //第2个点Y位置
#define POINT_3_X 100 //第3个点X位置
#define POINT_3_Y 200 //第3个点Y位置
#define POINT_4_X 150 //第4个点X位置
#define POINT_4_Y 300 //第4个点Y位置
#define POINT_5_X 300 //第4个点X位置
#define POINT_5_Y 200 //第4个点Y位置
#define POINT_6_X 350 //第4个点X位置
#define POINT_6_Y 350 //第4个点Y位置
}

#endif // !_DUNGEON_CONFIG_H_

