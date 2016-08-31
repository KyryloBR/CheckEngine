#include "Loger.h"

Loger::Loger()
{
	m_pLogFile = new std::ofstream(_LOG_FILE_, std::ios::app);
	if (m_pLogFile->is_open())
	{
		std::string msg;
		msg.append(__DATE__);
		msg.append(" : ");
		msg.append(__TIME__);
		msg.append(" : ");
		msg.append("INFO : ");
		msg.append("Application has been started.\n");
		std::cout << msg.c_str();
		*m_pLogFile << msg.c_str();
		m_pLogFile->close();
	}
}

Loger::~Loger()
{
	
}

bool Loger::isFull()
{
	return true;
}

void Loger::clear()
{

}

void Loger::writeMsg(const std::string & _msg)
{
	m_pLogFile->open(_LOG_FILE_, std::ios::app);
	if (m_pLogFile->is_open())
	{
		std::cout << _msg.c_str();
		*m_pLogFile << _msg.c_str();
		m_pLogFile->close();
	}
}