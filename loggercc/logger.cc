#include "logger.h"
#include <fstream>
#include <iostream>
#include <mutex>
#include <string>
#include <ctime>

namespace {
    // Mutex for writing logs.
    std::mutex log_lock;    
}

namespace loggercc {

          Logger::Logger(const char  *file_name){
              OpenLog(file_name);
          }
          Logger::~Logger(){
              CloseLog();
          }
          void Logger::OpenLog(const char *file_name){
             if(!log_file_.is_open()){
                log_file_.open(file_name, std::ios::in | std::ios::out | 
                std::ios::app);
              }
              else{
                std::cout << "Log already opened." << std::endl;
              }
          }
          void Logger::CloseLog(){
              log_file_.close();
          }
          void Logger::ReadLog(const char *file_name){
              std::cout << "Log File: " << std::endl;
              std::ifstream fin;
              fin.open(file_name); 
              std::string line;
              while(fin >> line){
                std::cout << line;
              }
              fin.close();
          }
          void Logger::WriteLog(Level status, std::string text,const int linenum, const char *fname){ 
              // Get the time before the mutex.  
              std::time_t time_now = time(nullptr);
               // To avoid writes at the same time in the critical section. 
              std::lock_guard<std::mutex> guard(log_lock);
              log_file_ << log_level_[static_cast<int>(status)] <<  " | " << linenum 
              << " | " << fname << " | " << ctime(&time_now)<< text << std::endl;
          }
          void Logger::Flush(){
            log_file_.flush();
          }
}