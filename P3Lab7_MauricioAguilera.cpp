#include "Consola.cpp"

int main(){
	string usuario;
	cout<<"...:::BIENVENIDO:::..."<<endl;
	cout<<"Usuario: ";
	cin>>usuario;
	Consola* consola= new Consola(usuario, new Logger(usuario, "logs,bin"));
	
	try{
		consola->getLogger()->run();
	}
	catch(exception &e){
		cout<<"Oops"<<endl;
	}
	delete consola;
	system("pause");
	return 0;
}
