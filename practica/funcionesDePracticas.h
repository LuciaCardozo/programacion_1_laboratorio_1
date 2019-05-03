#ifndef FUNCIONESDEPRACTICAS_H_INCLUDED
#define FUNCIONESDEPRACTICAS_H_INCLUDED
/** \brief suma dos numeros y carga el valor en la variable pResultado
 *
 * \param float numeroUno es el primer numero ingresado por el usuario
 * \param float numeroDos es el segundo numero ingresado por el usuario
 * \param float* pResultado es el resultado de la suma de las dos variables ingresada por el usuario
 *\
 * \return si devuelve 0(cero) esto indica que mi funcion esta todo ok
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
 * \return si devuelve 0(cero) esto indica que mi funcion esta todo ok
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
 * \return retorna el resultado
 *
 */
int sacarFactorial(int numeroIngresado);
int opcionesMenu();
char subMenucalcularOperaciones();
char subMenuInformarResultados();


#endif // FUNCIONESDEPRACTICAS_H_INCLUDED
