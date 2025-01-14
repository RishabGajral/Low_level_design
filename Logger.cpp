#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class LogProcess{
    public:
    static int INFO;
    static int DEBUG;
    static int ERROR;
    LogProcess* next_process;
    LogProcess(LogProcess* obj){
        next_process =obj;
        cout<<"Base class constructor called, next_process initialized"<<endl;
    }
    virtual void log(int level, const string& message){
        if(next_process!=NULL){
            next_process->log(level,message);
        }
    }
};

int LogProcess:: INFO=1;
int LogProcess:: DEBUG=2;
int LogProcess:: ERROR=3;

class InfoProcess: public LogProcess{
  public:
  InfoProcess(LogProcess* next): LogProcess(next){
      cout<<"INFO constructor called"<<endl;
  }
  void log(int level, const string& message){
      if(level== INFO){
          cout<<"INFO level "<<message<<endl;
      }
      else
      { if(next_process!=NULL)
          next_process->log(level,message);
      }
  }
};
class DebugProcess: public LogProcess{
  public:
  DebugProcess(LogProcess* next): LogProcess(next){     //calling the base class constructor
      cout<<"Debug constructor called"<<endl;           // assigning next_pointer with next child(new object)
  }
  void log(int level, const string& message){
      if(level== DEBUG){
          cout<<"Debug level "<<message<<endl;
      }
      else
      { if(next_process!=NULL)
          next_process->log(level,message);
      }
  }
};



int main()
{
    LogProcess* obj;
    obj=new InfoProcess(new DebugProcess (NULL));
    obj->log(LogProcess::DEBUG,"this is an info message");
    return 1;
}
