#ifndef USUSARIO_H
#define USUSARIO_H
#include <string>
//#pragma once
class Ususario
{
    private:
        char usuario[20], password[15];
        bool login;
    public:
        Ususario();
        virtual ~Ususario();
        void setUser();
        void setPass();
        void getUser();
        void getPass();
        void cargarUsuario();
        void grabarUsuario();
};
    void leerUsuarios();
#endif // USUSARIO_H
