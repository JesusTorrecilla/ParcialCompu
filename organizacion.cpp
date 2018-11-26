#include "organizacion.h"
#include <iostream>
#include "myconnection.h"
#include "persona.h"

using namespace std;
Organizacion::Organizacion()
{
    nombre="";

}

Organizacion::Organizacion(string nombre)
{
    this->setNombre(nombre);
}

void Organizacion::agregar()
{
string stringSQL;
    stringstream values;
    values << this->getNombre();
    stringSQL = "INSERT INTO organizacion (nombre) VALUES ('"+values.str()+"');";
    MyConnection::instance()->execute(stringSQL);
    this->inicio();
}

void Organizacion::inicio(){

     cout<<"<html><head>"<<endl;
    cout<<"<link href='http://localhost/bootstrap.css' rel='stylesheet'>"<<endl;
    cout << "</head>" <<endl;
    cout << "<body>   <div class='container'>"<<endl;
    cout<<"<br><br><br>"<<endl;
    cout<<"<div class='centrar'><h1>Organizaciones</h1></div>"<<endl;
    cout<<"<div class='centrar'><h2>Organizaciones cargadas</h2></div>"<<endl;
    cout << "<table class='table table-hover table-bordered  table-striped' cellpadding='0' cellspacing='0'>" << endl;
    cout << "<thead><tr>" << endl;
    cout << "<th >id</th>"<< endl;
    cout << "<th >Nombre</th>"<< endl;
    cout << "</tr></thead>" << endl;
    cout << "<tbody><tr>" << endl;
    this->listar();
    cout << "</tr>" << endl;
    cout << "</tr></tbody>" << endl;
    cout << "</table>" << endl;
    cout << "<br><h3>Ordenado por nombre</h3><br>" << endl;
    cout << "<table class='table table-hover table-bordered  table-striped' cellpadding='0' cellspacing='0'>" << endl;
    cout << "<thead><tr>" << endl;
    cout << "<th >id</th>"<< endl;
    cout << "<th >Nombre</th>"<< endl;
    cout << "</tr></thead>" << endl;
    cout << "<tbody><tr>" << endl;
    this->listar2();
    cout << "</tr>" << endl;
    cout << "</tr></tbody>" << endl;
    cout << "</table>" << endl;
        cout << "<br><h3>Personas por organizacion</h3><br>" << endl;
    cout << "<table class='table table-hover table-bordered  table-striped' cellpadding='0' cellspacing='0'>" << endl;
    cout << "<thead><tr>" << endl;
    cout << "<th >Nombre</th>"<< endl;
    cout << "<th >Personas</th>"<< endl;
    cout << "</tr></thead>" << endl;
    cout << "<tbody><tr>" << endl;
    this->listar3();
    cout << "</tr>" << endl;
    cout << "</tr></tbody>" << endl;
    cout << "</table>" << endl;
    cout<<"<div class='centrar'><h2>Agregar Organizacion</h2></div>"<<endl;
    cout<<"<form class='form-signin'  method='post'>"<<endl;
    cout<<"<label for='org' class='sr-only'>Organizacion</label>"<<endl;
    cout<<"<input type='text' id='org' name='org' class='form-control' placeholder='org' required autofocus>"<<endl;
    cout<<"<br>"<<endl;
    cout<<"<br>"<<endl;
    cout<<"<button class='btn btn-lg btn-primary btn-block' name='botonorg' type='submit'>Enviar</button>"<<endl;
    cout << "<a href='2Parcial'" << endl;
    cout << ">Volver</a>"<<endl;
    cout<<"</form>"<<endl;
    cout<<"</div></body></html>"<<endl;
}
void Organizacion::listar()
{
    MyConnection myconnection;
    myconnection.connect();
    sql::ResultSet* personas_organizaciones = myconnection.query("SELECT * FROM organizacion");

    while (personas_organizaciones->next()) {
        cout << "<tr>" << endl;
        cout << "<td>" << endl;
        cout << personas_organizaciones->getString("id") << endl;
        cout << "</td>" << endl;
        cout << "<td>" << endl;
        cout << personas_organizaciones->getString("nombre") << endl;
        cout << "</td>" << endl;
        cout << "<td>" << endl;
        cout << "<a href='2Parcial?ideliminar=" + personas_organizaciones->getString("id") + "'" << endl;
        cout << ">Eliminar</a>"<<endl;
        cout << "</td>" << endl;
        cout << "<td>" << endl;
    }
}

void Organizacion::listar2()
{
    MyConnection myconnection;
    myconnection.connect();
    sql::ResultSet* personas_organizaciones = myconnection.query("SELECT * FROM computacion.organizacion ORDER BY nombre ASC;");

    while (personas_organizaciones->next()) {
        cout << "<tr>" << endl;
        cout << "<td>" << endl;
        cout << personas_organizaciones->getString("id") << endl;
        cout << "</td>" << endl;
        cout << "<td>" << endl;
        cout << personas_organizaciones->getString("nombre") << endl;
        cout << "</td>" << endl;
        cout << "<td>" << endl;
        cout << "<a href='2Parcial?ideliminar=" + personas_organizaciones->getString("id") + "'" << endl;
        cout << ">Eliminar</a>"<<endl;
        cout << "</td>" << endl;
        cout << "<td>" << endl;
    }
}

void Organizacion::listar3()
{
    MyConnection myconnection;
    myconnection.connect();
    sql::ResultSet* personas_organizaciones = myconnection.query("SELECT persona.idorganizacion, count(*) as contador, organizacion.id as id_organizacion, organizacion.nombre as nombre_organizacion FROM persona INNER JOIN organizacion ON persona.idorganizacion = organizacion.id group by idorganizacion");

    while (personas_organizaciones->next()) {
    cout << "<tr>" << endl;
      cout << "<td>" << endl;
      cout << personas_organizaciones->getString("nombre_organizacion") << endl;
      cout << "</td>" << endl;
      cout << "<td>" << endl;
      cout << personas_organizaciones->getString("contador") << endl;
      cout << "</td>" << endl;
      cout << "<td>" << endl;
      cout << "<a href='P2?eliminar_organizacion=" + personas_organizaciones->getString("id_organizacion") + "'" << endl;
      cout << ">Eliminar</a>"<<endl;
      cout << "</td>" << endl;
      cout << "</tr>" << endl;
    }
}


void Organizacion::eliminar(string id){
    string stringSQL;
    stringSQL = "DELETE FROM organizacion WHERE id='"+id+"'";
    MyConnection::instance()->execute(stringSQL);
}

void Organizacion::setNombre(string nombre)
{
    this->nombre = nombre;
}

string Organizacion::getNombre()
{
    return this->nombre;
}
