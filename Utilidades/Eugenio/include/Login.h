#ifndef LOGIN_H
#define LOGIN_H


class Login
{
    private:
        string usuario="Admin";
        string contrasena="tongogestion";
    public:
        bool acceso;
        string userName;
        string pass;
        bool setLogin(bool);
//        virtual ~Login();
        void setUser();
        void setPass();
        void getUser();
        void login();
};

#endif // LOGIN_H
