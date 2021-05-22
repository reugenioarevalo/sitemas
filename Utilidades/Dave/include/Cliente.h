#ifndef CLIENTE_H
#define CLIENTE_H


class Cliente: public Persona {

	private:
	    int idCliente;
        char razonSocial[50];
        char mail[50];
        int tipoCliente;
	public:
		Cliente();
		Cliente(char*, char*, int);
		//virtual ~Cliente();

		void setIdCliente();
		int getIdCliente();


};

#endif // CLIENTE_H
