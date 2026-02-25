#include <windows.h>
#include <stdio.h>

/**
 * 颜色宏定义
 */
#define CANVAS_COLOR (BACKGROUND_RED)    /* 红色 */
#define OBJECT_COLOR (BACKGROUND_GREEN)  /* 绿色 */
#define DEFAULT_COLOR (FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE)  /* 黑色 */

void Gotoxy(int x, int y) {
    HANDLE mConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD mCursorPos;
    mCursorPos.X = (SHORT)x;
    mCursorPos.Y = (SHORT)y;
    SetConsoleCursorPosition(mConsole, mCursorPos);
}

void SetColor(WORD color) {
    HANDLE mOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(mOutput, color);
}

/**
 * 在画布内绘制一个逻辑像素
 * @param x 逻辑X坐标 (0-31)
 * @param y 逻辑Y坐标 (0-31)
 * @param originX 画布左上角在终端的物理X
 * @param originY 画布左上角在终端的物理Y
 */
void DrawPixel(int x, int y, int originX, int originY, WORD color) {
    // 物理X = 初始偏移 + (逻辑x * 2)
    Gotoxy(originX + (x * 2), originY + y);
    SetColor(color);
    printf("  ");
    SetColor(DEFAULT_COLOR);
}
