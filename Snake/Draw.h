#pragma once
#include<windows.h>
#include<iostream>

class Draw {
public:
	/**
	 *	����Ψһ���������
	 *
	 *	@return Draw& ����������
	 */
	static	Draw& getDraw();
	/**
	 *	�����ַ���
	 *
	 * @param point	����
	 * @param color ��ɫ
	 * @param content ����
	 */
	void writeChar(COORD point, WORD color, const char* content);
	/**
	 *	��������ʾ�����
	 *
	 * @param bool �Ƿ�����,Ĭ������
	 */
	void hideCursor(bool hide = true);
	/**
	 *	����int����
	 *
	 * @param point	����
	 * @param color ��ɫ
	 * @param content ����
	 */
	void writeInt(COORD point, WORD color, int content);

private:
	Draw();
};