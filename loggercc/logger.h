#ifndef PROJECTS_CS323_LOGGER_H
#define PROJECTS_CS323_LOGGER_H
/*
By Josef Jankowski
02/11/2020
*/
#include <string>
#include <fstream>

namespace loggercc{
    enum Level {
      INFO,
      WARNING,
      ERROR,
      FATAL
    };
    class Logger {
        public:
        // Example input: "logger.log"
          Logger(const char *file_name);
          void OpenLog(const char *file_name);
          void CloseLog();
          void ReadLog(const char *file_name);
          void WriteLog(Level status, std::string text, const int linenum, const char *fname);
          void Flush();
          ~Logger();

        private: 
          std::fstream log_file_;
          std::string log_level_[4] = {"INFO", "WARNING", "ERROR", "FATAL"};
    };

}



#endif //PROJECTS_CS323_LOGGER_H