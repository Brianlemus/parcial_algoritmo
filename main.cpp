#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

//variables constantes
const int maximo = 1100;
const int minimo = 110;
const int valor_pelicula = 45;

//variables globales
string us = "";
string sucursal = "";

//aqui empiezo a armar las estructuras de datos.

// aqui empiezo armando la estructura de las peliculas
struct Peliculas{
    string nombre;
    string lanzaminto;
    string tipo;
    string resenia;
    int anio_produccion;
};

// aqui empiezo armando la estructura del usuario
struct Usuario{
    string user;
    string pass;
    string sucursal;
};


// aqui empiezo armando la estructura para los boletos
struct Boleto{
    int id_pelicula;
    int num_personas;
    int numero_butaca;
    string hora_funcion;
    float golosinas;
    string sucursal;
};

Peliculas *fichas = new Peliculas[maximo];//arreglo para poder almacenar las peliculas, hasta un limite de 1100
Usuario *fichas1 = new Usuario[minimo];//arreglo para almacenar los usuarios, hasta un limite de 20 usuarios
Boleto *fichas2 = new Boleto[maximo];//arreglo para almacenar los usuarios, hasta un limite de 20 usuarios

//variables para saber los interadores de cuando se agrega un nuevo struc a su respectivo arreglo
int cantidad_usuarios=0;
int cantidad_peliculas=0;
int cantidad_boletos=0;

int opcion;



// aqui empiezo a cargar el usuario
void cargar_usuario(){

    string nombre = "usuarios.txt";
    string linea;
    cantidad_usuarios = 0;

    ifstream fichero(nombre.c_str());
    if( fichero.fail() ){
        cout << "No existe el fichero " << nombre << "!" << endl;
        exit(1);
    }

    while (!fichero.eof()) {
        getline(fichero,linea);

        if (!fichero.eof()){

            vector <string> tokens;
            stringstream check1(linea);
            string intermediate;

            while(getline(check1, intermediate, ',')){

                tokens.push_back(intermediate);
            }

            for(int i = 0; i < tokens.size(); i=i+3){
                if(cantidad_usuarios < minimo){
                    fichas1[cantidad_usuarios].user = tokens[i];
                    fichas1[cantidad_usuarios].pass = tokens[i+1];
                    fichas1[cantidad_usuarios].sucursal = tokens[i+2];
                    cantidad_usuarios++;
                }

             }

        }
    }

    fichero.close();


}

void cargarlaspeliculas(){

    string nombre = "peliculas.txt";
    string linea;
    cantidad_peliculas = 0;

    ifstream fichero(nombre.c_str());
    if( fichero.fail() ){
        cout << "No existe el fichero " << nombre << "!" << endl;
        exit(1);
    }

    while (!fichero.eof()) {
        getline(fichero,linea);

        if (!fichero.eof()){

            vector <string> tokens1;
            stringstream check1(linea);
            string intermediate;

            while(getline(check1, intermediate, ',')){

                tokens1.push_back(intermediate);
            }

            for(int i = 0; i < tokens1.size(); i=i+5){
                if(cantidad_peliculas < maximo){
                    fichas[cantidad_peliculas].nombre = tokens1[i];
                    fichas[cantidad_peliculas].lanzaminto = tokens1[i+1];
                    fichas[cantidad_peliculas].tipo = tokens1[i+2];
                    fichas[cantidad_peliculas].resenia = tokens1[i+3];
                    fichas[cantidad_peliculas].anio_produccion = atoi(tokens1[i+4].c_str());
                    cantidad_peliculas++;

                }

             }

        }
    }

    fichero.close();

}

void cargar_boletos(){

    string nombre = "boletos.txt";
    string linea;
    cantidad_boletos = 0;

    ifstream fichero(nombre.c_str());
    if( fichero.fail() ){
        cout << "No existe el fichero " << nombre << "!" << endl;
        exit(1);
    }

    while (!fichero.eof()) {
        getline(fichero,linea);

        if (!fichero.eof()){

            vector <string> tokens2;
            stringstream check1(linea);
            string intermediate;

            while(getline(check1, intermediate, ',')){

                tokens2.push_back(intermediate);
            }

            for(int i = 0; i < tokens2.size(); i=i+6){
                if(cantidad_boletos < maximo){
                    fichas2[cantidad_boletos].id_pelicula = atoi(tokens2[i].c_str());
                    fichas2[cantidad_boletos].num_personas = atoi(tokens2[i+1].c_str());
                    fichas2[cantidad_boletos].numero_butaca = atoi(tokens2[i+2].c_str());
                    fichas2[cantidad_boletos].hora_funcion = tokens2[i+3];
                    fichas2[cantidad_boletos].golosinas = stof(tokens2[i+4].c_str());
                    fichas2[cantidad_boletos].sucursal = tokens2[i+5];
                    cantidad_boletos++;

                }

             }
        }
    }

    fichero.close();
}

void guardar_peliculas(){
    remove("peliculas.txt");
    ofstream fichero("peliculas.txt");
    for(int i = 0; i < cantidad_peliculas; i++){
        fichero << fichas[i].nombre << "," ;
        fichero << fichas[i].lanzaminto << "," ;
        fichero << fichas[i].tipo << "," ;
        fichero << fichas[i].resenia << "," ;
        fichero << fichas[i].anio_produccion << endl;
    }


    fichero.close();

}

// aqui empiezo a guardar los boletos con datos.
void guardar_boletos(){
    remove("boletos.txt");
    ofstream fichero("boletos.txt");
    for(int i = 0; i < cantidad_boletos; i++){
        fichero<<fichas2[i].id_pelicula << "," ;
        fichero<<fichas2[i].num_personas << "," ;
        fichero<<fichas2[i].numero_butaca << "," ;
        fichero<<fichas2[i].hora_funcion << "," ;
        fichero<<fichas2[i].golosinas << "," ;
        fichero<<fichas2[i].sucursal << endl;
    }

    fichero.close();

}

// aqui empiezo a guardar los boletos con datos.

void guardar_usuarios(){
    remove("usuarios.txt");
    ofstream fichero("usuarios.txt");
    for(int i = 0; i < cantidad_usuarios; i++){
        fichero<<fichas1[i].user << "," ;
        fichero<<fichas1[i].pass << ",";
        fichero<<fichas1[i].sucursal << endl;
    }


    fichero.close();

}

// armo el login.
void login(){
    bool bandera = true;

    do{
        cout << ">>IDENTIFIQUESE<<" << endl;
        string user ="";
        string pass ="";

        cout << "ingrese su usuario: ";
        getline(cin, user);
        cout << "ingrese su contrasenia: ";
        getline(cin, pass);

        for(int i = 0; i < cantidad_usuarios; i++){
            if(fichas1[i].user == user && fichas1[i].pass == pass){
                bandera = false;
                us = fichas1[i].user;
                sucursal = fichas1[i].sucursal;
                break;
            }
        }
        if(bandera){
            cout << "...Credenciales incorrectas..." << endl;
            system("pause");
            system("cls");
        }
    }while(bandera);

    system("cls");
}

// empiezo a agregar las peliculas.

void agregar_pelicula(){
    if (cantidad_peliculas < maximo){ // Si queda espacio
        cout << "Introduce el nombre de la pelicula: ";
        getline(cin, fichas[cantidad_peliculas].nombre);
        cin.sync();

        cout << "Introduce el anio de lanzamiento: ";
        getline(cin, fichas[cantidad_peliculas].lanzaminto);
        cin.sync();

        cout << "Introduce el tipo de video (2d o 3d): ";
        getline(cin, fichas[cantidad_peliculas].tipo);
        cin.sync();

        cout << "Introduce el anio de produccion: ";
        cin >> fichas[cantidad_peliculas].anio_produccion;
        cin.sync();

        cout << "Introduce una resenia: ";
        getline(cin, fichas[cantidad_peliculas].resenia);
        cin.sync();

        cantidad_peliculas++;

        cout << "<< Pelicula registrada correctamente >>" << endl;

        guardar_peliculas();
        cargarlaspeliculas();
        system("pause");
        system("cls");
    }else{
            cout << "Maximo de peliculas alcanzado (" << maximo << ")!" << endl;
    }
}

// empiezo a agregar los usuarios
void agregar_usuarios(){
    if (cantidad_usuarios < maximo){ // Si queda espacio
        cout << "Introduce el nombre de usuario: ";
        getline(cin, fichas1[cantidad_usuarios].user);
        cin.sync();

        cout << "Introduce el password: ";
        getline(cin, fichas1[cantidad_usuarios].pass);
        cin.sync();

        cout << "Introduce la sucursal: ";
        getline(cin, fichas1[cantidad_usuarios].sucursal);
        cin.sync();

        cantidad_usuarios++;

        cout << "<< Usuario registrado correctamente >>" << endl;

        guardar_usuarios();
        cargar_usuario();
        system("pause");
        system("cls");

    }else{
            cout << "Maximo de usuarios alcanzado (" << minimo << ")!" << endl;
    }
}

// aqui inboco los usuarios que ya estan guardados.
void muestra_usuario(){
    for (int i=0; i<cantidad_usuarios; i++){
        cout << "Usuario: " << fichas1[i].user << "\n";
    }
    system("pause");
    system("cls");
}

// aqui empiezo a mostrar las peliculas guardadas.
void muestra_peliculas(){
    for (int i=0; i < cantidad_peliculas; i++){
        cout << "ID: " << i << "\n"
             << "Nombre: " << fichas[i].nombre << "\n"
             << "Lanzamiento: " << fichas[i].lanzaminto << "\n"
             << "Tipo: " << fichas[i].tipo << "\n"
             << "Produccion: " << fichas[i].anio_produccion << "\n"
             << "Resenia: " << fichas[i].resenia << endl << endl;
    }
    system("pause");
    system("cls");

}

// aqui empiezo a mostrar los boletos ya guardados.
void muestra_boletos(){
    for (int i=0; i < cantidad_boletos; i++){
        cout << "ID: " << i << "\n"
             << "Pelicula: " << fichas[fichas2[i].id_pelicula].nombre << "\n"
             << "Hora de la funcion: " << fichas2[i].hora_funcion << "\n"
             << "Numero de butaca: " << fichas2[i].numero_butaca << "\n"
             << "Numero de personas: " << fichas2[i].num_personas << "\n"
             << "Total gastado: " << fichas2[i].golosinas + (fichas2[i].num_personas*valor_pelicula) << "\n"
             << "Resenia: " << fichas[i].resenia << endl << endl;
    }
    system("pause");
    system("cls");

}

// aqui edito usuarios ya guardados.
void editar_usuario(){
    string nombre = "";
    string pass = "";
    int numero;
    bool existe = false;

    cout << "Introduce el nombre de usuario: ";
    getline(cin,nombre);
    cin.sync();

    for(int i = 0; i < cantidad_usuarios; i++){
        if(nombre == fichas1[i].user){
            existe = true;
            numero = i;
            break;
        }
    }

    if(existe){
        cout << "Introduce la contraseña anterior: ";
        getline(cin, pass);
        cin.sync();

        if(fichas1[numero].pass == pass){
            string nueva = "";
            cout << "Ingrese nueva contraseña: ";
            getline(cin, nueva);
            cin.sync();

            fichas1[numero].pass = nueva;
        }else{
            cout << "La contraseña es incorrecta, intenta nuevamente!" << endl;
        }

    }else{
        cout << "El usuario no existe en nuestra base de datos!" << endl;
    }

    guardar_usuarios();
    cargar_usuario();
    system("pause");
    system("cls");
}

// aqui edito las peliculas guardadas.
void editar_pelicula(){
    int id = 999;
    string res = "";

    cout << "Ingrese el ID de la pelicula: ";
    cin >> id;
    cin.sync();

    cout << "La pelicula es: " << fichas[id].nombre << "? si/no" << endl;
    getline(cin, res);
    if(res == "si"){
        cout << "Introduce el nombre de la pelicula: ";
        getline(cin, fichas[id].nombre);
        cin.sync();

        cout << "Introduce el anio de lanzamiento: ";
        getline(cin, fichas[id].lanzaminto);
        cin.sync();

        cout << "Introduce el tipo de video (2d o 3d): ";
        getline(cin, fichas[id].tipo);
        cin.sync();

        cout << "Introduce el anio de produccion: ";
        cin >> fichas[id].anio_produccion;
        cin.sync();

        cout << "Introduce una resenia: ";
        getline(cin, fichas[id].resenia);
        cin.sync();

        guardar_peliculas();
        cargarlaspeliculas();
        system("pause");
        system("cls");
    }else{
        cout << "Intentalo nuevamente!" << endl;
        system("pause");
        system("cls");
    }
}

// aqui muestro las peliculas por a?o ya guardadas.
void mostrarPeliculasPorAnio(){
    int anio = 0;
    bool bandera = false;
    cout << "Ingrese el anio que desea filtrar: ";
    cin >> anio;
    cin.sync();
    system("cls");

    for(int i = 0; i < cantidad_peliculas; i++){
        if(fichas[i].anio_produccion == anio){
            cout << "ID: " << i << "\n"
             << "Nombre: " << fichas[i].nombre << "\n"
             << "Lanzamiento: " << fichas[i].lanzaminto << "\n"
             << "Tipo: " << fichas[i].tipo << "\n"
             << "Produccion: " << fichas[i].anio_produccion << endl << endl;
             bandera = true;
        }
    }

    if(!bandera){
        cout << "No tenemos en nuestra base de datos peliculas de ese anio." << endl;
    }

    system("pause");
    system("cls");
}

// aqui muestro las peliculas por estreno guardadas.
void mostrar_peliculas_Estreno(){
    for(int i = 0; i < cantidad_peliculas; i++){
        if(fichas[i].anio_produccion == 2020){
            cout << "ID: " << i << "\n"
             << "Nombre: " << fichas[i].nombre << "\n"
             << "Resenia: " << fichas[i].resenia << endl << endl;
        }
    }

    system("pause");
    system("cls");
}

void crearBoleto(){


    if (cantidad_boletos < maximo){

        cout << "El precio para todas las peliculas es de: " << valor_pelicula << endl;

        cout << "Introduce el ID de la pelicula: ";
        cin >> fichas2[cantidad_boletos].id_pelicula;
        cin.sync();

        cout << "Introduce el numero de personas: ";
        cin >> fichas2[cantidad_boletos].num_personas;
        cin.sync();

        cout << "Introduce el numero de butaca: ";
        cin >> fichas2[cantidad_boletos].numero_butaca;
        cin.sync();

        cout << "Introduce la hora de la funcion: ";
        getline(cin, fichas2[cantidad_boletos].hora_funcion);
        cin.sync();

        cout << "Introduce el total gastado en golosinas: ";
        cin >> fichas2[cantidad_boletos].golosinas;
        cin.sync();

        fichas2[cantidad_boletos].sucursal = sucursal;

        cout << "Total gastado: " << fichas2[cantidad_boletos].golosinas + (fichas2[cantidad_boletos].num_personas*valor_pelicula) << endl;
        cout << "<< Boleto guardado correctamente >>" << endl;

        cantidad_boletos++;

        guardar_boletos();
        cargar_boletos();

        system("pause");
        system("cls");
    }else{
            cout << "Maximo de boletos alcanzado (" << maximo << ")!" << endl;
    }
}


//funcion inicial
int main(){

    cargar_usuario();
    login();
    cargarlaspeliculas();
    cargar_boletos();

    do
    {

        // Menu principal
        cout << endl;
        cout << "************** Sucursal de: " << sucursal << " **************" << endl;
        cout << "Escoja una opcion:" << endl;
        cout << "1.-  Aniadir una pelicula" << endl;
        cout << "2.-  Mostrar todas las peliculas" << endl;
        cout << "3.-  Editar pelicula" << endl;
        cout << "4.-  Agregar usuario" << endl;
        cout << "5.-  Mostrar usuarios" << endl;
        cout << "6.-  Cambiar contrasenia usuario" << endl;
        cout << "7.-  Mostrar peliculas segun anio de produccion" << endl;
        cout << "8.-  Mostrar peliculas de estreno" << endl;
        cout << "9.-  Crear boleto" << endl;
        cout << "10.- Ver boletos" << endl;
        cout << "11.- Salir" << endl;

        cin >> opcion;
        cin.sync();
        system("cls");

        // Hacemos una cosa u otra según la opción escogida
        switch(opcion){
            case 1: //añadir una pelicula
                agregar_pelicula();
                break;

            case 2://mostrar todas las peliculas
                muestra_peliculas();
                break;

            case 3: //editar pelicula
                editar_pelicula();
                break;

            case 4: //agregar usuario
                agregar_usuarios();
                break;

            case 5:
                muestra_usuario();
                break;

            case 6:
                editar_usuario();
                break;

            case 7:
                mostrarPeliculasPorAnio();
                break;

            case 8:
                mostrar_peliculas_Estreno();
                break;
            case 9:
                crearBoleto();
                break;
            case 10:
                muestra_boletos();
                break;
            case 11: // Salir: avisamos de que salimos
                cout << "Fin del programa" << endl;
                break;

            default: // Otra opcion: no válida
                cout << "Opción desconocida!" << endl;
                system("pause");
                system("cls");
                break;
        }
    } while (opcion != 11);  // Si la opcion es 11, terminamos
    return 0;
}
