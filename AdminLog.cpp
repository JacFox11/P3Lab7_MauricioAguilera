#include "Log.cpp"
#include <fstream>
#include <vector>

#ifndef AdminLog_CPP
#define AdminLog_CPP

class AdminLog{
	private:
		string ruta;
		vector <Log*> logs;
	public:
		AdminLog(string ruta){
			this->ruta=ruta;
		}
		
		string getRuta(){
			return ruta;
		}
		
		void addLog(Log *p){
                 logs.push_back(p);
		    }
            
             vector<Log*> getlogs(){
                  return this->logs;
             } 

			void remLog(int p){
                  logs.erase(
				     logs.begin()+p);
             }
			 
			 int getN(){
               logs.size();
			}             
            
            ~AdminLog(){}
            
            void Escribir(){
            	fstream Escribir(ruta.c_str(), ios::out | ios::binary);
            	for (int i=0; i<logs.size() ;i++){
            		Log actual(logs.at(i)->getUsuario(), logs.at(i)->getComando(), logs.at(i)->getNum());
            		Escribir.seekp(0,ios::end);
					Escribir.write((char*)(&actual), sizeof(Log)); 
				}
				Escribir.close();
			}
			
			void Leer(){
				fstream Leer(ruta.c_str(), ios::in | ios::binary);
				Leer.seekg(0,ios::beg);
				logs.clear();
				int c=0;
				if (!Leer){
				}else{
					while(!Leer.eof()){
						Log actual;
						Leer.read((char*)(&actual), sizeof(Log));
						Log* e= new Log(actual.getUsuario(), actual.getComando(), actual.getNum());
						addLog(e);
					}
					Leer.close();
				}
			}
			
			void print(){
				system("pause");
				cout<<"logs:"<<endl;
				for(int i=0; i<logs.size(); i++){
					logs.at(i)->print();
				}
			}
};

#endif
