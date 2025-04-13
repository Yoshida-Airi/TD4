#pragma once
#include "ICommand.h"

class InputHandler
{
public:
	ICommand* HandleInput();

	void AssignMoveLeftCommand4PressKeyA();
	void AssignMoveRightCommand4PressKeyD();
	void AssignMoveUpCommand4PressKeyW();
	void AssignMoveDownCommand4PressKeyS();

private:
	ICommand* pressKeyD_;
	ICommand* pressKeyA_;
	ICommand* pressKeyW_;
	ICommand* pressKeyS_;
};
