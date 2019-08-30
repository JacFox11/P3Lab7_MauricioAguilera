#include<iostream>
#include<iomanip> 
#include <string.h>

#ifndef Log_CPP
#define Log_CPP
using namespace std;
class Log{
    private:
            char usuario[25];
            char comando[25];
            int num;
    public:
        Log(){
		}    
		          
        Log(string usuario, string comando, int num){
            setUsuario(usuario);
            setComando(comando);
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
             
        void setComando(string comando){
            const char *temp = comando.data();
            int num =comando.size();
            num = num < 50 ? num:49;
            strncpy(this->comando, temp, num);
            this->comando[num] = '\0';
        }
             
        string getComando(){
            return this->comando;
        }
             
        void setNum(int num){
            this->num=num;
        }
             
        int getNum(){
            return this->num;
        }
			                     
        void print(){
            cout<<"Num: "<<num<<", Usuario: "<<usuario<<", cmd: "<<comando<<endl;
        } 
        
        ~Log(){}    
};
#endif

