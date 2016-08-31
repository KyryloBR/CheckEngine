#ifndef _ADDITION_VARIABLE_
#define _ADDITION_VARIABLE_

//-----------------------------------------------------------
//------------------Debug function begin---------------------
//-----------------------------------------------------------

#define DEBUG(TEXT,TYPE)\
	std::string msg = static_cast<std::string>(TEXT);\
	int typeMsg = static_cast<int>(TYPE);\
			std::string * message = new std::string();\
			message->append(__DATE__);\
			message->append(" : ");\
			message->append(__TIME__);\
			message->append(" : ");\
			if(typeMsg == LogType::ERROR)\
						{\
				message->append("ERROR : ");\
						}\
						else if(typeMsg == LogType::WARNING)\
						{\
				message->append("WARNING : ");\
						}\
						else\
						{\
				message->append("INFO : ");\
						}\
			message->append(__FUNCTION__);\
			message->append(" : ");\
			message->append(msg);\
			message->append("\n");\
			Configuration::log()->writeMsg(*message);\
			delete message;\

//---------------------------------------------------------
//------------------Debug function end---------------------
//---------------------------------------------------------

#define _FPS_ 60


#endif