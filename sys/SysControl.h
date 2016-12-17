#ifndef __SYS_CONTROL_H__
#define __SYS_CONTROL_H__

class CSysControl	//虚基类
{
public:
	// 状态
	enum {					//这个枚举体为什么没有枚举名
		STATE_FORWARD = 0,	//向前
		STATE_BACKWARD,		//向后
		STATE_MOVE_LEFT,	//向左移动
		STATE_MOVE_RIGHT,	//向右移动
		STATE_TURN_UP,		//向上转
		STATE_TURN_DOWN,	//向下转
		STATE_TURN_LEFT,	//向左转
		STATE_TURN_RIGHT,	//向右转
		STATE_CROUCH,		//蹲
		STATE_JUMP,			//跳
		STATE_RUN,			//跑
		STATE_USE,			//使用物品？
		STATE_FIRE,			//开火
		STATE_SAVE,			//保存
		STATE_RESTORE,		//恢复
		STATE_SCREENSHOT,	//屏幕快照
		STATE_AUX_0,		//辅助设备
		STATE_AUX_1,
		STATE_AUX_2,
		STATE_AUX_3,
		STATE_AUX_4,
		STATE_AUX_5,
		STATE_AUX_6,
		STATE_AUX_7,
		STATE_AUX_8,
		STATE_AUX_9,
		STATE_AUX_A,
		STATE_AUX_B,
		STATE_AUX_C,
		STATE_AUX_D,
		STATE_AUX_E,
		STATE_AUX_F,
		NUM_STATES,			//这个应该是数字键的那个小键盘是否可用的标志
	};
private:

}