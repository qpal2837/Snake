#pragma once
#include<windows.h>
#include<iostream>

class Draw {
public:
	/**
	 *	返回唯一绘制类对象
	 *
	 *	@return Draw& 绘制类引用
	 */
	static	Draw& getDraw();
	/**
	 *	绘制字符串
	 *
	 * @param point	坐标
	 * @param color 颜色
	 * @param content 内容
	 */
	void writeChar(COORD point, WORD color, const char* content);
	/**
	 *	隐藏与显示输入符
	 *
	 * @param bool 是否隐藏,默认隐藏
	 */
	void hideCursor(bool hide = true);
	/**
	 *	绘制int数据
	 *
	 * @param point	坐标
	 * @param color 颜色
	 * @param content 内容
	 */
	void writeInt(COORD point, WORD color, int content);

private:
	Draw();
};