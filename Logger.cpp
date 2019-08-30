#include <vector>
#include "Log.cpp"
#include "AdminLog.cpp"
#include "cmdError.cpp"

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
		          
        Logger(string usuario, string archivo){
            setUsuario(usuario);
            this->archivo=archivo;
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
		
		void run(){
			string cmd;
			AdminLog* al = new AdminLog("logs.bin");
			al->Leer();
			while(cmd!="exit"){
				try{
					cout<<"Comando: ";
					cin>>cmd;
					if (al->getN()<1){
						num=0;
					}
					else{
						num=al->getN();
					}
					al->addLog(new Log(usuario, cmd, num));
					cmderror(cmd, al);
					al->Escribir();
				}
				catch(cmdError &e){
					cout<<e.what()<<endl;
				}
			}
		}
		
		void cmderror(string cmd, AdminLog* al){
			int error;
			if (cmd=="listar"){
				al->print();
			}else{
				error=system(cmd.c_str());
				system("cls");
			}
			if (error==1){
				throw cmdError("El comando introducido no es valido");
			}else{
				if(cmd=="listar"){
					
				}else{
					system(cmd.c_str());
				}
			}
		}
        
        ~Logger(){}    
};
#endif
