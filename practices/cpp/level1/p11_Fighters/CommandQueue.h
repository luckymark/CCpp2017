#ifndef COMMANDQUEUE_H_
#define COMMANDQUEUE_H_

#include "Command.h"
#include"YOUneedTHIS.h"


class CommandQueue
{
	public:
		void push(const Command& command);
		Command pop();
		bool isEmpty() const;

		
	private:
		std::queue<Command> mQueue;
};

#endif // !COMMANDQUEUE_H_
