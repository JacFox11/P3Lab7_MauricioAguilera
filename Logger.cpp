#include <vector>
#include "Log.cpp"

#ifndef Logger_CPP
#define Logger_CPP
class Logger{
    private:
            char usuario[25];
            string archivo;
            int num;
            vector <Log*> logs;
    public:
        Logger(){
		}    
		          
        Logger(string usuario, string archivo, int num){
            setUsuario(usuario);
            this->archivo=archivo;
       		this->num=num;
       	}
             
  	    void setUsuario(string usuario){
            const char *temp = usuario.data();
            int num =usuario.size();
       	    num = num < 50 ? num:49;
   	        strncpy(this->usuario, temp, num);
            this->usuario[num] = '\0';
		}
             
        string getUsuario(){
            return this->usuario;
        }
        
        string getArchivo(){
        	return archivo;
		}
             
        void setNum(int num){
            this->num=num;
        }
             
        int getNum(){
            return this->num;
        }
        
        vector <Log*> getLogs(){
        	return logs;
		}
		
		void addLog(Log* log){
			logs.push_back(log);
		}
        
        ~Logger(){}    
};
#endif
