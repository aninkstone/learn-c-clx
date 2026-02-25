#ifndef __CONSOLE_H__
#define __CONSOLE_H__

/* 初始化函数 */
void Init();

/* 这是描画一个背景的函数，也可以不使用。 自己用 DrawPixel自己来画 */
void DrawBackground(int width, int height);


/* 这是描画一个小方块的函数 */
void DrawPixel(int x, int y, unsigned int color);

#endif //__CONSOLE_H__
