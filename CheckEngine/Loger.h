#pragma once
#include <iostream>
#include <fstream>
#define _LOG_FILE_ "logging.log"

enum LogType{ INFO = 0, WARNING, ERROR };

class Loger
{
public:
	Loger(const Loger&) = delete;
	Loger & operator=(const Loger&) = delete;

	Loger();
	~Loger();
	
	void writeMsg(const std::string & _msg); // Write some messages to log file.

private:
	bool isFull();		  // Check is file already full.
	void clear();		  // Clear file.

	std::ofstream * m_pLogFile;
};

