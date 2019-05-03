#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
/** \brief suma dos numeros y carga el valor en la variable pResultado
 *
 * \param float numeroUno es el primer numero ingresado por el usuario
 * \param float numeroDos es el segundo numero ingresado por el usuario
 * \param float* pResultado es el resultado de la suma de las dos variables ingresada por el usuario
 *\
 * \return retorna 0(cero
 *
 */
float sumaDosNumeros(float numeroUno, float numeroDos, float* pResultado);
/** \brief resta dos numeros y carga el valor en la variable pResultado
 *
 * \param float numeroUno es el primer numero ingresado por el usuario
 * \param float numeroDos es el segundo numero ingresado por el usuario
 * \param float* pResultado es el resultado de la resta de las dos variables ingresada por el usuario
 *\
 * \return si devuelve 0(cero) esto indica que mi funcion esta todo ok
 *
 */
float restaDosNumeros(float numeroUno, float numeroDos, float* pResultado);
/** \brief divide dos numeros y carga el valor en la variable pResultado
 *
 * \param float numeroUno es el primer numero ingresado por el usuario
 * \param float numeroDos es el segundo numero ingresado por el usuario
 * \param float* pResultado se guarda el resultado de la division de las dos variables ingresada por el usuario
 *\
 * \return retorna 0 si esta todo ok o retorna -1 si hay un error
 *
 */
float divideDosNumeros(float numeroUno, float numeroDos, float* pResultado);
/** \brief multiplica dos numeros y carga el valor en la variable pResultado
 *
 * \param float numeroUno es el primer numero ingresado por el usuario
 * \param float numeroDos es el segundo numero ingresado por el usuario
 * \param float* pResultado se guarda el resultado de la multiplicacion de las dos variables ingresada por el usuario
 *\
 * \return si devuelve 0(cero) esto indica que mi funcion esta todo ok
 *
 */
float multiplicoDosNumeros(float numeroUno, float numeroDos, float* pResultado);
/** \brief saca factorial de un numero
 *
 * \param el numeroIngresado es el numero que ingresa el usuario
 * \param
 *\
 * \return retorna resultado, devuelve 0(cero) si esta todo ok o devuelve -1(menos uno) si tiene un error
 *
 */
int sacarFactorial(int numeroIngresado);
/** \brief Esta funcion muestra el menu principal y el usuario elije una opcion
 *
 * \param
 * \param
 * \return retorna la respuesta si esta todo ok o retorna -1 si hay un error
 *
 */

int opcionesMenu();
/** \brief Esta funcion muestra un sub menu,el usuario elije una opcion y se calcula lo que selecciono
 *
 * \param
 * \param
 * \return retorna la respuesta si esta todo ok o retorna -1 si hay un error
 *
 */

char subMenucalcularOperaciones();
/** \brief Esta funcion muestra un sub menu, el usuario selecciona la opcion que eligio anteriormente y se muestra por pantalla
 *
 * \param
 * \param
 * \return retorna la respuesta si esta todo ok o retorna -1 si hay un error
 *
 */

char subMenuInformarResultados();
void limpiarMemoria();


#endif // FUNCIONES_H_INCLUDED
