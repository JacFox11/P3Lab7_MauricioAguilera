#include "Logger.cpp"

#ifndef Consola_CPP
#define Consola_CPP
using namespace std;
class Consola{
    private:
            char usuario[25];
            Logger* logger;
            int num;
    public:
        Consola(){
        	logger= new Logger();
		}    
		          
        Consola(string usuario, Logger* logger){
        	setUsuario(usuario);
        	this->logger=logger;
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
        
        Logger* getLogger(){
        	return logger;
		}
		
		void setLogger(Logger* logger){
			this->logger=logger;
		}
        
        ~Consola(){}    
};
#endif
